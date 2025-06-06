#ifndef _MPU9250_H_
#define _MPU9250_H_
#include "MPU6050.h"
class MPU9250 : public MPU6050 {
    public:
        MPU9250(uint8_t address=0x68) : MPU6050(address) {}
};
#endif

