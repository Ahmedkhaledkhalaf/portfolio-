/*
 * Timer1_interface.h
 *
 * Created: 12/3/2022 7:33:08 PM
 *  Author: Eng Ahmed khaled
 */ 


#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_

 #define TMR_TIMER0_NORMAL_MODE        1
 #define TMR_TIMER0_CTC_MODE           2
 #define TMR_TIMER0_FAST_PWM_MODE      3
 
 /* TIMER 0 */
 
 
 
 void TMR_timer0Init(void);
 void TMR_timer0SetCompareMatchValue(u8 compareVal);
 void TMR_timer0_CTC_SetCallBack(void (*ptr)(void));
 
 
 /* Timer 1 funcs */
 
 void TMR_timer1Init(void);
 
 



#endif /* TIMER1_INTERFACE_H_ */