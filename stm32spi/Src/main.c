/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  ** This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * COPYRIGHT(c) 2018 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "dma.h"
#include "fatfs.h"
#include "sdmmc.h"
#include "spi.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdio.h"
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
//DEL_1
#define SpiEn		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,GPIO_PIN_RESET);
#define SpiDis		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,GPIO_PIN_SET);
#define ResendEn	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET);
#define ResendDis	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_SET);
#define SendDis		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, GPIO_PIN_RESET);
#define SendEn		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, GPIO_PIN_SET);
#define ResetEn 	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET);
#define ResetDis	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_SET);
#define SD_GET_INFO         0x1B1B
#define SD_GET_SIZE         0x2D2D
#define SD_GET_OPEN_SPACE   0x3636
#define SD_LOAD_ISO         0x4E4E
#define SD_TYPE				0x02
#define SD_VER				0x01
#define SD_CAPACITY			0x0000

uint8_t send_data = 32;
uint8_t receive_data = 0;
char readData[32];

FRESULT res;
FATFS SDFatFs;
FIL myFile;
char buffwr[30] = "This is Test programming\n\r";
char buffrd[30];
//char SDPath[10];
uint32_t byteswritten, bytesread;
//enum _bool{
//	false = 0,
//	true = 1;
//};
typedef enum _bool boolean;

/*
 * The Txbuffer in hardware should empty, we have the address, read it.
 * Find the function that takes in the Tx buffer and copies it to the Rx buffer.
 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* Enable I-Cache---------------------------------------------------------*/
  SCB_EnableICache();

  /* Enable D-Cache---------------------------------------------------------*/
  SCB_EnableDCache();

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
  MX_DMA_Init();
  MX_SPI2_Init();
  MX_SPI1_Init();
  MX_SDMMC1_SD_Init();
  MX_FATFS_Init();
  /* USER CODE BEGIN 2 */

  //Init stuff
  SendDis;
  HAL_SPI_Receive_DMA(&hspi2, &receive_data, 1);

  /*
  //FatFS stuff
  FATFS myFATFS;
  FIL myFILE;
  UINT testByte;

  //Write file to SD Card.
  if(f_mount(&myFATFS, SDPath, 1) == FR_OK)
  {
	  //HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12);
	  char myPath[] = "Write1.txt\0";
	  f_open(&myFILE, myPath, FA_WRITE | FA_CREATE_ALWAYS);
	  char myData[] = "Hello World\0";
	  f_write(&myFILE, myData, sizeof(myData), &testByte);
	  f_close(&myFILE);
	  HAL_Delay(1000);
	  //HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_13);
  }

  //Read file from SD Card.
  if(f_mount(&myFATFS, SDPath, 1) == FR_OK)
    {
  	  //HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12);
  	  char myPath[] = "Read1.txt\0";
  	  f_open(&myFILE, myPath, FA_READ | FA_OPEN_ALWAYS);
  	  f_read(&myFILE, readData, 32, &testByte);
  	  f_close(&myFILE);
  	  HAL_Delay(1000);
  	  //HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_13);
    }
    */

  // This checks if there is an SD card inserted. It's inverted in the driver software, so we
  // are checking if "res" is ok rather than not ok. Since this ignores any error that isn't
  // a missing SD card, a better solution would be to invert the signal at the hardware level
  // using a NOT gate and then check if "res" is not ok. Or perhaps get better driver software.
  res = BSP_SD_Init();
  if(res != FR_OK){
	  Error_Handler();
  }

  // String is "C:sdch"
  // Volume is -1 which returns "FR_INVALID_DRIVE"
  // Reason: first checks if path is not null.
  //	Checks for ":" in the path = passes
  //	Check for a numeric drive id = fails because path++ - '0' = 19, which is more than 9
  //	 To pass this part, we need 9 or less.
  //	This part depends on what the path is, just a slash fails the contains ':' check, giving a volume of 0
  //	"C:sdch" gives a volume of -1
  //	0:/ gives volume of 0
  //	Code currently hard faults.
  res = f_mount(&SDFatFs, "0:/", 1);
  if(res != FR_OK){
	  Error_Handler();
  }

  res = f_open(&myFile, "youtube1.txt", FA_OPEN_ALWAYS|FA_WRITE|FA_READ);
  if(res != FR_OK){
	  Error_Handler();
  }

  res = f_lseek(&myFile, f_size(&myFile));
  if(res != FR_OK){
	  Error_Handler();
  }

  f_printf(&myFile, "%s", buffwr);
  if(res != FR_OK){
	  Error_Handler();
  }
  f_close(&myFile);

  res = f_open(&myFile, "youtube1.txt", FA_READ);
  if(res != FR_OK){
	  Error_Handler();
  }

  res = f_read(&myFile, buffrd, 30, &bytesread);
  if(res != FR_OK){
	  Error_Handler();
  }
  f_close(&myFile);
  f_mount(0, "", 1);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_6) == GPIO_PIN_SET)
	  {
		  //Fill send buffer
		  HAL_Delay(15);
		  send_data = SD_TYPE;
		  //Toggle send
		  SendEn;
		  SendDis;
		  while(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_6) != GPIO_PIN_SET){}
		  HAL_Delay(15);
		  //Fill send buffer
		  send_data = 0x00;
		  //Toggle send
		  SendEn;
		  SendDis;
	  }
	  if(receive_data == SD_GET_INFO)
	  {
		  //Fill send buffer
		  send_data = SD_TYPE;
		  //Toggle send
		  SendEn;
		  SendDis;
		  //Wait for receive to be filled with zeroes
		  while(receive_data != 0x00){}
		  //Fill send buffer
		  send_data = 0x00;
		  //Toggle send
		  SendEn;
		  SendDis;
	  }
	  //SpiEn;
	  //HAL_SPI_Transmit_IT(&hspi1, &send_data, 1);
	  //HAL_Delay(1000);
	  //send_data++;

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
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
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};

  /**Configure the main internal regulator output voltage 
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /**Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 216;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /**Activate the Over-Drive mode 
  */
  if (HAL_PWREx_EnableOverDrive() != HAL_OK)
  {
    Error_Handler();
  }
  /**Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_SDMMC1|RCC_PERIPHCLK_CLK48;
  PeriphClkInitStruct.Clk48ClockSelection = RCC_CLK48SOURCE_PLL;
  PeriphClkInitStruct.Sdmmc1ClockSelection = RCC_SDMMC1CLKSOURCE_CLK48;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

void HAL_SPI_TxCpltCallback(SPI_HandleTypeDef *hspi)
{
	if(hspi->Instance == hspi1.Instance)
	{
		SpiDis;
	}
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
	HAL_Delay(100);

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
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
