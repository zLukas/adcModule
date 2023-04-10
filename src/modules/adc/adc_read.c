#include "adc.h"

adc_operation_status_te adc_read_channel(adc_ts* adc, measurement_ts* data, uint8 channel_num){ 
    
    uint16 raw_data = 0;
    adc_operation_status_te read_results = (adc_operation_status_te)adc->hw_read(&raw_data, channel_num);
    if (read_results == ADC_READ_OK
        && raw_data <= adc->config.adc_max_level){
        data->level = raw_data;
        data->voltage = (float32)raw_data * adc->config.ref_voltage /
        adc->config.adc_max_level;
    }else{
        data->level = 0;
        data->voltage = 0;
        data->percentage = 0;
    }
    return read_results;
}