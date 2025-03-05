
#include "C111.h"

#include <esp_log.h>
#include <esp_adc/adc_oneshot.h>
#include <driver/gpio.h>
#include <driver/i2c.h>
#include <freertos/FreeRTOS.h>
#include <cstring>

#define TAG ((const char*)("C111"))

//  Registers                           //  description              datasheet P9
#define MCP23x08_DDR_A          0x00    //  Data Direction Register A   P 10
#define MCP23x08_POL_A          0x01    //  Input Polarity A            P 11
#define MCP23x08_GPINTEN_A      0x02    //  NOT USED interrupt enable   P 12
#define MCP23x08_DEFVAL_A       0x03    //  NOT USED interrupt def      P 13
#define MCP23x08_INTCON_A       0x04    //  NOT USED interrupt control  P 14
#define MCP23x08_IOCR           0x05    //  IO control register         P 15
#define MCP23x08_PUR_A          0x06    //  Pull Up Resistors A         P 16
#define MCP23x08_INTF_A         0x07    //  NOT USED interrupt flag     P 17
#define MCP23x08_INTCAP_A       0x08    //  NOT USED interrupt capture  P 18
#define MCP23x08_GPIO_A         0x09    //  General Purpose IO A        P 19
#define MCP23x08_OLAT_A         0x0A    //  NOT USED output latch       P 20
#define MCP23x08_IOCR_SEQOP     0x20    //  Sequential Operation mode bit.
#define MCP23x08_IOCR_DISSLW    0x10    //  Slew Rate control bit for SDA output.
#define MCP23x08_IOCR_HAEN      0x08    //  Hardware Address Enable bit (MCP23S17 only).
#define MCP23x08_IOCR_ODR       0x04    //  Configures the INT pin as an open-drain output.
#define MCP23x08_IOCR_INTPOL    0x02    //  This bit sets the polarity of the INT output pin.
#define MCP23x08_IOCR_NI        0x01    //  Not implemented.

static float convertADCToTemperature(int adcValue) {

  float resistance = 1000.0f;
  float voltage = (float) adcValue * (3.3f / 4096.0f);
  float amps = voltage / resistance;
  float milliAmps = amps * 1000.0f;

  // milliAmps = ISNST
  return ((milliAmps - 0.85f) / 0.011f) + 25.0f;
}

static float convertADCToCurrent(int adcValue, float scaleFactor, float offset) {
  return ((static_cast<float>(adcValue) - offset) * scaleFactor);
}

C111::C111() :
  initialized(false),
  overheatTempCelsius(C111_OVERHEATED_TEMP_CELSIUS),
  psuOffset(0),
  psuScaleFactor(0),
  powerSupplyOffset(0),
  powerSupplyScaleFactor(0) {

}

