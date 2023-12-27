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
  HAL_TIM_Base_Start_IT(&htim6);
  f_mount(&USERFatFS, USERPath, 0);
  printf("USERPath: %s\r\n", USERPath);
  lv_init();
  lv_port_disp_init();
  lv_port_indev_init();
  setup_ui(&guider_ui);

  // NRF24L01_Init();   // 初始化NRF24L01
  // POINT_COLOR = RED; // 设置字体为红色
  // LCD_ShowString(60, 50, 200, 16, 16, "Mini STM32");
  // LCD_ShowString(60, 70, 200, 16, 16, "NRF24L01 TEST");
  // LCD_ShowString(60, 90, 200, 16, 16, "ATOM@ALIENTEK");
  // LCD_ShowString(60, 110, 200, 16, 16, "2014/3/12");
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    // while (NRF24L01_Check()) // 检查NRF24L01是否在位.
    // {
    //   LCD_ShowString(60, 130, 200, 16, 16, "NRF24L01 Error");
    //   HAL_Delay(200);
    //   LCD_Fill(60, 130, 239, 130 + 16, WHITE);
    //   HAL_Delay(200);
    // }
    // LCD_ShowString(60, 130, 200, 16, 16, "NRF24L01 OK");
    // mode=0;
    // LCD_Fill(10, 150, 240, 166, WHITE); // 清空上面的显示
    // POINT_COLOR = BLUE;                 // 设置字体为蓝色
    // if (mode == 0)                      // RX模式
    // {
    //   LCD_ShowString(60, 150, 200, 16, 16, "NRF24L01 RX_Mode");
    //   LCD_ShowString(60, 170, 200, 16, 16, "Received DATA:");
    //   NRF24L01_RX_Mode();
    //   while (1)
    //   {
    //     if (NRF24L01_RxPacket(tmp_buf) == 0) // 一旦接收到信息,则显示出来.
    //     {
    //       tmp_buf[32] = 0; // 加入字符串结束符
    //       LCD_ShowString(0, 190, 239, 32, 16, tmp_buf);
    //     }
    //     else
    //       delay_us(100);
    //     t++;
    //     if (t == 10000) // 大约1s钟改变一次状态
    //     {
    //       t = 0;
    //     }
    //   };
    // }
    // else // TX模式
    // {
    //   LCD_ShowString(60, 150, 200, 16, 16, "NRF24L01 TX_Mode");
    //   NRF24L01_TX_Mode();
    //   mode = ' '; // 从空格键开始
    //   while (1)
    //   {
    //     if (NRF24L01_TxPacket(tmp_buf) == TX_OK)
    //     {
    //       LCD_ShowString(60, 170, 239, 32, 16, "Sended DATA:");
    //       LCD_ShowString(0, 190, 239, 32, 16, tmp_buf);
    //       key = mode;
    //       for (t = 0; t < 32; t++)
    //       {
    //         key++;
    //         if (key > ('~'))
    //           key = ' ';
    //         tmp_buf[t] = key;
    //       }
    //       mode++;
    //       if (mode > '~')
    //         mode = ' ';
    //       tmp_buf[32] = 0; // 加入结束符
    //     }
    //     else
    //     {
    //       LCD_ShowString(60, 170, 239, 32, 16, "Send Failed ");
    //       LCD_Fill(0, 188, 240, 218, WHITE); // 清空上面的显示
    //     };
    //     HAL_Delay(1500);
    //   };
    // }
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
    lv_task_handler();
    HAL_Delay(30);
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
