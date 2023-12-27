
#ifndef LED_MANAGER_H
#define LED_MANAGER_H

#include <Arduino.h>
#include <FastLED.h>
#include <vector>
#include <atomic>

#include "LED_Strip.h"
#include "LED_Panel.h"

#define LED_CONFIG_FILE "/conf/led.json"

class LED_Manager {
public:
    LED_Manager();
    ~LED_Manager();

    void unload();
    bool load(const String& jsonFile = LED_CONFIG_FILE);
    bool save(const String& jsonFile = LED_CONFIG_FILE);

    LED_Strip* addStrip(LED_StripDefinition& definition, uint8_t id = 0);
    bool removeStrip(uint8_t id);
    LED_Strip* getStripById(uint8_t id);
    LED_Strip* getStripByName(String& name);

    LED_Panel* addPanel(LED_PanelDefinition& definition, uint8_t id = 0);
    bool removePanel(uint8_t id);
    LED_Panel* getPanelById(uint8_t id);
    LED_Panel* getPanelByName(String& name);

private:
    uint8_t generateNextId();
    static std::atomic<uint8_t> idGenerator;
    std::vector<LED_Strip> strips;
    std::vector<LED_Panel> panels;
};

extern LED_Manager LED_MANAGER;

#endif