bool C111::initialize() {

  i2c_config_t i2c_config;
  std::memset(&i2c_config, 0, sizeof(i2c_config));

  i2c_config.mode = I2C_MODE_MASTER;
  i2c_config.sda_io_num = C111_ESP_I2C_SDA;
  i2c_config.scl_io_num = C111_ESP_I2C_SCL;
  i2c_config.sda_pullup_en = GPIO_PULLUP_ENABLE;
  i2c_config.scl_pullup_en = GPIO_PULLUP_ENABLE;
  i2c_config.master.clk_speed = 100000;

  ESP_ERROR_CHECK(i2c_param_config(I2C_NUM_0, &i2c_config));
  ESP_ERROR_CHECK(i2c_driver_install(I2C_NUM_0, I2C_MODE_MASTER, 0, 0, 0));

  std::array<uint8_t, 3> i2cBuffer{};

  i2cBuffer = {0x01, 0x1f, 0xff};
  ESP_ERROR_CHECK(this->write_i2c(
      C111_TEMP_SENSOR_I2C_ADDRESS,
      i2cBuffer.data(), 3));

  // pin mode 8
  i2cBuffer = {MCP23x08_DDR_A, 0xFF};
  ESP_ERROR_CHECK(this->write_i2c(
      C111_IO_EXPANDER_I2C_ADDRESS,
      i2cBuffer.data(), 2));

  // pullup 8
  i2cBuffer = {MCP23x08_PUR_A, 0x00};
  ESP_ERROR_CHECK(this->write_i2c(
      C111_IO_EXPANDER_I2C_ADDRESS,
      i2cBuffer.data(), 2));

  adc_oneshot_unit_init_cfg_t adc1Config = {
      .unit_id = ADC_UNIT_1,
      .clk_src = ADC_RTC_CLK_SRC_DEFAULT,
      .ulp_mode = ADC_ULP_MODE_DISABLE
  };
  ESP_ERROR_CHECK(adc_oneshot_new_unit(&adc1Config, &this->adc1));

  adc_oneshot_chan_cfg_t oneShotConfig = {
      .atten = ADC_ATTEN_DB_12,
      .bitwidth = ADC_BITWIDTH_12
  };
  ESP_ERROR_CHECK(adc_oneshot_config_channel(adc1, C111_ESP_12V_VOLTAGE_MONITOR_ADC_CHANNEL, &oneShotConfig));
  ESP_ERROR_CHECK(adc_oneshot_config_channel(adc1, C111_ESP_HIGHSIDESWITCH_DIAGNOSTICS_MONITOR_ADC_CHANNEL, &oneShotConfig));
  ESP_ERROR_CHECK(adc_oneshot_config_channel(adc1, C111_ESP_LINE_LEVEL_AUDIO_INPUT_ADC_CHANNEL, &oneShotConfig));

  // highside switch monitor selection
  gpio_set_direction(C111_ESP_HIGHSIDESWITCH_CHANNEL_1_ENABLE, GPIO_MODE_OUTPUT);
  gpio_set_direction(C111_ESP_HIGHSIDESWITCH_CHANNEL_2_ENABLE, GPIO_MODE_OUTPUT);

  gpio_set_direction(C111_ESP_HIGHSIDESWITCH_DIAGNOSTICS_SELECT_1, GPIO_MODE_OUTPUT);
  gpio_set_direction(C111_ESP_HIGHSIDESWITCH_DIAGNOSTICS_SELECT_2, GPIO_MODE_OUTPUT);

  // highside fault latch
  //gpio_set_direction(C111_ESP_HIGHSIDESWITCH_FAULT_LATCH, GPIO_MODE_OUTPUT);
  //gpio_set_level(C111_ESP_HIGHSIDESWITCH_FAULT_LATCH, 1);

  // power supply
  gpio_set_direction(C111_ESP_POWER_SUPPLY_KEEP_ALIVE, GPIO_MODE_OUTPUT);

  // can terminator
  gpio_set_direction(C111_ESP_CAN_TERMINATION_SWITCH, GPIO_MODE_OUTPUT);

  // data line configuration
  gpio_set_direction(C111_ESP_DIFF_OR_SE_SWITCH, GPIO_MODE_OUTPUT);
  gpio_set_direction(C111_ESP_DATA_1, GPIO_MODE_OUTPUT);
  gpio_set_direction(C111_ESP_DATA_2, GPIO_MODE_OUTPUT);
  gpio_set_direction(C111_ESP_DATA_3, GPIO_MODE_OUTPUT);
  gpio_set_direction(C111_ESP_DATA_4, GPIO_MODE_OUTPUT);
  gpio_set_direction(C111_ESP_DATA_5, GPIO_MODE_OUTPUT);
  gpio_set_direction(C111_ESP_DATA_6, GPIO_MODE_OUTPUT);

  // set defaults
  this->setPSU1Enabled(false);
  this->setPSU2Enabled(false);
  this->setPowerSupplyScaleFactor(0.007843);
  this->setPowerSupplyOffset(-196);
  this->setPsuScaleFactor(0.0016722);
  this->setPsuOffset(-169);
  this->setCanTerminated(false);
  this->setOverheatTempCelsius(C111_OVERHEATED_TEMP_CELSIUS);
  this->setPowerSupplyKeepAliveEnabled(true);

  return true;
}


esp_err_t C111::write_i2c(uint8_t device_addr, const uint8_t* data, size_t len) {
  return i2c_master_write_to_device(I2C_NUM_0, device_addr, data, len, pdMS_TO_TICKS(1000));
}

esp_err_t C111::read_i2c(uint8_t device_addr, uint8_t* read_data, size_t read_len) {
  return i2c_master_read_from_device(I2C_NUM_0, device_addr, read_data, read_len, pdMS_TO_TICKS(1000));
}

