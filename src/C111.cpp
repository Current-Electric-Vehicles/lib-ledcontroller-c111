
#include "C111.h"

#include <driver/adc.h>

static float convertADCToTemperature(int adcValue) {

    float resistance    = 1000.0f;
    float voltage       = (float)adcValue * (3.3f / 4096.0f);
    float amps          = voltage / resistance;
    float milliAmps     = amps * 1000.0f;

    // milliAmps = ISNST
    return ((milliAmps - 0.85) / 0.011) + 25.0f;
}

static float convertADCToCurrent(int adcValue, float scaleFactor) {
    float resistance    = 1000.0f;
    float voltage       = (float)adcValue * (3.3f / 4096.0f);
    float amps          = voltage / resistance;
    // float milliAmps     = amps * 1000.0f;

    // milliAmps = ISNSI
    return amps * scaleFactor;
}

inline int readADCValue(int adcPin) {
    adcAttachPin(adcPin);
    analogReadResolution(12);
    return analogRead(adcPin);
}

C111::C111():
    wire(0),
    tempSensor(wire, C111_TEMP_SENSOR_I2C_ADDRESS),
    ioExpander(C111_IO_EXPANDER_I2C_ADDRESS, &wire),
    initialized(false),
    overheatTempCelcius(C111_OVERHEATED_TEMP_CELCIUS) {

}

C111::~C111() {

}

bool C111::initialize() {

    wire.setPins(C111_ESP_I2C_SDA, C111_ESP_I2C_SCL);
    if (!wire.begin(C111_ESP_I2C_SDA, C111_ESP_I2C_SCL)) {
        Serial.println("Unable to initialize I2C");
        return false;
    }

    if (!ioExpander.begin()) {
        Serial.println("Unable to initialize IO expander");
        return false;
    }

    adc1_config_width(ADC_WIDTH_BIT_12);
    adc1_config_channel_atten(ADC1_CHANNEL_6, ADC_ATTEN_DB_11);

    // inputs
    ioExpander.pinMode8(0xFF);
    ioExpander.setPullup8(0x00);

    // analog
    pinMode(C111_ESP_LINE_LEVEL_AUDIO_INPUT, ANALOG);
    pinMode(C111_ESP_12V_VOLTAGE_MONITOR, ANALOG);
    pinMode(C111_ESP_HIGHSIDESWITCH_DIAGNOSTICS_MONITOR, ANALOG);
    
    // highside switch monitor selection
    pinMode(C111_ESP_HIGHSIDESWITCH_CHANNEL_1_ENABLE, OUTPUT);
    pinMode(C111_ESP_HIGHSIDESWITCH_CHANNEL_2_ENABLE, OUTPUT);
    pinMode(C111_ESP_HIGHSIDESWITCH_DIAGNOSTICS_SELECT_1, OUTPUT);
    pinMode(C111_ESP_HIGHSIDESWITCH_DIAGNOSTICS_SELECT_2, OUTPUT);

    // power supply
    pinMode(C111_ESP_POWER_SUPPLY_KEEP_ALIVE, OUTPUT);

    // can terminator
    pinMode(C111_ESP_CAN_TERMINATION_SWITCH, OUTPUT);

    // data line configuration
    pinMode(C111_ESP_DIFF_OR_SE_SWITCH, OUTPUT);
    pinMode(C111_ESP_DATA_1, OUTPUT);
    pinMode(C111_ESP_DATA_2, OUTPUT);
    pinMode(C111_ESP_DATA_3, OUTPUT);
    pinMode(C111_ESP_DATA_4, OUTPUT);
    pinMode(C111_ESP_DATA_5, OUTPUT);
    pinMode(C111_ESP_DATA_6, OUTPUT);

    // set defaults
    this->setCanTerminated(false);
    this->setOverheatTempCelcius(C111_OVERHEATED_TEMP_CELCIUS);
    this->setPowerSupplyKeepAliveEnabled(true);

    return true;
}

void C111::setPowerSupplyKeepAliveEnabled(bool enabled) {
    digitalWrite(C111_ESP_POWER_SUPPLY_KEEP_ALIVE, enabled ? HIGH : LOW);
}

bool C111::isPowerSupplyKeepAliveEnabled() {
    return digitalRead(C111_ESP_POWER_SUPPLY_KEEP_ALIVE) == HIGH;
}

