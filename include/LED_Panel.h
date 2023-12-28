
#ifndef LED_PANEL_H
#define LED_PANEL_H

#include <Arduino.h>
#include <FastLED.h>
#include <vector>

#include "LED_Strip.h"

#define INVALID_PANEL_ID ((uint8_t)UINT8_MAX)

struct LED_PanelConfig {
    uint8_t id = 0;
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

    LED_Panel(LED_PanelConfig* conf);
    ~LED_Panel();

    LED_MappedPixel* getMappedPixelAt(uint16_t x, uint16_t y);
    LED_MappedPixel* mapPixelAt(uint16_t x, uint16_t y, LED_Strip* strip, uint16_t pixelIndex);
    LED_MappedPixel* removeMappedPixelAt(uint16_t x, uint16_t y);
    
    void setPixelAt(uint16_t x, uint16_t y, CRGB* pixel);
    void setPixelAt(uint16_t x, uint16_t y, CRGB pixel);
    bool setNonEmptyPixelAt(uint16_t x, uint16_t y, CRGB* pixel);
    bool setNonEmptyPixelAt(uint16_t x, uint16_t y, CRGB pixel);
    
    uint8_t getId();
    const String& getName();
    uint16_t getWidth();
    uint16_t getHeight();
    std::vector<LED_MappedPixel>& getLeds();

    void dumpDebug();
    
private:
    uint8_t id;
    String name;
    uint16_t width;
    uint16_t height;
    std::vector<LED_MappedPixel> leds;
};

#endif
