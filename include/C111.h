
#ifndef C111_H
#define C111_H

#include "C111_Pinout.h"
#include <driver/i2c.h>
#include <esp_adc/adc_oneshot.h>

#include <array>
#include <functional>

class C111 {
public:

  C111();
  ~C111() = default;

  bool initialize();

  void setPowerSupplyKeepAliveEnabled(bool enabled);
  bool isPowerSupplyKeepAliveEnabled();
  float getPowerSupplyVoltage();

  void setCanTerminated(bool terminated);
  bool isCanTerminated();

  void setDifferentialDataEnabled(bool enabled);
  bool isDifferentialDataEnabled();

  float getTemperatureCelsius();
  void setOverheatTempCelsius(float temp);
  bool isOverHeated();

  void resetFaultLatch();

  float getPSU1Current();
  float getPSU1TemperatureCelsius();
  void setPSU1Enabled(bool enabled);
  bool isPSU1Enabled();

  float getPSU2Current();
  float getPSU2TemperatureCelsius();
  void setPSU2Enabled(bool enabled);
  bool isPSU2Enabled();

  uint8_t getUserInputState(uint8_t input);

  float getPsuScaleFactor();
  void setPsuScaleFactor(float psuScaleFactor);

  float getPsuOffset();
  void setPsuOffset(float psuOffset);

  float getPowerSupplyScaleFactor();
  void setPowerSupplyScaleFactor(float powerSupplyScaleFactor);

  float getPowerSupplyOffset();
  void setPowerSupplyOffset(float powerSupplyOffset);

  std::array<uint8_t, 8> getUserInputState();

  uint16_t getLineLevelAudio();


private:
  esp_err_t write_i2c(uint8_t device_addr, const uint8_t* data, size_t len);
  esp_err_t read_i2c(uint8_t device_addr, uint8_t* read_data, size_t read_len);

  bool initialized;
  float overheatTempCelsius;
  float psuOffset;
  float psuScaleFactor;
  float powerSupplyOffset;
  float powerSupplyScaleFactor;
  adc_oneshot_unit_handle_t adc1;
};

#endif
