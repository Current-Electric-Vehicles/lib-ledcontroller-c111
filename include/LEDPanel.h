
#ifndef LED_PANEL_H
#define LED_PANEL_H

#include <Arduino.h>
#include <FastLED.h>
#include <vector>

#include "LEDStrip.h"

enum StripDirection {
    TOP_TO_BOTTOM__LEFT_TO_RIGHT,
    TOP_TO_BOTTOM__RIGHT_TO_LEFT,

    BOTTOM_TO_TOP__LEFT_TO_RIGHT,
    BOTTOM_TO_TOP__RIGHT_TO_LEFT,

    LEFT_TO_RIGHT__TOP_TO_BOTTOM,
    LEFT_TO_RIGHT__BOTTOM_TO_TOP,

    RIGHT_TO_LEFT__TOP_TO_BOTTOM,
    RIGHT_TO_LEFT__BOTTOM_TO_TOP
};

class LEDPanel {
public:

    LEDPanel(uint16_t w, uint16_t h);
    ~LEDPanel();

    CRGB* getPixelAt(uint16_t x, uint16_t y);
    void setPixelAt(uint16_t x, uint16_t y, CRGB* pixel);
    void setPixelAt(uint16_t x, uint16_t y, CRGB pixel);
    bool setNonEmptyPixelAt(uint16_t x, uint16_t y, CRGB* pixel);
    bool setNonEmptyPixelAt(uint16_t x, uint16_t y, CRGB pixel);
    
    uint16_t getWidth();
    uint16_t getHeight();

    void init(LEDStrip& strip, StripDirection direction, CRGB* leds);
    void dumpDebug();
    
private:
    uint16_t width;
    uint16_t height;
    std::vector<CRGB*> leds;
    
};

#endif
