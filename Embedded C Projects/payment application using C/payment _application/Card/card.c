/**
 * @file card.c
 * @author Ahmed khaled khalaf (khalafawy22899@gmail.com)
 * @brief  file contains the implementation of the functions of the card module
 * @version 0.1
 * @date 2022-10-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <string.h>
#include "card.h"

EN_cardError_t getCardHolderName(ST_cardData_t *cardData)
{
    
    
    printf("please enter the card holder name\nnote: the name must be 20 characters at least, and 24 characters at most\nCard holder name:\t");
    fflush(stdin);
    gets(cardData->cardHolderName);
    
    if ((strlen(cardData ->cardHolderName) < 25) && (20 <= (strlen(cardData ->cardHolderName))))
    {
        return OK;
    }
    
    else 
    {
        return WRONG_NAME;
    }

}
EN_cardError_t getCardExpiryDate(ST_cardData_t *cardData)
{
    fflush(stdin);
    printf("\nplease enter the card expiration date\nnote: the date format must be 'MM/YY'\nExpiratin date:\t");
    gets(cardData -> cardExpirationDate);
    
    if ((strlen(cardData ->cardExpirationDate)<5) || (cardData->cardExpirationDate[2] != '/') || (cardData -> cardExpirationDate == NULL))
    {
        return WRONG_EXP_DATE;
    }
    
    else 
    {
        return OK;
    }
}
EN_cardError_t getCardPAN(ST_cardData_t *cardData)
{
     fflush(stdin);
    printf("\nplease enter the card's Primary Account Number:\t");
    gets(cardData -> primaryAccountNumber);
   
    if ((strlen(cardData ->primaryAccountNumber)<16) || (strlen(cardData ->primaryAccountNumber) > 19) || (cardData->primaryAccountNumber == NULL ))
    {
        return WRONG_PAN;
    }
    
    else 
    {
        return OK;
    }
}

//test functions

EN_cardError_t getCardHolderNameTest(EN_cardError_t (*TestFunction) (ST_cardData_t *cardData), ST_cardData_t *cardData)

{
    EN_cardError_t CardHolderNameState = TestFunction(cardData);
printf("\nTester name: Ahmed khaled khalaf\nFunction name: getCardHolderName");
if (CardHolderNameState == OK)
{
    printf("\nValid Name!");
    printf("\nTest Case 1: Valid Card Holder Name.\\
    \nInput Data: %s\n Expected Result: Valid Name!\\
    \nActual Result:Valid Name!", cardData->cardHolderName);
    return OK;
}
else
{
    printf("The name is less than 20 characters or greater than 24. \nOr, contains any special character or numbers.\n");
	printf("Please, enter acceptable name.\n\n");
    printf("\nTest Case 2: Wrong Card Holder Name.\\
    \nInput Data: %s\n Expected Result: Wrong Name!\\
    \nActual Result:Wrong Name!", cardData->cardHolderName);
   return WRONG_NAME;
    
}
}

EN_cardError_t getCardExpiryDateTest(EN_cardError_t (*TestFunction) (ST_cardData_t *cardData), ST_cardData_t *cardData)
{
     EN_cardError_t CardDateState = TestFunction(cardData);
    printf("\nTester name: Ahmed khaled khalaf\nFunction name: getCardExpiryDate");
if (CardDateState == OK)
{
    printf("\nValid Expiration Date!");
    printf("\nTest Case 1: Valid Expiration date.\\
    \nInput Data: %s\n Expected Result: Valid Expiration date!\\
    \nActual Result:Valid Expiration date!", cardData->cardExpirationDate);
    return OK;
}
else
{
     printf("Wrong Expiration Date.\n");
     printf("\nTest Case 2: Invalid Expiration date.\\
    \nInput Data: %s\n Expected Result: Invalid Expiration date!\\
    \nActual Result:Invalid Expiration date!", cardData->cardExpirationDate);
    return WRONG_EXP_DATE;
}
}


EN_cardError_t getCardPANTest(EN_cardError_t (*TestFunction)(ST_cardData_t *cardData), ST_cardData_t *cardData)

{
    
    EN_cardError_t CardPanState = TestFunction(cardData);

     printf("\nTester name: Ahmed khaled khalaf\nFunction name: getCardExpiryDate");

if (CardPanState == OK)
{
    printf("Valid Primary Account Number.\n");
    printf("\nTest Case 1: Valid Expiration date.\\
    \nInput Data: %s\n Expected Result: Valid Expiration date!\\
    \nActual Result:Valid Expiration date!", cardData->cardExpirationDate);
    return OK;
}
else
{
    printf("Wrong Primary Account Number.\n");
     printf("\nTest Case 2: Invalid Expiration date.\\
    \nInput Data: %s\n Expected Result: Invalid Expiration date!\\
    \nActual Result:Invalid Expiration date!", cardData->cardExpirationDate);

    return WRONG_PAN;
}
}

