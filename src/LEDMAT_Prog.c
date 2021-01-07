/******************************************************************/
/*             >>DATE:22/11/2020                                  */
/*             >>AUTHOR:ELSAYED MANSOUR SHALABY                   */
/*             >>VERSION:0.1                                      */
/******************************************************************/
#include"../include/BIT_MATH.h"
#include"../include/STD_TYPES.h"
#include"../include/GPIO_Priv.h"
#include"../include/GPIO_INT.h"
#include"../include/LEDMAT_INT.h"
#include"../include/LEDMAT_Config.h"
#include"../include/SYSTICK_Priv.h"
#include"../include/SYSTICK_INT.h"
void LEDMAT_VidINIT(void)
{
	MGPIO_VidSetGPIODirection(COLUM_PORT, 0X22222222, LOW_REG);
	MGPIO_VidSetGPIODirection(ROW_PORT, 0X22222222, HIGH_REG);
}
void LEDMAT_VidDisplayFrame(u8 *Copyu8Data)
{
	/*Disable All Colums*/
	MGPIO_VidSetGPIOValue(COLUM_PORT, HIGH_LEDMAT); 
	/*Disable All Rows*/
	MGPIO_VidSetGPIOValue(ROW_PORT, LOW_LEDMAT);
	for(u8 LOC_u8Counter=0;LOC_u8Counter<8;LOC_u8Counter++)
	{
	MGPIO_VidSetPinValue(COLUM_PORT, LOC_u8Counter, LOW);
	MGPIO_VidSetGPIOValue(ROW_PORT, (Copyu8Data[LOC_u8Counter])<<8);
	MSTK_VidSetBusyWait(2500);
		/*Disable All Colums*/
	MGPIO_VidSetGPIOValue(COLUM_PORT, HIGH_LEDMAT); 
	/*Disable All Rows*/
	MGPIO_VidSetGPIOValue(ROW_PORT, LOW_LEDMAT);
	}
}
