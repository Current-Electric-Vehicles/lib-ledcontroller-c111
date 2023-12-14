
#include "LEDStrip.h"

LEDStrip::LEDStrip():
    pixels(),
    marker(0),
    count(0) {

}

LEDStrip::~LEDStrip() {

}

void LEDStrip::appendPixels(uint16_t count, PixelType pixelType) {
    for (uint16_t i = 0; i < count; i++) {
        this->setPixelAt(this->marker, pixelType);
        this->marker++;
    }
}

void LEDStrip::seek(uint16_t index) {
    this->marker = index;
}

bool LEDStrip::getPixelAt(uint16_t index) {
    if (index >= this->count) {
        return false;
    }
    uint16_t segment = index / SEGMENT_SIZE;
    uint16_t bitIndex = index % SEGMENT_SIZE;
    return bitRead(this->pixels[segment], bitIndex) == 1;
}

void LEDStrip::setPixelAt(uint16_t index, PixelType pixelType) {
    while (index >= (this->pixels.size() * SEGMENT_SIZE)) {
        this->pixels.push_back((LEDPixelSegment)0);
    }
    uint16_t segment = index / SEGMENT_SIZE;
    uint16_t bitIndex = index % SEGMENT_SIZE;
    if (pixelType == PixelType::EMPTY) {
        this->pixels[segment] = bitClear(this->pixels[segment], bitIndex);
    } else {
        this->pixels[segment] = bitSet(this->pixels[segment], bitIndex);
    }
    if (index >= this->count) {
        this->count = index + 1;
    }
}

std::vector<LEDPixelSegment>& LEDStrip::getPixels() {
    return this->pixels;
}

LEDPixelSegment* LEDStrip::getPixelData() {
    return this->pixels.data();
}

uint16_t LEDStrip::getPixelCount() {
    return this->count;
}
