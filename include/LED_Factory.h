
#ifndef LED_FACTORY_H
#define LED_FACTORY_H

#include <FastLED.h>
#include "LED_Strip.h"

CLEDController& createController(LED_StripDefinition* def, CRGB* leds);

#endif
