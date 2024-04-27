/*
 * MPU6050_program.c
 *
 *  Created on: Apr 25, 2024
 *      Author: M0rE
 */

#include "MPU6050_interface.h"

extern I2C_HandleTypeDef hi2c1;

void MPU_6050_Init() {
	HAL_StatusTypeDef retState = HAL_ERROR;
//  checking for device availability
	retState = HAL_I2C_IsDeviceReady(&hi2c1,
			((MPU_I2C_ADDRESS << 1) + MPU_I2C_WRITE_OPERATION), 1,
			MPU_MAX_TIMEOUT_MS);
#if MPU_DEBUG_STATE == MPU_DEBUG_ENABLED
	if (retState == HAL_OK) {
		printf("Device is Ready to use\n");
	} else {
		printf("Device isn't Ready to use\n");
	}
#else
#endif

//  Configure Gyroscope
	uint8_t l_gyroData = (MPU_FS_SEL_500 << MPU_FS_SEL_OFFSET);

	retState = HAL_I2C_Mem_Write(&hi2c1,
			((MPU_I2C_ADDRESS << 1) + MPU_I2C_WRITE_OPERATION),
			MPU_GYROSCOPE_CFG_REG, 1, &l_gyroData, 1, MPU_MAX_TIMEOUT_MS);
#if MPU_DEBUG_STATE == MPU_DEBUG_ENABLED
	if (retState == HAL_OK) {
		printf("Configured GyroScope\n");
	} else {
		printf("GyroScope isn't Ready to use\n");
	}
#else
#endif

//  Configure Accelerometer
	uint8_t l_accData = (MPU_AFS_SEL_4g << MPU_AFS_SEL_OFFSET);

	retState = HAL_I2C_Mem_Write(&hi2c1,
			((MPU_I2C_ADDRESS << 1) + MPU_I2C_WRITE_OPERATION),
			MPU_ACCELEROMETER_CFG_REG, 1, &l_accData, 1, MPU_MAX_TIMEOUT_MS);
#if MPU_DEBUG_STATE == MPU_DEBUG_ENABLED
	if (retState == HAL_OK) {
		printf("Configured Accelerometer\n");
	} else {
		printf("Accelerometer isn't Ready to use\n");
	}
#else
#endif

//  Configure POWER 8 MHz internal oscillator and Stop SleepMode
	uint8_t l_pwrData = 0;

	retState = HAL_I2C_Mem_Write(&hi2c1,
			((MPU_I2C_ADDRESS << 1) + MPU_I2C_WRITE_OPERATION),
			MPU_PWR_MANAGMENT_REG1, 1, &l_pwrData, 1, MPU_MAX_TIMEOUT_MS);
#if MPU_DEBUG_STATE == MPU_DEBUG_ENABLED
	if (retState == HAL_OK) {
		printf("Device Running Mode\n");
	} else {
		printf("Device is in Sleep Mode\n");
	}
#else
#endif

	//  Configure digital Low-Pass Filter for Accelerometer/Gyroscope
	//  External SYNC off by default

	uint8_t l_cfgData = MPU_DLPF_ACCEL_1kHz_0Ms_GYRO_8kHz_1Ms;

	retState = HAL_I2C_Mem_Write(&hi2c1,
			((MPU_I2C_ADDRESS << 1) + MPU_I2C_WRITE_OPERATION),
			MPU_DEVICE_CONFIG_REG, 1, &l_cfgData, 1, MPU_MAX_TIMEOUT_MS);
#if MPU_DEBUG_STATE == MPU_DEBUG_ENABLED
	if (retState == HAL_OK) {
		printf("Device Running Mode\n");
	} else {
		printf("Device is in Sleep Mode\n");
	}
#else
#endif
}

uint16_t MPU_6050_getGyroX() {
	uint8_t l_Data[2];
	HAL_StatusTypeDef retState = HAL_I2C_Mem_Read(&hi2c1,
			((MPU_I2C_ADDRESS << 1) + MPU_I2C_READ_OPERATION),
			MPU_GYROSCOPE_DATA_REG_START + MPU_GYROSCOPE_X_DATA_REG_OFFSET, 1,
			l_Data, 2, MPU_MAX_TIMEOUT_MS);
	uint16_t retData = (l_Data[0] << 8) + l_Data[1];

#if MPU_DEBUG_STATE == MPU_DEBUG_ENABLED
	if (retState == HAL_OK) {
		printf("X Data retrieved successfully\n");
	} else {
		printf("X Data retrieving Failed\n");
	}
#else
#endif
	return retData;
}

