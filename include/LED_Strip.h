
#ifndef LED_STRIP_H
#define LED_STRIP_H

#include <Arduino.h>
#include <FastLED.h>
#include <vector>

#include "LED_Factory.h"

#define INVALID_STRIP_ID ((uint8_t)UINT8_MAX)

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
