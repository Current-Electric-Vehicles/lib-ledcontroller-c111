
#ifndef LED_STRIP_H
#define LED_STRIP_H

#include <Arduino.h>
#include <FastLED.h>
#include <vector>

#define INVALID_STRIP_ID ((uint8_t)UINT8_MAX)

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
    uint16_t offset;
    uint16_t count;
};

class LED_Strip {
public:
    LED_Strip(LED_StripDefinition& def);
    ~LED_Strip();

    LED_StripDefinition& getDefinition();
    uint8_t getId();
    void setId(uint8_t id);

    CRGB* getLeds();
    CRGB* getPixelAt(uint16_t index);

private:
    uint8_t id;
    LED_StripDefinition def;
    CLEDController* controller;
    std::vector<CRGB> leds;
};

#endif
