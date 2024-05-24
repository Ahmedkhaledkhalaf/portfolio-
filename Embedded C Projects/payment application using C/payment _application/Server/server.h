/**
 * @file server.h
 * @author Ahmed khaled khalaf (khalafawy22899@gmail.com)
 * @brief file conatins prototypes and definantions
 * @version 0.1
 * @date 2022-10-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>



#ifndef SERVER_H
#define SERVER_H

#include "../Terminal/terminal.h"

typedef unsigned int uint32_t;


typedef enum EN_transState_t
{
APPROVED, DECLINED_INSUFFECIENT_FUND, DECLINED_STOLEN_CARD, INTERNAL_SERVER_ERROR, FRAUD_CARD
}EN_transState_t;

typedef enum EN_serverError_t
{
SERVER_OK, SAVING_FAILED, TRANSACTION_NOT_FOUND, ACCOUNT_NOT_FOUND, LOW_BALANCE
}EN_serverError_t;



typedef struct ST_transaction_t
{
ST_cardData_t cardHolderData;
ST_terminalData_t terminalData;
EN_transState_t transState;
uint32_t transactionSequenceNumber;
}ST_transaction_t;

typedef enum EN_accountState_t
{
     RUNNING,
     BLOCKED
}EN_accountState_t;

typedef struct ST_accountsDB_t
{
     float balance;
     EN_accountState_t state;
     uint8_t primaryAccountNumber[20];
}ST_accountsDB_t;

/****************************** Functions ProtoTypes ************************************/

/* Description:
 * takes PAN from cardData_s and check if an account with this PAN in the accounts array
 * takes transAmount from terminalData_s and compare it with account balance
 * checks if this account is blocked or not
 * save transaction and update balance or return error if array of transactions is full
 * inputs: address of a ST_transaction_t
 * output: FRAUD_CARD , DECLINED_INSUFFECIENT_FUND , DECLINED_STOLEN_CARD
 * INTERNAL_SERVER_ERROR , APPROVED
 */

EN_transState_t recieveTransactionData(ST_transaction_t *transData);



EN_serverError_t isValidAccount(ST_cardData_t *cardData);
EN_serverError_t isAmountAvailable(ST_terminalData_t *termData);
EN_serverError_t saveTransaction(ST_transaction_t *transData);
EN_serverError_t getTransaction(uint32_t transactionSequenceNumber, ST_transaction_t *transData);
uint8_t SearchAccount (ST_cardData_t *cardData, ST_accountsDB_t *ARRAY);
EN_serverError_t isBlockedAccount(ST_accountsDB_t *accountRefrence);

EN_serverError_t recieveTransactionDataTest(EN_transState_t (*TestFunction)(ST_transaction_t *transData), ST_transaction_t *transData);
#endif /* header guard */
//gcc Application/app.c Card/card.c Server/server.c Terminal/terminal.c -o payapp4.exe