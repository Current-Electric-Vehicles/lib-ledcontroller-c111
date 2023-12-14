
#ifndef LED_GFX_H
#define LED_GFX_H

#include <Adafruit_GFX.h>
#include "LEDPanel.h"

class LED_GFX : public Adafruit_GFX {
public:

    LED_GFX(LEDPanel* panel);
    ~LED_GFX();

    void drawPixel(int16_t x, int16_t y, uint16_t color);

    inline CRGB fromRgb565(uint16_t color) {
        return CRGB((uint8_t)(color >> 16), (uint8_t)(color >> 8), (uint8_t)color);
    }

    inline uint16_t toRgb565(CRGB& color) {
        int16_t red     = ((color.red >> 3) << 11) & 0xF800;
        int16_t green   = ((color.green >> 2) << 5) & 0x07E0;
        int16_t blue    = ((color.blue >> 3) << 11) & 0x001F;
        return (red | green | blue);
    }

    inline uint16_t toRgb565(CRGB* color) {
        int16_t red     = ((color->red >> 3) << 11) & 0xF800;
        int16_t green   = ((color->green >> 2) << 5) & 0x07E0;
        int16_t blue    = ((color->blue >> 3) << 11) & 0x001F;
        return (red | green | blue);
    }

    inline uint16_t toRgb565(uint8_t r, uint8_t g, uint8_t b) {
        int16_t red     = ((r >> 3) << 11) & 0xF800;
        int16_t green   = ((g >> 2) << 5) & 0x07E0;
        int16_t blue    = ((b >> 3) << 11) & 0x001F;
        return (red | green | blue);
    }

private:
    LEDPanel* panel;
};


#endif