uint16_t MPU_6050_getGyroY() {
	uint8_t l_Data[2];
	HAL_StatusTypeDef retState = HAL_I2C_Mem_Read(&hi2c1,
			((MPU_I2C_ADDRESS << 1) + MPU_I2C_READ_OPERATION),
			MPU_GYROSCOPE_DATA_REG_START + MPU_GYROSCOPE_Y_DATA_REG_OFFSET, 1,
			l_Data, 2, MPU_MAX_TIMEOUT_MS);
	uint16_t retData = (l_Data[0] << 8) + l_Data[1];

#if MPU_DEBUG_STATE == MPU_DEBUG_ENABLED
	if (retState == HAL_OK) {
		printf("Y Data retrieved successfully\n");
	} else {
		printf("Y Data retrieving Failed\n");
	}
#else
#endif
	return retData;
}

uint16_t MPU_6050_getGyroZ() {
	uint8_t l_Data[2];
	HAL_StatusTypeDef retState = HAL_I2C_Mem_Read(&hi2c1,
			((MPU_I2C_ADDRESS << 1) + MPU_I2C_READ_OPERATION),
			MPU_GYROSCOPE_DATA_REG_START + MPU_GYROSCOPE_Z_DATA_REG_OFFSET, 1,
			l_Data, 2, MPU_MAX_TIMEOUT_MS);
	uint16_t retData = (l_Data[0] << 8) + l_Data[1];

#if MPU_DEBUG_STATE == MPU_DEBUG_ENABLED
	if (retState == HAL_OK) {
		printf("Z Data retrieved successfully\n");
	} else {
		printf("Z Data retrieving Failed\n");
	}
#else
#endif
	return retData;

}

uint16_t MPU_6050_getAccX() {

	uint8_t l_Data[2];
	HAL_StatusTypeDef retState = HAL_I2C_Mem_Read(&hi2c1,
			((MPU_I2C_ADDRESS << 1) + MPU_I2C_READ_OPERATION),
			MPU_ACCELEROMETER_DATA_REG_START
					+ MPU_ACCELEROMETER_X_DATA_REG_OFFSET, 1, l_Data, 2,
			MPU_MAX_TIMEOUT_MS);
	uint16_t retData = (l_Data[0] << 8) + l_Data[1];

#if MPU_DEBUG_STATE == MPU_DEBUG_ENABLED
	if (retState == HAL_OK) {
		printf("X Data retrieved successfully\n");
	} else {
		printf("X Data retrieving Failed\n");
	}
#else
	#endif
	return retData;
}

uint16_t MPU_6050_getAccY() {
	uint8_t l_Data[2];
	HAL_StatusTypeDef retState = HAL_I2C_Mem_Read(&hi2c1,
			((MPU_I2C_ADDRESS << 1) + MPU_I2C_READ_OPERATION),
			MPU_ACCELEROMETER_DATA_REG_START
					+ MPU_ACCELEROMETER_Y_DATA_REG_OFFSET, 1, l_Data, 2,
			MPU_MAX_TIMEOUT_MS);
	uint16_t retData = (l_Data[0] << 8) + l_Data[1];

#if MPU_DEBUG_STATE == MPU_DEBUG_ENABLED
	if (retState == HAL_OK) {
		printf("Y Data retrieved successfully\n");
	} else {
		printf("Y Data retrieving Failed\n");
	}
#else
#endif
	return retData;
}

uint16_t MPU_6050_getAccZ() {
	uint8_t l_Data[2];
	HAL_StatusTypeDef retState = HAL_I2C_Mem_Read(&hi2c1,
			((MPU_I2C_ADDRESS << 1) + MPU_I2C_READ_OPERATION),
			MPU_ACCELEROMETER_DATA_REG_START
					+ MPU_ACCELEROMETER_Z_DATA_REG_OFFSET, 1, l_Data, 2,
			MPU_MAX_TIMEOUT_MS);
	uint16_t retData = (l_Data[0] << 8) + l_Data[1];

#if MPU_DEBUG_STATE == MPU_DEBUG_ENABLED
	if (retState == HAL_OK) {
		printf("Z Data retrieved successfully\n");
	} else {
		printf("Z Data retrieving Failed\n");
	}
#else
#endif
	return retData;
}

