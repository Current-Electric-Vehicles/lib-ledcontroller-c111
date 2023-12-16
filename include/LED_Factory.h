
#ifndef LED_FACTORY_H
#define LED_FACTORY_H

#include <Arduino.h>
#include <FastLED.h>

enum PixelType {
    T_NEOPIXEL        = 0,
    T_SM16703         = 1,
    T_TM1829          = 2,
    T_TM1812          = 3,
    T_TM1809          = 4,
    T_TM1804          = 5,
    T_TM1803          = 6,
    T_UCS1903         = 7,
    T_UCS1903B        = 8,
    T_UCS1904         = 9,
    T_UCS2903         = 10,
    T_WS2812          = 11,
    T_WS2852          = 12,
    T_WS2812B         = 13,
    T_GS1903          = 14,
    T_SK6812          = 15,
    T_SK6822          = 16,
    T_APA106          = 17,
    T_PL9823          = 18,
    T_WS2811          = 19,
    T_WS2813          = 20,
    T_APA104          = 21,
    T_WS2811_400      = 22,
    T_GE8822          = 23,
    T_GW6205          = 24,
    T_GW6205_400      = 25,
    T_LPD1886         = 26,
    T_LPD1886_8BIT    = 27
};

struct LED_StripDefinition {
    String name;
    PixelType pixelType;
    uint8_t pin;
    EOrder rgbOrder;
    uint16_t count;
};

CLEDController& createController(LED_StripDefinition* def, CRGB* leds);

#endif
