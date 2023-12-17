
#include "LED_GFX.h"

LED_GFX::LED_GFX(LED_Panel* panel):
    Adafruit_GFX(panel->getWidth(), panel->getHeight()),
    panel(panel) {

}

LED_GFX::~LED_GFX() {
    this->panel = nullptr;
}

void LED_GFX::drawPixel(int16_t x, int16_t y, uint16_t color) {
    this->panel->setNonEmptyPixelAt(x, y, fromRgb565(color));
}

