cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(mpu9250_collect)

pico_sdk_init()

add_library(mpu_common
    I2Cdev.cpp
    MPU6050.cpp
)

pico_generate_pio_header(mpu_common)

target_include_directories(mpu_common PUBLIC ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(mpu_common PUBLIC pico_stdlib hardware_i2c)

add_executable(collect_data
    collect_data.cpp
)

target_link_libraries(collect_data mpu_common pico_stdlib hardware_i2c)

pico_add_extra_outputs(collect_data)

add_executable(IMU_zero
    IMU_zero.cpp
)

target_link_libraries(IMU_zero mpu_common pico_stdlib hardware_i2c)

pico_add_extra_outputs(IMU_zero)