void C111::resetFaultLatch() {
  //gpio_set_level(C111_ESP_HIGHSIDESWITCH_FAULT_LATCH, 0);
  //vTaskDelay(50);
  //gpio_set_level(C111_ESP_HIGHSIDESWITCH_FAULT_LATCH, 1);
}

void C111::setPowerSupplyKeepAliveEnabled(bool enabled) {
  gpio_set_level(C111_ESP_POWER_SUPPLY_KEEP_ALIVE, enabled ? 1 : 0);
}

bool C111::isPowerSupplyKeepAliveEnabled() {
  return gpio_get_level(C111_ESP_POWER_SUPPLY_KEEP_ALIVE) == 1;
}

float C111::getPowerSupplyVoltage() {
  int reading;
  ESP_ERROR_CHECK(adc_oneshot_read(this->adc1, C111_ESP_12V_VOLTAGE_MONITOR_ADC_CHANNEL, &reading));
  return ((reading - this->powerSupplyOffset) * this->powerSupplyScaleFactor);
}

void C111::setCanTerminated(bool terminated) {
  gpio_set_level(C111_ESP_CAN_TERMINATION_SWITCH, terminated ? 1 : 0);
}

bool C111::isCanTerminated() {
  return gpio_get_level(C111_ESP_CAN_TERMINATION_SWITCH) == 1;
}

void C111::setDifferentialDataEnabled(bool enabled) {
  gpio_set_level(C111_ESP_DIFF_OR_SE_SWITCH, enabled ? 1 : 0);
}

bool C111::isDifferentialDataEnabled() {
  return gpio_get_level(C111_ESP_DIFF_OR_SE_SWITCH) == 0;
}

float C111::getTemperatureCelsius() {

  uint16_t result;
  std::array<uint8_t, 3> outBuff = {0x01, 0x00};

  ESP_ERROR_CHECK(this->write_i2c(
      C111_TEMP_SENSOR_I2C_ADDRESS,
      outBuff.data(), outBuff.size()));

  ESP_ERROR_CHECK(this->read_i2c(
      C111_TEMP_SENSOR_I2C_ADDRESS,
      reinterpret_cast<uint8_t*>(&result), 2));

  return 0.0625f * float(result) / 16;
}

float C111::getPSU1Current() {
  if (gpio_get_level(C111_ESP_HIGHSIDESWITCH_DIAGNOSTICS_SELECT_1) != 0
      || gpio_get_level(C111_ESP_HIGHSIDESWITCH_DIAGNOSTICS_SELECT_2) != 0) {
    gpio_set_level(C111_ESP_HIGHSIDESWITCH_DIAGNOSTICS_SELECT_1, 0);
    gpio_set_level(C111_ESP_HIGHSIDESWITCH_DIAGNOSTICS_SELECT_2, 0);
  }
  int reading;
  ESP_ERROR_CHECK(adc_oneshot_read(this->adc1, C111_ESP_HIGHSIDESWITCH_DIAGNOSTICS_MONITOR_ADC_CHANNEL, &reading));
  return convertADCToCurrent(reading, this->psuScaleFactor, this->psuOffset);
}

float C111::getPSU1TemperatureCelsius() {
  if (gpio_get_level(C111_ESP_HIGHSIDESWITCH_DIAGNOSTICS_SELECT_1) != 1
      || gpio_get_level(C111_ESP_HIGHSIDESWITCH_DIAGNOSTICS_SELECT_2) != 0) {
    gpio_set_level(C111_ESP_HIGHSIDESWITCH_DIAGNOSTICS_SELECT_1, 1);
    gpio_set_level(C111_ESP_HIGHSIDESWITCH_DIAGNOSTICS_SELECT_2, 0);
  }
  int reading;
  ESP_ERROR_CHECK(adc_oneshot_read(this->adc1, C111_ESP_HIGHSIDESWITCH_DIAGNOSTICS_MONITOR_ADC_CHANNEL, &reading));
  return convertADCToTemperature(reading);
}

