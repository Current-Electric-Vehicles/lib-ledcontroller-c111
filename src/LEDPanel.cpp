
#include "LEDPanel.h"

LEDPanel::LEDPanel(uint16_t w, uint16_t h):
    leds(),
    width(w),
    height(h) {

    this->leds.reserve(w * h);
    for (int i = 0; i < (w * h); i++) {
        this->leds.push_back(nullptr);
    }
    this->leds.shrink_to_fit();
}

LEDPanel::~LEDPanel() {

}

CRGB* LEDPanel::getPixelAt(uint16_t x, uint16_t y) {
    uint16_t index = (y * this->width) + x;
    if (index >= this->leds.size()) {
        return nullptr;
    }
    return this->leds[index];
}

bool LEDPanel::setNonEmptyPixelAt(uint16_t x, uint16_t y, CRGB* pixel) {
    uint16_t index = (y * this->width) + x;
    if (index >= this->leds.size()) {
        return false;
    } else if (this->leds[index] == nullptr) {
        return false;
    }
    this->leds[index] = pixel;
    return true;
}

bool LEDPanel::setNonEmptyPixelAt(uint16_t x, uint16_t y, CRGB pixel) {
    uint16_t index = (y * this->width) + x;
    if (index >= this->leds.size()) {
        return false;
    } else if (this->leds[index] == nullptr) {
        return false;
    }
    *this->leds[index] = pixel;
    return true;
}

void LEDPanel::setPixelAt(uint16_t x, uint16_t y, CRGB* pixel) {
    uint16_t index = (y * this->width) + x;
    if (index >= this->leds.size()) {
        return;
    }
    this->leds[index] = pixel;
}

void LEDPanel::setPixelAt(uint16_t x, uint16_t y, CRGB pixel) {
    uint16_t index = (y * this->width) + x;
    if (index >= this->leds.size()) {
        return;
    }
    *this->leds[index] = pixel;
}

uint16_t LEDPanel::getWidth() {
    return this->width;
}

uint16_t LEDPanel::getHeight() {
    return this->height;
}

void LEDPanel::init(LEDStrip& strip, uint16_t stripOffset, StripDirection direction, CRGB* leds, uint16_t ledsOffset) {

    int stripIndex = stripOffset;
    int pixelIndex = ledsOffset;
    auto nextPixel = [&stripIndex, &pixelIndex, &strip, leds]() -> CRGB* {
        CRGB* ret = nullptr;
        if (strip.getPixelAt(stripIndex)) {
            ret = leds + pixelIndex;
            pixelIndex++;
        } else {
        }
        stripIndex++;
        return ret;
    };

    switch (direction) {
        case StripDirection::TOP_TO_BOTTOM__LEFT_TO_RIGHT:
            for (uint16_t x = 0; x < this->width; x++) {
                for (int16_t y = 0; y < this->height; y++) {
                    this->setPixelAt(x, y, nextPixel());
                }
            }
            break;
        case StripDirection::TOP_TO_BOTTOM__RIGHT_TO_LEFT:
            for (uint16_t x = this->width - 1; x >= 0; x--) {
                for (int16_t y = 0; y < this->height; y++) {
                    this->setPixelAt(x, y, nextPixel());
                }
            }
            break;
        case StripDirection::BOTTOM_TO_TOP__LEFT_TO_RIGHT:
            for (uint16_t x = 0; x < this->width; x++) {
                for (int16_t y = this->height - 1; y >= 0; y--) {
                    this->setPixelAt(x, y, nextPixel());
                }
            }
            break;
        case StripDirection::BOTTOM_TO_TOP__RIGHT_TO_LEFT:
            for (int16_t y = this->height - 1; y >= 0; y--) {
                for (uint16_t x = this->width - 1; x >= 0; x--) {
                    this->setPixelAt(x, y, nextPixel());
                }
            }
            break;
        case StripDirection::LEFT_TO_RIGHT__TOP_TO_BOTTOM:
            for (int16_t y = 0; y < this->height; y++) {
                for (uint16_t x = 0; x < this->width; x++) {
                    this->setPixelAt(x, y, nextPixel());
                }
            }
            break;
        case StripDirection::LEFT_TO_RIGHT__BOTTOM_TO_TOP:
            for (int16_t y = this->height; y >= 0; y--) {
                for (uint16_t x = 0; x < this->width; x++) {
                    this->setPixelAt(x, y, nextPixel());
                }
            }
            break;
        case StripDirection::RIGHT_TO_LEFT__TOP_TO_BOTTOM:
            for (int16_t y = 0; y < this->height; y++) {
                for (uint16_t x = this->width; x >= 0; x--) {
                    this->setPixelAt(x, y, nextPixel());
                }
            }
            break;
        case StripDirection::RIGHT_TO_LEFT__BOTTOM_TO_TOP:
            for (int16_t y = this->height; y >= 0; y--) {
                for (uint16_t x = this->width; x >= 0; x--) {
                    this->setPixelAt(x, y, nextPixel());
                }
            }
            break;
    }
}

void LEDPanel::dumpDebug() {
    Serial.print("Panel size: ");  Serial.print(this->width);  Serial.print("x");  Serial.println(this->height);
    Serial.print("+");
    for (uint16_t x = 0; x < this->width; x++) {
        Serial.print("-");
    }
    Serial.println("+");

    for (uint16_t y = 0; y < this->height; y++) {
        Serial.print("|");
        for (uint16_t x = 0; x < this->width; x++) {
            if (this->getPixelAt(x, y) == nullptr) {
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