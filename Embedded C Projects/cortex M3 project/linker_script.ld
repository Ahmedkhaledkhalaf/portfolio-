/*
 * @file linker script.ld
 * @author Ahmed Khaled Khalaf (khalafawy22899@gmail.com)
 * @brief linker script for Arm cortexM3 stm32 project
 * @version 0.1
 * @date 2024-05-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */
 
 MEMORY
 {
	FLASH (RX) : ORIGIN = 0x08000000, LENGTH = 128K
	SRAM (RWX) : ORIGIN = 0x20000000, LENGTH = 20K
}

SECTIONS
{
	.text : {
			*(.vectors*)
			*(.text*)
			*(.rodata)
	}>FLASH
	
	.data : {
			*(.data)

	}>FLASH 

	
	.bss : {
			*(.bss)
	}>SRAM

}