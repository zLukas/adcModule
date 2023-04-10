#include <stdio.h>

#include "unity.h"
#include "adc.h"


adc_config_ts test_config;
adc_ts test_adc;



uint8 mock_hw_read(uint16* data, uint8 channel){
    TEST_ASSERT_NOT_EQUAL_INT8(0, channels);
    return hw_init_results;
}

void setUp(void){
    test_adc.hw_init = NULL; 
    hw_init_results = ADC_INIT_FAIL;
}   

void tearDown(void){

}


void test_read_failed(void){
    
}