float C111::getPowerSupplyVoltage() {
    int reading = adc1_get_raw(ADC1_CHANNEL_6);
    return 1.0f + ((((float)reading * 0.98) * C111_ADC_RESOLUTION) * 9.708);
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

float C111::getPSU1Current() {
    digitalWrite(C111_ESP_HIGHSIDESWITCH_DIAGNOSTICS_SELECT_1, LOW);
    digitalWrite(C111_ESP_HIGHSIDESWITCH_DIAGNOSTICS_SELECT_2, LOW);
    auto reading = readADCValue(C111_ESP_HIGHSIDESWITCH_DIAGNOSTICS_MONITOR);
    return convertADCToCurrent(reading, this->psuScaleFactor);
}

float C111::getPSU1TemperatureCelcius() {
    digitalWrite(C111_ESP_HIGHSIDESWITCH_DIAGNOSTICS_SELECT_1, HIGH);
    digitalWrite(C111_ESP_HIGHSIDESWITCH_DIAGNOSTICS_SELECT_2, LOW);
    auto reading = readADCValue(C111_ESP_HIGHSIDESWITCH_DIAGNOSTICS_MONITOR);
    return convertADCToTemperature(reading);
}

float C111::getPSU2Current() {
    digitalWrite(C111_ESP_HIGHSIDESWITCH_DIAGNOSTICS_SELECT_1, LOW);
    digitalWrite(C111_ESP_HIGHSIDESWITCH_DIAGNOSTICS_SELECT_2, HIGH);
    auto reading = readADCValue(C111_ESP_HIGHSIDESWITCH_DIAGNOSTICS_MONITOR);
    return convertADCToCurrent(reading, this->psuScaleFactor);
}

float C111::getPSU2TemperatureCelcius() {
    return this->getPSU1TemperatureCelcius();
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
        case C111_USER_INPUT_1: return ioExpander.read1(C111_IO_EXPANDER_INPUT_1);
        case C111_USER_INPUT_2: return ioExpander.read1(C111_IO_EXPANDER_INPUT_2);
        case C111_USER_INPUT_3: return ioExpander.read1(C111_IO_EXPANDER_INPUT_3);
        case C111_USER_INPUT_4: return ioExpander.read1(C111_IO_EXPANDER_INPUT_4);
        case C111_USER_INPUT_5: return ioExpander.read1(C111_IO_EXPANDER_INPUT_5);
        case C111_USER_INPUT_6: return ioExpander.read1(C111_IO_EXPANDER_INPUT_6);
        case C111_USER_INPUT_7: return ioExpander.read1(C111_IO_EXPANDER_INPUT_7);
        case C111_USER_INPUT_8: return ioExpander.read1(C111_IO_EXPANDER_INPUT_8);
        default: return false;
    }
}

std::array<uint8_t, 8> C111::getUserInputState() {
    int value = ioExpander.read8();
    return {
        (uint8_t)(value & (1 << C111_IO_EXPANDER_INPUT_1) ? HIGH : LOW),
        (uint8_t)(value & (1 << C111_IO_EXPANDER_INPUT_2) ? HIGH : LOW),
        (uint8_t)(value & (1 << C111_IO_EXPANDER_INPUT_3) ? HIGH : LOW),
        (uint8_t)(value & (1 << C111_IO_EXPANDER_INPUT_4) ? HIGH : LOW),
        (uint8_t)(value & (1 << C111_IO_EXPANDER_INPUT_5) ? HIGH : LOW),
        (uint8_t)(value & (1 << C111_IO_EXPANDER_INPUT_6) ? HIGH : LOW),
        (uint8_t)(value & (1 << C111_IO_EXPANDER_INPUT_7) ? HIGH : LOW),
        (uint8_t)(value & (1 << C111_IO_EXPANDER_INPUT_8) ? HIGH : LOW),
    };
}

uint16_t C111::getLineLevelAudio() {
    return adc1_get_raw(ADC1_CHANNEL_6);
}

float C111::getPsuScaleFactor() {
    return this->psuScaleFactor;
}

void C111::setPsuScaleFactor(float psuScaleFactor) {
    this->psuScaleFactor = psuScaleFactor;
}