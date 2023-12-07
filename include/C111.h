
#ifndef C111_H
#define C111_H

#include "C111_Pinout.h"

#include <Wire.h>
#include <TMP1075.h>

class C111 {
public:

    C111();
    ~C111();

    void initialize();

    void setCanTerminated(bool terminated);
    bool isCanTerminated();

    void setDifferentialDataEnabled(bool enabled);
    bool isDifferentialDataEnabled();

    float getPSUCurrent(uint8_t sensor);

    float getTemperatureCelcius();
    void setOverheatTempCelcius(float temp);
    bool isOverHeated();

    void enablePSU1(bool enabled);
    bool isPSU1Enabled();

    void enablePSU2(bool enabled);
    bool isPSU2Enabled();

    uint8_t getUserInputState(uint8_t input);
    void attachInputInterrupt(uint8_t input, uint8_t mode, void (*userFunc)(void));

private:
    TwoWire wire;
    TMP1075::TMP1075 tempSensor;
    bool initialized;
    float overheatTempCelcius;
};

#endif
