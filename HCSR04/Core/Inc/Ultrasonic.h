/**********************************************
 * @SWC: Ultrasonic.h
 * @date: May 2, 2024
 * @author:Hossam Emad 
************************************************/
#ifndef _INC_ULTRASONIC_H_
#define _INC_ULTRASONIC_H_

#include "main.h"

#define TRIG_PIN_1 GPIO_PIN_13
#define TRIG_PORT_1 GPIOB
typedef struct
{
	uint32_t IC_Val1;
	uint32_t IC_Val2;
	uint32_t Difference;
	uint8_t Is_First_Captured;  // is the first value captured ?
	uint8_t Distance;
} Ultrasonic_t;

void delay (uint16_t time);
void HCSR04_Init(void);
void HCSR04_Read1 (void);
uint8_t Get_Distance(void);

#endif 
