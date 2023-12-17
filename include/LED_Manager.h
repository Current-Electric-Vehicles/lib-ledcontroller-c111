
#ifndef LED_MANAGER_H
#define LED_MANAGER_H

#include <Arduino.h>
#include <FastLED.h>
#include <vector>

#include "LED_Strip.h"
#include "LED_Panel.h"

class LED_Manager {
public:
    LED_Manager();
    ~LED_Manager();

    uint8_t addStrip(LED_StripDefinition& definition);
    LED_Strip* getStripByIndex(uint8_t index);
    LED_Strip* getStripByName(String& name);

    uint8_t addPanel(LED_PanelDefinition& definition);
    LED_Panel* getPanelByIndex(uint8_t index);
    LED_Panel* getPanelByName(String& name);

private:
    std::vector<LED_Strip> strips;
    std::vector<LED_Panel> panels;
};

#endif
