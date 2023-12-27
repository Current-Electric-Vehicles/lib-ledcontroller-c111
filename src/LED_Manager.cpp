
#include "LED_Manager.h"

#include <ArduinoJson.h>
#include <SPIFFS.h>

LED_Manager LED_MANAGER;

std::atomic<uint8_t> LED_Manager::idGenerator(1);

LED_Manager::LED_Manager():
    strips(),
    panels() {

}

LED_Manager::~LED_Manager() {
    
}

void LED_Manager::unload() {
    this->panels.clear();
    this->panels.shrink_to_fit();
    this->strips.clear();
    this->strips.shrink_to_fit();
    LED_Manager::idGenerator = 1;
}

bool LED_Manager::load(const String& jsonFile) {
    size_t size = (this->strips.size() * 128);
    for (auto& panel : this->panels) {
        size += (panel.getWidth() * panel.getHeight() * 32);
        size += 128;
    }

    DynamicJsonDocument configDoc(size);
    File file = SPIFFS.open(jsonFile, FILE_READ);
    if (!file) {
        return false;
    }

    this->unload();
            
    deserializeJson(configDoc, file);
    file.close();

    // strips
    auto strips = configDoc["strips"].as<JsonArray>();
    for (int i = 0; i <strips.size(); i++) {
        auto stripJson = strips[i];

        LED_StripDefinition def;
        def.name        = stripJson["name"].as<String>();
        def.pixelType   = stripJson["pixelType"];
        def.pin         = stripJson["pin"];
        def.rgbOrder    = stripJson["rgbOrder"];
        def.offset      = stripJson["offset"];
        def.count       = stripJson["count"];

        this->addStrip(def, stripJson["id"].as<uint8_t>());
    }

    // panels
    auto panels = configDoc["panels"].as<JsonArray>();
    for (int i = 0; i <panels.size(); i++) {
        auto panelJson = panels[i];

        LED_PanelDefinition def;
        def.name        = panelJson["name"].as<String>();
        def.width       = panelJson["width"];
        def.height      = panelJson["height"];

        auto* panel = this->addPanel(def, panelJson["id"].as<uint8_t>());

        for (uint16_t x = 0; x < panel->getWidth(); x++) {
            for (uint16_t y = 0; y < panel->getHeight(); y++) {
                if (panelJson["pixels"][x][y] == nullptr || panelJson["pixels"][x][y].isNull()) {
                    continue;
                }
                uint8_t stripId = panelJson["pixels"][x][y][0];
                uint16_t pixelIndex = panelJson["pixels"][x][y][1];
                auto* strip = this->getStripById(stripId);
                panel->mapPixelAt(x, y, strip, pixelIndex);
            }
        }
    }

    return true;
}

bool LED_Manager::save(const String& jsonFile) {
    size_t size = (this->strips.size() * 128);
    for (auto& panel : this->panels) {
        size += (panel.getWidth() * panel.getHeight() * 32);
        size += 128;
    }

    DynamicJsonDocument configDoc(size);

    // strips
    for (int i = 0; i < this->strips.size(); i++) {
        auto& strip = this->strips[i];
        auto& def = strip.getDefinition();

        DynamicJsonDocument subDoc(128);
        subDoc["id"]          = strip.getId();
        subDoc["name"]        = def.name;
        subDoc["pixelType"]   = def.pixelType;
        subDoc["pin"]         = def.pin;
        subDoc["rgbOrder"]    = def.rgbOrder;
        subDoc["offset"]      = def.offset;
        subDoc["count"]       = def.count;

        configDoc["strips"][i] = subDoc;
    }

    // panels
    for (int i = 0; i < this->panels.size(); i++) {
        auto& panel = this->panels[i];
        auto& def = panel.getDefinition();

        DynamicJsonDocument subDoc(128 + (panel.getWidth() * panel.getHeight() * 24));
        subDoc["id"]          = panel.getId();
        subDoc["name"]        = def.name;
        subDoc["width"]       = panel.getWidth();
        subDoc["height"]      = panel.getHeight();

        for (uint16_t x = 0; x < panel.getWidth(); x++) {
            for (uint16_t y = 0; y < panel.getHeight(); y++) {
                auto* mappedPixel = panel.getMappedPixelAt(x, y);
                if (mappedPixel == nullptr) {
                    subDoc["pixels"][x][y] = nullptr;
                } else {
                    subDoc["pixels"][x][y][0] = mappedPixel->stripId;
                    subDoc["pixels"][x][y][1] = mappedPixel->pixelIndex;
                }
            }
        }

        configDoc["panels"][i] = subDoc;
    }

    // save it
    File file = SPIFFS.open(jsonFile, FILE_WRITE);
    if (!file) {
        return false;
    }
    serializeJson(configDoc, file);
    file.close();
    return true;
}

LED_Strip* LED_Manager::addStrip(LED_StripDefinition& definition, uint8_t id) {
    if (id == 0) {
        id = this->generateNextId();
    }
    this->strips.emplace_back(definition);
    LED_Strip* ret = &this->strips.back();
    ret->setId(id);
    return ret;
}

bool LED_Manager::removeStrip(uint8_t id) {
    for (size_t i = 0; i < this->strips.size(); i++) {
        auto& strip = this->strips[i];
        if (strip.getId() == id) {
            this->strips.erase(this->strips.begin() + i);
            return true;
        }
    }
    return false;
}

LED_Strip* LED_Manager::getStripById(uint8_t id) {
    for (auto& strip : this->strips) {
        if (strip.getId() == id) {
            return &strip;
        }
    }
    return nullptr;
}

LED_Strip* LED_Manager::getStripByName(String& name) {
    for (auto& strip : this->strips) {
        if (strip.getDefinition().name == name) {
            return &strip;
        }
    }
    return nullptr;
}

LED_Panel* LED_Manager::addPanel(LED_PanelDefinition& definition, uint8_t id) {
    if (id == 0) {
        id = this->generateNextId();
    }
    this->panels.emplace_back(definition);
    LED_Panel* ret = &this->panels.back();
    ret->setId(id);
    return ret;
}

bool LED_Manager::removePanel(uint8_t id) {
    for (size_t i = 0; i < this->panels.size(); i++) {
        auto& panel = this->panels[i];
        if (panel.getId() == id) {
            this->panels.erase(this->panels.begin() + i);
            return true;
        }
    }
    return false;
}

LED_Panel* LED_Manager::getPanelById(uint8_t id) {
    for (auto& panel : this->panels) {
        if (panel.getId() == id) {
            return &panel;
        }
    }
    return nullptr;
}

LED_Panel* LED_Manager::getPanelByName(String& name) {
    for (auto& panel : this->panels) {
        if (panel.getDefinition().name == name) {
            return &panel;
        }
    }
    return nullptr;
}

uint8_t LED_Manager::generateNextId() {
    uint8_t maxId = 0;
    for (auto& strip : this->strips) {
        if (strip.getId() > maxId) {
            maxId = strip.getId();
        }
    }
    for (auto& panel : this->panels) {
        if (panel.getId() > maxId) {
            maxId = panel.getId();
        }
    }
    uint8_t id = LED_Manager::idGenerator++;
    while (id <= maxId) {
        id = LED_Manager::idGenerator++;
        if (id == UINT8_MAX) {
            id = 0;
            break;
        }
    }
    return id;
}