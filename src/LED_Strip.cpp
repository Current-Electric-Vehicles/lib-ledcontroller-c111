
#include "LED_Strip.h"

#include "LED_Factory.h"

LED_Strip::LED_Strip(LED_StripConfig* conf):
    id(conf->id),
    name(conf->name),
    pixelType(conf->pixelType),
    pin(conf->pin),
    rgbOrder(conf->rgbOrder),
    leds(0) {

    this->leds.resize(conf->count, 0);
    this->controller = createController(this->pin, this->rgbOrder, this->pixelType, 0, conf->count, this->leds.data());
}

LED_Strip::~LED_Strip() {
    if (this->controller != nullptr) {
        this->controller->setLeds(nullptr, 0);
        this->controller = nullptr;
    }
    this->leds.clear();
    this->leds.shrink_to_fit();
}

uint8_t LED_Strip::getId() {
    return this->id;
}

const String& LED_Strip::getName() {
    return this->name;
}

PixelType LED_Strip::getPixelType() {
    return this->pixelType;
}

uint8_t LED_Strip::getPin() {
    return this->pin;
}

EOrder LED_Strip::getRgbOrder() {
    return this->rgbOrder;
}

uint16_t LED_Strip::getCount() {
    return this->leds.size();
}

CRGB* LED_Strip::getLeds() {
    return this->leds.data();
}

CRGB* LED_Strip::getPixelAt(uint16_t index) {
    return &this->leds[index];
}
