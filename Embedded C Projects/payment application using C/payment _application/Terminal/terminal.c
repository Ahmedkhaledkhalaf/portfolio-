/**
 * @file terminal.c
 * @author Ahmed khaled khalaf (khalafawy22899@gmail.com)
 * @brief file contains the implementation of the functions of the terminal module
 * @version 0.1
 * @date 2022-10-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include "terminal.h"


EN_terminalError_t getTransactionDate(ST_terminalData_t *termData)
{
    printf("\nPlease enter the date of transaction\nnote:the date format must be 'DD/MM/YYYY':\t");
    fflush(stdin);
    gets(termData->transactionDate);
    uint8_t is = (strlen(termData->transactionDate));
    if ( is < 10)
    {
        return WRONG_DATE;
    }
    else
    {
        return TERMINAL_OK;
    }

}

EN_terminalError_t isCardExpired(ST_cardData_t cardData, ST_terminalData_t termData)
{
    uint8_t* ex_date = cardData.cardExpirationDate;
    uint8_t* trans_date = &termData.transactionDate[3];
    uint8_t ex_date_years = (10 * atoi(ex_date[3])) + atoi(ex_date[4]);
    uint8_t ex_date_month = (10 * atoi(ex_date[0])) + atoi(ex_date[1]);
    uint8_t trans_date_years = (10 * atoi(trans_date[5])) + atoi(trans_date[6]);
    uint8_t trans_date_month = (10 * atoi(trans_date[0]) + atoi(trans_date[1]));
    
    if (trans_date_years < ex_date_years)
    {
        return OK;
    }
    else if (trans_date_years == ex_date_years && trans_date_month < ex_date_month)
    {
        return OK;
    }
    
    else
    {
        return EXPIRED_CARD;
    }
}
EN_terminalError_t isValidCardPAN(ST_cardData_t *cardData)
{
    if (strlen(cardData -> primaryAccountNumber) < 16)
    {
        return INVALID_CARD;
    }
    else
    {
        return OK;
    }
    
}
EN_terminalError_t getTransactionAmount(ST_terminalData_t *termData)
{
    printf("\n\nPlease enter the transaction amount:\t");
    fflush(stdin);
    scanf("%f", &(termData ->transAmount));

}
EN_terminalError_t isBelowMaxAmount(ST_terminalData_t *termData)
{
if ((termData ->transAmount) < (termData ->maxTransAmount))
{
    return TERMINAL_OK;
}
else
{
    return EXCEED_MAX_AMOUNT;
}
}
EN_terminalError_t setMaxAmount(ST_terminalData_t *termData)
{
   
   termData ->maxTransAmount = 10000.000;
    if (termData->maxTransAmount <= 0)
    {
        return INVALID_MAX_AMOUNT;
    }
    else
    {
        return OK;
    }
    
}


EN_terminalError_t getTransactionDateTest(EN_terminalError_t (*TestFunction)(ST_terminalData_t *termData), ST_terminalData_t *termData)

{
    
    EN_terminalError_t TERMINAL_State = TestFunction(termData);

     printf("\nTester name: Ahmed khaled khalaf\nFunction name: getTransactionDateTest");

if (TERMINAL_State == TERMINAL_OK)
{
    printf("valid trnsaction date.\n");
    printf("\nTest Case 1: Valid transaction date.\\
    \nInput Data: %s\n Expected Result: Valid transaction date!\\
    \nActual Result:Valid transaction date date!", termData->transactionDate);
    
}
else
{
    printf("Invalid trnsaction date.\n");
     printf("\nTest Case 2: Invalid transaction date.\\
    \nInput Data: %s\n Expected Result: Invalid transaction date!\\
    \nActual Result:Invalid transaction date!", termData->transactionDate);
    
}
return TERMINAL_State;
}


EN_terminalError_t isCardExpiredTest(EN_terminalError_t (*TestFunction)(ST_cardData_t cardData, ST_terminalData_t termData),ST_cardData_t cardData, ST_terminalData_t termData)

{
    
    uint8_t TERMINAL_State = TestFunction( cardData, termData);

     printf("\nTester name: Ahmed khaled khalaf\nFunction name: isCardExpiredTest");

if (TERMINAL_State == TERMINAL_OK)
{
    printf("card is not expired\n");
    printf("\nTest Case 1: Valid card.\\
    \nInput Data: %s\n Expected Result: Valid card!\\
    \nActual Result:Valid transaction date date!", termData.transactionDate);
    return TERMINAL_OK;
}
else
{
    printf("card is expired\n");
     printf("\nTest Case 2: Invalid card is expired.\\
    \nInput Data: %s\n Expected Result: Invalid card is expired.!\\
    \nActual Result:Invalid card is expired.!", termData.transactionDate);
    return EXPIRED_CARD;
}
}
EN_terminalError_t isValidCardPANTest(EN_terminalError_t (*TestFunction)(ST_cardData_t *cardData), ST_cardData_t *cardData)

{
    
    uint8_t TERMINAL_State = TestFunction(cardData);

     printf("\nTester name: Ahmed khaled khalaf\nFunction name: isValidCardPANTest");

if (TERMINAL_State == TERMINAL_OK)
{
    printf("Valid card PAN\n");
    printf("\nTest Case 1: Valid card PAN.\\
    \nInput Data: %s\n Expected Result: Valid card PAN!\\
    \nActual Result:Valid card PAN!", cardData->primaryAccountNumber);
    return TERMINAL_OK;
}
else
{
    printf("InValid card PAN\n");
     printf("\nTest Case 2: InValid card PAN.\\
    \nInput Data: %s\n Expected Result: InValid card PAN.!\\
    \nActual Result:InValid card PAN.!", cardData->primaryAccountNumber);
    return INVALID_CARD;
}
}

EN_terminalError_t isBelowMaxAmountTest(EN_terminalError_t (*TestFunction)(ST_terminalData_t *termData), ST_terminalData_t *termData)

{
    
    uint8_t TERMINAL_State = TestFunction(termData);

     printf("\nTester name: Ahmed khaled khalaf\nFunction name: isBelowMaxAmountTest");

if (TERMINAL_State == TERMINAL_OK)
{
    printf("Amount is below the maximum amount\n");
    printf("\nTest Case 1: Amount is below the maximum amount.\\
    \nInput Data: %s\n Expected Result:Amount is below the maximum amount!\\
    \nActual Result:Amount is below the maximum amount!", termData->maxTransAmount);
    return TERMINAL_OK;
}
else
{
    printf("Amount Exceeds the maximum amount\n");
     printf("\nTest Case 2: Amount Exceeds the maximum amount.\\
      \nInput Data: %s\n Expected Result: Amount Exceeds the maximum amount.!\\
       \nActual Result:Amount Exceeds the maximum amount.!", termData->maxTransAmount);

    return EXCEED_MAX_AMOUNT;
}
}