float C111::getPSU2Current() {
  if (gpio_get_level(C111_ESP_HIGHSIDESWITCH_DIAGNOSTICS_SELECT_1) != 0
      || gpio_get_level(C111_ESP_HIGHSIDESWITCH_DIAGNOSTICS_SELECT_2) != 1) {
    gpio_set_level(C111_ESP_HIGHSIDESWITCH_DIAGNOSTICS_SELECT_1, 0);
    gpio_set_level(C111_ESP_HIGHSIDESWITCH_DIAGNOSTICS_SELECT_2, 1);
  }
  int reading;
  ESP_ERROR_CHECK(adc_oneshot_read(this->adc1, C111_ESP_HIGHSIDESWITCH_DIAGNOSTICS_MONITOR_ADC_CHANNEL, &reading));
  return convertADCToCurrent(reading, this->psuScaleFactor, this->psuOffset);
}

float C111::getPSU2TemperatureCelsius() {
  return this->getPSU1TemperatureCelsius();
}

void C111::setOverheatTempCelsius(float temp) {
  this->overheatTempCelsius = temp;
}

bool C111::isOverHeated() {
  return this->getTemperatureCelsius() >= this->overheatTempCelsius;
}

void C111::setPSU1Enabled(bool enabled) {
  gpio_set_level(C111_ESP_HIGHSIDESWITCH_CHANNEL_1_ENABLE, enabled ? 1 : 0);
}

bool C111::isPSU1Enabled() {
  return gpio_get_level(C111_ESP_HIGHSIDESWITCH_CHANNEL_1_ENABLE) == 1;
}

void C111::setPSU2Enabled(bool enabled) {
  gpio_set_level(C111_ESP_HIGHSIDESWITCH_CHANNEL_2_ENABLE, enabled ? 1 : 0);
}

bool C111::isPSU2Enabled() {
  return gpio_get_level(C111_ESP_HIGHSIDESWITCH_CHANNEL_2_ENABLE) == 1;
}

uint8_t C111::getUserInputState(uint8_t input) {
  auto values = this->getUserInputState();
  return values[0];
}

std::array<uint8_t, 8> C111::getUserInputState() {

  uint8_t value = MCP23x08_GPIO_A;
  ESP_ERROR_CHECK(this->write_i2c(
      C111_IO_EXPANDER_I2C_ADDRESS,
      &value, 1));

  ESP_ERROR_CHECK(this->read_i2c(
      C111_IO_EXPANDER_I2C_ADDRESS,
      &value, 1));

  return {
    (uint8_t) (value & (1 << C111_IO_EXPANDER_INPUT_1) ? 1 : 0),
    (uint8_t) (value & (1 << C111_IO_EXPANDER_INPUT_2) ? 1 : 0),
    (uint8_t) (value & (1 << C111_IO_EXPANDER_INPUT_3) ? 1 : 0),
    (uint8_t) (value & (1 << C111_IO_EXPANDER_INPUT_4) ? 1 : 0),
    (uint8_t) (value & (1 << C111_IO_EXPANDER_INPUT_5) ? 1 : 0),
    (uint8_t) (value & (1 << C111_IO_EXPANDER_INPUT_6) ? 1 : 0),
    (uint8_t) (value & (1 << C111_IO_EXPANDER_INPUT_7) ? 1 : 0),
    (uint8_t) (value & (1 << C111_IO_EXPANDER_INPUT_8) ? 1 : 0)
  };
}

uint16_t C111::getLineLevelAudio() {
  int reading;
  ESP_ERROR_CHECK(adc_oneshot_read(this->adc1, C111_ESP_LINE_LEVEL_AUDIO_INPUT_ADC_CHANNEL, &reading));
  return reading;
}

float C111::getPsuScaleFactor() {
  return this->psuScaleFactor;
}

void C111::setPsuScaleFactor(float psuScaleFactor) {
  this->psuScaleFactor = psuScaleFactor;
}

float C111::getPsuOffset() {
  return this->psuOffset;
}

void C111::setPsuOffset(float psuOffset) {
  this->psuOffset = psuOffset;
}

float C111::getPowerSupplyScaleFactor() {
  return this->powerSupplyScaleFactor;
}

void C111::setPowerSupplyScaleFactor(float powerSupplyScaleFactor) {
  this->powerSupplyScaleFactor = powerSupplyScaleFactor;
}

float C111::getPowerSupplyOffset() {
  return this->powerSupplyOffset;
}

void C111::setPowerSupplyOffset(float powerSupplyOffset) {
  this->powerSupplyOffset = powerSupplyOffset;
}
