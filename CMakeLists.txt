cmake_minimum_required(VERSION 3.20.1)

project(adcModule C)

include_directories(
        ${PROJECT_SOURCE_DIR}/inc
        ${PROJECT_SOURCE_DIR}/src/modules/adc
)

add_executable(adcModule reader.c)
