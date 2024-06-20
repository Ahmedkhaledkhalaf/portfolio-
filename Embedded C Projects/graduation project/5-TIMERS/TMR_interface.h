/*
 * TMR_interface.h
 *
 * Created: 11/12/2022 10:15:37 PM
 *  Author: AMIT
 */ 


#ifndef TMR_INTERFACE_H_
#define TMR_INTERFACE_H_

#define TMR_TIMER0_NORMAL_MODE        1
#define TMR_TIMER0_CTC_MODE           2
#define TMR_TIMER0_FAST_PWM_MODE      3

/* TIMER0 */
void TMR_timer0Init                (void);
void TMR_timer0setCompareMatchValue(u8 compareValue);
void TMR_timer0_CTC_SetCallBack    (void (*ptr)(void));


/* TIMER1 */
void TMR_timer1Init(void);
void TMR_timer1setCompareMatchAValue(u16 compareValue);


#endif /* TMR_INTERFACE_H_ */