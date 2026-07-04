/*
 * LCD.c
 *
 *  Created on: May 23, 2026
 *      Author: nickw
 */

#include "LCD.h"

void Command(uint8_t data_bits)
{
//	void command(char i)
//	{
//	 P1 = i; //put data on output Port
//	 D_I =0; //D/I=LOW : send instruction
//	 R_W =0; //R/W=LOW : Write
//	 E = 1;
//	 Delay(1); //enable pulse width >= 300ns
//	 E = 0; //Clock enable: falling edge
//	}

	GPIOC->ODR = (GPIOC->ODR & 0xFFFFFF00) | data_bits;
	HAL_GPIO_WritePin(GPIOC, Register_Select_Pin, GPIO_PIN_RESET); // Sets RS to 0 for command
	HAL_GPIO_WritePin(GPIOC, RW_Select_Pin, GPIO_PIN_RESET); // Sets RW to 0 for write
	HAL_GPIO_WritePin(GPIOC, LCD_Enable_Pin, GPIO_PIN_SET);
	U_Delay(1);
	HAL_GPIO_WritePin(GPIOC, LCD_Enable_Pin, GPIO_PIN_RESET);

	U_Delay(40);

}

void Write_Data(uint8_t data_bits)
{
//	void write(char i)
//	{
//	 P1 = i; //put data on output Port
//	 D_I =1; //D/I=HIGH : send data
//	 R_W =0; //R/W=LOW : Write
//	 E = 1;
//	 Delay(1); //enable pulse width >= 300ns
//	 E = 0; //Clock enable: falling edge
//	}

	GPIOC->ODR = (GPIOC->ODR & 0xFFFFFF00) | data_bits;
	HAL_GPIO_WritePin(GPIOC, Register_Select_Pin, GPIO_PIN_SET); // Sets RS to 1 for data
	HAL_GPIO_WritePin(GPIOC, RW_Select_Pin, GPIO_PIN_RESET); // Sets RW to 0 for write
	HAL_GPIO_WritePin(GPIOC, LCD_Enable_Pin, GPIO_PIN_SET);
	U_Delay(1);
	HAL_GPIO_WritePin(GPIOC, LCD_Enable_Pin, GPIO_PIN_RESET);

	U_Delay(40);
}

void Init_LCD(void)
{
//	void init()
//	{
//	 E = 0;
//	 Delay(100); //Wait >40 msec after power is applied
//	 command(0x30); //command 0x30 = Wake up
//	 Delay(30); //must wait 5ms, busy flag not available
//	 command(0x30); //command 0x30 = Wake up #2
//	 Delay(10); //must wait 160us, busy flag not available
//	 command(0x30); //command 0x30 = Wake up #3
//	 Delay(10); //must wait 160us, busy flag not available
//	 command(0x38); //Function set: 8-bit/2-line
//	 command(0x10); //Set cursor
//	 command(0x0c); //Display ON; Cursor ON
//	 command(0x06); //Entry mode set
//	}

	HAL_GPIO_WritePin(GPIOC, LCD_Enable_Pin, GPIO_PIN_RESET);
	HAL_Delay(50);
	Command(0x30);
	HAL_Delay(5);
	Command(0x30);
	U_Delay(180);
	Command(0x30);
	U_Delay(180);
	Command(0x38); //Function set: 8-bit/2-line
	Command(0x10); //Set cursor
	Command(0x0C); //Display ON; Cursor ON
	Command(0x06); //Entry mode set
	U_Delay(1600);
	Command(0x01); // Clear Display
	U_Delay(1600);

}

void LCD_Write_String(uint8_t *str)
{
	while(*str != '\0') // Loop until Null Terminator
	{
		Write_Data(*str);
		str++;
	}
}

void LCD_Set_Cursor(uint8_t row, uint8_t col)
{
	uint8_t address = 0;

	if (row == 0)
	{
		address = 0x00 + col; // Line 1 starts at 0x00
	}
	else if (row == 1)
	{
		address = 0x40 + col; // Line 2 starts at 0x40
	}

	Command(0x80 | address);

//	U_Delay(40); // Change this later
}

void Clear_LCD(void)
{
	Command(0x01); // Clear Display
	U_Delay(1600);
}

void Update_UI(uint32_t PWM_Value, float temp_value, float Temp_Target)
{
	char LCD_buffer[21] = {0};


	LCD_Set_Cursor(0,0);

	sprintf(LCD_buffer, "Actual Temp: %.1f %cF", temp_value, 0xDF);
	LCD_Write_String((uint8_t*)LCD_buffer);

	LCD_Set_Cursor(1,0);

	if(PWM_Value != 0)
	{
		sprintf(LCD_buffer, "Trg: %.1f%cF  Heating", Temp_Target, 0xDF);
		LCD_Write_String((uint8_t*)LCD_buffer);
	}

	else
	{
		sprintf(LCD_buffer, "Trg: %.1f%cF     Idle", Temp_Target, 0xDF);
		LCD_Write_String((uint8_t*)LCD_buffer);
	}
}

void Intro_Message(void)
{
	LCD_Write_String((uint8_t*)"  Wheelock's Heated ");
	LCD_Set_Cursor(1, 0);
	LCD_Write_String((uint8_t*)"    Cabinet V1.0    ");
	HAL_Delay(3500);
}
