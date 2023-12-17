
#ifndef LED_GFX_H
#define LED_GFX_H

class LEDPanel;

#include <Adafruit_GFX.h>
#include "LED_Panel.h"

class LED_GFX : public Adafruit_GFX {
public:

    LED_GFX(LED_Panel* panel);
    ~LED_GFX();

    void drawPixel(int16_t x, int16_t y, uint16_t color);

private:
    LED_Panel* panel;
};

inline CRGB fromRgb565(uint16_t color) {
    return CRGB((uint8_t)(color >> 16), (uint8_t)(color >> 8), (uint8_t)color);
}

#define toRgb565(r, g, b) ((uint16_t)(((( r * 249 + 1014 ) >> 11) << 11) | ((( g * 253 + 505 ) >> 10) << 5) | (( b * 249 + 1014 ) >> 11)))

#define CRGBtoRgb565(c) toRgb565(c.r, c.g, c.b)

#endif
