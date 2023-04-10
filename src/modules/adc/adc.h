#ifndef _ADC_H_
#define _ADC_H_

#include "basic_types.h"

typedef enum adc_operation_status_te{
    OK = 0,
    ADC_INIT_FAIL,
    ADC_INIT_OK,
    ADC_READ_COMPLETE,
    ADC_READ_FAILED,
}adc_operation_status_te;

typedef enum adc_state_te{
    ADC_INITIALIZED = 0,
    ADC_NOT_INITIALIZED

}adc_state_te;

typedef enum out_format {
    RAW = 0, 
    VOLTAGE,
    PERCENT
}out_format;

typedef struct adc_config_ts {
    uint8 resolution;
    uint8 num_of_channels;
    float32 ref_voltage;
    out_format data_format;
}adc_config_ts;

typedef struct adc_ts{
    adc_state_te state;
    adc_config_ts config;
    uint8 (*hw_init)(uint8, uint8, float32);
    uint8 (*hw_read)(uint16*, uint8);
}adc_ts;

adc_operation_status_te adc_init(adc_ts* adc, adc_config_ts config);
adc_operation_status_te adc_raw_read(adc_ts* adc, uint16* data)
#endif
