/*
 * @file Startup.s
 * @author Ahmed Khaled Khalaf (khalafawy22899@gmail.com)
 * @brief startup code for Arm cortexM3 stm32
 * @version 0.1
 * @date 2024-05-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */
 
 /*SRAM 0x20000000 */
 .section .vectors
 
 
.word 0x20001000		/*stack top address*/
.word _reset			/* 1 Reset */
.word Vector_handler	/* 2NMI */
.word Vector_handler	/* 3 Hard Fault */
.word Vector_handler	/* 4 MM Fault */
.word Vector_handler	/* 5 Bus Fault */
.word Vector_handler	/* 6 Usage Fault */
.word Vector_handler	/* 7 RESERVED */
.word Vector_handler	/* 8 RESERVED */
.word Vector_handler	/* 9 RESERVED */
.word Vector_handler	/* 10 RESERVED */
.word Vector_handler	/* 11 SV call */
.word Vector_handler	/* 12 Debug RESERVED */
.word Vector_handler	/* 13 RESERVED */
.word Vector_handler	/* 14 PendSV */
.word Vector_handler	/* 15 SysTick */
.word Vector_handler	/* 16 IRQ0 */
.word Vector_handler	/* 17 IRQ1 */
.word Vector_handler	/* 18 IRQ2 */
.word Vector_handler	/* 18 IRQ3 */
.word Vector_handler	/* 18 IRQ4 */
.word Vector_handler	/* 18 IRQ5 */
.word Vector_handler	/* 18 IRQ6 */

				/* End OF Vector Table */
				


 .section .text

 _reset:
	bl main
	b .
.thumb_func		/* to enable the switching between 32 and 16 bits ld and str */


Vector_handler:
	b _reset