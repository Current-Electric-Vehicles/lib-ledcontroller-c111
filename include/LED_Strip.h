
#ifndef LED_STRIP_H
#define LED_STRIP_H

#include <Arduino.h>
#include <FastLED.h>
#include <vector>

#include "LED_Factory.h"

class LED_Strip {
public:
    LED_Strip(LED_StripDefinition& def);
    ~LED_Strip();

    LED_StripDefinition& getDefinition();

    void init();
    void deInit();

    CRGB* getLeds();

private:
    LED_StripDefinition def;
    CLEDController* controller;
    std::vector<CRGB> leds;
};

#endif