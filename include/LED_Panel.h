
#ifndef LED_PANEL_H
#define LED_PANEL_H

#include <Arduino.h>
#include <FastLED.h>
#include <vector>

struct LED_PanelDefinition {
    String name;
    uint16_t width;
    uint16_t height;
};

class LED_Panel {
public:

    LED_Panel(LED_PanelDefinition& def);
    ~LED_Panel();

    LED_PanelDefinition& getDefinition();

    CRGB* getMappedPixelAt(uint16_t x, uint16_t y);
    void mapPixelAt(uint16_t x, uint16_t y, CRGB* pixel);
    
    void setPixelAt(uint16_t x, uint16_t y, CRGB* pixel);
    void setPixelAt(uint16_t x, uint16_t y, CRGB pixel);
    bool setNonEmptyPixelAt(uint16_t x, uint16_t y, CRGB* pixel);
    bool setNonEmptyPixelAt(uint16_t x, uint16_t y, CRGB pixel);
    
    uint16_t getWidth();
    uint16_t getHeight();

    void dumpDebug();
    
private:
    LED_PanelDefinition def;
    std::vector<CRGB*> leds;
    
};

#endif
