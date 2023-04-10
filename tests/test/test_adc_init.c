#include <stdio.h>

#include "unity.h"
#include "adc.h"


adc_config_ts test_config;
adc_ts test_adc;
adc_operation_status_te hw_init_results = ADC_INIT_FAIL;


uint8 mock_hw_init(uint8 channels, uint8 resolution, float32 ref_voltage){
    TEST_ASSERT_NOT_EQUAL_INT8(0, channels);
    return hw_init_results;
}

void setUp(void){
    test_adc.hw_init = NULL; 
    hw_init_results = ADC_INIT_FAIL;
}   

void tearDown(void){

}


void test_adc_init_hw_init_return_fail(void){
    /* arrange */
    test_config.num_of_channels = 1;
    test_adc.hw_init = mock_hw_init; 

    /* act */
    /* assert */
    TEST_ASSERT_EQUAL_UINT8((uint8)ADC_INIT_FAIL , (uint8)adc_init(&test_adc, test_config));
    TEST_ASSERT_EQUAL_UINT8((uint8)ADC_NOT_INITIALIZED , (uint8)test_adc.state);
} 


void test_adc_init_hw_init_return_ok(void){
    /* arrange */
    test_config.num_of_channels = 1;
    test_config.resolution = 12;
    hw_init_results = ADC_INIT_OK;
    test_adc.hw_init = mock_hw_init; 

    /* act */
    /* assert */
    TEST_ASSERT_EQUAL_UINT8((uint8)ADC_INIT_OK , (uint8)adc_init(&test_adc, test_config));
    TEST_ASSERT_EQUAL_UINT8((uint8)ADC_INITIALIZED , (uint8)test_adc.state);
    TEST_ASSERT_EQUAL_UINT16(4096,test_adc.config.adc_max_level);
} 
