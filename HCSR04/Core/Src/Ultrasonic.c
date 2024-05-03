/**********************************************
 * @SWC: Ultrasonic.c
 * @date: May 2, 2024
 * @author:Hossam Emad 
************************************************/

#include "Ultrasonic.h"
#include "main.h"

extern TIM_HandleTypeDef htim1;

void delay (uint16_t time)
{
	__HAL_TIM_SET_COUNTER(&htim1, 0);
	while (__HAL_TIM_GET_COUNTER (&htim1) < time);
}


/*generate 4 sensors struct*/
Ultrasonic_t HCSR04_sensor[4];




// Let's write the callback function

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
	
	if (   (htim == &htim1)  && htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1)  // if the interrupt source is channel1
	{
		if (HCSR04_sensor[0].Is_First_Captured==0) // if the first value is not captured
		{
			HCSR04_sensor[0].IC_Val1 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1); // read the first value
			HCSR04_sensor[0].Is_First_Captured = 1;  // set the first captured as true
			// Now change the polarity to falling edge
			__HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_1, TIM_INPUTCHANNELPOLARITY_FALLING);
		}

		else if (HCSR04_sensor[0].Is_First_Captured==1)   // if the first is already captured
		{
			HCSR04_sensor[0].IC_Val2 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);  // read second value
			__HAL_TIM_SET_COUNTER(htim, 0);  // reset the counter

			if (HCSR04_sensor[0].IC_Val2 > HCSR04_sensor[0].IC_Val1)
			{
				HCSR04_sensor[0].Difference = HCSR04_sensor[0].IC_Val2-HCSR04_sensor[0].IC_Val1;
			}

			else if (HCSR04_sensor[0].IC_Val1 > HCSR04_sensor[0].IC_Val2)
			{
				HCSR04_sensor[0].Difference = (0xffff - HCSR04_sensor[0].IC_Val1) + HCSR04_sensor[0].IC_Val2;
			}

			HCSR04_sensor[0].Distance = HCSR04_sensor[0].Difference * .034/2;
			HCSR04_sensor[0].Is_First_Captured = 0; // set it back to false

			// set polarity to rising edge
			__HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_1, TIM_INPUTCHANNELPOLARITY_RISING);
			__HAL_TIM_DISABLE_IT(&htim1, TIM_IT_CC1);
		}
	}

	if (   (htim == &htim1)  && htim->Channel == HAL_TIM_ACTIVE_CHANNEL_2)  // if the interrupt source is channel1
	{
		if (HCSR04_sensor[1].Is_First_Captured==0) // if the first value is not captured
		{
			HCSR04_sensor[1].IC_Val1 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_2); // read the first value
			HCSR04_sensor[1].Is_First_Captured = 1;  // set the first captured as true
			// Now change the polarity to falling edge
			__HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_2, TIM_INPUTCHANNELPOLARITY_FALLING);
		}

		else if (HCSR04_sensor[1].Is_First_Captured==1)   // if the first is already captured
		{
			HCSR04_sensor[1].IC_Val2 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_2);  // read second value
			__HAL_TIM_SET_COUNTER(htim, 0);  // reset the counter

			if (HCSR04_sensor[1].IC_Val2 > HCSR04_sensor[1].IC_Val1)
			{
				HCSR04_sensor[1].Difference = HCSR04_sensor[1].IC_Val2-HCSR04_sensor[1].IC_Val1;
			}

			else if (HCSR04_sensor[1].IC_Val1 > HCSR04_sensor[1].IC_Val2)
			{
				HCSR04_sensor[1].Difference = (0xffff - HCSR04_sensor[1].IC_Val1) + HCSR04_sensor[1].IC_Val2;
			}

			HCSR04_sensor[1].Distance = HCSR04_sensor[1].Difference * .034/2;
			HCSR04_sensor[1].Is_First_Captured = 0; // set it back to false

			// set polarity to rising edge
			__HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_2, TIM_INPUTCHANNELPOLARITY_RISING);
			__HAL_TIM_DISABLE_IT(&htim1, TIM_IT_CC2);
		}
	}
	if (   (htim == &htim1)  && htim->Channel == HAL_TIM_ACTIVE_CHANNEL_3)  // if the interrupt source is channel1
	{
		if (HCSR04_sensor[2].Is_First_Captured==0) // if the first value is not captured
		{
			HCSR04_sensor[2].IC_Val1 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_3); // read the first value
			HCSR04_sensor[2].Is_First_Captured = 1;  // set the first captured as true
			// Now change the polarity to falling edge
			__HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_3, TIM_INPUTCHANNELPOLARITY_FALLING);
		}

		else if (HCSR04_sensor[2].Is_First_Captured==1)   // if the first is already captured
		{
			HCSR04_sensor[2].IC_Val2 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_3);  // read second value
			__HAL_TIM_SET_COUNTER(htim, 0);  // reset the counter

			if (HCSR04_sensor[2].IC_Val2 > HCSR04_sensor[2].IC_Val1)
			{
				HCSR04_sensor[2].Difference = HCSR04_sensor[2].IC_Val2-HCSR04_sensor[2].IC_Val1;
			}

			else if (HCSR04_sensor[2].IC_Val1 > HCSR04_sensor[2].IC_Val2)
			{
				HCSR04_sensor[2].Difference = (0xffff - HCSR04_sensor[2].IC_Val1) + HCSR04_sensor[2].IC_Val2;
			}

			HCSR04_sensor[2].Distance = HCSR04_sensor[2].Difference * .034/2;
			HCSR04_sensor[2].Is_First_Captured = 0; // set it back to false

			// set polarity to rising edge
			__HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_3, TIM_INPUTCHANNELPOLARITY_RISING);
			__HAL_TIM_DISABLE_IT(&htim1, TIM_IT_CC3);
		}
	}

	if (   (htim == &htim1)  && htim->Channel == HAL_TIM_ACTIVE_CHANNEL_4)  // if the interrupt source is channel1
	{
		if (HCSR04_sensor[3].Is_First_Captured==0) // if the first value is not captured
		{
			HCSR04_sensor[3].IC_Val1 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_4); // read the first value
			HCSR04_sensor[3].Is_First_Captured = 1;  // set the first captured as true
			// Now change the polarity to falling edge
			__HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_4, TIM_INPUTCHANNELPOLARITY_FALLING);
		}

		else if (HCSR04_sensor[3].Is_First_Captured==1)   // if the first is already captured
		{
			HCSR04_sensor[3].IC_Val2 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_4);  // read second value
			__HAL_TIM_SET_COUNTER(htim, 0);  // reset the counter

			if (HCSR04_sensor[3].IC_Val2 > HCSR04_sensor[3].IC_Val1)
			{
				HCSR04_sensor[3].Difference = HCSR04_sensor[3].IC_Val2-HCSR04_sensor[3].IC_Val1;
			}

			else if (HCSR04_sensor[3].IC_Val1 > HCSR04_sensor[3].IC_Val2)
			{
				HCSR04_sensor[3].Difference = (0xffff - HCSR04_sensor[3].IC_Val1) + HCSR04_sensor[3].IC_Val2;
			}

			HCSR04_sensor[3].Distance = HCSR04_sensor[3].Difference * .034/2;
			HCSR04_sensor[3].Is_First_Captured = 0; // set it back to false

			// set polarity to rising edge
			__HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_4, TIM_INPUTCHANNELPOLARITY_RISING);
			__HAL_TIM_DISABLE_IT(&htim1, TIM_IT_CC4);
		}
	}
}
void HCSR04_Init(void)
{
	HAL_TIM_IC_Start_IT(&htim1, TIM_CHANNEL_1);
	HAL_TIM_IC_Start_IT(&htim1, TIM_CHANNEL_2);
	HAL_TIM_IC_Start_IT(&htim1, TIM_CHANNEL_3);
	HAL_TIM_IC_Start_IT(&htim1, TIM_CHANNEL_4);
}

