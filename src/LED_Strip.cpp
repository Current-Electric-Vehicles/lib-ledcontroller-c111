
#include "LED_Strip.h"

#include "LED_Factory.h"

LED_Strip::LED_Strip(LED_StripDefinition& def):
    def(def),
    leds(0) {

    this->leds.resize(this->def.count, 0);
    this->controller = &createController(&this->def, this->leds.data());
}

LED_Strip::~LED_Strip() {
    if (this->controller != nullptr) {
        delete this->controller;
        this->controller = nullptr;
    }
    this->leds.clear();
    this->leds.shrink_to_fit();
}

LED_StripDefinition& LED_Strip::getDefinition() {
    return this->def;
}

CRGB* LED_Strip::getLeds() {
    return this->leds.data();
}

CRGB* LED_Strip::getPixelAt(uint16_t index) {
    return &this->leds[index];
}
