/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include "fsmc.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "lcd.h"
#include "touch.h"
#include "stdio.h"
#include "lvgl/lvgl.h"
#include "lvgl_port/lv_port_disp.h"
#include "lvgl_port/lv_port_indev.h"
#include "demos/lv_demos.h"
#include "sram.h"
#include "w25qxx.h"
#include "exfuns.h"
#include "ff.h"
#include "malloc.h"
#include "generated/events_init.h"
#include "generated/gui_guider.h"
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

static void event_handler(lv_event_t *event)
{
  lv_obj_t *obj = lv_event_get_target(event);
  switch (lv_event_get_code(event))
  {
  case LV_EVENT_PRESSED:
    break;
  case LV_EVENT_RELEASED:

    break;
  case LV_EVENT_VALUE_CHANGED:
    if (strcmp((char *)lv_event_get_user_data(event), "sw1") == 0)
    {
      if (lv_obj_has_state(obj, LV_STATE_CHECKED))
        HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, 0);
      else
        HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, 1);
    }
    else if (strcmp((char *)lv_event_get_user_data(event), "sw2") == 0)
    {
      if (lv_obj_has_state(obj, LV_STATE_CHECKED))
        HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, 0);
      else
        HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, 1);
    }

    break;

  default:
    break;
  }
}

/* void vUint16ConvertString(u16 *usWdata, u8 *Rstr, u16 usNBytes)
{
  u8 i, j;
  i = j = 0;
  while (i < usNBytes)
  {
    if ((i % 2) == 0)
      Rstr[i++] = (u8)(usWdata[j] & 0xff);
    else
      Rstr[i++] = (u8)(usWdata[j++] >> 8);
  }
} */

static void lvgl_first_demo_start(void)
{
  /* LV_IMG_DECLARE(debian_s);
  static lv_style_t style;
  lv_style_init(&style);
  lv_style_set_bg_img_src(&style, &debian_s);
  lv_obj_t *sy = lv_obj_create(lv_scr_act());
  lv_obj_add_style(sy, &style, 0);
  lv_obj_set_size(sy, 480, 800);
  lv_obj_center(sy); */

  lv_obj_t *btn = lv_btn_create(lv_scr_act());
  lv_obj_set_pos(btn, 20, 10);
  lv_obj_set_size(btn, 140, 50);
  lv_obj_t *btn1 = lv_btn_create(lv_scr_act());
  lv_obj_set_pos(btn1, 20, 10);
  lv_obj_set_size(btn1, 140, 50);
  lv_obj_add_flag(btn1, LV_OBJ_FLAG_CHECKABLE);

  lv_obj_t *label = lv_label_create(btn);
  lv_label_set_text(label, "button");
  lv_obj_align_to(label, btn, LV_ALIGN_CENTER, 0, 0);

  lv_obj_t *coord_x = lv_label_create(lv_scr_act());
  lv_obj_set_size(coord_x, 120, 20);

  lv_obj_t *coord_y = lv_label_create(lv_scr_act());
  lv_obj_set_size(coord_y, 120, 20);

  lv_obj_t *sw1 = lv_switch_create(lv_scr_act());
  lv_obj_add_event_cb(sw1, event_handler, LV_EVENT_ALL, "sw1");
  lv_obj_t *sw2 = lv_switch_create(lv_scr_act());
  lv_obj_add_event_cb(sw2, event_handler, LV_EVENT_ALL, "sw2");

  lv_obj_t *label1 = lv_label_create(lv_scr_act());
  lv_label_set_text(label1, "Hello,world!");
  lv_obj_align(label1, LV_ALIGN_CENTER, 0, 0);
  lv_obj_align_to(btn, label1, LV_ALIGN_OUT_TOP_MID, 85, -20);
  lv_obj_align_to(btn1, btn, LV_ALIGN_OUT_LEFT_MID, -30, 0);
  lv_obj_align_to(coord_x, label1, LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
  lv_obj_align_to(coord_y, coord_x, LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
  lv_obj_align_to(sw1, coord_y, LV_ALIGN_OUT_BOTTOM_LEFT, -45, 30);
  lv_obj_align_to(sw2, sw1, LV_ALIGN_OUT_RIGHT_MID, 40, 0);

  // vUint16ConvertString(&(tp_dev.x), x, 2);
  // vUint16ConvertString(&(tp_dev.y), y, 2);

  lv_label_set_text_fmt(coord_x, "X: %d", tp_dev.x[0]);
  lv_label_set_text_fmt(coord_y, "Y: %d", tp_dev.y[0]);
}
// lv_ui guider_ui;
/* USER CODE END 0 */

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void)
{
  /* USER CODE BEGIN 1 */
  u32 total, free;
  u8 res = 0;
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
  MX_FSMC_Init();
  MX_TIM3_Init();
  MX_USART1_UART_Init();
  MX_TIM6_Init();
  MX_SPI1_Init();

  /* USER CODE BEGIN 2 */

  lv_init();
  lv_port_disp_init();
  lv_port_indev_init();
  SRAM_Init();
  W25QXX_Init();
  exfuns_init();

  res = f_mount(fs[1], "S:", 1);
  if (res == 0X0D) // FLASH磁盘,FAT文件系统错误,重新格式化FLASH
  {
    // LCD_ShowString(30, 150, 200, 16, 16, "Flash Disk Formatting..."); //格式化FLASH
    res = f_mkfs("S:", 1, 4096); //格式化FLASH,1,盘符;1,不需要引导区,8个扇区为1个簇
    if (res == 0)
    {
      f_setlabel((const TCHAR *)"1:ALIENTEK"); //设置Flash磁盘的名字为：ALIENTEK
      // LCD_ShowString(30, 150, 200, 16, 16, "Flash Disk Format Finish"); //格式化完成
    }
    else
      // LCD_ShowString(30, 150, 200, 16, 16, "Flash Disk Format Error "); //格式化失败
      HAL_Delay(1000);
  }
  HAL_TIM_Base_Start_IT(&htim6);
  // lv_demo_music();
  //  lv_demo_stress();
  // lv_demo_benchmark();
  // lv_demo_widgets();
  lvgl_first_demo_start();
  // setup_ui(&guider_ui);
  // events_init(&guider_ui);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
    lv_task_handler();
    /* POINT_COLOR = WHITE;
    BACK_COLOR = RED;
    LCD_ShowString(10, 40, 240, 40, 24, "LCD_Test, 1234567890"); */
    // HAL_Delay(2000);
    //  HAL_GPIO_TogglePin(BL_GPIO_Port, BL_Pin);
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

  /** Configure the main internal regulator output voltage
   */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
   * in the RCC_OscInitTypeDef structure.
   */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
   */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
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

#ifdef USE_FULL_ASSERT
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
