
#include "LED_Strip.h"

LED_Strip::LED_Strip(LED_StripDefinition& def):
    def(def),
    leds(0) {

}

LED_Strip::~LED_Strip() {
    this->deInit();
}

void LED_Strip::init() {
    if (this->controller != nullptr) {
        return;
    }
    this->leds.resize(this->def.count, 0);
    this->controller = &createController(&this->def, this->leds.data());
}

void LED_Strip::deInit() {
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
    if (!this->leds.size() == this->def.count) {
        return nullptr;
    }
    return this->leds.data();
}
