/*
 * MPU6050_interface.h
 *
 *  Created on: Apr 25, 2024
 *      Author: M0rE
 */

#ifndef INC_MPU6050_INTERFACE_H_
#define INC_MPU6050_INTERFACE_H_

#include "stm32f1xx_hal.h"
#include "MPU6050_register.h"

#define MPU_DEBUG_DISABLED 2
#define MPU_DEBUG_ENABLED 1

#define MPU_DEBUG_STATE 	MPU_DEBUG_ENABLED

#if MPU_DEBUG_STATE == MPU_DEBUG_ENABLED
//	For Debugging Purposes
#include <stdio.h>
#else

#endif

typedef enum {
	MPU_AFS_SEL_2g,
	MPU_AFS_SEL_4g,
	MPU_AFS_SEL_8g,
	MPU_AFS_SEL_16g
} MPU_Accelerometer_FullScale_t;

typedef enum {
	MPU_FS_SEL_250 =0 ,
	MPU_FS_SEL_500,
	MPU_FS_SEL_1000,
	MPU_FS_SEL_2000
}MPU_GyroScope_FullScale_t;

typedef enum {
	MPU_DLPF_ACCEL_1kHz_0Ms_GYRO_8kHz_1Ms = 0,
    MPU_DLPF_ACCEL_1kHz_2Ms_GYRO_8kHz_2Ms,
    MPU_DLPF_ACCEL_1kHz_3Ms_GYRO_8kHz_3Ms,
    MPU_DLPF_ACCEL_1kHz_5Ms_GYRO_8kHz_5Ms,
    MPU_DLPF_ACCEL_1kHz_9Ms_GYRO_8kHz_9Ms,
    MPU_DLPF_ACCEL_1kHz_14Ms_GYRO_8kHz_14Ms,
    MPU_DLPF_ACCEL_1kHz_19Ms_GYRO_8kHz_19Ms,
} MPU_Device_CFG_t;

void MPU_6050_Init();

uint16_t MPU_6050_getGyroX();
uint16_t MPU_6050_getGyroY();
uint16_t MPU_6050_getGyroZ();

uint16_t MPU_6050_getAccX();
uint16_t MPU_6050_getAccY();
uint16_t MPU_6050_getAccZ();

#endif /* INC_MPU6050_INTERFACE_H_ */
