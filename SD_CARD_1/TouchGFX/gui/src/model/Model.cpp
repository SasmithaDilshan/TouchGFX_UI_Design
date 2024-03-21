#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#include "main.h"
#include "fatfs.h"
#include "ff.h" // Include the FATFS header file
#include <string.h>
#include <stdbool.h>

extern "C"
{

	FRESULT n;
	extern UART_HandleTypeDef huart1;
	extern char SDPath[4]; /* SD logical drive path */
	extern FATFS SDFatFS; /* File system object for SD logical drive */
	extern FIL SDFile;
}
Model::Model() : modelListener(0)
{

}

void Model::tick()
{

}
void Model::loaddata(char *data)
{

	f_mount(&SDFatFS, (TCHAR const*)SDPath, 0);



	n = (f_open(&SDFile,"STM.txt",FA_READ));
	if (n != FR_OK){
		Error_Handler();
	}

	while (f_gets(data, sizeof(data),&SDFile) != NULL)
	{
	            // Send data over UART

		HAL_UART_Transmit(&huart1, (uint8_t*)data, strlen(data), 1000);
	}
//	else
//	{
	f_close(&SDFile);
//	}

}
