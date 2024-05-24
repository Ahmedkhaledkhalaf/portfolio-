/**
 * @file card.h
 * @author Ahmed khaled khalaf (khalafawy22899@gmail.com)
 * @brief file conatins prototypes and definantions
 * @version 0.1
 * @date 2022-10-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

/*Header guard*/
#ifndef CARD_H
#define CARD_H
/*type defination of the variables and data types which will be used*/
typedef unsigned char uint8_t;

typedef struct ST_cardData_t //structure that will be used to take the information of the clint's card
{
uint8_t cardHolderName[25];
uint8_t primaryAccountNumber[20];
uint8_t cardExpirationDate[6];
}ST_cardData_t;

typedef enum EN_cardError_t
{
OK, WRONG_NAME, WRONG_EXP_DATE, WRONG_PAN
}EN_cardError_t;

/*praimary functions which are used to get the card Holder data*/
EN_cardError_t getCardHolderName(ST_cardData_t *cardData);
EN_cardError_t getCardExpiryDate(ST_cardData_t *cardData);
EN_cardError_t getCardPAN(ST_cardData_t *cardData);

//test functions

EN_cardError_t getCardHolderNameTest(EN_cardError_t (*TestFunction)(ST_cardData_t *cardData), ST_cardData_t *cardData);
EN_cardError_t getCardExpiryDateTest(EN_cardError_t (*TestFunction)(ST_cardData_t *cardData), ST_cardData_t *cardData);
EN_cardError_t getCardPANTest(EN_cardError_t (*TestFunction)(ST_cardData_t *cardData), ST_cardData_t *cardData);
#endif /* header guard */