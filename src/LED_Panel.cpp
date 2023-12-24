
#include "LED_Panel.h"

LED_Panel::LED_Panel(LED_PanelDefinition& def):
    id(UINT8_MAX),
    def(def),
    leds() {

    this->leds.resize(def.width * def.height, {INVALID_PANEL_ID, UINT16_MAX, 0});
    this->leds.shrink_to_fit();
}

LED_Panel::~LED_Panel() {

}

LED_PanelDefinition& LED_Panel::getDefinition() {
    return this->def;
}

uint8_t LED_Panel::getId() {
    return this->id;
}

void LED_Panel::setId(uint8_t id) {
    this->id = id;
}

LED_MappedPixel* LED_Panel::getMappedPixelAt(uint16_t x, uint16_t y) {
    uint16_t index = (y * this->def.width) + x;
    if (index >= this->leds.size()) {
        return nullptr;
    }
    return &this->leds[index];
}

LED_MappedPixel* LED_Panel::mapPixelAt(uint16_t x, uint16_t y, LED_Strip* strip, uint16_t pixelIndex) {
    auto* mp = this->getMappedPixelAt(x, y);
    if (mp == nullptr) {
        return nullptr;
    }
    mp->stripId = strip->getId();
    mp->pixelIndex = pixelIndex;
    mp->pixel = strip->getPixelAt(pixelIndex);
    return mp;
}

void LED_Panel::setPixelAt(uint16_t x, uint16_t y, CRGB* pixel) {
    auto* mp = this->getMappedPixelAt(x, y);
    if (mp == nullptr) {
        return;
    }
    *mp->pixel = *pixel;
}

void LED_Panel::setPixelAt(uint16_t x, uint16_t y, CRGB pixel) {
    auto* mp = this->getMappedPixelAt(x, y);
    if (mp == nullptr) {
        return;
    }
    *mp->pixel = pixel;
}

bool LED_Panel::setNonEmptyPixelAt(uint16_t x, uint16_t y, CRGB* pixel) {
    auto* mp = this->getMappedPixelAt(x, y);
    if (mp == nullptr) {
        return false;
    } else if (mp->stripId == INVALID_STRIP_ID) {
        return false;
    }
    *mp->pixel = *pixel;
    return true;
}

bool LED_Panel::setNonEmptyPixelAt(uint16_t x, uint16_t y, CRGB pixel) {
    auto* mp = this->getMappedPixelAt(x, y);
    if (mp == nullptr) {
        return false;
    } else if (mp->stripId == INVALID_STRIP_ID) {
        return false;
    }
    *mp->pixel = pixel;
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
            if (this->getMappedPixelAt(x, y)->stripId == INVALID_STRIP_ID) {
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