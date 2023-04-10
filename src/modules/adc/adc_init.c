#include "adc.h"
adc_operation_status_te adc_init(adc_ts* adc, adc_config_ts config){
    adc->config = config;
    adc_operation_status_te hw_init_results = ADC_INIT_FAIL;

    /* calculate max level basing on ref voltage and bit resoultion */
    adc->config.adc_max_level = pow((float64)2, (float64)adc->config.resolution);

    if (adc->hw_init){
        hw_init_results = adc->hw_init(config.num_of_channels,
            config.resolution,
            config.ref_voltage);

        adc->state = (hw_init_results == ADC_INIT_OK) ? ADC_INITIALIZED : ADC_NOT_INITIALIZED;
    }
    return hw_init_results;
}
