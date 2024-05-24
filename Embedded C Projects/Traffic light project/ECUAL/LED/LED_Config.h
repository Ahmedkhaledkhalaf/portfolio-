/*
 * LED.h
 *
 * Created: 11/9/2022 7:55:37 PM
 *  Author: Eng Ahmed khaled
 */ 


#ifndef LED_CONFIG_H_
#define LED_CONFIG_H_


#include "../../MCAL/DIO/DIO_CONFIG.h"
#include "../MCAL/TIMERS/Timers_Config.h"
// Car leds port and pins
#define CARS_LED_PORT                DIO_PORTA
#define CARS_LED_R_PIN               PIN0
#define CARS_LED_Y_PIN               PIN1
#define CARS_LED_G_PIN               PIN2

// Pedestrian leds port and pins
#define PED_LED_PORT                 DIO_PORTB
#define PED_LED_R_PIN                PIN0
#define PED_LED_Y_PIN                PIN1
#define PED_LED_G_PIN                PIN2

void LED_init(u8 LedPortID, u8 LedPinID);
void LED_on(u8 LedPortID, u8 LedPinID);
void LED_off(u8 LedPortID, u8 LedPinID);
void LED_toggle(u8 LedPortID, u8 LedPinID);


#endif /* LED_CONFIG_H_ */