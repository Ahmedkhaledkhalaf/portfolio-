/*
 * APPLICATION_Config.h
 *
 * Created: 11/9/2022 8:21:08 PM
 *  Author: Eng Ahmed khaled
 */ 


#ifndef APPLICATION_CONFIG_H_
#define APPLICATION_CONFIG_H_

#include "../SERVICE (UTILS)/ATMEGA32_REGS.h"
#include "../SERVICE (UTILS)/DATA_TYPES.h"

#include "../ECUAL/LED/LED_Config.h"
#include "../ECUAL/PUSH BUTTON/PUSHBUTTON_Config.h"


#define F_CPU 1000000U

//** Execution phases **//
#define phase_1 0
#define phase_2 1
#define phase_3 2
#define phase_4 3

void APP_Init(void);
void APP_Start(void);



#endif /* APPLICATION_CONFIG_H_ */