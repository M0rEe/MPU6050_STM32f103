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
	retState = HAL_I2C_IsDeviceReady(&hi2c1, ((MPU_I2C_ADDRESS << 1) + 0), 1,
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

	retState = HAL_I2C_Mem_Write(&hi2c1, ((MPU_I2C_ADDRESS << 1) + 0),
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

	retState = HAL_I2C_Mem_Write(&hi2c1, ((MPU_I2C_ADDRESS << 1) + 0),
	MPU_ACCELEROMETER_CFG_REG, 1, &l_accData, 1, MPU_MAX_TIMEOUT_MS);
#if MPU_DEBUG_STATE == MPU_DEBUG_ENABLED
	if (retState == HAL_OK) {
		printf("Configured Accelerometer\n");
	} else {
		printf("Accelerometer isn't Ready to use\n");
	}
#else
#endif

//  Configure POWER and Stop SleepMode
	uint8_t l_pwrData = 0;

	retState = HAL_I2C_Mem_Write(&hi2c1, ((MPU_I2C_ADDRESS << 1) + 0),
	MPU_PWR_MANAGMENT_REG1, 1, &l_pwrData, 1, MPU_MAX_TIMEOUT_MS);
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

}
uint16_t MPU_6050_getGyroY() {

}
uint16_t MPU_6050_getGyroZ() {

}

uint16_t MPU_6050_getAccX() {

}
uint16_t MPU_6050_getAccY() {

}
uint16_t MPU_6050_getAccZ() {

}

