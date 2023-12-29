
#ifndef LED_STRIP_H
#define LED_STRIP_H

#include <Arduino.h>
#include <FastLED.h>
#include <vector>

#include "LED_Factory.h"

#define INVALID_STRIP_ID ((uint8_t)UINT8_MAX)

struct LED_StripConfig {
    uint8_t id = 0;
    String name;
    PixelType pixelType;
    uint8_t pin;
    EOrder rgbOrder;
    uint16_t count;
};

class LED_Strip {
public:
    LED_Strip(LED_StripConfig* conf);
    ~LED_Strip();

    uint8_t getId();
    const String& getName();
    PixelType getPixelType();
    uint8_t getPin();
    EOrder getRgbOrder();
    uint16_t getCount();
    CRGB* getLeds();
    CRGB* getPixelAt(uint16_t index);
    CLEDController* getController();

private:
    uint8_t id;
    String name;
    PixelType pixelType;
    uint8_t pin;
    EOrder rgbOrder;
    CLEDController* controller;
    std::vector<CRGB> leds;
};

#endif
