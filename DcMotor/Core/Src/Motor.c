#include "Motor.h"


void Motor_Move_R(void)
{
    HAL_GPIO_WritePin(MOTOR_D1_GPIO_Port,MOTOR_D1_Pin,1);
    HAL_GPIO_WritePin(MOTOR_D2_GPIO_Port,MOTOR_D2_Pin,0);
}

void Motor_Move_L(void)
{
    HAL_GPIO_WritePin(MOTOR_D1_GPIO_Port,MOTOR_D1_Pin,0);
    HAL_GPIO_WritePin(MOTOR_D2_GPIO_Port,MOTOR_D2_Pin,1);
}

void Motor_Stop(void)
{
    HAL_GPIO_WritePin(MOTOR_D1_GPIO_Port,MOTOR_D1_Pin,0);
    HAL_GPIO_WritePin(MOTOR_D2_GPIO_Port,MOTOR_D2_Pin,0);
}

void Motor_Set_Speed(uint8_t MotorSpeed)
{
    TIM2->CCR1 = MotorSpeed;
    /*Don't Miss to add this line in the main function */
    //HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_1);
}
