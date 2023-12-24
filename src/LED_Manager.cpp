
#include "LED_Manager.h"

LED_Manager LED_MANAGER;

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
}

void LED_Manager::load(String& jsonFile) {

}

void LED_Manager::save(String& jsonFile) {

}

LED_Strip* LED_Manager::addStrip(LED_StripDefinition& definition) {
    uint8_t id = this->strips.size();
    this->strips.emplace_back(definition);
    LED_Strip* ret = &this->strips[id];
    ret->setId(id);
    return ret;
}

LED_Strip* LED_Manager::getStripByIndex(uint8_t index) {
    if (index >= this->strips.size()) {
        return nullptr;
    }
    return &this->strips[index];
}

LED_Strip* LED_Manager::getStripByName(String& name) {
    for (auto& strip : this->strips) {
        if (strip.getDefinition().name == name) {
            return &strip;
        }
    }
    return nullptr;
}

LED_Panel* LED_Manager::addPanel(LED_PanelDefinition& definition) {
    uint8_t id = this->panels.size();
    this->panels.emplace_back(definition);
    LED_Panel* ret = &this->panels[id];
    ret->setId(id);
    return ret;
}

LED_Panel* LED_Manager::getPanelByIndex(uint8_t index) {
    if (index >= this->panels.size()) {
        return nullptr;
    }
    return &this->panels[index];
}

LED_Panel* LED_Manager::getPanelByName(String& name) {
    for (auto& panel : this->panels) {
        if (panel.getDefinition().name == name) {
            return &panel;
        }
    }
    return nullptr;
}
