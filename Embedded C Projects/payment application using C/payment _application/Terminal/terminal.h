/**
 * @file terminal.h
 * @author Ahmed khaled khalaf (khalafawy22899@gmail.com)
 * @brief file conatins prototypes and definantions
 * @version 0.1
 * @date 2022-10-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>


#ifndef TERMINAL_H
#define TERMINAL_H

#include "../Card/card.h"
typedef unsigned char uint8_t;

typedef struct ST_terminalData_t
{
float transAmount;
float maxTransAmount;
uint8_t transactionDate[11];
}ST_terminalData_t;

typedef enum EN_terminalError_t
{
TERMINAL_OK, WRONG_DATE, EXPIRED_CARD, INVALID_CARD, INVALID_AMOUNT, EXCEED_MAX_AMOUNT, INVALID_MAX_AMOUNT
}EN_terminalError_t ;

EN_terminalError_t getTransactionDate(ST_terminalData_t *termData);
EN_terminalError_t isCardExpired(ST_cardData_t cardData, ST_terminalData_t termData);
EN_terminalError_t isValidCardPAN(ST_cardData_t *cardData);
EN_terminalError_t getTransactionAmount(ST_terminalData_t *termData);
EN_terminalError_t isBelowMaxAmount(ST_terminalData_t *termData);
EN_terminalError_t setMaxAmount(ST_terminalData_t *termData);

//test functions

EN_terminalError_t getTransactionDateTest(EN_terminalError_t (*TestFunction)(ST_terminalData_t *termData), ST_terminalData_t *termData);
EN_terminalError_t isCardExpiredTest(EN_terminalError_t (*TestFunction)(ST_cardData_t cardData, ST_terminalData_t termData),ST_cardData_t cardData, ST_terminalData_t termData);
EN_terminalError_t isValidCardPANTest(EN_terminalError_t (*TestFunction)(ST_cardData_t *cardData), ST_cardData_t *cardData);
EN_terminalError_t isBelowMaxAmountTest(EN_terminalError_t (*TestFunction)(ST_terminalData_t *termData), ST_terminalData_t *termData);
#endif /* header guard */