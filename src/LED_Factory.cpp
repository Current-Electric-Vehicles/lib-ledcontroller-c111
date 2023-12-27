
#include "LED_Factory.h"

#include <Arduino.h>

#include "C111_Pinout.h"

CLEDController& createController(LED_StripDefinition* def, CRGB* leds) {

    if (def->pin == C111_ESP_DIFF_1_OR_SINGLE_ENDED_1) {
        if (def->rgbOrder == RGB) {
            #ifdef LED_FACTORY_RGB
            switch (def->pixelType) {
                case T_NEOPIXEL:                return FastLED.addLeds<NEOPIXEL, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1>(leds, def->offset, def->count);
                case T_SM16703:                 return FastLED.addLeds<SM16703, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, RGB>(leds, def->offset, def->count);
                case T_TM1829:                  return FastLED.addLeds<TM1829, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, RGB>(leds, def->offset, def->count);
                case T_TM1812:                  return FastLED.addLeds<TM1812, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, RGB>(leds, def->offset, def->count);
                case T_TM1809:                  return FastLED.addLeds<TM1809, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, RGB>(leds, def->offset, def->count);
                case T_TM1804:                  return FastLED.addLeds<TM1804, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, RGB>(leds, def->offset, def->count);
                case T_TM1803:                  return FastLED.addLeds<TM1803, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, RGB>(leds, def->offset, def->count);
                case T_UCS1903:                 return FastLED.addLeds<UCS1903, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, RGB>(leds, def->offset, def->count);
                case T_UCS1903B:                return FastLED.addLeds<UCS1903B, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, RGB>(leds, def->offset, def->count);
                case T_UCS1904:                 return FastLED.addLeds<UCS1904, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, RGB>(leds, def->offset, def->count);
                case T_UCS2903:                 return FastLED.addLeds<UCS2903, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, RGB>(leds, def->offset, def->count);
                case T_WS2812:                  return FastLED.addLeds<WS2812, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, RGB>(leds, def->offset, def->count);
                case T_WS2852:                  return FastLED.addLeds<WS2852, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, RGB>(leds, def->offset, def->count);
                case T_WS2812B:                 return FastLED.addLeds<WS2812B, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, RGB>(leds, def->offset, def->count);
                case T_GS1903:                  return FastLED.addLeds<GS1903, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, RGB>(leds, def->offset, def->count);
                case T_SK6812:                  return FastLED.addLeds<SK6812, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, RGB>(leds, def->offset, def->count);
                case T_SK6822:                  return FastLED.addLeds<SK6822, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, RGB>(leds, def->offset, def->count);
                case T_APA106:                  return FastLED.addLeds<APA106, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, RGB>(leds, def->offset, def->count);
                case T_PL9823:                  return FastLED.addLeds<PL9823, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, RGB>(leds, def->offset, def->count);
                case T_WS2811:                  return FastLED.addLeds<WS2811, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, RGB>(leds, def->offset, def->count);
                case T_WS2813:                  return FastLED.addLeds<WS2813, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, RGB>(leds, def->offset, def->count);
                case T_APA104:                  return FastLED.addLeds<APA104, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, RGB>(leds, def->offset, def->count);
                case T_WS2811_400:              return FastLED.addLeds<WS2811_400, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, RGB>(leds, def->offset, def->count);
                case T_GE8822:                  return FastLED.addLeds<GE8822, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, RGB>(leds, def->offset, def->count);
                case T_GW6205:                  return FastLED.addLeds<GW6205, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, RGB>(leds, def->offset, def->count);
                case T_GW6205_400:              return FastLED.addLeds<GW6205_400, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, RGB>(leds, def->offset, def->count);
                case T_LPD1886:                 return FastLED.addLeds<LPD1886, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, RGB>(leds, def->offset, def->count);
                default /*T_LPD1886_8BIT*/:     return FastLED.addLeds<LPD1886_8BIT, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, RGB>(leds, def->offset, def->count);
            }
            #else
            Serial.println("LED_FACTORY_RGB NOT DEFINED");
            #endif

        } else if (def->rgbOrder == RBG) {
            #ifdef LED_FACTORY_RBG
            switch (def->pixelType) {
                case T_NEOPIXEL:                return FastLED.addLeds<NEOPIXEL, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1>(leds, def->offset, def->count);
                case T_SM16703:                 return FastLED.addLeds<SM16703, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, RBG>(leds, def->offset, def->count);
                case T_TM1829:                  return FastLED.addLeds<TM1829, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, RBG>(leds, def->offset, def->count);
                case T_TM1812:                  return FastLED.addLeds<TM1812, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, RBG>(leds, def->offset, def->count);
                case T_TM1809:                  return FastLED.addLeds<TM1809, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, RBG>(leds, def->offset, def->count);
                case T_TM1804:                  return FastLED.addLeds<TM1804, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, RBG>(leds, def->offset, def->count);
                case T_TM1803:                  return FastLED.addLeds<TM1803, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, RBG>(leds, def->offset, def->count);
                case T_UCS1903:                 return FastLED.addLeds<UCS1903, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, RBG>(leds, def->offset, def->count);
                case T_UCS1903B:                return FastLED.addLeds<UCS1903B, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, RBG>(leds, def->offset, def->count);
                case T_UCS1904:                 return FastLED.addLeds<UCS1904, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, RBG>(leds, def->offset, def->count);
                case T_UCS2903:                 return FastLED.addLeds<UCS2903, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, RBG>(leds, def->offset, def->count);
                case T_WS2812:                  return FastLED.addLeds<WS2812, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, RBG>(leds, def->offset, def->count);
                case T_WS2852:                  return FastLED.addLeds<WS2852, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, RBG>(leds, def->offset, def->count);
                case T_WS2812B:                 return FastLED.addLeds<WS2812B, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, RBG>(leds, def->offset, def->count);
                case T_GS1903:                  return FastLED.addLeds<GS1903, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, RBG>(leds, def->offset, def->count);
                case T_SK6812:                  return FastLED.addLeds<SK6812, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, RBG>(leds, def->offset, def->count);
                case T_SK6822:                  return FastLED.addLeds<SK6822, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, RBG>(leds, def->offset, def->count);
                case T_APA106:                  return FastLED.addLeds<APA106, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, RBG>(leds, def->offset, def->count);
                case T_PL9823:                  return FastLED.addLeds<PL9823, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, RBG>(leds, def->offset, def->count);
                case T_WS2811:                  return FastLED.addLeds<WS2811, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, RBG>(leds, def->offset, def->count);
                case T_WS2813:                  return FastLED.addLeds<WS2813, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, RBG>(leds, def->offset, def->count);
                case T_APA104:                  return FastLED.addLeds<APA104, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, RBG>(leds, def->offset, def->count);
                case T_WS2811_400:              return FastLED.addLeds<WS2811_400, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, RBG>(leds, def->offset, def->count);
                case T_GE8822:                  return FastLED.addLeds<GE8822, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, RBG>(leds, def->offset, def->count);
                case T_GW6205:                  return FastLED.addLeds<GW6205, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, RBG>(leds, def->offset, def->count);
                case T_GW6205_400:              return FastLED.addLeds<GW6205_400, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, RBG>(leds, def->offset, def->count);
                case T_LPD1886:                 return FastLED.addLeds<LPD1886, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, RBG>(leds, def->offset, def->count);
                default /*T_LPD1886_8BIT*/:     return FastLED.addLeds<LPD1886_8BIT, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, RBG>(leds, def->offset, def->count);
            }
            #else
            Serial.println("LED_FACTORY_RBG NOT DEFINED");
            #endif
            
        } else if (def->rgbOrder == GRB) {
            #ifdef LED_FACTORY_GRB
            switch (def->pixelType) {
                case T_NEOPIXEL:                return FastLED.addLeds<NEOPIXEL, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1>(leds, def->offset, def->count);
                case T_SM16703:                 return FastLED.addLeds<SM16703, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, GRB>(leds, def->offset, def->count);
                case T_TM1829:                  return FastLED.addLeds<TM1829, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, GRB>(leds, def->offset, def->count);
                case T_TM1812:                  return FastLED.addLeds<TM1812, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, GRB>(leds, def->offset, def->count);
                case T_TM1809:                  return FastLED.addLeds<TM1809, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, GRB>(leds, def->offset, def->count);
                case T_TM1804:                  return FastLED.addLeds<TM1804, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, GRB>(leds, def->offset, def->count);
                case T_TM1803:                  return FastLED.addLeds<TM1803, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, GRB>(leds, def->offset, def->count);
                case T_UCS1903:                 return FastLED.addLeds<UCS1903, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, GRB>(leds, def->offset, def->count);
                case T_UCS1903B:                return FastLED.addLeds<UCS1903B, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, GRB>(leds, def->offset, def->count);
                case T_UCS1904:                 return FastLED.addLeds<UCS1904, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, GRB>(leds, def->offset, def->count);
                case T_UCS2903:                 return FastLED.addLeds<UCS2903, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, GRB>(leds, def->offset, def->count);
                case T_WS2812:                  return FastLED.addLeds<WS2812, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, GRB>(leds, def->offset, def->count);
                case T_WS2852:                  return FastLED.addLeds<WS2852, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, GRB>(leds, def->offset, def->count);
                case T_WS2812B:                 return FastLED.addLeds<WS2812B, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, GRB>(leds, def->offset, def->count);
                case T_GS1903:                  return FastLED.addLeds<GS1903, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, GRB>(leds, def->offset, def->count);
                case T_SK6812:                  return FastLED.addLeds<SK6812, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, GRB>(leds, def->offset, def->count);
                case T_SK6822:                  return FastLED.addLeds<SK6822, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, GRB>(leds, def->offset, def->count);
                case T_APA106:                  return FastLED.addLeds<APA106, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, GRB>(leds, def->offset, def->count);
                case T_PL9823:                  return FastLED.addLeds<PL9823, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, GRB>(leds, def->offset, def->count);
                case T_WS2811:                  return FastLED.addLeds<WS2811, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, GRB>(leds, def->offset, def->count);
                case T_WS2813:                  return FastLED.addLeds<WS2813, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, GRB>(leds, def->offset, def->count);
                case T_APA104:                  return FastLED.addLeds<APA104, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, GRB>(leds, def->offset, def->count);
                case T_WS2811_400:              return FastLED.addLeds<WS2811_400, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, GRB>(leds, def->offset, def->count);
                case T_GE8822:                  return FastLED.addLeds<GE8822, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, GRB>(leds, def->offset, def->count);
                case T_GW6205:                  return FastLED.addLeds<GW6205, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, GRB>(leds, def->offset, def->count);
                case T_GW6205_400:              return FastLED.addLeds<GW6205_400, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, GRB>(leds, def->offset, def->count);
                case T_LPD1886:                 return FastLED.addLeds<LPD1886, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, GRB>(leds, def->offset, def->count);
                default /*T_LPD1886_8BIT*/:     return FastLED.addLeds<LPD1886_8BIT, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, GRB>(leds, def->offset, def->count);
            }
            #else
            Serial.println("LED_FACTORY_GRB NOT DEFINED");
            #endif
            
        } else if (def->rgbOrder == GBR) {
            #ifdef LED_FACTORY_GBR
            switch (def->pixelType) {
                case T_NEOPIXEL:                return FastLED.addLeds<NEOPIXEL, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1>(leds, def->offset, def->count);
                case T_SM16703:                 return FastLED.addLeds<SM16703, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, GBR>(leds, def->offset, def->count);
                case T_TM1829:                  return FastLED.addLeds<TM1829, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, GBR>(leds, def->offset, def->count);
                case T_TM1812:                  return FastLED.addLeds<TM1812, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, GBR>(leds, def->offset, def->count);
                case T_TM1809:                  return FastLED.addLeds<TM1809, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, GBR>(leds, def->offset, def->count);
                case T_TM1804:                  return FastLED.addLeds<TM1804, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, GBR>(leds, def->offset, def->count);
                case T_TM1803:                  return FastLED.addLeds<TM1803, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, GBR>(leds, def->offset, def->count);
                case T_UCS1903:                 return FastLED.addLeds<UCS1903, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, GBR>(leds, def->offset, def->count);
                case T_UCS1903B:                return FastLED.addLeds<UCS1903B, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, GBR>(leds, def->offset, def->count);
                case T_UCS1904:                 return FastLED.addLeds<UCS1904, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, GBR>(leds, def->offset, def->count);
                case T_UCS2903:                 return FastLED.addLeds<UCS2903, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, GBR>(leds, def->offset, def->count);
                case T_WS2812:                  return FastLED.addLeds<WS2812, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, GBR>(leds, def->offset, def->count);
                case T_WS2852:                  return FastLED.addLeds<WS2852, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, GBR>(leds, def->offset, def->count);
                case T_WS2812B:                 return FastLED.addLeds<WS2812B, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, GBR>(leds, def->offset, def->count);
                case T_GS1903:                  return FastLED.addLeds<GS1903, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, GBR>(leds, def->offset, def->count);
                case T_SK6812:                  return FastLED.addLeds<SK6812, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, GBR>(leds, def->offset, def->count);
                case T_SK6822:                  return FastLED.addLeds<SK6822, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, GBR>(leds, def->offset, def->count);
                case T_APA106:                  return FastLED.addLeds<APA106, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, GBR>(leds, def->offset, def->count);
                case T_PL9823:                  return FastLED.addLeds<PL9823, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, GBR>(leds, def->offset, def->count);
                case T_WS2811:                  return FastLED.addLeds<WS2811, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, GBR>(leds, def->offset, def->count);
                case T_WS2813:                  return FastLED.addLeds<WS2813, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, GBR>(leds, def->offset, def->count);
                case T_APA104:                  return FastLED.addLeds<APA104, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, GBR>(leds, def->offset, def->count);
                case T_WS2811_400:              return FastLED.addLeds<WS2811_400, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, GBR>(leds, def->offset, def->count);
                case T_GE8822:                  return FastLED.addLeds<GE8822, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, GBR>(leds, def->offset, def->count);
                case T_GW6205:                  return FastLED.addLeds<GW6205, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, GBR>(leds, def->offset, def->count);
                case T_GW6205_400:              return FastLED.addLeds<GW6205_400, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, GBR>(leds, def->offset, def->count);
                case T_LPD1886:                 return FastLED.addLeds<LPD1886, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, GBR>(leds, def->offset, def->count);
                default /*T_LPD1886_8BIT*/:     return FastLED.addLeds<LPD1886_8BIT, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, GBR>(leds, def->offset, def->count);
            }
            #else
            Serial.println("LED_FACTORY_GBR NOT DEFINED");
            #endif
            
        } else if (def->rgbOrder == BRG) {
            #ifdef LED_FACTORY_BRG
            switch (def->pixelType) {
                case T_NEOPIXEL:                return FastLED.addLeds<NEOPIXEL, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1>(leds, def->offset, def->count);
                case T_SM16703:                 return FastLED.addLeds<SM16703, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, BRG>(leds, def->offset, def->count);
                case T_TM1829:                  return FastLED.addLeds<TM1829, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, BRG>(leds, def->offset, def->count);
                case T_TM1812:                  return FastLED.addLeds<TM1812, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, BRG>(leds, def->offset, def->count);
                case T_TM1809:                  return FastLED.addLeds<TM1809, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, BRG>(leds, def->offset, def->count);
                case T_TM1804:                  return FastLED.addLeds<TM1804, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, BRG>(leds, def->offset, def->count);
                case T_TM1803:                  return FastLED.addLeds<TM1803, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, BRG>(leds, def->offset, def->count);
                case T_UCS1903:                 return FastLED.addLeds<UCS1903, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, BRG>(leds, def->offset, def->count);
                case T_UCS1903B:                return FastLED.addLeds<UCS1903B, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, BRG>(leds, def->offset, def->count);
                case T_UCS1904:                 return FastLED.addLeds<UCS1904, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, BRG>(leds, def->offset, def->count);
                case T_UCS2903:                 return FastLED.addLeds<UCS2903, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, BRG>(leds, def->offset, def->count);
                case T_WS2812:                  return FastLED.addLeds<WS2812, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, BRG>(leds, def->offset, def->count);
                case T_WS2852:                  return FastLED.addLeds<WS2852, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, BRG>(leds, def->offset, def->count);
                case T_WS2812B:                 return FastLED.addLeds<WS2812B, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, BRG>(leds, def->offset, def->count);
                case T_GS1903:                  return FastLED.addLeds<GS1903, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, BRG>(leds, def->offset, def->count);
                case T_SK6812:                  return FastLED.addLeds<SK6812, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, BRG>(leds, def->offset, def->count);
                case T_SK6822:                  return FastLED.addLeds<SK6822, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, BRG>(leds, def->offset, def->count);
                case T_APA106:                  return FastLED.addLeds<APA106, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, BRG>(leds, def->offset, def->count);
                case T_PL9823:                  return FastLED.addLeds<PL9823, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, BRG>(leds, def->offset, def->count);
                case T_WS2811:                  return FastLED.addLeds<WS2811, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, BRG>(leds, def->offset, def->count);
                case T_WS2813:                  return FastLED.addLeds<WS2813, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, BRG>(leds, def->offset, def->count);
                case T_APA104:                  return FastLED.addLeds<APA104, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, BRG>(leds, def->offset, def->count);
                case T_WS2811_400:              return FastLED.addLeds<WS2811_400, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, BRG>(leds, def->offset, def->count);
                case T_GE8822:                  return FastLED.addLeds<GE8822, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, BRG>(leds, def->offset, def->count);
                case T_GW6205:                  return FastLED.addLeds<GW6205, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, BRG>(leds, def->offset, def->count);
                case T_GW6205_400:              return FastLED.addLeds<GW6205_400, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, BRG>(leds, def->offset, def->count);
                case T_LPD1886:                 return FastLED.addLeds<LPD1886, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, BRG>(leds, def->offset, def->count);
                default /*T_LPD1886_8BIT*/:     return FastLED.addLeds<LPD1886_8BIT, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, BRG>(leds, def->offset, def->count);
            }
            #else
            Serial.println("LED_FACTORY_BRG NOT DEFINED");
            #endif
            
        } else if (def->rgbOrder == BGR) {
            #ifdef LED_FACTORY_BGR
            switch (def->pixelType) {
                case T_NEOPIXEL:                return FastLED.addLeds<NEOPIXEL, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1>(leds, def->offset, def->count);
                case T_SM16703:                 return FastLED.addLeds<SM16703, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, BGR>(leds, def->offset, def->count);
                case T_TM1829:                  return FastLED.addLeds<TM1829, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, BGR>(leds, def->offset, def->count);
                case T_TM1812:                  return FastLED.addLeds<TM1812, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, BGR>(leds, def->offset, def->count);
                case T_TM1809:                  return FastLED.addLeds<TM1809, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, BGR>(leds, def->offset, def->count);
                case T_TM1804:                  return FastLED.addLeds<TM1804, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, BGR>(leds, def->offset, def->count);
                case T_TM1803:                  return FastLED.addLeds<TM1803, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, BGR>(leds, def->offset, def->count);
                case T_UCS1903:                 return FastLED.addLeds<UCS1903, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, BGR>(leds, def->offset, def->count);
                case T_UCS1903B:                return FastLED.addLeds<UCS1903B, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, BGR>(leds, def->offset, def->count);
                case T_UCS1904:                 return FastLED.addLeds<UCS1904, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, BGR>(leds, def->offset, def->count);
                case T_UCS2903:                 return FastLED.addLeds<UCS2903, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, BGR>(leds, def->offset, def->count);
                case T_WS2812:                  return FastLED.addLeds<WS2812, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, BGR>(leds, def->offset, def->count);
                case T_WS2852:                  return FastLED.addLeds<WS2852, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, BGR>(leds, def->offset, def->count);
                case T_WS2812B:                 return FastLED.addLeds<WS2812B, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, BGR>(leds, def->offset, def->count);
                case T_GS1903:                  return FastLED.addLeds<GS1903, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, BGR>(leds, def->offset, def->count);
                case T_SK6812:                  return FastLED.addLeds<SK6812, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, BGR>(leds, def->offset, def->count);
                case T_SK6822:                  return FastLED.addLeds<SK6822, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, BGR>(leds, def->offset, def->count);
                case T_APA106:                  return FastLED.addLeds<APA106, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, BGR>(leds, def->offset, def->count);
                case T_PL9823:                  return FastLED.addLeds<PL9823, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, BGR>(leds, def->offset, def->count);
                case T_WS2811:                  return FastLED.addLeds<WS2811, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, BGR>(leds, def->offset, def->count);
                case T_WS2813:                  return FastLED.addLeds<WS2813, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, BGR>(leds, def->offset, def->count);
                case T_APA104:                  return FastLED.addLeds<APA104, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, BGR>(leds, def->offset, def->count);
                case T_WS2811_400:              return FastLED.addLeds<WS2811_400, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, BGR>(leds, def->offset, def->count);
                case T_GE8822:                  return FastLED.addLeds<GE8822, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, BGR>(leds, def->offset, def->count);
                case T_GW6205:                  return FastLED.addLeds<GW6205, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, BGR>(leds, def->offset, def->count);
                case T_GW6205_400:              return FastLED.addLeds<GW6205_400, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, BGR>(leds, def->offset, def->count);
                case T_LPD1886:                 return FastLED.addLeds<LPD1886, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, BGR>(leds, def->offset, def->count);
                default /*T_LPD1886_8BIT*/:     return FastLED.addLeds<LPD1886_8BIT, C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, BGR>(leds, def->offset, def->count);
            }
            #else
            Serial.println("LED_FACTORY_BGR NOT DEFINED");
            #endif
            
        }

    }

    if (def->pin == C111_ESP_DIFF_2_OR_SINGLE_ENDED_2) {
        if (def->rgbOrder == RGB) {
            #ifdef LED_FACTORY_RGB
            switch (def->pixelType) {
                case T_NEOPIXEL:                return FastLED.addLeds<NEOPIXEL, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2>(leds, def->offset, def->count);
                case T_SM16703:                 return FastLED.addLeds<SM16703, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, RGB>(leds, def->offset, def->count);
                case T_TM1829:                  return FastLED.addLeds<TM1829, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, RGB>(leds, def->offset, def->count);
                case T_TM1812:                  return FastLED.addLeds<TM1812, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, RGB>(leds, def->offset, def->count);
                case T_TM1809:                  return FastLED.addLeds<TM1809, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, RGB>(leds, def->offset, def->count);
                case T_TM1804:                  return FastLED.addLeds<TM1804, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, RGB>(leds, def->offset, def->count);
                case T_TM1803:                  return FastLED.addLeds<TM1803, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, RGB>(leds, def->offset, def->count);
                case T_UCS1903:                 return FastLED.addLeds<UCS1903, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, RGB>(leds, def->offset, def->count);
                case T_UCS1903B:                return FastLED.addLeds<UCS1903B, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, RGB>(leds, def->offset, def->count);
                case T_UCS1904:                 return FastLED.addLeds<UCS1904, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, RGB>(leds, def->offset, def->count);
                case T_UCS2903:                 return FastLED.addLeds<UCS2903, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, RGB>(leds, def->offset, def->count);
                case T_WS2812:                  return FastLED.addLeds<WS2812, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, RGB>(leds, def->offset, def->count);
                case T_WS2852:                  return FastLED.addLeds<WS2852, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, RGB>(leds, def->offset, def->count);
                case T_WS2812B:                 return FastLED.addLeds<WS2812B, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, RGB>(leds, def->offset, def->count);
                case T_GS1903:                  return FastLED.addLeds<GS1903, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, RGB>(leds, def->offset, def->count);
                case T_SK6812:                  return FastLED.addLeds<SK6812, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, RGB>(leds, def->offset, def->count);
                case T_SK6822:                  return FastLED.addLeds<SK6822, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, RGB>(leds, def->offset, def->count);
                case T_APA106:                  return FastLED.addLeds<APA106, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, RGB>(leds, def->offset, def->count);
                case T_PL9823:                  return FastLED.addLeds<PL9823, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, RGB>(leds, def->offset, def->count);
                case T_WS2811:                  return FastLED.addLeds<WS2811, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, RGB>(leds, def->offset, def->count);
                case T_WS2813:                  return FastLED.addLeds<WS2813, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, RGB>(leds, def->offset, def->count);
                case T_APA104:                  return FastLED.addLeds<APA104, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, RGB>(leds, def->offset, def->count);
                case T_WS2811_400:              return FastLED.addLeds<WS2811_400, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, RGB>(leds, def->offset, def->count);
                case T_GE8822:                  return FastLED.addLeds<GE8822, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, RGB>(leds, def->offset, def->count);
                case T_GW6205:                  return FastLED.addLeds<GW6205, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, RGB>(leds, def->offset, def->count);
                case T_GW6205_400:              return FastLED.addLeds<GW6205_400, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, RGB>(leds, def->offset, def->count);
                case T_LPD1886:                 return FastLED.addLeds<LPD1886, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, RGB>(leds, def->offset, def->count);
                default /*T_LPD1886_8BIT*/:     return FastLED.addLeds<LPD1886_8BIT, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, RGB>(leds, def->offset, def->count);
            }
            #else
            Serial.println("LED_FACTORY_RGB NOT DEFINED");
            #endif

        } else if (def->rgbOrder == RBG) {
            #ifdef LED_FACTORY_RBG
            switch (def->pixelType) {
                case T_NEOPIXEL:                return FastLED.addLeds<NEOPIXEL, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2>(leds, def->offset, def->count);
                case T_SM16703:                 return FastLED.addLeds<SM16703, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, RBG>(leds, def->offset, def->count);
                case T_TM1829:                  return FastLED.addLeds<TM1829, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, RBG>(leds, def->offset, def->count);
                case T_TM1812:                  return FastLED.addLeds<TM1812, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, RBG>(leds, def->offset, def->count);
                case T_TM1809:                  return FastLED.addLeds<TM1809, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, RBG>(leds, def->offset, def->count);
                case T_TM1804:                  return FastLED.addLeds<TM1804, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, RBG>(leds, def->offset, def->count);
                case T_TM1803:                  return FastLED.addLeds<TM1803, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, RBG>(leds, def->offset, def->count);
                case T_UCS1903:                 return FastLED.addLeds<UCS1903, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, RBG>(leds, def->offset, def->count);
                case T_UCS1903B:                return FastLED.addLeds<UCS1903B, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, RBG>(leds, def->offset, def->count);
                case T_UCS1904:                 return FastLED.addLeds<UCS1904, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, RBG>(leds, def->offset, def->count);
                case T_UCS2903:                 return FastLED.addLeds<UCS2903, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, RBG>(leds, def->offset, def->count);
                case T_WS2812:                  return FastLED.addLeds<WS2812, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, RBG>(leds, def->offset, def->count);
                case T_WS2852:                  return FastLED.addLeds<WS2852, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, RBG>(leds, def->offset, def->count);
                case T_WS2812B:                 return FastLED.addLeds<WS2812B, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, RBG>(leds, def->offset, def->count);
                case T_GS1903:                  return FastLED.addLeds<GS1903, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, RBG>(leds, def->offset, def->count);
                case T_SK6812:                  return FastLED.addLeds<SK6812, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, RBG>(leds, def->offset, def->count);
                case T_SK6822:                  return FastLED.addLeds<SK6822, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, RBG>(leds, def->offset, def->count);
                case T_APA106:                  return FastLED.addLeds<APA106, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, RBG>(leds, def->offset, def->count);
                case T_PL9823:                  return FastLED.addLeds<PL9823, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, RBG>(leds, def->offset, def->count);
                case T_WS2811:                  return FastLED.addLeds<WS2811, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, RBG>(leds, def->offset, def->count);
                case T_WS2813:                  return FastLED.addLeds<WS2813, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, RBG>(leds, def->offset, def->count);
                case T_APA104:                  return FastLED.addLeds<APA104, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, RBG>(leds, def->offset, def->count);
                case T_WS2811_400:              return FastLED.addLeds<WS2811_400, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, RBG>(leds, def->offset, def->count);
                case T_GE8822:                  return FastLED.addLeds<GE8822, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, RBG>(leds, def->offset, def->count);
                case T_GW6205:                  return FastLED.addLeds<GW6205, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, RBG>(leds, def->offset, def->count);
                case T_GW6205_400:              return FastLED.addLeds<GW6205_400, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, RBG>(leds, def->offset, def->count);
                case T_LPD1886:                 return FastLED.addLeds<LPD1886, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, RBG>(leds, def->offset, def->count);
                default /*T_LPD1886_8BIT*/:     return FastLED.addLeds<LPD1886_8BIT, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, RBG>(leds, def->offset, def->count);
            }
            #else
            Serial.println("LED_FACTORY_RBG NOT DEFINED");
            #endif
            
        } else if (def->rgbOrder == GRB) {
            #ifdef LED_FACTORY_GRB
            switch (def->pixelType) {
                case T_NEOPIXEL:                return FastLED.addLeds<NEOPIXEL, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2>(leds, def->offset, def->count);
                case T_SM16703:                 return FastLED.addLeds<SM16703, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, GRB>(leds, def->offset, def->count);
                case T_TM1829:                  return FastLED.addLeds<TM1829, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, GRB>(leds, def->offset, def->count);
                case T_TM1812:                  return FastLED.addLeds<TM1812, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, GRB>(leds, def->offset, def->count);
                case T_TM1809:                  return FastLED.addLeds<TM1809, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, GRB>(leds, def->offset, def->count);
                case T_TM1804:                  return FastLED.addLeds<TM1804, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, GRB>(leds, def->offset, def->count);
                case T_TM1803:                  return FastLED.addLeds<TM1803, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, GRB>(leds, def->offset, def->count);
                case T_UCS1903:                 return FastLED.addLeds<UCS1903, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, GRB>(leds, def->offset, def->count);
                case T_UCS1903B:                return FastLED.addLeds<UCS1903B, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, GRB>(leds, def->offset, def->count);
                case T_UCS1904:                 return FastLED.addLeds<UCS1904, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, GRB>(leds, def->offset, def->count);
                case T_UCS2903:                 return FastLED.addLeds<UCS2903, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, GRB>(leds, def->offset, def->count);
                case T_WS2812:                  return FastLED.addLeds<WS2812, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, GRB>(leds, def->offset, def->count);
                case T_WS2852:                  return FastLED.addLeds<WS2852, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, GRB>(leds, def->offset, def->count);
                case T_WS2812B:                 return FastLED.addLeds<WS2812B, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, GRB>(leds, def->offset, def->count);
                case T_GS1903:                  return FastLED.addLeds<GS1903, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, GRB>(leds, def->offset, def->count);
                case T_SK6812:                  return FastLED.addLeds<SK6812, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, GRB>(leds, def->offset, def->count);
                case T_SK6822:                  return FastLED.addLeds<SK6822, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, GRB>(leds, def->offset, def->count);
                case T_APA106:                  return FastLED.addLeds<APA106, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, GRB>(leds, def->offset, def->count);
                case T_PL9823:                  return FastLED.addLeds<PL9823, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, GRB>(leds, def->offset, def->count);
                case T_WS2811:                  return FastLED.addLeds<WS2811, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, GRB>(leds, def->offset, def->count);
                case T_WS2813:                  return FastLED.addLeds<WS2813, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, GRB>(leds, def->offset, def->count);
                case T_APA104:                  return FastLED.addLeds<APA104, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, GRB>(leds, def->offset, def->count);
                case T_WS2811_400:              return FastLED.addLeds<WS2811_400, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, GRB>(leds, def->offset, def->count);
                case T_GE8822:                  return FastLED.addLeds<GE8822, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, GRB>(leds, def->offset, def->count);
                case T_GW6205:                  return FastLED.addLeds<GW6205, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, GRB>(leds, def->offset, def->count);
                case T_GW6205_400:              return FastLED.addLeds<GW6205_400, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, GRB>(leds, def->offset, def->count);
                case T_LPD1886:                 return FastLED.addLeds<LPD1886, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, GRB>(leds, def->offset, def->count);
                default /*T_LPD1886_8BIT*/:     return FastLED.addLeds<LPD1886_8BIT, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, GRB>(leds, def->offset, def->count);
            }
            #else
            Serial.println("LED_FACTORY_GRB NOT DEFINED");
            #endif
            
        } else if (def->rgbOrder == GBR) {
            #ifdef LED_FACTORY_GBR
            switch (def->pixelType) {
                case T_NEOPIXEL:                return FastLED.addLeds<NEOPIXEL, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2>(leds, def->offset, def->count);
                case T_SM16703:                 return FastLED.addLeds<SM16703, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, GBR>(leds, def->offset, def->count);
                case T_TM1829:                  return FastLED.addLeds<TM1829, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, GBR>(leds, def->offset, def->count);
                case T_TM1812:                  return FastLED.addLeds<TM1812, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, GBR>(leds, def->offset, def->count);
                case T_TM1809:                  return FastLED.addLeds<TM1809, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, GBR>(leds, def->offset, def->count);
                case T_TM1804:                  return FastLED.addLeds<TM1804, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, GBR>(leds, def->offset, def->count);
                case T_TM1803:                  return FastLED.addLeds<TM1803, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, GBR>(leds, def->offset, def->count);
                case T_UCS1903:                 return FastLED.addLeds<UCS1903, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, GBR>(leds, def->offset, def->count);
                case T_UCS1903B:                return FastLED.addLeds<UCS1903B, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, GBR>(leds, def->offset, def->count);
                case T_UCS1904:                 return FastLED.addLeds<UCS1904, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, GBR>(leds, def->offset, def->count);
                case T_UCS2903:                 return FastLED.addLeds<UCS2903, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, GBR>(leds, def->offset, def->count);
                case T_WS2812:                  return FastLED.addLeds<WS2812, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, GBR>(leds, def->offset, def->count);
                case T_WS2852:                  return FastLED.addLeds<WS2852, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, GBR>(leds, def->offset, def->count);
                case T_WS2812B:                 return FastLED.addLeds<WS2812B, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, GBR>(leds, def->offset, def->count);
                case T_GS1903:                  return FastLED.addLeds<GS1903, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, GBR>(leds, def->offset, def->count);
                case T_SK6812:                  return FastLED.addLeds<SK6812, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, GBR>(leds, def->offset, def->count);
                case T_SK6822:                  return FastLED.addLeds<SK6822, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, GBR>(leds, def->offset, def->count);
                case T_APA106:                  return FastLED.addLeds<APA106, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, GBR>(leds, def->offset, def->count);
                case T_PL9823:                  return FastLED.addLeds<PL9823, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, GBR>(leds, def->offset, def->count);
                case T_WS2811:                  return FastLED.addLeds<WS2811, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, GBR>(leds, def->offset, def->count);
                case T_WS2813:                  return FastLED.addLeds<WS2813, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, GBR>(leds, def->offset, def->count);
                case T_APA104:                  return FastLED.addLeds<APA104, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, GBR>(leds, def->offset, def->count);
                case T_WS2811_400:              return FastLED.addLeds<WS2811_400, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, GBR>(leds, def->offset, def->count);
                case T_GE8822:                  return FastLED.addLeds<GE8822, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, GBR>(leds, def->offset, def->count);
                case T_GW6205:                  return FastLED.addLeds<GW6205, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, GBR>(leds, def->offset, def->count);
                case T_GW6205_400:              return FastLED.addLeds<GW6205_400, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, GBR>(leds, def->offset, def->count);
                case T_LPD1886:                 return FastLED.addLeds<LPD1886, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, GBR>(leds, def->offset, def->count);
                default /*T_LPD1886_8BIT*/:     return FastLED.addLeds<LPD1886_8BIT, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, GBR>(leds, def->offset, def->count);
            }
            #else
            Serial.println("LED_FACTORY_GBR NOT DEFINED");
            #endif
            
        } else if (def->rgbOrder == BRG) {
            #ifdef LED_FACTORY_BRG
            switch (def->pixelType) {
                case T_NEOPIXEL:                return FastLED.addLeds<NEOPIXEL, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2>(leds, def->offset, def->count);
                case T_SM16703:                 return FastLED.addLeds<SM16703, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, BRG>(leds, def->offset, def->count);
                case T_TM1829:                  return FastLED.addLeds<TM1829, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, BRG>(leds, def->offset, def->count);
                case T_TM1812:                  return FastLED.addLeds<TM1812, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, BRG>(leds, def->offset, def->count);
                case T_TM1809:                  return FastLED.addLeds<TM1809, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, BRG>(leds, def->offset, def->count);
                case T_TM1804:                  return FastLED.addLeds<TM1804, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, BRG>(leds, def->offset, def->count);
                case T_TM1803:                  return FastLED.addLeds<TM1803, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, BRG>(leds, def->offset, def->count);
                case T_UCS1903:                 return FastLED.addLeds<UCS1903, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, BRG>(leds, def->offset, def->count);
                case T_UCS1903B:                return FastLED.addLeds<UCS1903B, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, BRG>(leds, def->offset, def->count);
                case T_UCS1904:                 return FastLED.addLeds<UCS1904, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, BRG>(leds, def->offset, def->count);
                case T_UCS2903:                 return FastLED.addLeds<UCS2903, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, BRG>(leds, def->offset, def->count);
                case T_WS2812:                  return FastLED.addLeds<WS2812, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, BRG>(leds, def->offset, def->count);
                case T_WS2852:                  return FastLED.addLeds<WS2852, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, BRG>(leds, def->offset, def->count);
                case T_WS2812B:                 return FastLED.addLeds<WS2812B, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, BRG>(leds, def->offset, def->count);
                case T_GS1903:                  return FastLED.addLeds<GS1903, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, BRG>(leds, def->offset, def->count);
                case T_SK6812:                  return FastLED.addLeds<SK6812, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, BRG>(leds, def->offset, def->count);
                case T_SK6822:                  return FastLED.addLeds<SK6822, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, BRG>(leds, def->offset, def->count);
                case T_APA106:                  return FastLED.addLeds<APA106, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, BRG>(leds, def->offset, def->count);
                case T_PL9823:                  return FastLED.addLeds<PL9823, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, BRG>(leds, def->offset, def->count);
                case T_WS2811:                  return FastLED.addLeds<WS2811, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, BRG>(leds, def->offset, def->count);
                case T_WS2813:                  return FastLED.addLeds<WS2813, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, BRG>(leds, def->offset, def->count);
                case T_APA104:                  return FastLED.addLeds<APA104, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, BRG>(leds, def->offset, def->count);
                case T_WS2811_400:              return FastLED.addLeds<WS2811_400, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, BRG>(leds, def->offset, def->count);
                case T_GE8822:                  return FastLED.addLeds<GE8822, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, BRG>(leds, def->offset, def->count);
                case T_GW6205:                  return FastLED.addLeds<GW6205, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, BRG>(leds, def->offset, def->count);
                case T_GW6205_400:              return FastLED.addLeds<GW6205_400, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, BRG>(leds, def->offset, def->count);
                case T_LPD1886:                 return FastLED.addLeds<LPD1886, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, BRG>(leds, def->offset, def->count);
                default /*T_LPD1886_8BIT*/:     return FastLED.addLeds<LPD1886_8BIT, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, BRG>(leds, def->offset, def->count);
            }
            #else
            Serial.println("LED_FACTORY_BRG NOT DEFINED");
            #endif
            
        } else if (def->rgbOrder == BGR) {
            #ifdef LED_FACTORY_BGR
            switch (def->pixelType) {
                case T_NEOPIXEL:                return FastLED.addLeds<NEOPIXEL, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2>(leds, def->offset, def->count);
                case T_SM16703:                 return FastLED.addLeds<SM16703, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, BGR>(leds, def->offset, def->count);
                case T_TM1829:                  return FastLED.addLeds<TM1829, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, BGR>(leds, def->offset, def->count);
                case T_TM1812:                  return FastLED.addLeds<TM1812, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, BGR>(leds, def->offset, def->count);
                case T_TM1809:                  return FastLED.addLeds<TM1809, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, BGR>(leds, def->offset, def->count);
                case T_TM1804:                  return FastLED.addLeds<TM1804, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, BGR>(leds, def->offset, def->count);
                case T_TM1803:                  return FastLED.addLeds<TM1803, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, BGR>(leds, def->offset, def->count);
                case T_UCS1903:                 return FastLED.addLeds<UCS1903, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, BGR>(leds, def->offset, def->count);
                case T_UCS1903B:                return FastLED.addLeds<UCS1903B, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, BGR>(leds, def->offset, def->count);
                case T_UCS1904:                 return FastLED.addLeds<UCS1904, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, BGR>(leds, def->offset, def->count);
                case T_UCS2903:                 return FastLED.addLeds<UCS2903, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, BGR>(leds, def->offset, def->count);
                case T_WS2812:                  return FastLED.addLeds<WS2812, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, BGR>(leds, def->offset, def->count);
                case T_WS2852:                  return FastLED.addLeds<WS2852, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, BGR>(leds, def->offset, def->count);
                case T_WS2812B:                 return FastLED.addLeds<WS2812B, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, BGR>(leds, def->offset, def->count);
                case T_GS1903:                  return FastLED.addLeds<GS1903, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, BGR>(leds, def->offset, def->count);
                case T_SK6812:                  return FastLED.addLeds<SK6812, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, BGR>(leds, def->offset, def->count);
                case T_SK6822:                  return FastLED.addLeds<SK6822, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, BGR>(leds, def->offset, def->count);
                case T_APA106:                  return FastLED.addLeds<APA106, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, BGR>(leds, def->offset, def->count);
                case T_PL9823:                  return FastLED.addLeds<PL9823, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, BGR>(leds, def->offset, def->count);
                case T_WS2811:                  return FastLED.addLeds<WS2811, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, BGR>(leds, def->offset, def->count);
                case T_WS2813:                  return FastLED.addLeds<WS2813, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, BGR>(leds, def->offset, def->count);
                case T_APA104:                  return FastLED.addLeds<APA104, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, BGR>(leds, def->offset, def->count);
                case T_WS2811_400:              return FastLED.addLeds<WS2811_400, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, BGR>(leds, def->offset, def->count);
                case T_GE8822:                  return FastLED.addLeds<GE8822, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, BGR>(leds, def->offset, def->count);
                case T_GW6205:                  return FastLED.addLeds<GW6205, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, BGR>(leds, def->offset, def->count);
                case T_GW6205_400:              return FastLED.addLeds<GW6205_400, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, BGR>(leds, def->offset, def->count);
                case T_LPD1886:                 return FastLED.addLeds<LPD1886, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, BGR>(leds, def->offset, def->count);
                default /*T_LPD1886_8BIT*/:     return FastLED.addLeds<LPD1886_8BIT, C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, BGR>(leds, def->offset, def->count);
            }
            #else
            Serial.println("LED_FACTORY_BGR NOT DEFINED");
            #endif
            
        }

    }

    if (def->pin == C111_ESP_SINGLE_ENDED_3) {
        if (def->rgbOrder == RGB) {
            #ifdef LED_FACTORY_RGB
            switch (def->pixelType) {
                case T_NEOPIXEL:                return FastLED.addLeds<NEOPIXEL, C111_ESP_SINGLE_ENDED_3>(leds, def->offset, def->count);
                case T_SM16703:                 return FastLED.addLeds<SM16703, C111_ESP_SINGLE_ENDED_3, RGB>(leds, def->offset, def->count);
                case T_TM1829:                  return FastLED.addLeds<TM1829, C111_ESP_SINGLE_ENDED_3, RGB>(leds, def->offset, def->count);
                case T_TM1812:                  return FastLED.addLeds<TM1812, C111_ESP_SINGLE_ENDED_3, RGB>(leds, def->offset, def->count);
                case T_TM1809:                  return FastLED.addLeds<TM1809, C111_ESP_SINGLE_ENDED_3, RGB>(leds, def->offset, def->count);
                case T_TM1804:                  return FastLED.addLeds<TM1804, C111_ESP_SINGLE_ENDED_3, RGB>(leds, def->offset, def->count);
                case T_TM1803:                  return FastLED.addLeds<TM1803, C111_ESP_SINGLE_ENDED_3, RGB>(leds, def->offset, def->count);
                case T_UCS1903:                 return FastLED.addLeds<UCS1903, C111_ESP_SINGLE_ENDED_3, RGB>(leds, def->offset, def->count);
                case T_UCS1903B:                return FastLED.addLeds<UCS1903B, C111_ESP_SINGLE_ENDED_3, RGB>(leds, def->offset, def->count);
                case T_UCS1904:                 return FastLED.addLeds<UCS1904, C111_ESP_SINGLE_ENDED_3, RGB>(leds, def->offset, def->count);
                case T_UCS2903:                 return FastLED.addLeds<UCS2903, C111_ESP_SINGLE_ENDED_3, RGB>(leds, def->offset, def->count);
                case T_WS2812:                  return FastLED.addLeds<WS2812, C111_ESP_SINGLE_ENDED_3, RGB>(leds, def->offset, def->count);
                case T_WS2852:                  return FastLED.addLeds<WS2852, C111_ESP_SINGLE_ENDED_3, RGB>(leds, def->offset, def->count);
                case T_WS2812B:                 return FastLED.addLeds<WS2812B, C111_ESP_SINGLE_ENDED_3, RGB>(leds, def->offset, def->count);
                case T_GS1903:                  return FastLED.addLeds<GS1903, C111_ESP_SINGLE_ENDED_3, RGB>(leds, def->offset, def->count);
                case T_SK6812:                  return FastLED.addLeds<SK6812, C111_ESP_SINGLE_ENDED_3, RGB>(leds, def->offset, def->count);
                case T_SK6822:                  return FastLED.addLeds<SK6822, C111_ESP_SINGLE_ENDED_3, RGB>(leds, def->offset, def->count);
                case T_APA106:                  return FastLED.addLeds<APA106, C111_ESP_SINGLE_ENDED_3, RGB>(leds, def->offset, def->count);
                case T_PL9823:                  return FastLED.addLeds<PL9823, C111_ESP_SINGLE_ENDED_3, RGB>(leds, def->offset, def->count);
                case T_WS2811:                  return FastLED.addLeds<WS2811, C111_ESP_SINGLE_ENDED_3, RGB>(leds, def->offset, def->count);
                case T_WS2813:                  return FastLED.addLeds<WS2813, C111_ESP_SINGLE_ENDED_3, RGB>(leds, def->offset, def->count);
                case T_APA104:                  return FastLED.addLeds<APA104, C111_ESP_SINGLE_ENDED_3, RGB>(leds, def->offset, def->count);
                case T_WS2811_400:              return FastLED.addLeds<WS2811_400, C111_ESP_SINGLE_ENDED_3, RGB>(leds, def->offset, def->count);
                case T_GE8822:                  return FastLED.addLeds<GE8822, C111_ESP_SINGLE_ENDED_3, RGB>(leds, def->offset, def->count);
                case T_GW6205:                  return FastLED.addLeds<GW6205, C111_ESP_SINGLE_ENDED_3, RGB>(leds, def->offset, def->count);
                case T_GW6205_400:              return FastLED.addLeds<GW6205_400, C111_ESP_SINGLE_ENDED_3, RGB>(leds, def->offset, def->count);
                case T_LPD1886:                 return FastLED.addLeds<LPD1886, C111_ESP_SINGLE_ENDED_3, RGB>(leds, def->offset, def->count);
                default /*T_LPD1886_8BIT*/:     return FastLED.addLeds<LPD1886_8BIT, C111_ESP_SINGLE_ENDED_3, RGB>(leds, def->offset, def->count);
            }
            #else
            Serial.println("LED_FACTORY_RGB NOT DEFINED");
            #endif

        } else if (def->rgbOrder == RBG) {
            #ifdef LED_FACTORY_RBG
            switch (def->pixelType) {
                case T_NEOPIXEL:                return FastLED.addLeds<NEOPIXEL, C111_ESP_SINGLE_ENDED_3>(leds, def->offset, def->count);
                case T_SM16703:                 return FastLED.addLeds<SM16703, C111_ESP_SINGLE_ENDED_3, RBG>(leds, def->offset, def->count);
                case T_TM1829:                  return FastLED.addLeds<TM1829, C111_ESP_SINGLE_ENDED_3, RBG>(leds, def->offset, def->count);
                case T_TM1812:                  return FastLED.addLeds<TM1812, C111_ESP_SINGLE_ENDED_3, RBG>(leds, def->offset, def->count);
                case T_TM1809:                  return FastLED.addLeds<TM1809, C111_ESP_SINGLE_ENDED_3, RBG>(leds, def->offset, def->count);
                case T_TM1804:                  return FastLED.addLeds<TM1804, C111_ESP_SINGLE_ENDED_3, RBG>(leds, def->offset, def->count);
                case T_TM1803:                  return FastLED.addLeds<TM1803, C111_ESP_SINGLE_ENDED_3, RBG>(leds, def->offset, def->count);
                case T_UCS1903:                 return FastLED.addLeds<UCS1903, C111_ESP_SINGLE_ENDED_3, RBG>(leds, def->offset, def->count);
                case T_UCS1903B:                return FastLED.addLeds<UCS1903B, C111_ESP_SINGLE_ENDED_3, RBG>(leds, def->offset, def->count);
                case T_UCS1904:                 return FastLED.addLeds<UCS1904, C111_ESP_SINGLE_ENDED_3, RBG>(leds, def->offset, def->count);
                case T_UCS2903:                 return FastLED.addLeds<UCS2903, C111_ESP_SINGLE_ENDED_3, RBG>(leds, def->offset, def->count);
                case T_WS2812:                  return FastLED.addLeds<WS2812, C111_ESP_SINGLE_ENDED_3, RBG>(leds, def->offset, def->count);
                case T_WS2852:                  return FastLED.addLeds<WS2852, C111_ESP_SINGLE_ENDED_3, RBG>(leds, def->offset, def->count);
                case T_WS2812B:                 return FastLED.addLeds<WS2812B, C111_ESP_SINGLE_ENDED_3, RBG>(leds, def->offset, def->count);
                case T_GS1903:                  return FastLED.addLeds<GS1903, C111_ESP_SINGLE_ENDED_3, RBG>(leds, def->offset, def->count);
                case T_SK6812:                  return FastLED.addLeds<SK6812, C111_ESP_SINGLE_ENDED_3, RBG>(leds, def->offset, def->count);
                case T_SK6822:                  return FastLED.addLeds<SK6822, C111_ESP_SINGLE_ENDED_3, RBG>(leds, def->offset, def->count);
                case T_APA106:                  return FastLED.addLeds<APA106, C111_ESP_SINGLE_ENDED_3, RBG>(leds, def->offset, def->count);
                case T_PL9823:                  return FastLED.addLeds<PL9823, C111_ESP_SINGLE_ENDED_3, RBG>(leds, def->offset, def->count);
                case T_WS2811:                  return FastLED.addLeds<WS2811, C111_ESP_SINGLE_ENDED_3, RBG>(leds, def->offset, def->count);
                case T_WS2813:                  return FastLED.addLeds<WS2813, C111_ESP_SINGLE_ENDED_3, RBG>(leds, def->offset, def->count);
                case T_APA104:                  return FastLED.addLeds<APA104, C111_ESP_SINGLE_ENDED_3, RBG>(leds, def->offset, def->count);
                case T_WS2811_400:              return FastLED.addLeds<WS2811_400, C111_ESP_SINGLE_ENDED_3, RBG>(leds, def->offset, def->count);
                case T_GE8822:                  return FastLED.addLeds<GE8822, C111_ESP_SINGLE_ENDED_3, RBG>(leds, def->offset, def->count);
                case T_GW6205:                  return FastLED.addLeds<GW6205, C111_ESP_SINGLE_ENDED_3, RBG>(leds, def->offset, def->count);
                case T_GW6205_400:              return FastLED.addLeds<GW6205_400, C111_ESP_SINGLE_ENDED_3, RBG>(leds, def->offset, def->count);
                case T_LPD1886:                 return FastLED.addLeds<LPD1886, C111_ESP_SINGLE_ENDED_3, RBG>(leds, def->offset, def->count);
                default /*T_LPD1886_8BIT*/:     return FastLED.addLeds<LPD1886_8BIT, C111_ESP_SINGLE_ENDED_3, RBG>(leds, def->offset, def->count);
            }
            #else
            Serial.println("LED_FACTORY_RBG NOT DEFINED");
            #endif
            
        } else if (def->rgbOrder == GRB) {
            #ifdef LED_FACTORY_GRB
            switch (def->pixelType) {
                case T_NEOPIXEL:                return FastLED.addLeds<NEOPIXEL, C111_ESP_SINGLE_ENDED_3>(leds, def->offset, def->count);
                case T_SM16703:                 return FastLED.addLeds<SM16703, C111_ESP_SINGLE_ENDED_3, GRB>(leds, def->offset, def->count);
                case T_TM1829:                  return FastLED.addLeds<TM1829, C111_ESP_SINGLE_ENDED_3, GRB>(leds, def->offset, def->count);
                case T_TM1812:                  return FastLED.addLeds<TM1812, C111_ESP_SINGLE_ENDED_3, GRB>(leds, def->offset, def->count);
                case T_TM1809:                  return FastLED.addLeds<TM1809, C111_ESP_SINGLE_ENDED_3, GRB>(leds, def->offset, def->count);
                case T_TM1804:                  return FastLED.addLeds<TM1804, C111_ESP_SINGLE_ENDED_3, GRB>(leds, def->offset, def->count);
                case T_TM1803:                  return FastLED.addLeds<TM1803, C111_ESP_SINGLE_ENDED_3, GRB>(leds, def->offset, def->count);
                case T_UCS1903:                 return FastLED.addLeds<UCS1903, C111_ESP_SINGLE_ENDED_3, GRB>(leds, def->offset, def->count);
                case T_UCS1903B:                return FastLED.addLeds<UCS1903B, C111_ESP_SINGLE_ENDED_3, GRB>(leds, def->offset, def->count);
                case T_UCS1904:                 return FastLED.addLeds<UCS1904, C111_ESP_SINGLE_ENDED_3, GRB>(leds, def->offset, def->count);
                case T_UCS2903:                 return FastLED.addLeds<UCS2903, C111_ESP_SINGLE_ENDED_3, GRB>(leds, def->offset, def->count);
                case T_WS2812:                  return FastLED.addLeds<WS2812, C111_ESP_SINGLE_ENDED_3, GRB>(leds, def->offset, def->count);
                case T_WS2852:                  return FastLED.addLeds<WS2852, C111_ESP_SINGLE_ENDED_3, GRB>(leds, def->offset, def->count);
                case T_WS2812B:                 return FastLED.addLeds<WS2812B, C111_ESP_SINGLE_ENDED_3, GRB>(leds, def->offset, def->count);
                case T_GS1903:                  return FastLED.addLeds<GS1903, C111_ESP_SINGLE_ENDED_3, GRB>(leds, def->offset, def->count);
                case T_SK6812:                  return FastLED.addLeds<SK6812, C111_ESP_SINGLE_ENDED_3, GRB>(leds, def->offset, def->count);
                case T_SK6822:                  return FastLED.addLeds<SK6822, C111_ESP_SINGLE_ENDED_3, GRB>(leds, def->offset, def->count);
                case T_APA106:                  return FastLED.addLeds<APA106, C111_ESP_SINGLE_ENDED_3, GRB>(leds, def->offset, def->count);
                case T_PL9823:                  return FastLED.addLeds<PL9823, C111_ESP_SINGLE_ENDED_3, GRB>(leds, def->offset, def->count);
                case T_WS2811:                  return FastLED.addLeds<WS2811, C111_ESP_SINGLE_ENDED_3, GRB>(leds, def->offset, def->count);
                case T_WS2813:                  return FastLED.addLeds<WS2813, C111_ESP_SINGLE_ENDED_3, GRB>(leds, def->offset, def->count);
                case T_APA104:                  return FastLED.addLeds<APA104, C111_ESP_SINGLE_ENDED_3, GRB>(leds, def->offset, def->count);
                case T_WS2811_400:              return FastLED.addLeds<WS2811_400, C111_ESP_SINGLE_ENDED_3, GRB>(leds, def->offset, def->count);
                case T_GE8822:                  return FastLED.addLeds<GE8822, C111_ESP_SINGLE_ENDED_3, GRB>(leds, def->offset, def->count);
                case T_GW6205:                  return FastLED.addLeds<GW6205, C111_ESP_SINGLE_ENDED_3, GRB>(leds, def->offset, def->count);
                case T_GW6205_400:              return FastLED.addLeds<GW6205_400, C111_ESP_SINGLE_ENDED_3, GRB>(leds, def->offset, def->count);
                case T_LPD1886:                 return FastLED.addLeds<LPD1886, C111_ESP_SINGLE_ENDED_3, GRB>(leds, def->offset, def->count);
                default /*T_LPD1886_8BIT*/:     return FastLED.addLeds<LPD1886_8BIT, C111_ESP_SINGLE_ENDED_3, GRB>(leds, def->offset, def->count);
            }
            #else
            Serial.println("LED_FACTORY_GRB NOT DEFINED");
            #endif
            
        } else if (def->rgbOrder == GBR) {
            #ifdef LED_FACTORY_GBR
            switch (def->pixelType) {
                case T_NEOPIXEL:                return FastLED.addLeds<NEOPIXEL, C111_ESP_SINGLE_ENDED_3>(leds, def->offset, def->count);
                case T_SM16703:                 return FastLED.addLeds<SM16703, C111_ESP_SINGLE_ENDED_3, GBR>(leds, def->offset, def->count);
                case T_TM1829:                  return FastLED.addLeds<TM1829, C111_ESP_SINGLE_ENDED_3, GBR>(leds, def->offset, def->count);
                case T_TM1812:                  return FastLED.addLeds<TM1812, C111_ESP_SINGLE_ENDED_3, GBR>(leds, def->offset, def->count);
                case T_TM1809:                  return FastLED.addLeds<TM1809, C111_ESP_SINGLE_ENDED_3, GBR>(leds, def->offset, def->count);
                case T_TM1804:                  return FastLED.addLeds<TM1804, C111_ESP_SINGLE_ENDED_3, GBR>(leds, def->offset, def->count);
                case T_TM1803:                  return FastLED.addLeds<TM1803, C111_ESP_SINGLE_ENDED_3, GBR>(leds, def->offset, def->count);
                case T_UCS1903:                 return FastLED.addLeds<UCS1903, C111_ESP_SINGLE_ENDED_3, GBR>(leds, def->offset, def->count);
                case T_UCS1903B:                return FastLED.addLeds<UCS1903B, C111_ESP_SINGLE_ENDED_3, GBR>(leds, def->offset, def->count);
                case T_UCS1904:                 return FastLED.addLeds<UCS1904, C111_ESP_SINGLE_ENDED_3, GBR>(leds, def->offset, def->count);
                case T_UCS2903:                 return FastLED.addLeds<UCS2903, C111_ESP_SINGLE_ENDED_3, GBR>(leds, def->offset, def->count);
                case T_WS2812:                  return FastLED.addLeds<WS2812, C111_ESP_SINGLE_ENDED_3, GBR>(leds, def->offset, def->count);
                case T_WS2852:                  return FastLED.addLeds<WS2852, C111_ESP_SINGLE_ENDED_3, GBR>(leds, def->offset, def->count);
                case T_WS2812B:                 return FastLED.addLeds<WS2812B, C111_ESP_SINGLE_ENDED_3, GBR>(leds, def->offset, def->count);
                case T_GS1903:                  return FastLED.addLeds<GS1903, C111_ESP_SINGLE_ENDED_3, GBR>(leds, def->offset, def->count);
                case T_SK6812:                  return FastLED.addLeds<SK6812, C111_ESP_SINGLE_ENDED_3, GBR>(leds, def->offset, def->count);
                case T_SK6822:                  return FastLED.addLeds<SK6822, C111_ESP_SINGLE_ENDED_3, GBR>(leds, def->offset, def->count);
                case T_APA106:                  return FastLED.addLeds<APA106, C111_ESP_SINGLE_ENDED_3, GBR>(leds, def->offset, def->count);
                case T_PL9823:                  return FastLED.addLeds<PL9823, C111_ESP_SINGLE_ENDED_3, GBR>(leds, def->offset, def->count);
                case T_WS2811:                  return FastLED.addLeds<WS2811, C111_ESP_SINGLE_ENDED_3, GBR>(leds, def->offset, def->count);
                case T_WS2813:                  return FastLED.addLeds<WS2813, C111_ESP_SINGLE_ENDED_3, GBR>(leds, def->offset, def->count);
                case T_APA104:                  return FastLED.addLeds<APA104, C111_ESP_SINGLE_ENDED_3, GBR>(leds, def->offset, def->count);
                case T_WS2811_400:              return FastLED.addLeds<WS2811_400, C111_ESP_SINGLE_ENDED_3, GBR>(leds, def->offset, def->count);
                case T_GE8822:                  return FastLED.addLeds<GE8822, C111_ESP_SINGLE_ENDED_3, GBR>(leds, def->offset, def->count);
                case T_GW6205:                  return FastLED.addLeds<GW6205, C111_ESP_SINGLE_ENDED_3, GBR>(leds, def->offset, def->count);
                case T_GW6205_400:              return FastLED.addLeds<GW6205_400, C111_ESP_SINGLE_ENDED_3, GBR>(leds, def->offset, def->count);
                case T_LPD1886:                 return FastLED.addLeds<LPD1886, C111_ESP_SINGLE_ENDED_3, GBR>(leds, def->offset, def->count);
                default /*T_LPD1886_8BIT*/:     return FastLED.addLeds<LPD1886_8BIT, C111_ESP_SINGLE_ENDED_3, GBR>(leds, def->offset, def->count);
            }
            #else
            Serial.println("LED_FACTORY_GBR NOT DEFINED");
            #endif
            
        } else if (def->rgbOrder == BRG) {
            #ifdef LED_FACTORY_BRG
            switch (def->pixelType) {
                case T_NEOPIXEL:                return FastLED.addLeds<NEOPIXEL, C111_ESP_SINGLE_ENDED_3>(leds, def->offset, def->count);
                case T_SM16703:                 return FastLED.addLeds<SM16703, C111_ESP_SINGLE_ENDED_3, BRG>(leds, def->offset, def->count);
                case T_TM1829:                  return FastLED.addLeds<TM1829, C111_ESP_SINGLE_ENDED_3, BRG>(leds, def->offset, def->count);
                case T_TM1812:                  return FastLED.addLeds<TM1812, C111_ESP_SINGLE_ENDED_3, BRG>(leds, def->offset, def->count);
                case T_TM1809:                  return FastLED.addLeds<TM1809, C111_ESP_SINGLE_ENDED_3, BRG>(leds, def->offset, def->count);
                case T_TM1804:                  return FastLED.addLeds<TM1804, C111_ESP_SINGLE_ENDED_3, BRG>(leds, def->offset, def->count);
                case T_TM1803:                  return FastLED.addLeds<TM1803, C111_ESP_SINGLE_ENDED_3, BRG>(leds, def->offset, def->count);
                case T_UCS1903:                 return FastLED.addLeds<UCS1903, C111_ESP_SINGLE_ENDED_3, BRG>(leds, def->offset, def->count);
                case T_UCS1903B:                return FastLED.addLeds<UCS1903B, C111_ESP_SINGLE_ENDED_3, BRG>(leds, def->offset, def->count);
                case T_UCS1904:                 return FastLED.addLeds<UCS1904, C111_ESP_SINGLE_ENDED_3, BRG>(leds, def->offset, def->count);
                case T_UCS2903:                 return FastLED.addLeds<UCS2903, C111_ESP_SINGLE_ENDED_3, BRG>(leds, def->offset, def->count);
                case T_WS2812:                  return FastLED.addLeds<WS2812, C111_ESP_SINGLE_ENDED_3, BRG>(leds, def->offset, def->count);
                case T_WS2852:                  return FastLED.addLeds<WS2852, C111_ESP_SINGLE_ENDED_3, BRG>(leds, def->offset, def->count);
                case T_WS2812B:                 return FastLED.addLeds<WS2812B, C111_ESP_SINGLE_ENDED_3, BRG>(leds, def->offset, def->count);
                case T_GS1903:                  return FastLED.addLeds<GS1903, C111_ESP_SINGLE_ENDED_3, BRG>(leds, def->offset, def->count);
                case T_SK6812:                  return FastLED.addLeds<SK6812, C111_ESP_SINGLE_ENDED_3, BRG>(leds, def->offset, def->count);
                case T_SK6822:                  return FastLED.addLeds<SK6822, C111_ESP_SINGLE_ENDED_3, BRG>(leds, def->offset, def->count);
                case T_APA106:                  return FastLED.addLeds<APA106, C111_ESP_SINGLE_ENDED_3, BRG>(leds, def->offset, def->count);
                case T_PL9823:                  return FastLED.addLeds<PL9823, C111_ESP_SINGLE_ENDED_3, BRG>(leds, def->offset, def->count);
                case T_WS2811:                  return FastLED.addLeds<WS2811, C111_ESP_SINGLE_ENDED_3, BRG>(leds, def->offset, def->count);
                case T_WS2813:                  return FastLED.addLeds<WS2813, C111_ESP_SINGLE_ENDED_3, BRG>(leds, def->offset, def->count);
                case T_APA104:                  return FastLED.addLeds<APA104, C111_ESP_SINGLE_ENDED_3, BRG>(leds, def->offset, def->count);
                case T_WS2811_400:              return FastLED.addLeds<WS2811_400, C111_ESP_SINGLE_ENDED_3, BRG>(leds, def->offset, def->count);
                case T_GE8822:                  return FastLED.addLeds<GE8822, C111_ESP_SINGLE_ENDED_3, BRG>(leds, def->offset, def->count);
                case T_GW6205:                  return FastLED.addLeds<GW6205, C111_ESP_SINGLE_ENDED_3, BRG>(leds, def->offset, def->count);
                case T_GW6205_400:              return FastLED.addLeds<GW6205_400, C111_ESP_SINGLE_ENDED_3, BRG>(leds, def->offset, def->count);
                case T_LPD1886:                 return FastLED.addLeds<LPD1886, C111_ESP_SINGLE_ENDED_3, BRG>(leds, def->offset, def->count);
                default /*T_LPD1886_8BIT*/:     return FastLED.addLeds<LPD1886_8BIT, C111_ESP_SINGLE_ENDED_3, BRG>(leds, def->offset, def->count);
            }
            #else
            Serial.println("LED_FACTORY_BRG NOT DEFINED");
            #endif
            
        } else if (def->rgbOrder == BGR) {
            #ifdef LED_FACTORY_BGR
            switch (def->pixelType) {
                case T_NEOPIXEL:                return FastLED.addLeds<NEOPIXEL, C111_ESP_SINGLE_ENDED_3>(leds, def->offset, def->count);
                case T_SM16703:                 return FastLED.addLeds<SM16703, C111_ESP_SINGLE_ENDED_3, BGR>(leds, def->offset, def->count);
                case T_TM1829:                  return FastLED.addLeds<TM1829, C111_ESP_SINGLE_ENDED_3, BGR>(leds, def->offset, def->count);
                case T_TM1812:                  return FastLED.addLeds<TM1812, C111_ESP_SINGLE_ENDED_3, BGR>(leds, def->offset, def->count);
                case T_TM1809:                  return FastLED.addLeds<TM1809, C111_ESP_SINGLE_ENDED_3, BGR>(leds, def->offset, def->count);
                case T_TM1804:                  return FastLED.addLeds<TM1804, C111_ESP_SINGLE_ENDED_3, BGR>(leds, def->offset, def->count);
                case T_TM1803:                  return FastLED.addLeds<TM1803, C111_ESP_SINGLE_ENDED_3, BGR>(leds, def->offset, def->count);
                case T_UCS1903:                 return FastLED.addLeds<UCS1903, C111_ESP_SINGLE_ENDED_3, BGR>(leds, def->offset, def->count);
                case T_UCS1903B:                return FastLED.addLeds<UCS1903B, C111_ESP_SINGLE_ENDED_3, BGR>(leds, def->offset, def->count);
                case T_UCS1904:                 return FastLED.addLeds<UCS1904, C111_ESP_SINGLE_ENDED_3, BGR>(leds, def->offset, def->count);
                case T_UCS2903:                 return FastLED.addLeds<UCS2903, C111_ESP_SINGLE_ENDED_3, BGR>(leds, def->offset, def->count);
                case T_WS2812:                  return FastLED.addLeds<WS2812, C111_ESP_SINGLE_ENDED_3, BGR>(leds, def->offset, def->count);
                case T_WS2852:                  return FastLED.addLeds<WS2852, C111_ESP_SINGLE_ENDED_3, BGR>(leds, def->offset, def->count);
                case T_WS2812B:                 return FastLED.addLeds<WS2812B, C111_ESP_SINGLE_ENDED_3, BGR>(leds, def->offset, def->count);
                case T_GS1903:                  return FastLED.addLeds<GS1903, C111_ESP_SINGLE_ENDED_3, BGR>(leds, def->offset, def->count);
                case T_SK6812:                  return FastLED.addLeds<SK6812, C111_ESP_SINGLE_ENDED_3, BGR>(leds, def->offset, def->count);
                case T_SK6822:                  return FastLED.addLeds<SK6822, C111_ESP_SINGLE_ENDED_3, BGR>(leds, def->offset, def->count);
                case T_APA106:                  return FastLED.addLeds<APA106, C111_ESP_SINGLE_ENDED_3, BGR>(leds, def->offset, def->count);
                case T_PL9823:                  return FastLED.addLeds<PL9823, C111_ESP_SINGLE_ENDED_3, BGR>(leds, def->offset, def->count);
                case T_WS2811:                  return FastLED.addLeds<WS2811, C111_ESP_SINGLE_ENDED_3, BGR>(leds, def->offset, def->count);
                case T_WS2813:                  return FastLED.addLeds<WS2813, C111_ESP_SINGLE_ENDED_3, BGR>(leds, def->offset, def->count);
                case T_APA104:                  return FastLED.addLeds<APA104, C111_ESP_SINGLE_ENDED_3, BGR>(leds, def->offset, def->count);
                case T_WS2811_400:              return FastLED.addLeds<WS2811_400, C111_ESP_SINGLE_ENDED_3, BGR>(leds, def->offset, def->count);
                case T_GE8822:                  return FastLED.addLeds<GE8822, C111_ESP_SINGLE_ENDED_3, BGR>(leds, def->offset, def->count);
                case T_GW6205:                  return FastLED.addLeds<GW6205, C111_ESP_SINGLE_ENDED_3, BGR>(leds, def->offset, def->count);
                case T_GW6205_400:              return FastLED.addLeds<GW6205_400, C111_ESP_SINGLE_ENDED_3, BGR>(leds, def->offset, def->count);
                case T_LPD1886:                 return FastLED.addLeds<LPD1886, C111_ESP_SINGLE_ENDED_3, BGR>(leds, def->offset, def->count);
                default /*T_LPD1886_8BIT*/:     return FastLED.addLeds<LPD1886_8BIT, C111_ESP_SINGLE_ENDED_3, BGR>(leds, def->offset, def->count);
            }
            #else
            Serial.println("LED_FACTORY_BGR NOT DEFINED");
            #endif
            
        }

    }

    if (def->pin == C111_ESP_SINGLE_ENDED_4) {
        if (def->rgbOrder == RGB) {
            #ifdef LED_FACTORY_RGB
            switch (def->pixelType) {
                case T_NEOPIXEL:                return FastLED.addLeds<NEOPIXEL, C111_ESP_SINGLE_ENDED_4>(leds, def->offset, def->count);
                case T_SM16703:                 return FastLED.addLeds<SM16703, C111_ESP_SINGLE_ENDED_4, RGB>(leds, def->offset, def->count);
                case T_TM1829:                  return FastLED.addLeds<TM1829, C111_ESP_SINGLE_ENDED_4, RGB>(leds, def->offset, def->count);
                case T_TM1812:                  return FastLED.addLeds<TM1812, C111_ESP_SINGLE_ENDED_4, RGB>(leds, def->offset, def->count);
                case T_TM1809:                  return FastLED.addLeds<TM1809, C111_ESP_SINGLE_ENDED_4, RGB>(leds, def->offset, def->count);
                case T_TM1804:                  return FastLED.addLeds<TM1804, C111_ESP_SINGLE_ENDED_4, RGB>(leds, def->offset, def->count);
                case T_TM1803:                  return FastLED.addLeds<TM1803, C111_ESP_SINGLE_ENDED_4, RGB>(leds, def->offset, def->count);
                case T_UCS1903:                 return FastLED.addLeds<UCS1903, C111_ESP_SINGLE_ENDED_4, RGB>(leds, def->offset, def->count);
                case T_UCS1903B:                return FastLED.addLeds<UCS1903B, C111_ESP_SINGLE_ENDED_4, RGB>(leds, def->offset, def->count);
                case T_UCS1904:                 return FastLED.addLeds<UCS1904, C111_ESP_SINGLE_ENDED_4, RGB>(leds, def->offset, def->count);
                case T_UCS2903:                 return FastLED.addLeds<UCS2903, C111_ESP_SINGLE_ENDED_4, RGB>(leds, def->offset, def->count);
                case T_WS2812:                  return FastLED.addLeds<WS2812, C111_ESP_SINGLE_ENDED_4, RGB>(leds, def->offset, def->count);
                case T_WS2852:                  return FastLED.addLeds<WS2852, C111_ESP_SINGLE_ENDED_4, RGB>(leds, def->offset, def->count);
                case T_WS2812B:                 return FastLED.addLeds<WS2812B, C111_ESP_SINGLE_ENDED_4, RGB>(leds, def->offset, def->count);
                case T_GS1903:                  return FastLED.addLeds<GS1903, C111_ESP_SINGLE_ENDED_4, RGB>(leds, def->offset, def->count);
                case T_SK6812:                  return FastLED.addLeds<SK6812, C111_ESP_SINGLE_ENDED_4, RGB>(leds, def->offset, def->count);
                case T_SK6822:                  return FastLED.addLeds<SK6822, C111_ESP_SINGLE_ENDED_4, RGB>(leds, def->offset, def->count);
                case T_APA106:                  return FastLED.addLeds<APA106, C111_ESP_SINGLE_ENDED_4, RGB>(leds, def->offset, def->count);
                case T_PL9823:                  return FastLED.addLeds<PL9823, C111_ESP_SINGLE_ENDED_4, RGB>(leds, def->offset, def->count);
                case T_WS2811:                  return FastLED.addLeds<WS2811, C111_ESP_SINGLE_ENDED_4, RGB>(leds, def->offset, def->count);
                case T_WS2813:                  return FastLED.addLeds<WS2813, C111_ESP_SINGLE_ENDED_4, RGB>(leds, def->offset, def->count);
                case T_APA104:                  return FastLED.addLeds<APA104, C111_ESP_SINGLE_ENDED_4, RGB>(leds, def->offset, def->count);
                case T_WS2811_400:              return FastLED.addLeds<WS2811_400, C111_ESP_SINGLE_ENDED_4, RGB>(leds, def->offset, def->count);
                case T_GE8822:                  return FastLED.addLeds<GE8822, C111_ESP_SINGLE_ENDED_4, RGB>(leds, def->offset, def->count);
                case T_GW6205:                  return FastLED.addLeds<GW6205, C111_ESP_SINGLE_ENDED_4, RGB>(leds, def->offset, def->count);
                case T_GW6205_400:              return FastLED.addLeds<GW6205_400, C111_ESP_SINGLE_ENDED_4, RGB>(leds, def->offset, def->count);
                case T_LPD1886:                 return FastLED.addLeds<LPD1886, C111_ESP_SINGLE_ENDED_4, RGB>(leds, def->offset, def->count);
                default /*T_LPD1886_8BIT*/:     return FastLED.addLeds<LPD1886_8BIT, C111_ESP_SINGLE_ENDED_4, RGB>(leds, def->offset, def->count);
            }
            #else
            Serial.println("LED_FACTORY_RGB NOT DEFINED");
            #endif

        } else if (def->rgbOrder == RBG) {
            #ifdef LED_FACTORY_RBG
            switch (def->pixelType) {
                case T_NEOPIXEL:                return FastLED.addLeds<NEOPIXEL, C111_ESP_SINGLE_ENDED_4>(leds, def->offset, def->count);
                case T_SM16703:                 return FastLED.addLeds<SM16703, C111_ESP_SINGLE_ENDED_4, RBG>(leds, def->offset, def->count);
                case T_TM1829:                  return FastLED.addLeds<TM1829, C111_ESP_SINGLE_ENDED_4, RBG>(leds, def->offset, def->count);
                case T_TM1812:                  return FastLED.addLeds<TM1812, C111_ESP_SINGLE_ENDED_4, RBG>(leds, def->offset, def->count);
                case T_TM1809:                  return FastLED.addLeds<TM1809, C111_ESP_SINGLE_ENDED_4, RBG>(leds, def->offset, def->count);
                case T_TM1804:                  return FastLED.addLeds<TM1804, C111_ESP_SINGLE_ENDED_4, RBG>(leds, def->offset, def->count);
                case T_TM1803:                  return FastLED.addLeds<TM1803, C111_ESP_SINGLE_ENDED_4, RBG>(leds, def->offset, def->count);
                case T_UCS1903:                 return FastLED.addLeds<UCS1903, C111_ESP_SINGLE_ENDED_4, RBG>(leds, def->offset, def->count);
                case T_UCS1903B:                return FastLED.addLeds<UCS1903B, C111_ESP_SINGLE_ENDED_4, RBG>(leds, def->offset, def->count);
                case T_UCS1904:                 return FastLED.addLeds<UCS1904, C111_ESP_SINGLE_ENDED_4, RBG>(leds, def->offset, def->count);
                case T_UCS2903:                 return FastLED.addLeds<UCS2903, C111_ESP_SINGLE_ENDED_4, RBG>(leds, def->offset, def->count);
                case T_WS2812:                  return FastLED.addLeds<WS2812, C111_ESP_SINGLE_ENDED_4, RBG>(leds, def->offset, def->count);
                case T_WS2852:                  return FastLED.addLeds<WS2852, C111_ESP_SINGLE_ENDED_4, RBG>(leds, def->offset, def->count);
                case T_WS2812B:                 return FastLED.addLeds<WS2812B, C111_ESP_SINGLE_ENDED_4, RBG>(leds, def->offset, def->count);
                case T_GS1903:                  return FastLED.addLeds<GS1903, C111_ESP_SINGLE_ENDED_4, RBG>(leds, def->offset, def->count);
                case T_SK6812:                  return FastLED.addLeds<SK6812, C111_ESP_SINGLE_ENDED_4, RBG>(leds, def->offset, def->count);
                case T_SK6822:                  return FastLED.addLeds<SK6822, C111_ESP_SINGLE_ENDED_4, RBG>(leds, def->offset, def->count);
                case T_APA106:                  return FastLED.addLeds<APA106, C111_ESP_SINGLE_ENDED_4, RBG>(leds, def->offset, def->count);
                case T_PL9823:                  return FastLED.addLeds<PL9823, C111_ESP_SINGLE_ENDED_4, RBG>(leds, def->offset, def->count);
                case T_WS2811:                  return FastLED.addLeds<WS2811, C111_ESP_SINGLE_ENDED_4, RBG>(leds, def->offset, def->count);
                case T_WS2813:                  return FastLED.addLeds<WS2813, C111_ESP_SINGLE_ENDED_4, RBG>(leds, def->offset, def->count);
                case T_APA104:                  return FastLED.addLeds<APA104, C111_ESP_SINGLE_ENDED_4, RBG>(leds, def->offset, def->count);
                case T_WS2811_400:              return FastLED.addLeds<WS2811_400, C111_ESP_SINGLE_ENDED_4, RBG>(leds, def->offset, def->count);
                case T_GE8822:                  return FastLED.addLeds<GE8822, C111_ESP_SINGLE_ENDED_4, RBG>(leds, def->offset, def->count);
                case T_GW6205:                  return FastLED.addLeds<GW6205, C111_ESP_SINGLE_ENDED_4, RBG>(leds, def->offset, def->count);
                case T_GW6205_400:              return FastLED.addLeds<GW6205_400, C111_ESP_SINGLE_ENDED_4, RBG>(leds, def->offset, def->count);
                case T_LPD1886:                 return FastLED.addLeds<LPD1886, C111_ESP_SINGLE_ENDED_4, RBG>(leds, def->offset, def->count);
                default /*T_LPD1886_8BIT*/:     return FastLED.addLeds<LPD1886_8BIT, C111_ESP_SINGLE_ENDED_4, RBG>(leds, def->offset, def->count);
            }
            #else
            Serial.println("LED_FACTORY_RBG NOT DEFINED");
            #endif
            
        } else if (def->rgbOrder == GRB) {
            #ifdef LED_FACTORY_GRB
            switch (def->pixelType) {
                case T_NEOPIXEL:                return FastLED.addLeds<NEOPIXEL, C111_ESP_SINGLE_ENDED_4>(leds, def->offset, def->count);
                case T_SM16703:                 return FastLED.addLeds<SM16703, C111_ESP_SINGLE_ENDED_4, GRB>(leds, def->offset, def->count);
                case T_TM1829:                  return FastLED.addLeds<TM1829, C111_ESP_SINGLE_ENDED_4, GRB>(leds, def->offset, def->count);
                case T_TM1812:                  return FastLED.addLeds<TM1812, C111_ESP_SINGLE_ENDED_4, GRB>(leds, def->offset, def->count);
                case T_TM1809:                  return FastLED.addLeds<TM1809, C111_ESP_SINGLE_ENDED_4, GRB>(leds, def->offset, def->count);
                case T_TM1804:                  return FastLED.addLeds<TM1804, C111_ESP_SINGLE_ENDED_4, GRB>(leds, def->offset, def->count);
                case T_TM1803:                  return FastLED.addLeds<TM1803, C111_ESP_SINGLE_ENDED_4, GRB>(leds, def->offset, def->count);
                case T_UCS1903:                 return FastLED.addLeds<UCS1903, C111_ESP_SINGLE_ENDED_4, GRB>(leds, def->offset, def->count);
                case T_UCS1903B:                return FastLED.addLeds<UCS1903B, C111_ESP_SINGLE_ENDED_4, GRB>(leds, def->offset, def->count);
                case T_UCS1904:                 return FastLED.addLeds<UCS1904, C111_ESP_SINGLE_ENDED_4, GRB>(leds, def->offset, def->count);
                case T_UCS2903:                 return FastLED.addLeds<UCS2903, C111_ESP_SINGLE_ENDED_4, GRB>(leds, def->offset, def->count);
                case T_WS2812:                  return FastLED.addLeds<WS2812, C111_ESP_SINGLE_ENDED_4, GRB>(leds, def->offset, def->count);
                case T_WS2852:                  return FastLED.addLeds<WS2852, C111_ESP_SINGLE_ENDED_4, GRB>(leds, def->offset, def->count);
                case T_WS2812B:                 return FastLED.addLeds<WS2812B, C111_ESP_SINGLE_ENDED_4, GRB>(leds, def->offset, def->count);
                case T_GS1903:                  return FastLED.addLeds<GS1903, C111_ESP_SINGLE_ENDED_4, GRB>(leds, def->offset, def->count);
                case T_SK6812:                  return FastLED.addLeds<SK6812, C111_ESP_SINGLE_ENDED_4, GRB>(leds, def->offset, def->count);
                case T_SK6822:                  return FastLED.addLeds<SK6822, C111_ESP_SINGLE_ENDED_4, GRB>(leds, def->offset, def->count);
                case T_APA106:                  return FastLED.addLeds<APA106, C111_ESP_SINGLE_ENDED_4, GRB>(leds, def->offset, def->count);
                case T_PL9823:                  return FastLED.addLeds<PL9823, C111_ESP_SINGLE_ENDED_4, GRB>(leds, def->offset, def->count);
                case T_WS2811:                  return FastLED.addLeds<WS2811, C111_ESP_SINGLE_ENDED_4, GRB>(leds, def->offset, def->count);
                case T_WS2813:                  return FastLED.addLeds<WS2813, C111_ESP_SINGLE_ENDED_4, GRB>(leds, def->offset, def->count);
                case T_APA104:                  return FastLED.addLeds<APA104, C111_ESP_SINGLE_ENDED_4, GRB>(leds, def->offset, def->count);
                case T_WS2811_400:              return FastLED.addLeds<WS2811_400, C111_ESP_SINGLE_ENDED_4, GRB>(leds, def->offset, def->count);
                case T_GE8822:                  return FastLED.addLeds<GE8822, C111_ESP_SINGLE_ENDED_4, GRB>(leds, def->offset, def->count);
                case T_GW6205:                  return FastLED.addLeds<GW6205, C111_ESP_SINGLE_ENDED_4, GRB>(leds, def->offset, def->count);
                case T_GW6205_400:              return FastLED.addLeds<GW6205_400, C111_ESP_SINGLE_ENDED_4, GRB>(leds, def->offset, def->count);
                case T_LPD1886:                 return FastLED.addLeds<LPD1886, C111_ESP_SINGLE_ENDED_4, GRB>(leds, def->offset, def->count);
                default /*T_LPD1886_8BIT*/:     return FastLED.addLeds<LPD1886_8BIT, C111_ESP_SINGLE_ENDED_4, GRB>(leds, def->offset, def->count);
            }
            #else
            Serial.println("LED_FACTORY_GRB NOT DEFINED");
            #endif
            
        } else if (def->rgbOrder == GBR) {
            #ifdef LED_FACTORY_GBR
            switch (def->pixelType) {
                case T_NEOPIXEL:                return FastLED.addLeds<NEOPIXEL, C111_ESP_SINGLE_ENDED_4>(leds, def->offset, def->count);
                case T_SM16703:                 return FastLED.addLeds<SM16703, C111_ESP_SINGLE_ENDED_4, GBR>(leds, def->offset, def->count);
                case T_TM1829:                  return FastLED.addLeds<TM1829, C111_ESP_SINGLE_ENDED_4, GBR>(leds, def->offset, def->count);
                case T_TM1812:                  return FastLED.addLeds<TM1812, C111_ESP_SINGLE_ENDED_4, GBR>(leds, def->offset, def->count);
                case T_TM1809:                  return FastLED.addLeds<TM1809, C111_ESP_SINGLE_ENDED_4, GBR>(leds, def->offset, def->count);
                case T_TM1804:                  return FastLED.addLeds<TM1804, C111_ESP_SINGLE_ENDED_4, GBR>(leds, def->offset, def->count);
                case T_TM1803:                  return FastLED.addLeds<TM1803, C111_ESP_SINGLE_ENDED_4, GBR>(leds, def->offset, def->count);
                case T_UCS1903:                 return FastLED.addLeds<UCS1903, C111_ESP_SINGLE_ENDED_4, GBR>(leds, def->offset, def->count);
                case T_UCS1903B:                return FastLED.addLeds<UCS1903B, C111_ESP_SINGLE_ENDED_4, GBR>(leds, def->offset, def->count);
                case T_UCS1904:                 return FastLED.addLeds<UCS1904, C111_ESP_SINGLE_ENDED_4, GBR>(leds, def->offset, def->count);
                case T_UCS2903:                 return FastLED.addLeds<UCS2903, C111_ESP_SINGLE_ENDED_4, GBR>(leds, def->offset, def->count);
                case T_WS2812:                  return FastLED.addLeds<WS2812, C111_ESP_SINGLE_ENDED_4, GBR>(leds, def->offset, def->count);
                case T_WS2852:                  return FastLED.addLeds<WS2852, C111_ESP_SINGLE_ENDED_4, GBR>(leds, def->offset, def->count);
                case T_WS2812B:                 return FastLED.addLeds<WS2812B, C111_ESP_SINGLE_ENDED_4, GBR>(leds, def->offset, def->count);
                case T_GS1903:                  return FastLED.addLeds<GS1903, C111_ESP_SINGLE_ENDED_4, GBR>(leds, def->offset, def->count);
                case T_SK6812:                  return FastLED.addLeds<SK6812, C111_ESP_SINGLE_ENDED_4, GBR>(leds, def->offset, def->count);
                case T_SK6822:                  return FastLED.addLeds<SK6822, C111_ESP_SINGLE_ENDED_4, GBR>(leds, def->offset, def->count);
                case T_APA106:                  return FastLED.addLeds<APA106, C111_ESP_SINGLE_ENDED_4, GBR>(leds, def->offset, def->count);
                case T_PL9823:                  return FastLED.addLeds<PL9823, C111_ESP_SINGLE_ENDED_4, GBR>(leds, def->offset, def->count);
                case T_WS2811:                  return FastLED.addLeds<WS2811, C111_ESP_SINGLE_ENDED_4, GBR>(leds, def->offset, def->count);
                case T_WS2813:                  return FastLED.addLeds<WS2813, C111_ESP_SINGLE_ENDED_4, GBR>(leds, def->offset, def->count);
                case T_APA104:                  return FastLED.addLeds<APA104, C111_ESP_SINGLE_ENDED_4, GBR>(leds, def->offset, def->count);
                case T_WS2811_400:              return FastLED.addLeds<WS2811_400, C111_ESP_SINGLE_ENDED_4, GBR>(leds, def->offset, def->count);
                case T_GE8822:                  return FastLED.addLeds<GE8822, C111_ESP_SINGLE_ENDED_4, GBR>(leds, def->offset, def->count);
                case T_GW6205:                  return FastLED.addLeds<GW6205, C111_ESP_SINGLE_ENDED_4, GBR>(leds, def->offset, def->count);
                case T_GW6205_400:              return FastLED.addLeds<GW6205_400, C111_ESP_SINGLE_ENDED_4, GBR>(leds, def->offset, def->count);
                case T_LPD1886:                 return FastLED.addLeds<LPD1886, C111_ESP_SINGLE_ENDED_4, GBR>(leds, def->offset, def->count);
                default /*T_LPD1886_8BIT*/:     return FastLED.addLeds<LPD1886_8BIT, C111_ESP_SINGLE_ENDED_4, GBR>(leds, def->offset, def->count);
            }
            #else
            Serial.println("LED_FACTORY_GBR NOT DEFINED");
            #endif
            
        } else if (def->rgbOrder == BRG) {
            #ifdef LED_FACTORY_BRG
            switch (def->pixelType) {
                case T_NEOPIXEL:                return FastLED.addLeds<NEOPIXEL, C111_ESP_SINGLE_ENDED_4>(leds, def->offset, def->count);
                case T_SM16703:                 return FastLED.addLeds<SM16703, C111_ESP_SINGLE_ENDED_4, BRG>(leds, def->offset, def->count);
                case T_TM1829:                  return FastLED.addLeds<TM1829, C111_ESP_SINGLE_ENDED_4, BRG>(leds, def->offset, def->count);
                case T_TM1812:                  return FastLED.addLeds<TM1812, C111_ESP_SINGLE_ENDED_4, BRG>(leds, def->offset, def->count);
                case T_TM1809:                  return FastLED.addLeds<TM1809, C111_ESP_SINGLE_ENDED_4, BRG>(leds, def->offset, def->count);
                case T_TM1804:                  return FastLED.addLeds<TM1804, C111_ESP_SINGLE_ENDED_4, BRG>(leds, def->offset, def->count);
                case T_TM1803:                  return FastLED.addLeds<TM1803, C111_ESP_SINGLE_ENDED_4, BRG>(leds, def->offset, def->count);
                case T_UCS1903:                 return FastLED.addLeds<UCS1903, C111_ESP_SINGLE_ENDED_4, BRG>(leds, def->offset, def->count);
                case T_UCS1903B:                return FastLED.addLeds<UCS1903B, C111_ESP_SINGLE_ENDED_4, BRG>(leds, def->offset, def->count);
                case T_UCS1904:                 return FastLED.addLeds<UCS1904, C111_ESP_SINGLE_ENDED_4, BRG>(leds, def->offset, def->count);
                case T_UCS2903:                 return FastLED.addLeds<UCS2903, C111_ESP_SINGLE_ENDED_4, BRG>(leds, def->offset, def->count);
                case T_WS2812:                  return FastLED.addLeds<WS2812, C111_ESP_SINGLE_ENDED_4, BRG>(leds, def->offset, def->count);
                case T_WS2852:                  return FastLED.addLeds<WS2852, C111_ESP_SINGLE_ENDED_4, BRG>(leds, def->offset, def->count);
                case T_WS2812B:                 return FastLED.addLeds<WS2812B, C111_ESP_SINGLE_ENDED_4, BRG>(leds, def->offset, def->count);
                case T_GS1903:                  return FastLED.addLeds<GS1903, C111_ESP_SINGLE_ENDED_4, BRG>(leds, def->offset, def->count);
                case T_SK6812:                  return FastLED.addLeds<SK6812, C111_ESP_SINGLE_ENDED_4, BRG>(leds, def->offset, def->count);
                case T_SK6822:                  return FastLED.addLeds<SK6822, C111_ESP_SINGLE_ENDED_4, BRG>(leds, def->offset, def->count);
                case T_APA106:                  return FastLED.addLeds<APA106, C111_ESP_SINGLE_ENDED_4, BRG>(leds, def->offset, def->count);
                case T_PL9823:                  return FastLED.addLeds<PL9823, C111_ESP_SINGLE_ENDED_4, BRG>(leds, def->offset, def->count);
                case T_WS2811:                  return FastLED.addLeds<WS2811, C111_ESP_SINGLE_ENDED_4, BRG>(leds, def->offset, def->count);
                case T_WS2813:                  return FastLED.addLeds<WS2813, C111_ESP_SINGLE_ENDED_4, BRG>(leds, def->offset, def->count);
                case T_APA104:                  return FastLED.addLeds<APA104, C111_ESP_SINGLE_ENDED_4, BRG>(leds, def->offset, def->count);
                case T_WS2811_400:              return FastLED.addLeds<WS2811_400, C111_ESP_SINGLE_ENDED_4, BRG>(leds, def->offset, def->count);
                case T_GE8822:                  return FastLED.addLeds<GE8822, C111_ESP_SINGLE_ENDED_4, BRG>(leds, def->offset, def->count);
                case T_GW6205:                  return FastLED.addLeds<GW6205, C111_ESP_SINGLE_ENDED_4, BRG>(leds, def->offset, def->count);
                case T_GW6205_400:              return FastLED.addLeds<GW6205_400, C111_ESP_SINGLE_ENDED_4, BRG>(leds, def->offset, def->count);
                case T_LPD1886:                 return FastLED.addLeds<LPD1886, C111_ESP_SINGLE_ENDED_4, BRG>(leds, def->offset, def->count);
                default /*T_LPD1886_8BIT*/:     return FastLED.addLeds<LPD1886_8BIT, C111_ESP_SINGLE_ENDED_4, BRG>(leds, def->offset, def->count);
            }
            #else
            Serial.println("LED_FACTORY_BRG NOT DEFINED");
            #endif
            
        } else if (def->rgbOrder == BGR) {
            #ifdef LED_FACTORY_BGR
            switch (def->pixelType) {
                case T_NEOPIXEL:                return FastLED.addLeds<NEOPIXEL, C111_ESP_SINGLE_ENDED_4>(leds, def->offset, def->count);
                case T_SM16703:                 return FastLED.addLeds<SM16703, C111_ESP_SINGLE_ENDED_4, BGR>(leds, def->offset, def->count);
                case T_TM1829:                  return FastLED.addLeds<TM1829, C111_ESP_SINGLE_ENDED_4, BGR>(leds, def->offset, def->count);
                case T_TM1812:                  return FastLED.addLeds<TM1812, C111_ESP_SINGLE_ENDED_4, BGR>(leds, def->offset, def->count);
                case T_TM1809:                  return FastLED.addLeds<TM1809, C111_ESP_SINGLE_ENDED_4, BGR>(leds, def->offset, def->count);
                case T_TM1804:                  return FastLED.addLeds<TM1804, C111_ESP_SINGLE_ENDED_4, BGR>(leds, def->offset, def->count);
                case T_TM1803:                  return FastLED.addLeds<TM1803, C111_ESP_SINGLE_ENDED_4, BGR>(leds, def->offset, def->count);
                case T_UCS1903:                 return FastLED.addLeds<UCS1903, C111_ESP_SINGLE_ENDED_4, BGR>(leds, def->offset, def->count);
                case T_UCS1903B:                return FastLED.addLeds<UCS1903B, C111_ESP_SINGLE_ENDED_4, BGR>(leds, def->offset, def->count);
                case T_UCS1904:                 return FastLED.addLeds<UCS1904, C111_ESP_SINGLE_ENDED_4, BGR>(leds, def->offset, def->count);
                case T_UCS2903:                 return FastLED.addLeds<UCS2903, C111_ESP_SINGLE_ENDED_4, BGR>(leds, def->offset, def->count);
                case T_WS2812:                  return FastLED.addLeds<WS2812, C111_ESP_SINGLE_ENDED_4, BGR>(leds, def->offset, def->count);
                case T_WS2852:                  return FastLED.addLeds<WS2852, C111_ESP_SINGLE_ENDED_4, BGR>(leds, def->offset, def->count);
                case T_WS2812B:                 return FastLED.addLeds<WS2812B, C111_ESP_SINGLE_ENDED_4, BGR>(leds, def->offset, def->count);
                case T_GS1903:                  return FastLED.addLeds<GS1903, C111_ESP_SINGLE_ENDED_4, BGR>(leds, def->offset, def->count);
                case T_SK6812:                  return FastLED.addLeds<SK6812, C111_ESP_SINGLE_ENDED_4, BGR>(leds, def->offset, def->count);
                case T_SK6822:                  return FastLED.addLeds<SK6822, C111_ESP_SINGLE_ENDED_4, BGR>(leds, def->offset, def->count);
                case T_APA106:                  return FastLED.addLeds<APA106, C111_ESP_SINGLE_ENDED_4, BGR>(leds, def->offset, def->count);
                case T_PL9823:                  return FastLED.addLeds<PL9823, C111_ESP_SINGLE_ENDED_4, BGR>(leds, def->offset, def->count);
                case T_WS2811:                  return FastLED.addLeds<WS2811, C111_ESP_SINGLE_ENDED_4, BGR>(leds, def->offset, def->count);
                case T_WS2813:                  return FastLED.addLeds<WS2813, C111_ESP_SINGLE_ENDED_4, BGR>(leds, def->offset, def->count);
                case T_APA104:                  return FastLED.addLeds<APA104, C111_ESP_SINGLE_ENDED_4, BGR>(leds, def->offset, def->count);
                case T_WS2811_400:              return FastLED.addLeds<WS2811_400, C111_ESP_SINGLE_ENDED_4, BGR>(leds, def->offset, def->count);
                case T_GE8822:                  return FastLED.addLeds<GE8822, C111_ESP_SINGLE_ENDED_4, BGR>(leds, def->offset, def->count);
                case T_GW6205:                  return FastLED.addLeds<GW6205, C111_ESP_SINGLE_ENDED_4, BGR>(leds, def->offset, def->count);
                case T_GW6205_400:              return FastLED.addLeds<GW6205_400, C111_ESP_SINGLE_ENDED_4, BGR>(leds, def->offset, def->count);
                case T_LPD1886:                 return FastLED.addLeds<LPD1886, C111_ESP_SINGLE_ENDED_4, BGR>(leds, def->offset, def->count);
                default /*T_LPD1886_8BIT*/:     return FastLED.addLeds<LPD1886_8BIT, C111_ESP_SINGLE_ENDED_4, BGR>(leds, def->offset, def->count);
            }
            #else
            Serial.println("LED_FACTORY_BGR NOT DEFINED");
            #endif
            
        }

    }

    if (def->pin == C111_ESP_SINGLE_ENDED_5) {
        if (def->rgbOrder == RGB) {
            #ifdef LED_FACTORY_RGB
            switch (def->pixelType) {
                case T_NEOPIXEL:                return FastLED.addLeds<NEOPIXEL, C111_ESP_SINGLE_ENDED_5>(leds, def->offset, def->count);
                case T_SM16703:                 return FastLED.addLeds<SM16703, C111_ESP_SINGLE_ENDED_5, RGB>(leds, def->offset, def->count);
                case T_TM1829:                  return FastLED.addLeds<TM1829, C111_ESP_SINGLE_ENDED_5, RGB>(leds, def->offset, def->count);
                case T_TM1812:                  return FastLED.addLeds<TM1812, C111_ESP_SINGLE_ENDED_5, RGB>(leds, def->offset, def->count);
                case T_TM1809:                  return FastLED.addLeds<TM1809, C111_ESP_SINGLE_ENDED_5, RGB>(leds, def->offset, def->count);
                case T_TM1804:                  return FastLED.addLeds<TM1804, C111_ESP_SINGLE_ENDED_5, RGB>(leds, def->offset, def->count);
                case T_TM1803:                  return FastLED.addLeds<TM1803, C111_ESP_SINGLE_ENDED_5, RGB>(leds, def->offset, def->count);
                case T_UCS1903:                 return FastLED.addLeds<UCS1903, C111_ESP_SINGLE_ENDED_5, RGB>(leds, def->offset, def->count);
                case T_UCS1903B:                return FastLED.addLeds<UCS1903B, C111_ESP_SINGLE_ENDED_5, RGB>(leds, def->offset, def->count);
                case T_UCS1904:                 return FastLED.addLeds<UCS1904, C111_ESP_SINGLE_ENDED_5, RGB>(leds, def->offset, def->count);
                case T_UCS2903:                 return FastLED.addLeds<UCS2903, C111_ESP_SINGLE_ENDED_5, RGB>(leds, def->offset, def->count);
                case T_WS2812:                  return FastLED.addLeds<WS2812, C111_ESP_SINGLE_ENDED_5, RGB>(leds, def->offset, def->count);
                case T_WS2852:                  return FastLED.addLeds<WS2852, C111_ESP_SINGLE_ENDED_5, RGB>(leds, def->offset, def->count);
                case T_WS2812B:                 return FastLED.addLeds<WS2812B, C111_ESP_SINGLE_ENDED_5, RGB>(leds, def->offset, def->count);
                case T_GS1903:                  return FastLED.addLeds<GS1903, C111_ESP_SINGLE_ENDED_5, RGB>(leds, def->offset, def->count);
                case T_SK6812:                  return FastLED.addLeds<SK6812, C111_ESP_SINGLE_ENDED_5, RGB>(leds, def->offset, def->count);
                case T_SK6822:                  return FastLED.addLeds<SK6822, C111_ESP_SINGLE_ENDED_5, RGB>(leds, def->offset, def->count);
                case T_APA106:                  return FastLED.addLeds<APA106, C111_ESP_SINGLE_ENDED_5, RGB>(leds, def->offset, def->count);
                case T_PL9823:                  return FastLED.addLeds<PL9823, C111_ESP_SINGLE_ENDED_5, RGB>(leds, def->offset, def->count);
                case T_WS2811:                  return FastLED.addLeds<WS2811, C111_ESP_SINGLE_ENDED_5, RGB>(leds, def->offset, def->count);
                case T_WS2813:                  return FastLED.addLeds<WS2813, C111_ESP_SINGLE_ENDED_5, RGB>(leds, def->offset, def->count);
                case T_APA104:                  return FastLED.addLeds<APA104, C111_ESP_SINGLE_ENDED_5, RGB>(leds, def->offset, def->count);
                case T_WS2811_400:              return FastLED.addLeds<WS2811_400, C111_ESP_SINGLE_ENDED_5, RGB>(leds, def->offset, def->count);
                case T_GE8822:                  return FastLED.addLeds<GE8822, C111_ESP_SINGLE_ENDED_5, RGB>(leds, def->offset, def->count);
                case T_GW6205:                  return FastLED.addLeds<GW6205, C111_ESP_SINGLE_ENDED_5, RGB>(leds, def->offset, def->count);
                case T_GW6205_400:              return FastLED.addLeds<GW6205_400, C111_ESP_SINGLE_ENDED_5, RGB>(leds, def->offset, def->count);
                case T_LPD1886:                 return FastLED.addLeds<LPD1886, C111_ESP_SINGLE_ENDED_5, RGB>(leds, def->offset, def->count);
                default /*T_LPD1886_8BIT*/:     return FastLED.addLeds<LPD1886_8BIT, C111_ESP_SINGLE_ENDED_5, RGB>(leds, def->offset, def->count);
            }
            #else
            Serial.println("LED_FACTORY_RGB NOT DEFINED");
            #endif

        } else if (def->rgbOrder == RBG) {
            #ifdef LED_FACTORY_RBG
            switch (def->pixelType) {
                case T_NEOPIXEL:                return FastLED.addLeds<NEOPIXEL, C111_ESP_SINGLE_ENDED_5>(leds, def->offset, def->count);
                case T_SM16703:                 return FastLED.addLeds<SM16703, C111_ESP_SINGLE_ENDED_5, RBG>(leds, def->offset, def->count);
                case T_TM1829:                  return FastLED.addLeds<TM1829, C111_ESP_SINGLE_ENDED_5, RBG>(leds, def->offset, def->count);
                case T_TM1812:                  return FastLED.addLeds<TM1812, C111_ESP_SINGLE_ENDED_5, RBG>(leds, def->offset, def->count);
                case T_TM1809:                  return FastLED.addLeds<TM1809, C111_ESP_SINGLE_ENDED_5, RBG>(leds, def->offset, def->count);
                case T_TM1804:                  return FastLED.addLeds<TM1804, C111_ESP_SINGLE_ENDED_5, RBG>(leds, def->offset, def->count);
                case T_TM1803:                  return FastLED.addLeds<TM1803, C111_ESP_SINGLE_ENDED_5, RBG>(leds, def->offset, def->count);
                case T_UCS1903:                 return FastLED.addLeds<UCS1903, C111_ESP_SINGLE_ENDED_5, RBG>(leds, def->offset, def->count);
                case T_UCS1903B:                return FastLED.addLeds<UCS1903B, C111_ESP_SINGLE_ENDED_5, RBG>(leds, def->offset, def->count);
                case T_UCS1904:                 return FastLED.addLeds<UCS1904, C111_ESP_SINGLE_ENDED_5, RBG>(leds, def->offset, def->count);
                case T_UCS2903:                 return FastLED.addLeds<UCS2903, C111_ESP_SINGLE_ENDED_5, RBG>(leds, def->offset, def->count);
                case T_WS2812:                  return FastLED.addLeds<WS2812, C111_ESP_SINGLE_ENDED_5, RBG>(leds, def->offset, def->count);
                case T_WS2852:                  return FastLED.addLeds<WS2852, C111_ESP_SINGLE_ENDED_5, RBG>(leds, def->offset, def->count);
                case T_WS2812B:                 return FastLED.addLeds<WS2812B, C111_ESP_SINGLE_ENDED_5, RBG>(leds, def->offset, def->count);
                case T_GS1903:                  return FastLED.addLeds<GS1903, C111_ESP_SINGLE_ENDED_5, RBG>(leds, def->offset, def->count);
                case T_SK6812:                  return FastLED.addLeds<SK6812, C111_ESP_SINGLE_ENDED_5, RBG>(leds, def->offset, def->count);
                case T_SK6822:                  return FastLED.addLeds<SK6822, C111_ESP_SINGLE_ENDED_5, RBG>(leds, def->offset, def->count);
                case T_APA106:                  return FastLED.addLeds<APA106, C111_ESP_SINGLE_ENDED_5, RBG>(leds, def->offset, def->count);
                case T_PL9823:                  return FastLED.addLeds<PL9823, C111_ESP_SINGLE_ENDED_5, RBG>(leds, def->offset, def->count);
                case T_WS2811:                  return FastLED.addLeds<WS2811, C111_ESP_SINGLE_ENDED_5, RBG>(leds, def->offset, def->count);
                case T_WS2813:                  return FastLED.addLeds<WS2813, C111_ESP_SINGLE_ENDED_5, RBG>(leds, def->offset, def->count);
                case T_APA104:                  return FastLED.addLeds<APA104, C111_ESP_SINGLE_ENDED_5, RBG>(leds, def->offset, def->count);
                case T_WS2811_400:              return FastLED.addLeds<WS2811_400, C111_ESP_SINGLE_ENDED_5, RBG>(leds, def->offset, def->count);
                case T_GE8822:                  return FastLED.addLeds<GE8822, C111_ESP_SINGLE_ENDED_5, RBG>(leds, def->offset, def->count);
                case T_GW6205:                  return FastLED.addLeds<GW6205, C111_ESP_SINGLE_ENDED_5, RBG>(leds, def->offset, def->count);
                case T_GW6205_400:              return FastLED.addLeds<GW6205_400, C111_ESP_SINGLE_ENDED_5, RBG>(leds, def->offset, def->count);
                case T_LPD1886:                 return FastLED.addLeds<LPD1886, C111_ESP_SINGLE_ENDED_5, RBG>(leds, def->offset, def->count);
                default /*T_LPD1886_8BIT*/:     return FastLED.addLeds<LPD1886_8BIT, C111_ESP_SINGLE_ENDED_5, RBG>(leds, def->offset, def->count);
            }
            #else
            Serial.println("LED_FACTORY_RBG NOT DEFINED");
            #endif
            
        } else if (def->rgbOrder == GRB) {
            #ifdef LED_FACTORY_GRB
            switch (def->pixelType) {
                case T_NEOPIXEL:                return FastLED.addLeds<NEOPIXEL, C111_ESP_SINGLE_ENDED_5>(leds, def->offset, def->count);
                case T_SM16703:                 return FastLED.addLeds<SM16703, C111_ESP_SINGLE_ENDED_5, GRB>(leds, def->offset, def->count);
                case T_TM1829:                  return FastLED.addLeds<TM1829, C111_ESP_SINGLE_ENDED_5, GRB>(leds, def->offset, def->count);
                case T_TM1812:                  return FastLED.addLeds<TM1812, C111_ESP_SINGLE_ENDED_5, GRB>(leds, def->offset, def->count);
                case T_TM1809:                  return FastLED.addLeds<TM1809, C111_ESP_SINGLE_ENDED_5, GRB>(leds, def->offset, def->count);
                case T_TM1804:                  return FastLED.addLeds<TM1804, C111_ESP_SINGLE_ENDED_5, GRB>(leds, def->offset, def->count);
                case T_TM1803:                  return FastLED.addLeds<TM1803, C111_ESP_SINGLE_ENDED_5, GRB>(leds, def->offset, def->count);
                case T_UCS1903:                 return FastLED.addLeds<UCS1903, C111_ESP_SINGLE_ENDED_5, GRB>(leds, def->offset, def->count);
                case T_UCS1903B:                return FastLED.addLeds<UCS1903B, C111_ESP_SINGLE_ENDED_5, GRB>(leds, def->offset, def->count);
                case T_UCS1904:                 return FastLED.addLeds<UCS1904, C111_ESP_SINGLE_ENDED_5, GRB>(leds, def->offset, def->count);
                case T_UCS2903:                 return FastLED.addLeds<UCS2903, C111_ESP_SINGLE_ENDED_5, GRB>(leds, def->offset, def->count);
                case T_WS2812:                  return FastLED.addLeds<WS2812, C111_ESP_SINGLE_ENDED_5, GRB>(leds, def->offset, def->count);
                case T_WS2852:                  return FastLED.addLeds<WS2852, C111_ESP_SINGLE_ENDED_5, GRB>(leds, def->offset, def->count);
                case T_WS2812B:                 return FastLED.addLeds<WS2812B, C111_ESP_SINGLE_ENDED_5, GRB>(leds, def->offset, def->count);
                case T_GS1903:                  return FastLED.addLeds<GS1903, C111_ESP_SINGLE_ENDED_5, GRB>(leds, def->offset, def->count);
                case T_SK6812:                  return FastLED.addLeds<SK6812, C111_ESP_SINGLE_ENDED_5, GRB>(leds, def->offset, def->count);
                case T_SK6822:                  return FastLED.addLeds<SK6822, C111_ESP_SINGLE_ENDED_5, GRB>(leds, def->offset, def->count);
                case T_APA106:                  return FastLED.addLeds<APA106, C111_ESP_SINGLE_ENDED_5, GRB>(leds, def->offset, def->count);
                case T_PL9823:                  return FastLED.addLeds<PL9823, C111_ESP_SINGLE_ENDED_5, GRB>(leds, def->offset, def->count);
                case T_WS2811:                  return FastLED.addLeds<WS2811, C111_ESP_SINGLE_ENDED_5, GRB>(leds, def->offset, def->count);
                case T_WS2813:                  return FastLED.addLeds<WS2813, C111_ESP_SINGLE_ENDED_5, GRB>(leds, def->offset, def->count);
                case T_APA104:                  return FastLED.addLeds<APA104, C111_ESP_SINGLE_ENDED_5, GRB>(leds, def->offset, def->count);
                case T_WS2811_400:              return FastLED.addLeds<WS2811_400, C111_ESP_SINGLE_ENDED_5, GRB>(leds, def->offset, def->count);
                case T_GE8822:                  return FastLED.addLeds<GE8822, C111_ESP_SINGLE_ENDED_5, GRB>(leds, def->offset, def->count);
                case T_GW6205:                  return FastLED.addLeds<GW6205, C111_ESP_SINGLE_ENDED_5, GRB>(leds, def->offset, def->count);
                case T_GW6205_400:              return FastLED.addLeds<GW6205_400, C111_ESP_SINGLE_ENDED_5, GRB>(leds, def->offset, def->count);
                case T_LPD1886:                 return FastLED.addLeds<LPD1886, C111_ESP_SINGLE_ENDED_5, GRB>(leds, def->offset, def->count);
                default /*T_LPD1886_8BIT*/:     return FastLED.addLeds<LPD1886_8BIT, C111_ESP_SINGLE_ENDED_5, GRB>(leds, def->offset, def->count);
            }
            #else
            Serial.println("LED_FACTORY_GRB NOT DEFINED");
            #endif
            
        } else if (def->rgbOrder == GBR) {
            #ifdef LED_FACTORY_GBR
            switch (def->pixelType) {
                case T_NEOPIXEL:                return FastLED.addLeds<NEOPIXEL, C111_ESP_SINGLE_ENDED_5>(leds, def->offset, def->count);
                case T_SM16703:                 return FastLED.addLeds<SM16703, C111_ESP_SINGLE_ENDED_5, GBR>(leds, def->offset, def->count);
                case T_TM1829:                  return FastLED.addLeds<TM1829, C111_ESP_SINGLE_ENDED_5, GBR>(leds, def->offset, def->count);
                case T_TM1812:                  return FastLED.addLeds<TM1812, C111_ESP_SINGLE_ENDED_5, GBR>(leds, def->offset, def->count);
                case T_TM1809:                  return FastLED.addLeds<TM1809, C111_ESP_SINGLE_ENDED_5, GBR>(leds, def->offset, def->count);
                case T_TM1804:                  return FastLED.addLeds<TM1804, C111_ESP_SINGLE_ENDED_5, GBR>(leds, def->offset, def->count);
                case T_TM1803:                  return FastLED.addLeds<TM1803, C111_ESP_SINGLE_ENDED_5, GBR>(leds, def->offset, def->count);
                case T_UCS1903:                 return FastLED.addLeds<UCS1903, C111_ESP_SINGLE_ENDED_5, GBR>(leds, def->offset, def->count);
                case T_UCS1903B:                return FastLED.addLeds<UCS1903B, C111_ESP_SINGLE_ENDED_5, GBR>(leds, def->offset, def->count);
                case T_UCS1904:                 return FastLED.addLeds<UCS1904, C111_ESP_SINGLE_ENDED_5, GBR>(leds, def->offset, def->count);
                case T_UCS2903:                 return FastLED.addLeds<UCS2903, C111_ESP_SINGLE_ENDED_5, GBR>(leds, def->offset, def->count);
                case T_WS2812:                  return FastLED.addLeds<WS2812, C111_ESP_SINGLE_ENDED_5, GBR>(leds, def->offset, def->count);
                case T_WS2852:                  return FastLED.addLeds<WS2852, C111_ESP_SINGLE_ENDED_5, GBR>(leds, def->offset, def->count);
                case T_WS2812B:                 return FastLED.addLeds<WS2812B, C111_ESP_SINGLE_ENDED_5, GBR>(leds, def->offset, def->count);
                case T_GS1903:                  return FastLED.addLeds<GS1903, C111_ESP_SINGLE_ENDED_5, GBR>(leds, def->offset, def->count);
                case T_SK6812:                  return FastLED.addLeds<SK6812, C111_ESP_SINGLE_ENDED_5, GBR>(leds, def->offset, def->count);
                case T_SK6822:                  return FastLED.addLeds<SK6822, C111_ESP_SINGLE_ENDED_5, GBR>(leds, def->offset, def->count);
                case T_APA106:                  return FastLED.addLeds<APA106, C111_ESP_SINGLE_ENDED_5, GBR>(leds, def->offset, def->count);
                case T_PL9823:                  return FastLED.addLeds<PL9823, C111_ESP_SINGLE_ENDED_5, GBR>(leds, def->offset, def->count);
                case T_WS2811:                  return FastLED.addLeds<WS2811, C111_ESP_SINGLE_ENDED_5, GBR>(leds, def->offset, def->count);
                case T_WS2813:                  return FastLED.addLeds<WS2813, C111_ESP_SINGLE_ENDED_5, GBR>(leds, def->offset, def->count);
                case T_APA104:                  return FastLED.addLeds<APA104, C111_ESP_SINGLE_ENDED_5, GBR>(leds, def->offset, def->count);
                case T_WS2811_400:              return FastLED.addLeds<WS2811_400, C111_ESP_SINGLE_ENDED_5, GBR>(leds, def->offset, def->count);
                case T_GE8822:                  return FastLED.addLeds<GE8822, C111_ESP_SINGLE_ENDED_5, GBR>(leds, def->offset, def->count);
                case T_GW6205:                  return FastLED.addLeds<GW6205, C111_ESP_SINGLE_ENDED_5, GBR>(leds, def->offset, def->count);
                case T_GW6205_400:              return FastLED.addLeds<GW6205_400, C111_ESP_SINGLE_ENDED_5, GBR>(leds, def->offset, def->count);
                case T_LPD1886:                 return FastLED.addLeds<LPD1886, C111_ESP_SINGLE_ENDED_5, GBR>(leds, def->offset, def->count);
                default /*T_LPD1886_8BIT*/:     return FastLED.addLeds<LPD1886_8BIT, C111_ESP_SINGLE_ENDED_5, GBR>(leds, def->offset, def->count);
            }
            #else
            Serial.println("LED_FACTORY_GBR NOT DEFINED");
            #endif
            
        } else if (def->rgbOrder == BRG) {
            #ifdef LED_FACTORY_BRG
            switch (def->pixelType) {
                case T_NEOPIXEL:                return FastLED.addLeds<NEOPIXEL, C111_ESP_SINGLE_ENDED_5>(leds, def->offset, def->count);
                case T_SM16703:                 return FastLED.addLeds<SM16703, C111_ESP_SINGLE_ENDED_5, BRG>(leds, def->offset, def->count);
                case T_TM1829:                  return FastLED.addLeds<TM1829, C111_ESP_SINGLE_ENDED_5, BRG>(leds, def->offset, def->count);
                case T_TM1812:                  return FastLED.addLeds<TM1812, C111_ESP_SINGLE_ENDED_5, BRG>(leds, def->offset, def->count);
                case T_TM1809:                  return FastLED.addLeds<TM1809, C111_ESP_SINGLE_ENDED_5, BRG>(leds, def->offset, def->count);
                case T_TM1804:                  return FastLED.addLeds<TM1804, C111_ESP_SINGLE_ENDED_5, BRG>(leds, def->offset, def->count);
                case T_TM1803:                  return FastLED.addLeds<TM1803, C111_ESP_SINGLE_ENDED_5, BRG>(leds, def->offset, def->count);
                case T_UCS1903:                 return FastLED.addLeds<UCS1903, C111_ESP_SINGLE_ENDED_5, BRG>(leds, def->offset, def->count);
                case T_UCS1903B:                return FastLED.addLeds<UCS1903B, C111_ESP_SINGLE_ENDED_5, BRG>(leds, def->offset, def->count);
                case T_UCS1904:                 return FastLED.addLeds<UCS1904, C111_ESP_SINGLE_ENDED_5, BRG>(leds, def->offset, def->count);
                case T_UCS2903:                 return FastLED.addLeds<UCS2903, C111_ESP_SINGLE_ENDED_5, BRG>(leds, def->offset, def->count);
                case T_WS2812:                  return FastLED.addLeds<WS2812, C111_ESP_SINGLE_ENDED_5, BRG>(leds, def->offset, def->count);
                case T_WS2852:                  return FastLED.addLeds<WS2852, C111_ESP_SINGLE_ENDED_5, BRG>(leds, def->offset, def->count);
                case T_WS2812B:                 return FastLED.addLeds<WS2812B, C111_ESP_SINGLE_ENDED_5, BRG>(leds, def->offset, def->count);
                case T_GS1903:                  return FastLED.addLeds<GS1903, C111_ESP_SINGLE_ENDED_5, BRG>(leds, def->offset, def->count);
                case T_SK6812:                  return FastLED.addLeds<SK6812, C111_ESP_SINGLE_ENDED_5, BRG>(leds, def->offset, def->count);
                case T_SK6822:                  return FastLED.addLeds<SK6822, C111_ESP_SINGLE_ENDED_5, BRG>(leds, def->offset, def->count);
                case T_APA106:                  return FastLED.addLeds<APA106, C111_ESP_SINGLE_ENDED_5, BRG>(leds, def->offset, def->count);
                case T_PL9823:                  return FastLED.addLeds<PL9823, C111_ESP_SINGLE_ENDED_5, BRG>(leds, def->offset, def->count);
                case T_WS2811:                  return FastLED.addLeds<WS2811, C111_ESP_SINGLE_ENDED_5, BRG>(leds, def->offset, def->count);
                case T_WS2813:                  return FastLED.addLeds<WS2813, C111_ESP_SINGLE_ENDED_5, BRG>(leds, def->offset, def->count);
                case T_APA104:                  return FastLED.addLeds<APA104, C111_ESP_SINGLE_ENDED_5, BRG>(leds, def->offset, def->count);
                case T_WS2811_400:              return FastLED.addLeds<WS2811_400, C111_ESP_SINGLE_ENDED_5, BRG>(leds, def->offset, def->count);
                case T_GE8822:                  return FastLED.addLeds<GE8822, C111_ESP_SINGLE_ENDED_5, BRG>(leds, def->offset, def->count);
                case T_GW6205:                  return FastLED.addLeds<GW6205, C111_ESP_SINGLE_ENDED_5, BRG>(leds, def->offset, def->count);
                case T_GW6205_400:              return FastLED.addLeds<GW6205_400, C111_ESP_SINGLE_ENDED_5, BRG>(leds, def->offset, def->count);
                case T_LPD1886:                 return FastLED.addLeds<LPD1886, C111_ESP_SINGLE_ENDED_5, BRG>(leds, def->offset, def->count);
                default /*T_LPD1886_8BIT*/:     return FastLED.addLeds<LPD1886_8BIT, C111_ESP_SINGLE_ENDED_5, BRG>(leds, def->offset, def->count);
            }
            #else
            Serial.println("LED_FACTORY_BRG NOT DEFINED");
            #endif
            
        } else if (def->rgbOrder == BGR) {
            #ifdef LED_FACTORY_BGR
            switch (def->pixelType) {
                case T_NEOPIXEL:                return FastLED.addLeds<NEOPIXEL, C111_ESP_SINGLE_ENDED_5>(leds, def->offset, def->count);
                case T_SM16703:                 return FastLED.addLeds<SM16703, C111_ESP_SINGLE_ENDED_5, BGR>(leds, def->offset, def->count);
                case T_TM1829:                  return FastLED.addLeds<TM1829, C111_ESP_SINGLE_ENDED_5, BGR>(leds, def->offset, def->count);
                case T_TM1812:                  return FastLED.addLeds<TM1812, C111_ESP_SINGLE_ENDED_5, BGR>(leds, def->offset, def->count);
                case T_TM1809:                  return FastLED.addLeds<TM1809, C111_ESP_SINGLE_ENDED_5, BGR>(leds, def->offset, def->count);
                case T_TM1804:                  return FastLED.addLeds<TM1804, C111_ESP_SINGLE_ENDED_5, BGR>(leds, def->offset, def->count);
                case T_TM1803:                  return FastLED.addLeds<TM1803, C111_ESP_SINGLE_ENDED_5, BGR>(leds, def->offset, def->count);
                case T_UCS1903:                 return FastLED.addLeds<UCS1903, C111_ESP_SINGLE_ENDED_5, BGR>(leds, def->offset, def->count);
                case T_UCS1903B:                return FastLED.addLeds<UCS1903B, C111_ESP_SINGLE_ENDED_5, BGR>(leds, def->offset, def->count);
                case T_UCS1904:                 return FastLED.addLeds<UCS1904, C111_ESP_SINGLE_ENDED_5, BGR>(leds, def->offset, def->count);
                case T_UCS2903:                 return FastLED.addLeds<UCS2903, C111_ESP_SINGLE_ENDED_5, BGR>(leds, def->offset, def->count);
                case T_WS2812:                  return FastLED.addLeds<WS2812, C111_ESP_SINGLE_ENDED_5, BGR>(leds, def->offset, def->count);
                case T_WS2852:                  return FastLED.addLeds<WS2852, C111_ESP_SINGLE_ENDED_5, BGR>(leds, def->offset, def->count);
                case T_WS2812B:                 return FastLED.addLeds<WS2812B, C111_ESP_SINGLE_ENDED_5, BGR>(leds, def->offset, def->count);
                case T_GS1903:                  return FastLED.addLeds<GS1903, C111_ESP_SINGLE_ENDED_5, BGR>(leds, def->offset, def->count);
                case T_SK6812:                  return FastLED.addLeds<SK6812, C111_ESP_SINGLE_ENDED_5, BGR>(leds, def->offset, def->count);
                case T_SK6822:                  return FastLED.addLeds<SK6822, C111_ESP_SINGLE_ENDED_5, BGR>(leds, def->offset, def->count);
                case T_APA106:                  return FastLED.addLeds<APA106, C111_ESP_SINGLE_ENDED_5, BGR>(leds, def->offset, def->count);
                case T_PL9823:                  return FastLED.addLeds<PL9823, C111_ESP_SINGLE_ENDED_5, BGR>(leds, def->offset, def->count);
                case T_WS2811:                  return FastLED.addLeds<WS2811, C111_ESP_SINGLE_ENDED_5, BGR>(leds, def->offset, def->count);
                case T_WS2813:                  return FastLED.addLeds<WS2813, C111_ESP_SINGLE_ENDED_5, BGR>(leds, def->offset, def->count);
                case T_APA104:                  return FastLED.addLeds<APA104, C111_ESP_SINGLE_ENDED_5, BGR>(leds, def->offset, def->count);
                case T_WS2811_400:              return FastLED.addLeds<WS2811_400, C111_ESP_SINGLE_ENDED_5, BGR>(leds, def->offset, def->count);
                case T_GE8822:                  return FastLED.addLeds<GE8822, C111_ESP_SINGLE_ENDED_5, BGR>(leds, def->offset, def->count);
                case T_GW6205:                  return FastLED.addLeds<GW6205, C111_ESP_SINGLE_ENDED_5, BGR>(leds, def->offset, def->count);
                case T_GW6205_400:              return FastLED.addLeds<GW6205_400, C111_ESP_SINGLE_ENDED_5, BGR>(leds, def->offset, def->count);
                case T_LPD1886:                 return FastLED.addLeds<LPD1886, C111_ESP_SINGLE_ENDED_5, BGR>(leds, def->offset, def->count);
                default /*T_LPD1886_8BIT*/:     return FastLED.addLeds<LPD1886_8BIT, C111_ESP_SINGLE_ENDED_5, BGR>(leds, def->offset, def->count);
            }
            #else
            Serial.println("LED_FACTORY_BGR NOT DEFINED");
            #endif
            
        }

    }

    if (def->pin == C111_ESP_SINGLE_ENDED_6) {
        if (def->rgbOrder == RGB) {
            #ifdef LED_FACTORY_RGB
            switch (def->pixelType) {
                case T_NEOPIXEL:                return FastLED.addLeds<NEOPIXEL, C111_ESP_SINGLE_ENDED_6>(leds, def->offset, def->count);
                case T_SM16703:                 return FastLED.addLeds<SM16703, C111_ESP_SINGLE_ENDED_6, RGB>(leds, def->offset, def->count);
                case T_TM1829:                  return FastLED.addLeds<TM1829, C111_ESP_SINGLE_ENDED_6, RGB>(leds, def->offset, def->count);
                case T_TM1812:                  return FastLED.addLeds<TM1812, C111_ESP_SINGLE_ENDED_6, RGB>(leds, def->offset, def->count);
                case T_TM1809:                  return FastLED.addLeds<TM1809, C111_ESP_SINGLE_ENDED_6, RGB>(leds, def->offset, def->count);
                case T_TM1804:                  return FastLED.addLeds<TM1804, C111_ESP_SINGLE_ENDED_6, RGB>(leds, def->offset, def->count);
                case T_TM1803:                  return FastLED.addLeds<TM1803, C111_ESP_SINGLE_ENDED_6, RGB>(leds, def->offset, def->count);
                case T_UCS1903:                 return FastLED.addLeds<UCS1903, C111_ESP_SINGLE_ENDED_6, RGB>(leds, def->offset, def->count);
                case T_UCS1903B:                return FastLED.addLeds<UCS1903B, C111_ESP_SINGLE_ENDED_6, RGB>(leds, def->offset, def->count);
                case T_UCS1904:                 return FastLED.addLeds<UCS1904, C111_ESP_SINGLE_ENDED_6, RGB>(leds, def->offset, def->count);
                case T_UCS2903:                 return FastLED.addLeds<UCS2903, C111_ESP_SINGLE_ENDED_6, RGB>(leds, def->offset, def->count);
                case T_WS2812:                  return FastLED.addLeds<WS2812, C111_ESP_SINGLE_ENDED_6, RGB>(leds, def->offset, def->count);
                case T_WS2852:                  return FastLED.addLeds<WS2852, C111_ESP_SINGLE_ENDED_6, RGB>(leds, def->offset, def->count);
                case T_WS2812B:                 return FastLED.addLeds<WS2812B, C111_ESP_SINGLE_ENDED_6, RGB>(leds, def->offset, def->count);
                case T_GS1903:                  return FastLED.addLeds<GS1903, C111_ESP_SINGLE_ENDED_6, RGB>(leds, def->offset, def->count);
                case T_SK6812:                  return FastLED.addLeds<SK6812, C111_ESP_SINGLE_ENDED_6, RGB>(leds, def->offset, def->count);
                case T_SK6822:                  return FastLED.addLeds<SK6822, C111_ESP_SINGLE_ENDED_6, RGB>(leds, def->offset, def->count);
                case T_APA106:                  return FastLED.addLeds<APA106, C111_ESP_SINGLE_ENDED_6, RGB>(leds, def->offset, def->count);
                case T_PL9823:                  return FastLED.addLeds<PL9823, C111_ESP_SINGLE_ENDED_6, RGB>(leds, def->offset, def->count);
                case T_WS2811:                  return FastLED.addLeds<WS2811, C111_ESP_SINGLE_ENDED_6, RGB>(leds, def->offset, def->count);
                case T_WS2813:                  return FastLED.addLeds<WS2813, C111_ESP_SINGLE_ENDED_6, RGB>(leds, def->offset, def->count);
                case T_APA104:                  return FastLED.addLeds<APA104, C111_ESP_SINGLE_ENDED_6, RGB>(leds, def->offset, def->count);
                case T_WS2811_400:              return FastLED.addLeds<WS2811_400, C111_ESP_SINGLE_ENDED_6, RGB>(leds, def->offset, def->count);
                case T_GE8822:                  return FastLED.addLeds<GE8822, C111_ESP_SINGLE_ENDED_6, RGB>(leds, def->offset, def->count);
                case T_GW6205:                  return FastLED.addLeds<GW6205, C111_ESP_SINGLE_ENDED_6, RGB>(leds, def->offset, def->count);
                case T_GW6205_400:              return FastLED.addLeds<GW6205_400, C111_ESP_SINGLE_ENDED_6, RGB>(leds, def->offset, def->count);
                case T_LPD1886:                 return FastLED.addLeds<LPD1886, C111_ESP_SINGLE_ENDED_6, RGB>(leds, def->offset, def->count);
                default /*T_LPD1886_8BIT*/:     return FastLED.addLeds<LPD1886_8BIT, C111_ESP_SINGLE_ENDED_6, RGB>(leds, def->offset, def->count);
            }
            #else
            Serial.println("LED_FACTORY_RGB NOT DEFINED");
            #endif

        } else if (def->rgbOrder == RBG) {
            #ifdef LED_FACTORY_RBG
            switch (def->pixelType) {
                case T_NEOPIXEL:                return FastLED.addLeds<NEOPIXEL, C111_ESP_SINGLE_ENDED_6>(leds, def->offset, def->count);
                case T_SM16703:                 return FastLED.addLeds<SM16703, C111_ESP_SINGLE_ENDED_6, RBG>(leds, def->offset, def->count);
                case T_TM1829:                  return FastLED.addLeds<TM1829, C111_ESP_SINGLE_ENDED_6, RBG>(leds, def->offset, def->count);
                case T_TM1812:                  return FastLED.addLeds<TM1812, C111_ESP_SINGLE_ENDED_6, RBG>(leds, def->offset, def->count);
                case T_TM1809:                  return FastLED.addLeds<TM1809, C111_ESP_SINGLE_ENDED_6, RBG>(leds, def->offset, def->count);
                case T_TM1804:                  return FastLED.addLeds<TM1804, C111_ESP_SINGLE_ENDED_6, RBG>(leds, def->offset, def->count);
                case T_TM1803:                  return FastLED.addLeds<TM1803, C111_ESP_SINGLE_ENDED_6, RBG>(leds, def->offset, def->count);
                case T_UCS1903:                 return FastLED.addLeds<UCS1903, C111_ESP_SINGLE_ENDED_6, RBG>(leds, def->offset, def->count);
                case T_UCS1903B:                return FastLED.addLeds<UCS1903B, C111_ESP_SINGLE_ENDED_6, RBG>(leds, def->offset, def->count);
                case T_UCS1904:                 return FastLED.addLeds<UCS1904, C111_ESP_SINGLE_ENDED_6, RBG>(leds, def->offset, def->count);
                case T_UCS2903:                 return FastLED.addLeds<UCS2903, C111_ESP_SINGLE_ENDED_6, RBG>(leds, def->offset, def->count);
                case T_WS2812:                  return FastLED.addLeds<WS2812, C111_ESP_SINGLE_ENDED_6, RBG>(leds, def->offset, def->count);
                case T_WS2852:                  return FastLED.addLeds<WS2852, C111_ESP_SINGLE_ENDED_6, RBG>(leds, def->offset, def->count);
                case T_WS2812B:                 return FastLED.addLeds<WS2812B, C111_ESP_SINGLE_ENDED_6, RBG>(leds, def->offset, def->count);
                case T_GS1903:                  return FastLED.addLeds<GS1903, C111_ESP_SINGLE_ENDED_6, RBG>(leds, def->offset, def->count);
                case T_SK6812:                  return FastLED.addLeds<SK6812, C111_ESP_SINGLE_ENDED_6, RBG>(leds, def->offset, def->count);
                case T_SK6822:                  return FastLED.addLeds<SK6822, C111_ESP_SINGLE_ENDED_6, RBG>(leds, def->offset, def->count);
                case T_APA106:                  return FastLED.addLeds<APA106, C111_ESP_SINGLE_ENDED_6, RBG>(leds, def->offset, def->count);
                case T_PL9823:                  return FastLED.addLeds<PL9823, C111_ESP_SINGLE_ENDED_6, RBG>(leds, def->offset, def->count);
                case T_WS2811:                  return FastLED.addLeds<WS2811, C111_ESP_SINGLE_ENDED_6, RBG>(leds, def->offset, def->count);
                case T_WS2813:                  return FastLED.addLeds<WS2813, C111_ESP_SINGLE_ENDED_6, RBG>(leds, def->offset, def->count);
                case T_APA104:                  return FastLED.addLeds<APA104, C111_ESP_SINGLE_ENDED_6, RBG>(leds, def->offset, def->count);
                case T_WS2811_400:              return FastLED.addLeds<WS2811_400, C111_ESP_SINGLE_ENDED_6, RBG>(leds, def->offset, def->count);
                case T_GE8822:                  return FastLED.addLeds<GE8822, C111_ESP_SINGLE_ENDED_6, RBG>(leds, def->offset, def->count);
                case T_GW6205:                  return FastLED.addLeds<GW6205, C111_ESP_SINGLE_ENDED_6, RBG>(leds, def->offset, def->count);
                case T_GW6205_400:              return FastLED.addLeds<GW6205_400, C111_ESP_SINGLE_ENDED_6, RBG>(leds, def->offset, def->count);
                case T_LPD1886:                 return FastLED.addLeds<LPD1886, C111_ESP_SINGLE_ENDED_6, RBG>(leds, def->offset, def->count);
                default /*T_LPD1886_8BIT*/:     return FastLED.addLeds<LPD1886_8BIT, C111_ESP_SINGLE_ENDED_6, RBG>(leds, def->offset, def->count);
            }
            #else
            Serial.println("LED_FACTORY_RBG NOT DEFINED");
            #endif
            
        } else if (def->rgbOrder == GRB) {
            #ifdef LED_FACTORY_GRB
            switch (def->pixelType) {
                case T_NEOPIXEL:                return FastLED.addLeds<NEOPIXEL, C111_ESP_SINGLE_ENDED_6>(leds, def->offset, def->count);
                case T_SM16703:                 return FastLED.addLeds<SM16703, C111_ESP_SINGLE_ENDED_6, GRB>(leds, def->offset, def->count);
                case T_TM1829:                  return FastLED.addLeds<TM1829, C111_ESP_SINGLE_ENDED_6, GRB>(leds, def->offset, def->count);
                case T_TM1812:                  return FastLED.addLeds<TM1812, C111_ESP_SINGLE_ENDED_6, GRB>(leds, def->offset, def->count);
                case T_TM1809:                  return FastLED.addLeds<TM1809, C111_ESP_SINGLE_ENDED_6, GRB>(leds, def->offset, def->count);
                case T_TM1804:                  return FastLED.addLeds<TM1804, C111_ESP_SINGLE_ENDED_6, GRB>(leds, def->offset, def->count);
                case T_TM1803:                  return FastLED.addLeds<TM1803, C111_ESP_SINGLE_ENDED_6, GRB>(leds, def->offset, def->count);
                case T_UCS1903:                 return FastLED.addLeds<UCS1903, C111_ESP_SINGLE_ENDED_6, GRB>(leds, def->offset, def->count);
                case T_UCS1903B:                return FastLED.addLeds<UCS1903B, C111_ESP_SINGLE_ENDED_6, GRB>(leds, def->offset, def->count);
                case T_UCS1904:                 return FastLED.addLeds<UCS1904, C111_ESP_SINGLE_ENDED_6, GRB>(leds, def->offset, def->count);
                case T_UCS2903:                 return FastLED.addLeds<UCS2903, C111_ESP_SINGLE_ENDED_6, GRB>(leds, def->offset, def->count);
                case T_WS2812:                  return FastLED.addLeds<WS2812, C111_ESP_SINGLE_ENDED_6, GRB>(leds, def->offset, def->count);
                case T_WS2852:                  return FastLED.addLeds<WS2852, C111_ESP_SINGLE_ENDED_6, GRB>(leds, def->offset, def->count);
                case T_WS2812B:                 return FastLED.addLeds<WS2812B, C111_ESP_SINGLE_ENDED_6, GRB>(leds, def->offset, def->count);
                case T_GS1903:                  return FastLED.addLeds<GS1903, C111_ESP_SINGLE_ENDED_6, GRB>(leds, def->offset, def->count);
                case T_SK6812:                  return FastLED.addLeds<SK6812, C111_ESP_SINGLE_ENDED_6, GRB>(leds, def->offset, def->count);
                case T_SK6822:                  return FastLED.addLeds<SK6822, C111_ESP_SINGLE_ENDED_6, GRB>(leds, def->offset, def->count);
                case T_APA106:                  return FastLED.addLeds<APA106, C111_ESP_SINGLE_ENDED_6, GRB>(leds, def->offset, def->count);
                case T_PL9823:                  return FastLED.addLeds<PL9823, C111_ESP_SINGLE_ENDED_6, GRB>(leds, def->offset, def->count);
                case T_WS2811:                  return FastLED.addLeds<WS2811, C111_ESP_SINGLE_ENDED_6, GRB>(leds, def->offset, def->count);
                case T_WS2813:                  return FastLED.addLeds<WS2813, C111_ESP_SINGLE_ENDED_6, GRB>(leds, def->offset, def->count);
                case T_APA104:                  return FastLED.addLeds<APA104, C111_ESP_SINGLE_ENDED_6, GRB>(leds, def->offset, def->count);
                case T_WS2811_400:              return FastLED.addLeds<WS2811_400, C111_ESP_SINGLE_ENDED_6, GRB>(leds, def->offset, def->count);
                case T_GE8822:                  return FastLED.addLeds<GE8822, C111_ESP_SINGLE_ENDED_6, GRB>(leds, def->offset, def->count);
                case T_GW6205:                  return FastLED.addLeds<GW6205, C111_ESP_SINGLE_ENDED_6, GRB>(leds, def->offset, def->count);
                case T_GW6205_400:              return FastLED.addLeds<GW6205_400, C111_ESP_SINGLE_ENDED_6, GRB>(leds, def->offset, def->count);
                case T_LPD1886:                 return FastLED.addLeds<LPD1886, C111_ESP_SINGLE_ENDED_6, GRB>(leds, def->offset, def->count);
                default /*T_LPD1886_8BIT*/:     return FastLED.addLeds<LPD1886_8BIT, C111_ESP_SINGLE_ENDED_6, GRB>(leds, def->offset, def->count);
            }
            #else
            Serial.println("LED_FACTORY_GRB NOT DEFINED");
            #endif
            
        } else if (def->rgbOrder == GBR) {
            #ifdef LED_FACTORY_GBR
            switch (def->pixelType) {
                case T_NEOPIXEL:                return FastLED.addLeds<NEOPIXEL, C111_ESP_SINGLE_ENDED_6>(leds, def->offset, def->count);
                case T_SM16703:                 return FastLED.addLeds<SM16703, C111_ESP_SINGLE_ENDED_6, GBR>(leds, def->offset, def->count);
                case T_TM1829:                  return FastLED.addLeds<TM1829, C111_ESP_SINGLE_ENDED_6, GBR>(leds, def->offset, def->count);
                case T_TM1812:                  return FastLED.addLeds<TM1812, C111_ESP_SINGLE_ENDED_6, GBR>(leds, def->offset, def->count);
                case T_TM1809:                  return FastLED.addLeds<TM1809, C111_ESP_SINGLE_ENDED_6, GBR>(leds, def->offset, def->count);
                case T_TM1804:                  return FastLED.addLeds<TM1804, C111_ESP_SINGLE_ENDED_6, GBR>(leds, def->offset, def->count);
                case T_TM1803:                  return FastLED.addLeds<TM1803, C111_ESP_SINGLE_ENDED_6, GBR>(leds, def->offset, def->count);
                case T_UCS1903:                 return FastLED.addLeds<UCS1903, C111_ESP_SINGLE_ENDED_6, GBR>(leds, def->offset, def->count);
                case T_UCS1903B:                return FastLED.addLeds<UCS1903B, C111_ESP_SINGLE_ENDED_6, GBR>(leds, def->offset, def->count);
                case T_UCS1904:                 return FastLED.addLeds<UCS1904, C111_ESP_SINGLE_ENDED_6, GBR>(leds, def->offset, def->count);
                case T_UCS2903:                 return FastLED.addLeds<UCS2903, C111_ESP_SINGLE_ENDED_6, GBR>(leds, def->offset, def->count);
                case T_WS2812:                  return FastLED.addLeds<WS2812, C111_ESP_SINGLE_ENDED_6, GBR>(leds, def->offset, def->count);
                case T_WS2852:                  return FastLED.addLeds<WS2852, C111_ESP_SINGLE_ENDED_6, GBR>(leds, def->offset, def->count);
                case T_WS2812B:                 return FastLED.addLeds<WS2812B, C111_ESP_SINGLE_ENDED_6, GBR>(leds, def->offset, def->count);
                case T_GS1903:                  return FastLED.addLeds<GS1903, C111_ESP_SINGLE_ENDED_6, GBR>(leds, def->offset, def->count);
                case T_SK6812:                  return FastLED.addLeds<SK6812, C111_ESP_SINGLE_ENDED_6, GBR>(leds, def->offset, def->count);
                case T_SK6822:                  return FastLED.addLeds<SK6822, C111_ESP_SINGLE_ENDED_6, GBR>(leds, def->offset, def->count);
                case T_APA106:                  return FastLED.addLeds<APA106, C111_ESP_SINGLE_ENDED_6, GBR>(leds, def->offset, def->count);
                case T_PL9823:                  return FastLED.addLeds<PL9823, C111_ESP_SINGLE_ENDED_6, GBR>(leds, def->offset, def->count);
                case T_WS2811:                  return FastLED.addLeds<WS2811, C111_ESP_SINGLE_ENDED_6, GBR>(leds, def->offset, def->count);
                case T_WS2813:                  return FastLED.addLeds<WS2813, C111_ESP_SINGLE_ENDED_6, GBR>(leds, def->offset, def->count);
                case T_APA104:                  return FastLED.addLeds<APA104, C111_ESP_SINGLE_ENDED_6, GBR>(leds, def->offset, def->count);
                case T_WS2811_400:              return FastLED.addLeds<WS2811_400, C111_ESP_SINGLE_ENDED_6, GBR>(leds, def->offset, def->count);
                case T_GE8822:                  return FastLED.addLeds<GE8822, C111_ESP_SINGLE_ENDED_6, GBR>(leds, def->offset, def->count);
                case T_GW6205:                  return FastLED.addLeds<GW6205, C111_ESP_SINGLE_ENDED_6, GBR>(leds, def->offset, def->count);
                case T_GW6205_400:              return FastLED.addLeds<GW6205_400, C111_ESP_SINGLE_ENDED_6, GBR>(leds, def->offset, def->count);
                case T_LPD1886:                 return FastLED.addLeds<LPD1886, C111_ESP_SINGLE_ENDED_6, GBR>(leds, def->offset, def->count);
                default /*T_LPD1886_8BIT*/:     return FastLED.addLeds<LPD1886_8BIT, C111_ESP_SINGLE_ENDED_6, GBR>(leds, def->offset, def->count);
            }
            #else
            Serial.println("LED_FACTORY_GBR NOT DEFINED");
            #endif
            
        } else if (def->rgbOrder == BRG) {
            #ifdef LED_FACTORY_BRG
            switch (def->pixelType) {
                case T_NEOPIXEL:                return FastLED.addLeds<NEOPIXEL, C111_ESP_SINGLE_ENDED_6>(leds, def->offset, def->count);
                case T_SM16703:                 return FastLED.addLeds<SM16703, C111_ESP_SINGLE_ENDED_6, BRG>(leds, def->offset, def->count);
                case T_TM1829:                  return FastLED.addLeds<TM1829, C111_ESP_SINGLE_ENDED_6, BRG>(leds, def->offset, def->count);
                case T_TM1812:                  return FastLED.addLeds<TM1812, C111_ESP_SINGLE_ENDED_6, BRG>(leds, def->offset, def->count);
                case T_TM1809:                  return FastLED.addLeds<TM1809, C111_ESP_SINGLE_ENDED_6, BRG>(leds, def->offset, def->count);
                case T_TM1804:                  return FastLED.addLeds<TM1804, C111_ESP_SINGLE_ENDED_6, BRG>(leds, def->offset, def->count);
                case T_TM1803:                  return FastLED.addLeds<TM1803, C111_ESP_SINGLE_ENDED_6, BRG>(leds, def->offset, def->count);
                case T_UCS1903:                 return FastLED.addLeds<UCS1903, C111_ESP_SINGLE_ENDED_6, BRG>(leds, def->offset, def->count);
                case T_UCS1903B:                return FastLED.addLeds<UCS1903B, C111_ESP_SINGLE_ENDED_6, BRG>(leds, def->offset, def->count);
                case T_UCS1904:                 return FastLED.addLeds<UCS1904, C111_ESP_SINGLE_ENDED_6, BRG>(leds, def->offset, def->count);
                case T_UCS2903:                 return FastLED.addLeds<UCS2903, C111_ESP_SINGLE_ENDED_6, BRG>(leds, def->offset, def->count);
                case T_WS2812:                  return FastLED.addLeds<WS2812, C111_ESP_SINGLE_ENDED_6, BRG>(leds, def->offset, def->count);
                case T_WS2852:                  return FastLED.addLeds<WS2852, C111_ESP_SINGLE_ENDED_6, BRG>(leds, def->offset, def->count);
                case T_WS2812B:                 return FastLED.addLeds<WS2812B, C111_ESP_SINGLE_ENDED_6, BRG>(leds, def->offset, def->count);
                case T_GS1903:                  return FastLED.addLeds<GS1903, C111_ESP_SINGLE_ENDED_6, BRG>(leds, def->offset, def->count);
                case T_SK6812:                  return FastLED.addLeds<SK6812, C111_ESP_SINGLE_ENDED_6, BRG>(leds, def->offset, def->count);
                case T_SK6822:                  return FastLED.addLeds<SK6822, C111_ESP_SINGLE_ENDED_6, BRG>(leds, def->offset, def->count);
                case T_APA106:                  return FastLED.addLeds<APA106, C111_ESP_SINGLE_ENDED_6, BRG>(leds, def->offset, def->count);
                case T_PL9823:                  return FastLED.addLeds<PL9823, C111_ESP_SINGLE_ENDED_6, BRG>(leds, def->offset, def->count);
                case T_WS2811:                  return FastLED.addLeds<WS2811, C111_ESP_SINGLE_ENDED_6, BRG>(leds, def->offset, def->count);
                case T_WS2813:                  return FastLED.addLeds<WS2813, C111_ESP_SINGLE_ENDED_6, BRG>(leds, def->offset, def->count);
                case T_APA104:                  return FastLED.addLeds<APA104, C111_ESP_SINGLE_ENDED_6, BRG>(leds, def->offset, def->count);
                case T_WS2811_400:              return FastLED.addLeds<WS2811_400, C111_ESP_SINGLE_ENDED_6, BRG>(leds, def->offset, def->count);
                case T_GE8822:                  return FastLED.addLeds<GE8822, C111_ESP_SINGLE_ENDED_6, BRG>(leds, def->offset, def->count);
                case T_GW6205:                  return FastLED.addLeds<GW6205, C111_ESP_SINGLE_ENDED_6, BRG>(leds, def->offset, def->count);
                case T_GW6205_400:              return FastLED.addLeds<GW6205_400, C111_ESP_SINGLE_ENDED_6, BRG>(leds, def->offset, def->count);
                case T_LPD1886:                 return FastLED.addLeds<LPD1886, C111_ESP_SINGLE_ENDED_6, BRG>(leds, def->offset, def->count);
                default /*T_LPD1886_8BIT*/:     return FastLED.addLeds<LPD1886_8BIT, C111_ESP_SINGLE_ENDED_6, BRG>(leds, def->offset, def->count);
            }
            #else
            Serial.println("LED_FACTORY_BRG NOT DEFINED");
            #endif
            
        } else if (def->rgbOrder == BGR) {
            #ifdef LED_FACTORY_BGR
            switch (def->pixelType) {
                case T_NEOPIXEL:                return FastLED.addLeds<NEOPIXEL, C111_ESP_SINGLE_ENDED_6>(leds, def->offset, def->count);
                case T_SM16703:                 return FastLED.addLeds<SM16703, C111_ESP_SINGLE_ENDED_6, BGR>(leds, def->offset, def->count);
                case T_TM1829:                  return FastLED.addLeds<TM1829, C111_ESP_SINGLE_ENDED_6, BGR>(leds, def->offset, def->count);
                case T_TM1812:                  return FastLED.addLeds<TM1812, C111_ESP_SINGLE_ENDED_6, BGR>(leds, def->offset, def->count);
                case T_TM1809:                  return FastLED.addLeds<TM1809, C111_ESP_SINGLE_ENDED_6, BGR>(leds, def->offset, def->count);
                case T_TM1804:                  return FastLED.addLeds<TM1804, C111_ESP_SINGLE_ENDED_6, BGR>(leds, def->offset, def->count);
                case T_TM1803:                  return FastLED.addLeds<TM1803, C111_ESP_SINGLE_ENDED_6, BGR>(leds, def->offset, def->count);
                case T_UCS1903:                 return FastLED.addLeds<UCS1903, C111_ESP_SINGLE_ENDED_6, BGR>(leds, def->offset, def->count);
                case T_UCS1903B:                return FastLED.addLeds<UCS1903B, C111_ESP_SINGLE_ENDED_6, BGR>(leds, def->offset, def->count);
                case T_UCS1904:                 return FastLED.addLeds<UCS1904, C111_ESP_SINGLE_ENDED_6, BGR>(leds, def->offset, def->count);
                case T_UCS2903:                 return FastLED.addLeds<UCS2903, C111_ESP_SINGLE_ENDED_6, BGR>(leds, def->offset, def->count);
                case T_WS2812:                  return FastLED.addLeds<WS2812, C111_ESP_SINGLE_ENDED_6, BGR>(leds, def->offset, def->count);
                case T_WS2852:                  return FastLED.addLeds<WS2852, C111_ESP_SINGLE_ENDED_6, BGR>(leds, def->offset, def->count);
                case T_WS2812B:                 return FastLED.addLeds<WS2812B, C111_ESP_SINGLE_ENDED_6, BGR>(leds, def->offset, def->count);
                case T_GS1903:                  return FastLED.addLeds<GS1903, C111_ESP_SINGLE_ENDED_6, BGR>(leds, def->offset, def->count);
                case T_SK6812:                  return FastLED.addLeds<SK6812, C111_ESP_SINGLE_ENDED_6, BGR>(leds, def->offset, def->count);
                case T_SK6822:                  return FastLED.addLeds<SK6822, C111_ESP_SINGLE_ENDED_6, BGR>(leds, def->offset, def->count);
                case T_APA106:                  return FastLED.addLeds<APA106, C111_ESP_SINGLE_ENDED_6, BGR>(leds, def->offset, def->count);
                case T_PL9823:                  return FastLED.addLeds<PL9823, C111_ESP_SINGLE_ENDED_6, BGR>(leds, def->offset, def->count);
                case T_WS2811:                  return FastLED.addLeds<WS2811, C111_ESP_SINGLE_ENDED_6, BGR>(leds, def->offset, def->count);
                case T_WS2813:                  return FastLED.addLeds<WS2813, C111_ESP_SINGLE_ENDED_6, BGR>(leds, def->offset, def->count);
                case T_APA104:                  return FastLED.addLeds<APA104, C111_ESP_SINGLE_ENDED_6, BGR>(leds, def->offset, def->count);
                case T_WS2811_400:              return FastLED.addLeds<WS2811_400, C111_ESP_SINGLE_ENDED_6, BGR>(leds, def->offset, def->count);
                case T_GE8822:                  return FastLED.addLeds<GE8822, C111_ESP_SINGLE_ENDED_6, BGR>(leds, def->offset, def->count);
                case T_GW6205:                  return FastLED.addLeds<GW6205, C111_ESP_SINGLE_ENDED_6, BGR>(leds, def->offset, def->count);
                case T_GW6205_400:              return FastLED.addLeds<GW6205_400, C111_ESP_SINGLE_ENDED_6, BGR>(leds, def->offset, def->count);
                case T_LPD1886:                 return FastLED.addLeds<LPD1886, C111_ESP_SINGLE_ENDED_6, BGR>(leds, def->offset, def->count);
                default /*T_LPD1886_8BIT*/:     return FastLED.addLeds<LPD1886_8BIT, C111_ESP_SINGLE_ENDED_6, BGR>(leds, def->offset, def->count);
            }
            #else
            Serial.println("LED_FACTORY_BGR NOT DEFINED");
            #endif
            
        }
    }
}
