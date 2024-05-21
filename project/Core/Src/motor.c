/*
  * @file:       motor.c
 * @brief:       Source file of the motor driver.
 * @Created on:  Apr 24, 2024
 *      Author: samy
 */

/* USER CODE BEGIN Includes */
#include "tim.h"
#include "gpio.h"
#include "motor.h"
/* USER CODE END Includes */

/* Functions Implementation BEGIN   */



/**
  * @brief  Initializes motor's pins.
  * @param  None
  * @retval None
  */
void Motor_voidInit(void)
{
	/* Generate PWM for the four motors*/
	TIM3->CCR1 = 0;
	TIM3->CCR2 = 100;

	HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_1); /* Give same PWM signal to motor1  */
	HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_2);  /* Give same PWM signal to motor2  */
}
/**
  * @brief  Give Duty cycle to the motor to can move it by the speed which you need  .
  * @param  DutyCycle value of Duty cycle (0-->100) for PWM signal
  * @retval None
  */
void Motor_voidControlSpeed(uint16_t DutyCycle)
{
	TIM3->CCR1 = DutyCycle;
}
/**
  * @brief  Move motor forward.
  * @param  None
  * @retval None
  */
void Motor_voidMoveForward(uint16_t DutyCycle)
{
	/* STOP the Front motor  */
	// HAL_GPIO_WritePin(MOTOR1_D1_GPIO_Port, MOTOR1_D1_Pin, GPIO_PIN_RESET);
	// HAL_GPIO_WritePin(MOTOR1_D2_GPIO_Port, MOTOR1_D2_Pin, GPIO_PIN_RESET);
	/* Turn on The back motor  */
	HAL_GPIO_WritePin(MOTOR2_D1_GPIO_Port, MOTOR2_D1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(MOTOR2_D2_GPIO_Port, MOTOR2_D2_Pin, GPIO_PIN_RESET);
	Motor_voidControlSpeed(DutyCycle);
}
/**
  * @brief Move motor backward.
  * @param  None
  * @retval None
  */
void Motor_voidMoveBackward(uint16_t DutyCycle)
{
		/* STOP the Front motor  */
		// HAL_GPIO_WritePin(MOTOR1_D1_GPIO_Port, MOTOR1_D1_Pin, GPIO_PIN_RESET);
		// HAL_GPIO_WritePin(MOTOR1_D2_GPIO_Port, MOTOR1_D2_Pin, GPIO_PIN_RESET);
		/* Turn on The back motor  */
		HAL_GPIO_WritePin(MOTOR2_D1_GPIO_Port, MOTOR2_D1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(MOTOR2_D2_GPIO_Port, MOTOR2_D2_Pin, GPIO_PIN_SET);
		Motor_voidControlSpeed(DutyCycle);
}

/**
  * @brief Move motor Right.
  * @param  None
  * @retval None
  */
void Motor_voidMoveRight(uint16_t DutyCycle)
{
	/* STOP the Front motor  */
	HAL_GPIO_WritePin(MOTOR1_D1_GPIO_Port, MOTOR1_D1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(MOTOR1_D2_GPIO_Port, MOTOR1_D2_Pin, GPIO_PIN_RESET);
	/* Turn on The back motor  */
	//HAL_GPIO_WritePin(MOTOR2_D1_GPIO_Port, MOTOR2_D1_Pin, GPIO_PIN_SET);
	//HAL_GPIO_WritePin(MOTOR2_D2_GPIO_Port, MOTOR2_D2_Pin, GPIO_PIN_RESET);
	//Motor_voidControlSpeed(DutyCycle);
}
/**
  * @brief Move motor Left.
  * @param  None
  * @retval None
  */
void Motor_voidMoveLeft(uint16_t DutyCycle)
{
	/* STOP the Front motor  */
	HAL_GPIO_WritePin(MOTOR1_D1_GPIO_Port, MOTOR1_D1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(MOTOR1_D2_GPIO_Port, MOTOR1_D2_Pin, GPIO_PIN_SET);
}
/**
  * @brief Stop motor.
  * @param  None
  * @retval None
  */
void Motor_voidStop(void)
{
	/* STOP the Front motor  */
	HAL_GPIO_WritePin(MOTOR1_D1_GPIO_Port, MOTOR1_D1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(MOTOR1_D2_GPIO_Port, MOTOR1_D2_Pin, GPIO_PIN_RESET);
	/* Turn on The back motor  */
	HAL_GPIO_WritePin(MOTOR2_D1_GPIO_Port, MOTOR2_D1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(MOTOR2_D2_GPIO_Port, MOTOR2_D2_Pin, GPIO_PIN_RESET);

}

void Motor_voidMoveMiddle (void)
{
	/* STOP the Front motor  */
	HAL_GPIO_WritePin(MOTOR1_D1_GPIO_Port, MOTOR1_D1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(MOTOR1_D2_GPIO_Port, MOTOR1_D2_Pin, GPIO_PIN_RESET);
}

/* Functions Implementation END */
void Motor_voidDirection(uint8_t M_direction)
{
	switch (M_direction)
	{
	case M_L:	Motor_voidMoveLeft(0);	break;
	case M_R:	Motor_voidMoveRight(0);	break;
	case M_M:	Motor_voidMoveMiddle();	break;
	default:							break;
	}
}

/************* TO DO *************************
 * make 3 positions for direction  R	M	L 
	*the uart message for right or left move you one step 
*  make the forward and backward motor only for the car straight line control   
*/