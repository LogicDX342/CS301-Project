/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
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
#include "main.h"
#include "fatfs.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "lcd.h"
#include "touch.h"
#include "remote.h"
#include "24cxx.h"
#include "24l01.h"
#include "ff.h"
#include "lv_conf.h"
#include "lv_port_disp.h"
#include "lv_port_indev.h"
#include "gui_guider.h"

#include <stdio.h>
#include <string.h>
#include "chat.h"
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

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
lv_ui guider_ui;
u8 key, mode;
u8 tmp_buf[33]; 
u16 t=0;
extern UART_HandleTypeDef huart1;
extern uint8_t uBuffer[20];
extern u8 current_user;
u8 user0_online = 0;
u8 user1_online = 0;
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART1_UART_Init();
  MX_SPI1_Init();
  MX_FATFS_Init();
  MX_TIM5_Init();
  MX_TIM6_Init();
  /* USER CODE BEGIN 2 */
  NRF24L01_Init(); 
  Remote_Init();
  LCD_Init();
  tp_dev.init();
  HAL_UART_Receive_IT(&huart1, (uint8_t *)uBuffer,1);
  HAL_TIM_Base_Start_IT(&htim6);
  f_mount(&USERFatFS, USERPath, 0);
  printf("USERPath: %s\r\n", USERPath);
  lv_init();
  lv_port_disp_init();
  lv_port_indev_init();
  setup_ui(&guider_ui);


  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  if(lv_scr_act() == guider_ui.Homepage){
  		  if(current_user == 0){
  		  	  lv_label_set_text(guider_ui.Homepage_username_label, "Jerry");
  		    }else if (current_user == 1){
  		  	  lv_label_set_text(guider_ui.Homepage_username_label, "Tom");
  		    }else if (current_user == 2){
  		  	  lv_label_set_text(guider_ui.Homepage_username_label, "Scott");
  		    }
  }
  while (1)
  {
	  t++;
	  if(t == 30){
		  t = 0;
		  strcpy((char *)tmp_buf, "Hello!");
			if(simple_send(ECHO, current_user, 0, tmp_buf)){
				if(user0_online == false){
					user0_online = true;
					pop_msgbox("user0 online");

				}

			}else{
				if(user0_online == true){
					user0_online = false;
					pop_msgbox("user0 offline");
				}

			}

			if(simple_send(ECHO, current_user, 1, tmp_buf)){
				if(user1_online == false){
					user1_online = true;
					pop_msgbox("user1 online");

				}

			}else{
				if(user1_online == true){

					user1_online = false;
					pop_msgbox("user1 offline");

				}
			}



		  if(lv_scr_act() == guider_ui.chat){
			  if(user0_online){
				  lv_obj_set_style_text_color(guider_ui.chat_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
			  }else{
				  lv_obj_set_style_text_color(guider_ui.chat_btn_1, lv_color_hex(0xff0000), LV_PART_MAIN|LV_STATE_DEFAULT);
			  }

			  if(user1_online){
				  lv_obj_set_style_text_color(guider_ui.chat_btn_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
			  }else{
				  lv_obj_set_style_text_color(guider_ui.chat_btn_2, lv_color_hex(0xff0000), LV_PART_MAIN|LV_STATE_DEFAULT);
			  }
		  }
	  }


    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
    lv_task_handler();
    HAL_Delay(100);
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
