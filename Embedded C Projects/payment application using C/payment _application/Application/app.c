/**
 * @file app.c
 * @author Ahmed khaled khalaf (khalafawy22899@gmail.com)
 * @brief file that contains the main function and implementation of the appstart function
 * @version 0.1
 * @date 2022-10-17
 *
 * @copyright Copyright (c) 2022
 *
 */


#include <stdio.h>

#include "app.h"

extern ST_accountsDB_t DATA_BASE[10];
extern uint8_t Acc_Index;
void main()
{
	appStart();
}
void appStart(void)
{
    uint8_t choice = 0;
    uint32_t num = 0;
    float balanced, deposit;
    EN_cardError_t CARD_State;
    EN_terminalError_t TERMINAL_State;
    EN_transState_t TRANSACTION_State;
    EN_serverError_t SERVER_State;
	

   ST_transaction_t  User_Data = {{"","",""}, {0,0,""}, APPROVED, 0};


        printf("\n\t\tWelcome to Egypt Future Work digital Bank :)\n\n\n");

    while (1)
    {
		CARD_State =  getCardHolderNameTest(getCardHolderName, &User_Data.cardHolderData);
        if (CARD_State == WRONG_NAME)
        {
            continue;
        }
       
       
        
		
       
        CARD_State = getCardExpiryDateTest( getCardExpiryDate, &User_Data.cardHolderData);
        if (CARD_State == WRONG_EXP_DATE)
        {
			continue;
        }

		
       
        CARD_State = getCardPANTest( getCardPAN, &(User_Data.cardHolderData));
        if (CARD_State == WRONG_PAN)
        {
			continue;
        }
	   
        
		
      
        TERMINAL_State = isValidCardPANTest(isValidCardPAN, &(User_Data.cardHolderData));
        if (TERMINAL_State == INVALID_CARD)
        {
			continue;
        }
		
		User_Data.transState = isValidAccount(&(User_Data.cardHolderData));
        if (User_Data.transState == DECLINED_STOLEN_CARD)
        {
            printf("Declined Invalid Account or Blocked Account!\n");
			continue;
        }
		else if (User_Data.transState == FRAUD_CARD)
		{
			printf("card does not exist!\n");
			continue;
		}
		else
		{
			printf("Accepted Card\n");
		}
	   
       
        printf("\nPlease wait until data check ends.....\n");
        printf("\n\t\tWelcome %s !\n\n", User_Data.cardHolderData.cardHolderName);
        printf("Please choose the operation you want!\n");
			printf("1: To Make new Transaction.\n");
			printf("2: To Check Transaction.\n");
			printf("3: To Check Balance.\n");
			printf("4: To Deposit money.\n");
			//printf("5: To Report Stolen Card.\n");
			printf("5: To Exit.\n");
            fflush(stdin);
			scanf("%d",&choice);

        switch (choice)
        {
        case 1:
        {
           
            if(User_Data.transState == DECLINED_STOLEN_CARD)
				{
					printf("Declined Invalid Account or Blocked Account!\n\n");
				}
				else
				{
					TERMINAL_State = getTransactionDate(&User_Data.terminalData);
					if (TERMINAL_State == WRONG_DATE)
					{
						printf("Wrong Date.\n");
						continue;
					}

					if(isCardExpired(User_Data.cardHolderData, User_Data.terminalData)== EXPIRED_CARD)
					{
						printf("Declined Expired Card!\n");
						printf("Exit\n");
						continue;
					}
					else
					{
						printf("Accepted Card.\nwelcome!\n\n");
					}

					TERMINAL_State = setMaxAmount(&(User_Data.terminalData));
					if (TERMINAL_State == INVALID_MAX_AMOUNT)
					{
						printf("INVALID MAX AMOUNT.\n");
						break;
					}
					TERMINAL_State = getTransactionAmount(&(User_Data.terminalData));
					if (TERMINAL_State == INVALID_AMOUNT)
					{
						printf("INVALID AMOUNT.\n");
						break;
					}
					TERMINAL_State = isBelowMaxAmount(&User_Data.terminalData);
					if(TERMINAL_State == EXCEED_MAX_AMOUNT)
					{
						printf("Declined Amount Exceeding Limit!\n");
						printf("Exing\n");
						break;
					}

					TRANSACTION_State = recieveTransactionData(&User_Data);

					if(TRANSACTION_State == DECLINED_STOLEN_CARD)
					{
						printf("Declined Invalid Account or Blocked Account!\n");
						break;
					}
					else if(TRANSACTION_State == DECLINED_INSUFFECIENT_FUND)
					{
						printf("Declined Insufficient Funds!\n");
						break;
					}
					else if(TRANSACTION_State == INTERNAL_SERVER_ERROR)
					{
						printf("Server is down, please try again later!\n");
						break;
					}



					balanced = (DATA_BASE[Acc_Index].balance) + User_Data.terminalData.transAmount;
					printf("Your curent balance is %0.4f.\n",balanced);
					printf("Amount to be withdrawn = %0.4f.\n",User_Data.terminalData.transAmount);
					printf("Current Balance = %0.4f.\n",(DATA_BASE[Acc_Index].balance));
					printf("Transaction Number: %d\n",User_Data.transactionSequenceNumber);
					printf("Transaction Completed.\n\n\n\n\n\n\n");
					break;
				}
				break;

            
        }
        case 2:
        {
              TRANSACTION_State = isValidAccount(&(User_Data.cardHolderData));
				if (TRANSACTION_State == DECLINED_STOLEN_CARD)
				{
					printf("Declined Invalid Account or Blocked Account!\n");
					break;
				}
                else
                {
					if(User_Data.transState == DECLINED_STOLEN_CARD)
					{
						printf("Declined Invalid Account or Blocked Account!\n\n");
					}
					else
					{
						printf("Enetr Transaction sequence number to be searched:  "); fflush(stdout);
						scanf("%d",&num);
						SERVER_State = getTransaction(num, &User_Data);
						if(SERVER_State == ACCOUNT_NOT_FOUND)
						{
							printf("Declined Invalid Account!\n");
							break;
						}
						else if(SERVER_State == TRANSACTION_NOT_FOUND)
						{
							printf("Declined TRANSACTION NOT FOUND!\n");
							break;
						}
						printf("Transaction sequence number: %d\n",User_Data.transactionSequenceNumber);
						printf("Details of the Transaction owner.\n");
						printf("Name: %s.\n",User_Data.cardHolderData.cardHolderName);
						printf("PAN: %s.\n",User_Data.cardHolderData.primaryAccountNumber);
						printf("Transaction Date: %s.\n",User_Data.terminalData.transactionDate);
						printf("Transaction money = %0.4f.\n",User_Data.terminalData.transAmount);
						printf("Current Balance = %0.4f.\n",(DATA_BASE[Acc_Index].balance));
					}
				}
				break;
        }
        case 3:
         {
                    TERMINAL_State = isValidAccount(&(User_Data.cardHolderData));
				if (TERMINAL_State == DECLINED_STOLEN_CARD)
				{
					printf("Declined Invalid Account or Blocked Account!\n");
					break;
				}
                else
                {
					if(User_Data.transState == DECLINED_STOLEN_CARD)
					{
						printf("Declined Invalid Account or Blocked Account!\n\n");
					}
					else
					{
						balanced = (DATA_BASE[Acc_Index].balance);
						printf("Your curent balance is %0.4f.\n",balanced);
					}
                }
				break;
         }
         case 4:
         {
            TRANSACTION_State = isValidAccount(&(User_Data.cardHolderData));
				if (TRANSACTION_State == DECLINED_STOLEN_CARD)
				{
					printf("Declined Invalid Account or Blocked Account!\n");
					break;
				}
                else
                {
					if(User_Data.transState == DECLINED_STOLEN_CARD)
					{
						printf("Declined Invalid Account or Blocked Account!\n\n");
					}
					else
					{
						printf("Enter the amount of money: ");
                        fflush(stdout);
						scanf("%f",&deposit);
						DATA_BASE[Acc_Index].balance += deposit;
						printf("Current Balance = %0.4f.\n",(DATA_BASE[Acc_Index].balance));
						printf("Amount added successfully.\n");
					}
                }
				break;
         }
        
         case 5:
         {
            printf("Quit.\n");
				break;
         }
        default:
        {
            printf("Wrong choice.\n");
				break;
        }

        }

    }

}
