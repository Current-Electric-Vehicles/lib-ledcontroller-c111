
#ifndef LED_PANEL_H
#define LED_PANEL_H

#include <Arduino.h>
#include <FastLED.h>
#include <vector>

#include "LED_Strip.h"

#define INVALID_PANEL_ID ((uint8_t)UINT8_MAX)

struct LED_PanelDefinition {
    String name;
    uint16_t width;
    uint16_t height;
};

struct LED_MappedPixel {
    uint8_t stripId;
    uint16_t pixelIndex;
    CRGB* pixel;
};

class LED_Panel {
public:

    LED_Panel(LED_PanelDefinition& def);
    ~LED_Panel();

    LED_PanelDefinition& getDefinition();
    uint8_t getId();
    void setId(uint8_t id);

    LED_MappedPixel* getMappedPixelAt(uint16_t x, uint16_t y);
    LED_MappedPixel* mapPixelAt(uint16_t x, uint16_t y, LED_Strip* strip, uint16_t pixelIndex);
    
    void setPixelAt(uint16_t x, uint16_t y, CRGB* pixel);
    void setPixelAt(uint16_t x, uint16_t y, CRGB pixel);
    bool setNonEmptyPixelAt(uint16_t x, uint16_t y, CRGB* pixel);
    bool setNonEmptyPixelAt(uint16_t x, uint16_t y, CRGB pixel);
    
    uint16_t getWidth();
    uint16_t getHeight();

    void dumpDebug();
    
private:
    uint8_t id;
    LED_PanelDefinition def;
    std::vector<LED_MappedPixel> leds;
};

#endif
