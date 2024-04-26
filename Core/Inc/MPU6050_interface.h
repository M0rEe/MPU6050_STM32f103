/*
 * MPU6050_interface.h
 *
 *  Created on: Apr 25, 2024
 *      Author: M0rE
 */

#ifndef INC_MPU6050_INTERFACE_H_
#define INC_MPU6050_INTERFACE_H_

#include "stm32f1xx_hal.h"

#define MPU_DEBUG_DISABLED 2
#define MPU_DEBUG_ENABLED 1

#define MPU_DEBUG_STATE 	MPU_DEBUG_ENABLED

#if MPU_DEBUG_STATE == MPU_DEBUG_ENABLED
//	For Debugging Purposes
	#include <stdio.h>
#else

#endif

#define MPU_I2C_ADDRESS 0x68

#define MPU_SAMPLE_RATE_REG	25
#define MPU_USER_CONTROL_REG	106
#define MPU_PWR_MANAGMENT_REG1	107

#define MPU_GYROSCOPE_CFG_REG	27
#define MPU_ACCELEROMETER_CFG_REG	28

#define MPU_ACCELEROMETER_DATA_REG_START	59
#define MPU_GYROSCOPE_DATA_REG_START	67

#define MPU_FS_SEL_250  0
#define MPU_FS_SEL_500  1
#define MPU_FS_SEL_1000 2
#define MPU_FS_SEL_2000 3
#define MPU_FS_SEL_OFFSET 3

#define MPU_AFS_SEL_2g  0
#define MPU_AFS_SEL_4g  1
#define MPU_AFS_SEL_8g  2
#define MPU_AFS_SEL_16g 3
#define MPU_AFS_SEL_OFFSET 3

#define MPU_MAX_TIMEOUT_MS 100

void MPU_6050_Init();

uint16_t MPU_6050_getGyroX();
uint16_t MPU_6050_getGyroY();
uint16_t MPU_6050_getGyroZ();

uint16_t MPU_6050_getAccX();
uint16_t MPU_6050_getAccY();
uint16_t MPU_6050_getAccZ();

#endif /* INC_MPU6050_INTERFACE_H_ */
