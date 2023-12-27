
#ifndef LED_FACTORY_H
#define LED_FACTORY_H

#include <FastLED.h>
#include <vector>

enum PixelType {
    T_UNKNOWN         = 0,
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
    T_LPD1886_8BIT    = 27,
    T_NEOPIXEL        = 28,
};

std::vector<uint8_t> getEnabledPins();
std::vector<EOrder> getEnabledRGBOrders();
std::vector<PixelType> getEnabledControllers();

CLEDController* createController(uint8_t pin, EOrder rgbOrder, PixelType pixelType, uint16_t offset, uint16_t count, CRGB* leds);

#endif
