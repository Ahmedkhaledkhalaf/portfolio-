/*
 * KeyPad_Prog.c
 *
 * Created: 10/29/2022 11:24:37 PM
 *  Author: Eng Ahmed khaled
 */ 


/*UTILS*/
#include "DATA_TYPES.h"
#include "BIT_MATH.h"

/*HAL*/
#include "KeyPad_Config.h"
#include "KeyPad_interface.h"

/*MCAL*/
#include "DIO_CONFIG.h"


// Global arrays of each column and each row relating the connection of them with the DIO
u8 static ColomPins[] = {KPD_colom0_Pin, KPD_colom1_Pin, KPD_colom2_Pin, KPD_colom3_Pin};
u8 static  RowsPins[] = {KPD_Row0_Pin, KPD_Row1_Pin, KPD_Row2_Pin, KPD_Row3_Pin};
u8 static   PIN_VALUE = 0;	
// The Data of the KeyPad Buttons
u8 KPD_Buttons_Data[4][4] = {{ '1', '2', '3', 'A'}, {'4', '5', '6', 'B'}, {'7', '8', '9', 'C'}, {'*', '0', '#', 'D'}};
	
//using update method
void KPD_getvalue(u8* retval)
{
	*retval = KPD_NOT_PRESSED;
    u8 ColumnsCounter, RowsCounter;
    u8 PINFLAG = 0;
    for (ColumnsCounter = 0; ColumnsCounter < 4; ColumnsCounter++) // iterates on every column 
    {
		//Activate the current column 
        DIO_PinValue(KPD_Cols_Port, ColomPins[ColumnsCounter], LOW);
		//check each row 
		for (RowsCounter = 0; RowsCounter<4; RowsCounter++) // iterates on each row (the row which have value of zero will have the pressed button 
		{
			PIN_VALUE = DIO_GET_PIN_VALUE(KPD_Rows_Port,RowsPins[RowsCounter]);
			
			if (PIN_VALUE == 0)
			{
				// saves the value of the pressed button
				*retval = KPD_Buttons_Data[RowsCounter][ColumnsCounter];
				//preventing the long pressing on the button (the long press is just one press)
				while(PIN_VALUE == 0)
				{
					PIN_VALUE = DIO_GET_PIN_VALUE(KPD_Rows_Port,RowsPins[RowsCounter]);
				}
				
				PINFLAG = 1;
				break;
			}
			
		}
		//Deactivate the current column
		DIO_PinValue(KPD_Cols_Port, ColomPins[ColumnsCounter], HIGH);
		if (PINFLAG == 1)
		{
			break;
		}
    }
	
}



void KPD_init(void)
{
	DIO_SetPinDirection(KPD_Cols_Port, KPD_colom0_Pin, DIO_PIN_OUTPUT);
	DIO_SetPinDirection(KPD_Cols_Port, KPD_colom1_Pin, DIO_PIN_OUTPUT);
	DIO_SetPinDirection(KPD_Cols_Port, KPD_colom2_Pin, DIO_PIN_OUTPUT);
	DIO_SetPinDirection(KPD_Cols_Port, KPD_colom3_Pin, DIO_PIN_OUTPUT);
	
	DIO_PinValue(KPD_Cols_Port, KPD_colom0_Pin, HIGH);
	DIO_PinValue(KPD_Cols_Port, KPD_colom1_Pin, HIGH);
	DIO_PinValue(KPD_Cols_Port, KPD_colom2_Pin, HIGH);
	DIO_PinValue(KPD_Cols_Port, KPD_colom3_Pin, HIGH);
	
	
	DIO_SetPinDirection(KPD_Rows_Port, KPD_Row0_Pin, DIO_PIN_INPUT);
	DIO_SetPinDirection(KPD_Rows_Port, KPD_Row1_Pin, DIO_PIN_INPUT);
	DIO_SetPinDirection(KPD_Rows_Port, KPD_Row2_Pin, DIO_PIN_INPUT);
	DIO_SetPinDirection(KPD_Rows_Port, KPD_Row3_Pin, DIO_PIN_INPUT);
	
	DIO_ActevatePullUp(KPD_Rows_Port, KPD_Row0_Pin);
	DIO_ActevatePullUp(KPD_Rows_Port, KPD_Row1_Pin);
	DIO_ActevatePullUp(KPD_Rows_Port, KPD_Row2_Pin);
	DIO_ActevatePullUp(KPD_Rows_Port, KPD_Row3_Pin);
}