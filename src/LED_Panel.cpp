
#include "LED_Panel.h"

LED_Panel::LED_Panel(LED_PanelConfig* conf):
    id(conf->id),
    name(conf->name),
    width(conf->width),
    height(conf->height),
    leds() {

    this->leds.resize(this->width * this->height, {INVALID_PANEL_ID, UINT16_MAX, 0});
    this->leds.shrink_to_fit();
}

LED_Panel::~LED_Panel() {

}

LED_MappedPixel* LED_Panel::getMappedPixelAt(uint16_t x, uint16_t y) {
    uint16_t index = (y * this->width) + x;
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

LED_MappedPixel* LED_Panel::removeMappedPixelAt(uint16_t x, uint16_t y) {
    auto* mp = this->getMappedPixelAt(x, y);
    if (mp == nullptr) {
        return nullptr;
    }
    mp->stripId = INVALID_STRIP_ID;
    mp->pixelIndex = UINT16_MAX;
    mp->pixel = nullptr;
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

uint8_t LED_Panel::getId() {
    return this->id;
}

const String& LED_Panel::getName() {
    return this->name;
}

uint16_t LED_Panel::getWidth() {
    return this->width;
}

uint16_t LED_Panel::getHeight() {
    return this->height;
}

std::vector<LED_MappedPixel>& LED_Panel::getLeds() {
    return this->leds;
}

void LED_Panel::dumpDebug() {
    Serial.print("Panel size: ");  Serial.print(this->width);  Serial.print("x");  Serial.println(this->height);
    Serial.print("+");
    for (uint16_t x = 0; x < this->width; x++) {
        Serial.print("-");
    }
    Serial.println("+");

    for (uint16_t y = 0; y < this->height; y++) {
        Serial.print("|");
        for (uint16_t x = 0; x < this->width; x++) {
            if (this->getMappedPixelAt(x, y)->stripId == INVALID_STRIP_ID) {
                Serial.print(" ");
            } else {
                Serial.print("X");
            }
        }
        Serial.println("|");
    }

    Serial.print("+");
    for (uint16_t x = 0; x < this->width; x++) {
        Serial.print("-");
    }
    Serial.println("+");
}