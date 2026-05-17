/*
 * TMP1075.c
 *
 *  Created on: May 17, 2026
 *      Author: nickw
 */

#include "TMP1075.h"

void Init_Temp_Registers(uint8_t config_data[2])
{
	HAL_I2C_Mem_Write(&hi2c1, TMP1075_Adr, Configuration_Register, I2C_MEMADD_SIZE_8BIT, config_data, 2, 100);
    HAL_Delay(250); // Wait for the first conversion to finish
}




float Get_Temp_Data(void)
{
    uint8_t raw_temp_data[2] = {0,0};
    float temp_value = 0.0f;

	HAL_I2C_Mem_Read(&hi2c1, TMP1075_Adr, Temp_Result_Register, I2C_MEMADD_SIZE_8BIT, raw_temp_data, 2, 100);

    int16_t temp_data = (int16_t)((raw_temp_data[0] << 8) | raw_temp_data[1]) >> 4;
    temp_value = (temp_data * Temp_Constant * 1.8f) + 32.0f;

//    sprintf(temp_buffer, "The temperature is: %.2f degrees F\r\n", temp_value);
//
//    HAL_UART_Transmit(&huart2, (uint8_t *)temp_buffer, strlen(temp_buffer), 100);

    return(temp_value);
}
