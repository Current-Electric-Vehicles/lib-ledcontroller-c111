
#include "LED_Panel.h"

LED_Panel::LED_Panel(LED_PanelDefinition& def):
    def(def),
    leds() {

    this->leds.resize(def.width * def.height, 0);
    this->leds.shrink_to_fit();
}

LED_Panel::~LED_Panel() {

}

LED_PanelDefinition& LED_Panel::getDefinition() {
    return this->def;
}

CRGB* LED_Panel::getMappedPixelAt(uint16_t x, uint16_t y) {
    uint16_t index = (y * this->def.width) + x;
    if (index >= this->leds.size()) {
        return nullptr;
    }
    return this->leds[index];
}

void LED_Panel::mapPixelAt(uint16_t x, uint16_t y, CRGB* pixel) {
    uint16_t index = (y * this->def.width) + x;
    if (index >= this->leds.size()) {
        return;
    }
    this->leds[index] = pixel;
}

void LED_Panel::setPixelAt(uint16_t x, uint16_t y, CRGB* pixel) {
    uint16_t index = (y * this->def.width) + x;
    if (index >= this->leds.size()) {
        return;
    }
    *this->leds[index] = *pixel;
}

void LED_Panel::setPixelAt(uint16_t x, uint16_t y, CRGB pixel) {
    uint16_t index = (y * this->def.width) + x;
    if (index >= this->leds.size()) {
        return;
    }
    *this->leds[index] = pixel;
}

bool LED_Panel::setNonEmptyPixelAt(uint16_t x, uint16_t y, CRGB* pixel) {
    uint16_t index = (y * this->def.width) + x;
    if (index >= this->leds.size()) {
        return false;
    } else if (this->leds[index] == nullptr) {
        return false;
    }
    *this->leds[index] = *pixel;
    return true;
}

bool LED_Panel::setNonEmptyPixelAt(uint16_t x, uint16_t y, CRGB pixel) {
    uint16_t index = (y * this->def.width) + x;
    if (index >= this->leds.size()) {
        return false;
    } else if (this->leds[index] == nullptr) {
        return false;
    }
    *this->leds[index] = pixel;
    return true;
}

uint16_t LED_Panel::getWidth() {
    return this->def.width;
}

uint16_t LED_Panel::getHeight() {
    return this->def.height;
}

void LED_Panel::dumpDebug() {
    Serial.print("Panel size: ");  Serial.print(this->def.width);  Serial.print("x");  Serial.println(this->def.height);
    Serial.print("+");
    for (uint16_t x = 0; x < this->def.width; x++) {
        Serial.print("-");
    }
    Serial.println("+");

    for (uint16_t y = 0; y < this->def.height; y++) {
        Serial.print("|");
        for (uint16_t x = 0; x < this->def.width; x++) {
            if (this->getMappedPixelAt(x, y) == nullptr) {
                Serial.print(" ");
            } else {
                Serial.print("X");
            }
        }
        Serial.println("|");
    }

    Serial.print("+");
    for (uint16_t x = 0; x < this->def.width; x++) {
        Serial.print("-");
    }
    Serial.println("+");
}