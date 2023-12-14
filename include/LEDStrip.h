
#ifndef LED_STRIP_H
#define LED_STRIP_H

#include <Arduino.h>
#include <vector>

typedef uint8_t LEDPixelSegment;

#define SEGMENT_SIZE (sizeof(LEDPixelSegment) * 8)

enum PixelType {
    EMPTY,
    PRESENT
};

class LEDStrip {
public:

    LEDStrip();
    ~LEDStrip();

    bool getPixelAt(uint16_t index);
    void setPixelAt(uint16_t index, PixelType pixelType = PRESENT);
    void appendPixels(uint16_t count, PixelType pixelType = PRESENT);
    void seek(uint16_t index);

    std::vector<LEDPixelSegment>& getPixels();
    LEDPixelSegment* getPixelData();
    uint16_t getPixelCount();

private:
    std::vector<LEDPixelSegment> pixels;
    uint8_t marker;
    uint16_t count;
};




#endif
