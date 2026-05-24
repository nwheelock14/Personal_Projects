/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <string.h>
#include <stdio.h>
#include "TMP1075.h"
#include "PI.h"
#include "LCD.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
extern I2C_HandleTypeDef hi2c1;
extern TIM_HandleTypeDef htim10;
/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define B1_Pin GPIO_PIN_13
#define B1_GPIO_Port GPIOC
#define DB_0_Pin GPIO_PIN_0
#define DB_0_GPIO_Port GPIOC
#define DB_1_Pin GPIO_PIN_1
#define DB_1_GPIO_Port GPIOC
#define DB_2_Pin GPIO_PIN_2
#define DB_2_GPIO_Port GPIOC
#define DB_3_Pin GPIO_PIN_3
#define DB_3_GPIO_Port GPIOC
#define USART_TX_Pin GPIO_PIN_2
#define USART_TX_GPIO_Port GPIOA
#define USART_RX_Pin GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA
#define LD2_Pin GPIO_PIN_5
#define LD2_GPIO_Port GPIOA
#define Register_Select_Pin GPIO_PIN_7
#define Register_Select_GPIO_Port GPIOA
#define DB_4_Pin GPIO_PIN_4
#define DB_4_GPIO_Port GPIOC
#define DB_5_Pin GPIO_PIN_5
#define DB_5_GPIO_Port GPIOC
#define DB_6_Pin GPIO_PIN_6
#define DB_6_GPIO_Port GPIOC
#define DB_7_Pin GPIO_PIN_7
#define DB_7_GPIO_Port GPIOC
#define RW_Select_Pin GPIO_PIN_8
#define RW_Select_GPIO_Port GPIOC
#define LCD_Enable_Pin GPIO_PIN_9
#define LCD_Enable_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define SWO_Pin GPIO_PIN_3
#define SWO_GPIO_Port GPIOB
#define PWM_Signal_Pin GPIO_PIN_9
#define PWM_Signal_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
