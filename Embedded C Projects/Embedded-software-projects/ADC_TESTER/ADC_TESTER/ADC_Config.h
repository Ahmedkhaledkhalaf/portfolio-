/*
 * ADC_Config.h
 *
 * Created: 11/11/2022 9:47:27 PM
 *  Author: Eng Ahmed khaled
 */ 


#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

#include "DATA_TYPES.h"


#define ADC_CHANNEL0                    0
#define	ADC_CHANNEL1                    1
#define	ADC_CHANNEL2                    2
#define	ADC_CHANNEL3                    3
#define	ADC_CHANNEL4                    4
#define	ADC_CHANNEL5                    5
#define	ADC_CHANNEL6                    6
#define	ADC_CHANNEL7                    7
/************************************************************************/
/*                         APIS PROTOTYPES                              */
/************************************************************************/

void ADC_Init(void);
void ADC_GetDigitalVal(u16 *RetVal, u8 ChannelNum);



#endif /* ADC_CONFIG_H_ */