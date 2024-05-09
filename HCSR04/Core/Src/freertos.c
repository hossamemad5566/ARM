/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include"Ultrasonic.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
/* Definitions for Led */
osThreadId_t LedHandle;
const osThreadAttr_t Led_attributes = {
  .name = "Led",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityBelowNormal3,
};
/* Definitions for distance */
osThreadId_t distanceHandle;
const osThreadAttr_t distance_attributes = {
  .name = "distance",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime7,
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void Led_Task(void *argument);
void distance_get(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of Led */
  LedHandle = osThreadNew(Led_Task, NULL, &Led_attributes);

  /* creation of distance */
  distanceHandle = osThreadNew(distance_get, NULL, &distance_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_Led_Task */
/**
  * @brief  Function implementing the Led thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_Led_Task */
void Led_Task(void *argument)
{
  /* USER CODE BEGIN Led_Task */
  /* Infinite loop */
  for(;;)
  {
    HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
    HAL_UART_Transmit(&huart1,(uint8_t*)"Led_T",6,HAL_MAX_DELAY);
    osDelay(200);
  }
  /* USER CODE END Led_Task */
}

/* USER CODE BEGIN Header_distance_get */
/**
* @brief Function implementing the distance thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_distance_get */
void distance_get(void *argument)
{
  /* USER CODE BEGIN distance_get */
  HCSR04_Init();
  uint8_t distance =0;
  /* Infinite loop */
  for(;;)
  {
    distance = Get_Distance();
    if(distance > 5)
    {
      HAL_GPIO_WritePin(LED_O_GPIO_Port,LED_O_Pin,GPIO_PIN_RESET);
    }
    else{
      HAL_GPIO_WritePin(LED_O_GPIO_Port,LED_O_Pin,GPIO_PIN_SET);
    }
    HAL_UART_Transmit(&huart1,&distance,1,10);
  }
  /* USER CODE END distance_get */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */
