
#ifndef C111_ESP_C111_ESP_PINOUT
#define C111_ESP_C111_ESP_PINOUT

#include <driver/adc.h>
#include <driver/gpio.h>
#include <driver/gpio.h>

#define C111_TEMP_SENSOR_I2C_ADDRESS 0b1001000
#define C111_OVERHEATED_TEMP_CELSIUS 80.0f

#define C111_IO_EXPANDER_I2C_ADDRESS 0b0100000
#define C111_IO_EXPANDER_INPUT_1 0
#define C111_IO_EXPANDER_INPUT_2 1
#define C111_IO_EXPANDER_INPUT_3 2
#define C111_IO_EXPANDER_INPUT_4 3
#define C111_IO_EXPANDER_INPUT_5 4
#define C111_IO_EXPANDER_INPUT_6 5
#define C111_IO_EXPANDER_INPUT_7 7
#define C111_IO_EXPANDER_INPUT_8 6

#define C111_SENSOR_PSU1_CURRENT 1
#define C111_SENSOR_PSU2_CURRENT 2

#define C111_ADC_RESOLUTION (3.3f / 4096.0f)
#define C111_ADC_SCALE_FACTOR 2.0f

#define C111_USER_INPUT_1 1
#define C111_USER_INPUT_2 2
#define C111_USER_INPUT_3 3
#define C111_USER_INPUT_4 4
#define C111_USER_INPUT_5 5
#define C111_USER_INPUT_6 6
#define C111_USER_INPUT_7 7
#define C111_USER_INPUT_8 8

#define C111_ESP_12V_VOLTAGE_MONITOR_ADC_CHANNEL                    ADC1_CHANNEL_7
#define C111_ESP_HIGHSIDESWITCH_DIAGNOSTICS_MONITOR_ADC_CHANNEL     ADC1_CHANNEL_0
#define C111_ESP_LINE_LEVEL_AUDIO_INPUT_ADC_CHANNEL                 ADC1_CHANNEL_6

#define C111_ESP_HIGHSIDESWITCH_DIAGNOSTICS_MONITOR	    GPIO_NUM_36
#define C111_ESP_IO_EXPANDER_INTERRUPT                  GPIO_NUM_39
#define C111_ESP_LINE_LEVEL_AUDIO_INPUT                 GPIO_NUM_34
#define C111_ESP_12V_VOLTAGE_MONITOR                    GPIO_NUM_35
#define C111_ESP_DATA_3	                                GPIO_NUM_33
#define C111_ESP_DATA_4      	                          GPIO_NUM_32
#define C111_ESP_HIGHSIDESWITCH_CHANNEL_1_ENABLE        GPIO_NUM_25
#define C111_ESP_I2C_SCL                                GPIO_NUM_26
#define C111_ESP_HIGHSIDESWITCH_CHANNEL_2_ENABLE        GPIO_NUM_27
#define C111_ESP_I2C_SDA                                GPIO_NUM_14
#define C111_ESP_EXPANSION_HEADER_IO2                   GPIO_NUM_12
#define C111_ESP_EXPANSION_HEADER_IO3                   GPIO_NUM_13
#define C111_ESP_CAN_TERMINATION_SWITCH                 GPIO_NUM_15
#define C111_ESP_DIFF_OR_SE_SWITCH                      GPIO_NUM_2
#define C111_ESP_HIGHSIDESWITCH_DIAGNOSTICS_SELECT_2    GPIO_NUM_0
#define C111_ESP_CAN_RX                                 GPIO_NUM_4
#define C111_ESP_HIGHSIDESWITCH_FAULT_LATCH             GPIO_NUM_16
#define C111_ESP_HIGHSIDESWITCH_DIAGNOSTICS_SELECT_1    GPIO_NUM_17
#define C111_ESP_CAN_TX                                 GPIO_NUM_5
#define C111_ESP_POWER_SUPPLY_KEEP_ALIVE                GPIO_NUM_18
#define C111_ESP_DATA_2                                 GPIO_NUM_19
#define C111_ESP_DATA_1                                 GPIO_NUM_21
#define C111_ESP_UART_RX                                GPIO_NUM_3
#define C111_ESP_UART_TX                                GPIO_NUM_1
#define C111_ESP_DATA_5                                 GPIO_NUM_22
#define C111_ESP_DATA_6	                                GPIO_NUM_23

#endif
