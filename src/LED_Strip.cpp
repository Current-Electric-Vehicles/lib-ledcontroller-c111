
#include "LED_Strip.h"

#include "LED_Factory.h"

LED_Strip::LED_Strip(LED_StripDefinition& def):
    id(UINT8_MAX),
    def(def),
    leds(0) {

    this->leds.resize(this->def.count, 0);
    this->controller = createController(this->def.pin, this->def.rgbOrder, this->def.pixelType, this->def.offset, this->def.count, this->leds.data());
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

uint8_t LED_Strip::getId() {
    return this->id;
}

void LED_Strip::setId(uint8_t id) {
    this->id = id;
}

CRGB* LED_Strip::getLeds() {
    return this->leds.data();
}

CRGB* LED_Strip::getPixelAt(uint16_t index) {
    return &this->leds[index];
}
