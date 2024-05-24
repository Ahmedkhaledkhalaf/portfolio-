/**
 * @file server.c
 * @author Ahmed khaled khalaf (khalafawy22899@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <string.h>
#include "server.h"



ST_accountsDB_t DATA_BASE[10] = {{4000.00, RUNNING, "4916945627505481"},{12000.50, RUNNING,"4493625375298262"},
{20000.00, RUNNING, "4929101130212489"},{19000.25, RUNNING, "4485846819394224"},{50000.75, RUNNING, "4539780225981447"},
{67050.00, RUNNING,"4485456770455996"},{86000.00, BLOCKED, "4716069021758224"},{13078.30, BLOCKED, "4539207880267326"},
{90000.00, BLOCKED, "4571065954771386"},{74089.00, BLOCKED, "4539101982402479"}};




ST_transaction_t TRANSACTION_ARRAY[10] = {0};

uint8_t Acc_Index;

uint8_t SearchAccount (ST_cardData_t *cardData, ST_accountsDB_t *ARRAY)
{
	/*search for an account in server database */

	for(uint8_t i=0; i<10 ; i++)
	{
        uint8_t is = strcmp(cardData->primaryAccountNumber , ARRAY[i].primaryAccountNumber);
		if(is == 0)
        {
			return i;
            break;
        }
        
	}
	
	return -1;
}



EN_transState_t recieveTransactionData(ST_transaction_t *transData)
{
    EN_transState_t TransError = isValidAccount(&(transData->cardHolderData));
    if (TransError == FRAUD_CARD)
    {
        transData->transState = FRAUD_CARD;
        return FRAUD_CARD;
        
    }
    else if (TransError == DECLINED_STOLEN_CARD)
    {
       transData->transState = DECLINED_STOLEN_CARD;
       return DECLINED_STOLEN_CARD;
    }
    

    else
    {
        return APPROVED;
    }

    EN_serverError_t server_Error = isAmountAvailable(&(transData->terminalData));
    if (server_Error == LOW_BALANCE)
    {
        transData->transState = DECLINED_INSUFFECIENT_FUND;
        return DECLINED_INSUFFECIENT_FUND;
    }
    else
    {
        
         DATA_BASE[Acc_Index].balance -= (transData->terminalData.transAmount);
         return SERVER_OK;
    }
    
   

    server_Error = saveTransaction(transData);
    if (server_Error == SAVING_FAILED)
    {
        transData->transState = INTERNAL_SERVER_ERROR;
        return INTERNAL_SERVER_ERROR;
    }
    else
    {
        return SERVER_OK;
    }
    

}
EN_serverError_t isValidAccount(ST_cardData_t *cardData)
{
    
    Acc_Index = SearchAccount(cardData, DATA_BASE);
   if (isBlockedAccount(DATA_BASE) == DECLINED_STOLEN_CARD)
   {
    return DECLINED_STOLEN_CARD;
   }
   
   else if (Acc_Index == -1 || Acc_Index >=10)
    {
        return FRAUD_CARD;
    }
    
    
    else
    {
        return SERVER_OK;
    }

}

EN_serverError_t isBlockedAccount(ST_accountsDB_t *accountRefrence)
{
    if (accountRefrence[Acc_Index].state== BLOCKED)
    {
        return DECLINED_STOLEN_CARD;
    }
    else
    {
        return SERVER_OK;
    }
    
}
EN_serverError_t isAmountAvailable(ST_terminalData_t *termData)
{
    if ((termData -> transAmount) <= (DATA_BASE[Acc_Index].balance))
    {
        return OK;
    }

    else
    {
        return LOW_BALANCE;
    }
}
EN_serverError_t saveTransaction(ST_transaction_t *transData)
{

    static uint8_t counter = 1;

    TRANSACTION_ARRAY[Acc_Index].cardHolderData = transData->cardHolderData;
    TRANSACTION_ARRAY[Acc_Index].terminalData = transData->terminalData;
    transData->transactionSequenceNumber = counter;
    counter++;
    TRANSACTION_ARRAY[Acc_Index].transactionSequenceNumber = transData->transactionSequenceNumber;


    if (TRANSACTION_ARRAY[Acc_Index].transactionSequenceNumber ==0)
    {
        transData->transState = SAVING_FAILED;
        return SAVING_FAILED;
    }
    return APPROVED;
    

}

EN_serverError_t getTransaction(uint32_t transactionSequenceNumber, ST_transaction_t *transData)
{
    if (Acc_Index >= 10)
    {
        return ACCOUNT_NOT_FOUND;
    }
    if (TRANSACTION_ARRAY[Acc_Index].transactionSequenceNumber != transactionSequenceNumber)
    {
        return TRANSACTION_NOT_FOUND;
    }

    return APPROVED;
    
}


EN_serverError_t recieveTransactionDataTest(EN_transState_t (*TestFunction)(ST_transaction_t *transData), ST_transaction_t *transData)
{
     uint8_t SERVER_State = TestFunction(transData);

     printf("\nTester name: Ahmed khaled khalaf\nFunction name: recieveTransactionDataTest");

if (SERVER_State == FRAUD_CARD)
{
    printf("The account does not exist\n");
    printf("\nTest Case 1: The account does not exist.\\
    \nInput Data: \n Expected Result:The account does not exist!\\
    \nActual Result:The account does not exist!");
    return FRAUD_CARD;
}
else if (SERVER_State ==DECLINED_STOLEN_CARD)
{
    printf("Stolen card\n");
     printf("\nTest Case 2: Stolen card\\
    \nInput Data: \n Expected Result: Stolen card.!\\
    \nActual Result:Stolen card.!");
    return DECLINED_STOLEN_CARD;
}

else if (SERVER_State == DECLINED_INSUFFECIENT_FUND)
{
     printf("INSUFFECIENT FUND\n");
     printf("\nTest Case 3: INSUFFECIENT FUND\\
    \nInput Data: \n Expected Result: INSUFFECIENT FUND.!\\
    \nActual Result:INSUFFECIENT FUND!");
    return DECLINED_INSUFFECIENT_FUND;
}
else if (SERVER_State == INTERNAL_SERVER_ERROR)
{
    printf("The trunsaction did not saved\n");
     printf("\nTest Case 4: The trunsaction did not saved\\
    \nInput Data: \n Expected Result: The trunsaction did not saved.!\\
    \nActual Result:The trunsaction did not saved!");
    return INTERNAL_SERVER_ERROR;
}
else 
{
     printf("The Account is valid and the transaction is saved successfully\n sequans number: %S", &TRANSACTION_ARRAY[Acc_Index].transactionSequenceNumber);
     printf("\nTest Case 5:successful transaction\\
    \nInput Data: \n Expected Result: successful transaction.!\\
    \nActual Result:successful transaction!");
    
}


}