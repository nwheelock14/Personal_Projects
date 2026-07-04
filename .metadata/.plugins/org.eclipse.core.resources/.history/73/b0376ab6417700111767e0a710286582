/*
 * PI.c
 *
 *  Created on: May 17, 2026
 *      Author: nickw
 */

#include "PI.h"

uint32_t Call_PI(float target_temp, float temp_value)
{
	// PI Tuning Constants
	float Kp = 6.0f;
	float Ki = 1.0f;
	static float integral_sum = 0.0f;
	float dt = 1.0f;

	// Calculate Error Sig
	float error = target_temp - temp_value;
	float P_out = Kp*error;
	integral_sum = integral_sum + (error * dt);
	float I_out = Ki * integral_sum;
	float raw_pi_output = P_out + I_out;

	float final_pwm_output = raw_pi_output;

	if(final_pwm_output > 100.0f)
	{
		final_pwm_output = 100.0f;
		integral_sum -= error*dt;
	}
	else if(final_pwm_output < 0.0f)
	{
		final_pwm_output = 0.0f;
		integral_sum = 0.0f;
	}

	return((uint32_t)final_pwm_output);
}