void HCSR04_Read1 (void)
{
	HAL_GPIO_WritePin(TRIG_PORT_1, TRIG_PIN_1, GPIO_PIN_SET);  // pull the TRIG pin HIGH
	delay(10);  // wait for 10 us
	HAL_GPIO_WritePin(TRIG_PORT_1, TRIG_PIN_1, GPIO_PIN_RESET);  // pull the TRIG pin low

	__HAL_TIM_ENABLE_IT(&htim1, TIM_IT_CC1);
}

void HCSR04_Read2 (void)
{
	HAL_GPIO_WritePin(TRIG_PORT_2, TRIG_PIN_2, GPIO_PIN_SET);  // pull the TRIG pin HIGH
	delay(10);  // wait for 10 us
	HAL_GPIO_WritePin(TRIG_PORT_2, TRIG_PIN_2, GPIO_PIN_RESET);  // pull the TRIG pin low

	__HAL_TIM_ENABLE_IT(&htim1, TIM_IT_CC2);
}

void HCSR04_Read3 (void)
{
	HAL_GPIO_WritePin(TRIG_PORT_3, TRIG_PIN_3, GPIO_PIN_SET);  // pull the TRIG pin HIGH
	delay(10);  // wait for 10 us
	HAL_GPIO_WritePin(TRIG_PORT_3, TRIG_PIN_3, GPIO_PIN_RESET);  // pull the TRIG pin low

	__HAL_TIM_ENABLE_IT(&htim1, TIM_IT_CC3);
}

void HCSR04_Read4 (void)
{
	HAL_GPIO_WritePin(TRIG_PORT_4, TRIG_PIN_4, GPIO_PIN_SET);  // pull the TRIG pin HIGH
	delay(10);  // wait for 10 us
	HAL_GPIO_WritePin(TRIG_PORT_4, TRIG_PIN_4, GPIO_PIN_RESET);  // pull the TRIG pin low

	__HAL_TIM_ENABLE_IT(&htim1, TIM_IT_CC4);
}

