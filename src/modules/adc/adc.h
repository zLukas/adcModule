#ifndef _ADC_H_
#define _ADC_H_

#include "basic_types.h"

typedef enum adc_operation_status_te{
    OK = 0,
    ADC_INIT_FAIL,
    ADC_INIT_OK,
    ADC_READ_OK,
    ADC_READ_FAILED,
    ADC_VALUE_OVER_LIMIT,
}adc_operation_status_te;

typedef enum adc_state_te{
    ADC_INITIALIZED = 0,
    ADC_NOT_INITIALIZED

}adc_state_te;

typedef struct adc_config_ts {
    uint8 resolution;
    uint8 num_of_channels;
    float32 ref_voltage;
    uint16 adc_max_level;
}adc_config_ts;

typedef struct measurement_ts{
    uint16 level;
    float32 voltage;
    float32 percentage;
}measurement_ts;

typedef struct adc_ts{
    adc_state_te state;
    adc_config_ts config;
    uint8 (*hw_init)(uint8, uint8, float32);
    uint8 (*hw_read)(uint16*, uint8);
}adc_ts;

adc_operation_status_te adc_init(adc_ts* adc, adc_config_ts config);
adc_operation_status_te adc_read(adc_ts* adc, uint16* data);
#endif
