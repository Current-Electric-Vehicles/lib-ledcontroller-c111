
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
    Serial.print("Loading configuration from: ");  Serial.print(jsonFile);  Serial.println("");

    this->unload();

    StaticJsonDocument<LED_MANAGER_JSON_BUFFER_SIZE> configDoc;
    File file = SPIFFS.open(jsonFile, FILE_READ);
    if (!file) {
        Serial.print("Config file "); Serial.print(jsonFile); Serial.println(" not found!");
        return false;
    }
    auto result = deserializeJson(configDoc, file);
    file.close();

    if (result != DeserializationError::Ok) {
        Serial.print("DeserializationError: "); Serial.println(result.c_str());
        return false;
    }

    // strips
    for (int i = 0; i <configDoc["strips"].size(); i++) {
        Serial.println("Loading a strip");
        auto stripJson = configDoc["strips"][i];

        LED_StripConfig conf;
        conf.id          = stripJson["id"].as<uint8_t>();
        conf.name        = String(stripJson["name"].as<String>());
        conf.pixelType   = stripJson["pixelType"];
        conf.pin         = stripJson["pin"];
        conf.rgbOrder    = stripJson["rgbOrder"];
        conf.count       = stripJson["pixelCount"];

        this->addStrip(&conf);
    }

    // panels
    for (int i = 0; i <configDoc["panels"].size(); i++) {
        Serial.println("Loading a panel");
        auto panelJson = configDoc["panels"][i];

        LED_PanelConfig conf;
        conf.id          = panelJson["id"].as<uint8_t>();
        conf.name        = String(panelJson["name"].as<String>());
        conf.width       = panelJson["width"];
        conf.height      = panelJson["height"];

        auto* panel = this->addPanel(&conf);

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
    Serial.print("Saving configuration to: ");  Serial.print(jsonFile);  Serial.println("");

    StaticJsonDocument<LED_MANAGER_JSON_BUFFER_SIZE> configDoc;
    configDoc["version"] = 1;

    // strips
    for (int i = 0; i < this->strips.size(); i++) {
        auto& strip = this->strips[i];
        Serial.print("Saving strip with id "); Serial.println(strip.getId());

        configDoc["strips"][i]["id"]          = strip.getId();
        configDoc["strips"][i]["name"]        = strip.getName();
        configDoc["strips"][i]["pixelType"]   = strip.getPixelType();
        configDoc["strips"][i]["pin"]         = strip.getPin();;
        configDoc["strips"][i]["rgbOrder"]    = strip.getRgbOrder();
        configDoc["strips"][i]["pixelCount"]  = strip.getCount();
    }

    // panels
    for (int i = 0; i < this->panels.size(); i++) {
        auto& panel = this->panels[i];
        Serial.print("Saving panel with id "); Serial.println(panel.getId());

        configDoc["panels"][i]["id"]           = panel.getId();
        configDoc["panels"][i]["name"]         = panel.getName();
        configDoc["panels"][i]["width"]        = panel.getWidth();
        configDoc["panels"][i]["height"]       = panel.getHeight();

        for (uint16_t x = 0; x < panel.getWidth(); x++) {
            for (uint16_t y = 0; y < panel.getHeight(); y++) {
                auto* mappedPixel = panel.getMappedPixelAt(x, y);
                if (mappedPixel == nullptr) {
                    configDoc["panels"][i]["pixels"][x][y] = nullptr;
                } else {
                    configDoc["panels"][i]["pixels"][x][y][0] = mappedPixel->stripId;
                    configDoc["panels"][i]["pixels"][x][y][1] = mappedPixel->pixelIndex;
                }
            }
        }
    }

    // save it
    Serial.print("Saving config doc... ");
    File file = SPIFFS.open(jsonFile, "w+");
    if (!file) {
        Serial.print("Unable to open config file "); Serial.print(jsonFile); Serial.println(" for writing!");
        return false;
    }
    serializeJson(configDoc, file);
    file.close();
    Serial.println("Saved!");
    return true;
}

LED_Strip* LED_Manager::addStrip(LED_StripConfig* conf) {
    if (conf->id == 0) {
        conf->id = this->generateNextId();
    }
    this->strips.emplace_back(conf);
    return &this->strips.back();
}

bool LED_Manager::removeStrip(uint8_t id) {
    for (size_t i = 0; i < this->strips.size(); i++) {
        auto& strip = this->strips[i];
        if (strip.getId() == id) {
            Serial.println("About to erase");
            this->strips.erase(this->strips.begin() + i);
            Serial.println("Erased");

            // remove any panel references
            for (auto& panel : this->panels) {
                for (uint16_t x = 0; x < panel.getWidth(); x++) {
                    for (uint16_t y = 0; y < panel.getHeight(); y++) {
                        if (panel.getMappedPixelAt(x, y)->stripId == id) {
                            panel.removeMappedPixelAt(x, y);
                        }
                    }
                }
            }

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
        if (strip.getName() == name) {
            return &strip;
        }
    }
    return nullptr;
}

LED_Panel* LED_Manager::addPanel(LED_PanelConfig* conf) {
    if (conf->id == 0) {
        conf->id = this->generateNextId();
    }
    this->panels.emplace_back(conf);
    return &this->panels.back();
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
        if (panel.getName() == name) {
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
    while (id <= maxId && id == 0) {
        id = LED_Manager::idGenerator++;
        if (id == UINT8_MAX) {
            id = 0;
            break;
        }
    }
    return id;
}
