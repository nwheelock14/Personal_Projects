/*
 * Timer.c
 *
 *  Created on: May 24, 2026
 *      Author: nickw
 */

#include "Timer.h"

void U_Delay(uint16_t delay_us)
{
	htim10.Instance->CNT = 0;

	while(htim10.Instance->CNT < delay_us)
	{

	}
}
