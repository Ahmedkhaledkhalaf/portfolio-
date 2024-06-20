/**
 * @file bit math.h
 * @author Ahmed Khaled Khalaf (khalafawy22899@gmail.com)
 * @brief A FILE CONTAINS THE BIT WISE OPERATION FUNCTIONS IN EMBEDDED C
 * @version 0.1
 * @date 2022-09-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */
// HEADER GUARD that saves the file from doublication inclusion
#ifndef  BIT_MATH_H
#define BIT_MATH_H

/**
 * @brief  function that set a bit into a register
 * @param REG is the regester name
 * @param BIT_NUM is the index of the bit in the register  
 * @retval the bit with index BIT_NUM in the register REG will has the value 1
 */

#define SET(REG, BIT_NUM) REG |= (1<<BIT_NUM)


/**
 * @brief  function that reset a bit into a register
 * @param REG is the regester name
 * @param BIT_NUM is the index of the bit in the register  
 * @retval the bit with index BIT_NUM in the register REG will has the value 0
 */

#define RESET(REG, BIT_NUM) REG &= ~(1<<BIT_NUM)

/**
 * @brief  function that toggle a bit into a register
 * @param REG is the regester name
 * @param BIT_NUM is the index of the bit in the register  
 * @retval the bit with index BIT_NUM in the register REG will has the value 1 if it has 0 and 0if it has 1
 */
#define TOGGLE(REG, BIT_NUM) REG ^= (1<<BIT_NUM)

/**
 * @brief  function that read a bit into a register
 * @param REG is the regester name
 * @param BIT_NUM is the index of the bit in the register  
 * @retval 1 if the bit has the value of 1 and 0 if it has the value of 0
 */
#define GET_BIT(REG, BIT_NUM) ((REG >> BIT_NUM) & 1)
#endif /*BIT_MATH_H*/