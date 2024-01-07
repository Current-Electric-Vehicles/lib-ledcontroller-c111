
#include "C111.h"

C111::C111():
    wire(0),
    tempSensor(wire, C111_TEMP_SENSOR_I2C_ADDRESS),
    initialized(false),
    overheatTempCelcius(C111_OVERHEATED_TEMP_CELCIUS) {

}

C111::~C111() {

}

void C111::initialize() {

    // inputs
    pinMode(C111_ESP_USER_INPUT_1, INPUT);
    pinMode(C111_ESP_USER_INPUT_2, INPUT);
    pinMode(C111_ESP_USER_INPUT_3, INPUT);
    pinMode(C111_ESP_USER_INPUT_4, INPUT);
    pinMode(C111_ESP_USER_INPUT_5, INPUT);
    pinMode(C111_ESP_USER_INPUT_6, INPUT);
    pinMode(C111_ESP_USER_INPUT_7, INPUT);
    pinMode(C111_ESP_USER_INPUT_8, INPUT);

    // highside switch monitor selection
    pinMode(C111_ESP_HIGHSIDESWITCH_CHANNEL_1_ENABLE, OUTPUT);
    pinMode(C111_ESP_HIGHSIDESWITCH_CHANNEL_2_ENABLE, OUTPUT);

    // can terminator
    pinMode(C111_ESP_CAN_TERMINATION_SWITCH, OUTPUT);

    // data line configuration
    pinMode(C111_ESP_DIFF_OR_SE_SWITCH, OUTPUT);
    pinMode(C111_ESP_DIFF_1_OR_SINGLE_ENDED_1, OUTPUT);
    pinMode(C111_ESP_DIFF_2_OR_SINGLE_ENDED_2, OUTPUT);
    pinMode(C111_ESP_SINGLE_ENDED_3, OUTPUT);
    pinMode(C111_ESP_SINGLE_ENDED_4, OUTPUT);
    pinMode(C111_ESP_SINGLE_ENDED_5, OUTPUT);
    pinMode(C111_ESP_SINGLE_ENDED_6, OUTPUT);

    // set defaults
    this->setCanTerminated(false);
    this->setOverheatTempCelcius(C111_OVERHEATED_TEMP_CELCIUS);
}

void C111::setCanTerminated(bool terminated) {
    digitalWrite(C111_ESP_CAN_TERMINATION_SWITCH, terminated ? HIGH : LOW);
}

bool C111::isCanTerminated() {
    return digitalRead(C111_ESP_CAN_TERMINATION_SWITCH) == HIGH;
}

void C111::setDifferentialDataEnabled(bool enabled) {
    digitalWrite(C111_ESP_DIFF_OR_SE_SWITCH, enabled ? HIGH : LOW);
}

bool C111::isDifferentialDataEnabled() {
    return digitalRead(C111_ESP_DIFF_OR_SE_SWITCH) == LOW;
}

float C111::getTemperatureCelcius() {
    tempSensor.setConversionTime(TMP1075::ConversionTime220ms);
    return this->tempSensor.getTemperatureCelsius();
}

float C111::getPSUCurrent(uint8_t sensor) {

    if (sensor == C111_SENSOR_PSU1_CURRENT) {
        digitalWrite(C111_ESP_HIGHSIDESWITCH_DIAGNOSTICS_SELECT_2, LOW);
    } else if (sensor == C111_SENSOR_PSU2_CURRENT) {
        digitalWrite(C111_ESP_HIGHSIDESWITCH_DIAGNOSTICS_SELECT_2, HIGH);
    } else {
        return 0.0f;
    }

    analogReadResolution(12);
    float ret = (C111_ADC_RESOLUTION * (float)analogRead(C111_ESP_HIGHSIDESWITCH_DIAGNOSTICS_MONITOR)) * C111_ADC_SCALE_FACTOR;
    ret *= 2.0f;
    return ret;
}

void C111::setOverheatTempCelcius(float temp) {
    this->overheatTempCelcius = temp;
}

bool C111::isOverHeated() {
    return this->getTemperatureCelcius() >= this->overheatTempCelcius;
}

void C111::setPSU1Enabled(bool enabled) {
    digitalWrite(C111_ESP_HIGHSIDESWITCH_CHANNEL_1_ENABLE, enabled ? HIGH : LOW);
}

bool C111::isPSU1Enabled() {
    return digitalRead(C111_ESP_HIGHSIDESWITCH_CHANNEL_1_ENABLE) == HIGH;
}

void C111::setPSU2Enabled(bool enabled) {
    digitalWrite(C111_ESP_HIGHSIDESWITCH_CHANNEL_2_ENABLE, enabled ? HIGH : LOW);
}

bool C111::isPSU2Enabled() {
    return digitalRead(C111_ESP_HIGHSIDESWITCH_CHANNEL_2_ENABLE) == HIGH;
}

uint8_t C111::getUserInputState(uint8_t input) {
    switch (input) {
        case C111_USER_INPUT_1: return digitalRead(C111_ESP_USER_INPUT_1);
        case C111_USER_INPUT_2: return digitalRead(C111_ESP_USER_INPUT_2);
        case C111_USER_INPUT_3: return digitalRead(C111_ESP_USER_INPUT_3);
        case C111_USER_INPUT_4: return digitalRead(C111_ESP_USER_INPUT_4);
        case C111_USER_INPUT_5: return digitalRead(C111_ESP_USER_INPUT_5);
        case C111_USER_INPUT_6: return digitalRead(C111_ESP_USER_INPUT_6);
        case C111_USER_INPUT_7: return digitalRead(C111_ESP_USER_INPUT_7);
        case C111_USER_INPUT_8: return digitalRead(C111_ESP_USER_INPUT_8);
        default: return false;
    }
}

void C111::attachInputInterrupt(uint8_t input, uint8_t mode, void (*userFunc)(void)) {
    switch (input) {
        case C111_USER_INPUT_1: attachInterrupt(digitalPinToInterrupt(C111_ESP_USER_INPUT_1), userFunc, mode); return;
        case C111_USER_INPUT_2: attachInterrupt(digitalPinToInterrupt(C111_ESP_USER_INPUT_2), userFunc, mode); return;
        case C111_USER_INPUT_3: attachInterrupt(digitalPinToInterrupt(C111_ESP_USER_INPUT_3), userFunc, mode); return;
        case C111_USER_INPUT_4: attachInterrupt(digitalPinToInterrupt(C111_ESP_USER_INPUT_4), userFunc, mode); return;
        case C111_USER_INPUT_5: attachInterrupt(digitalPinToInterrupt(C111_ESP_USER_INPUT_5), userFunc, mode); return;
        case C111_USER_INPUT_6: attachInterrupt(digitalPinToInterrupt(C111_ESP_USER_INPUT_6), userFunc, mode); return;
        case C111_USER_INPUT_7: attachInterrupt(digitalPinToInterrupt(C111_ESP_USER_INPUT_7), userFunc, mode); return;
        case C111_USER_INPUT_8: attachInterrupt(digitalPinToInterrupt(C111_ESP_USER_INPUT_8), userFunc, mode); return;
    }
}
