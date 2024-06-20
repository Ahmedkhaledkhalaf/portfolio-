#include <stdio.h>
#include<stdlib.h>
#include "simple data base.h"


/**
 * @brief: allocation of the lists using continueous dynamic allocation.
 * 
 * @param:glbl_SDB is a global pointer to structer which points to the first element of structure in the heab
*/
SDB *glpl_SDB = (SDB *) calloc(N, sizeof(SDB)); 
glpl_SDB->next = glpl_SDB++;
(glpl_SDB+N-1)->next = NULL;
/**
 * @brief: function that check if the data base is full or no.
 * 
 * @param:  the return value will be boolian(1 if it is full, 0 otherwise)
*/
bool SDB_isFULL(void)
{
uint8 num = SDB_GetUsedSize();
if (num <N)
{
    return 0;

}
else
{
    return 1;

}
}

/**
 * @brief: function that gets the number of entries into the data base (a counter function)
 * 
 * @param: the return value will be the number of entries 
*/
uint8 SDB_GetUsedSize(void)
{
static uint8 counter =0;
return counter;
}

/**
 * @brief: function that will give the access to enter a new data
 * 
 * @param: name is a pointer to unsigned character will point to the name array which will be used to add the student name to the array in the memory
 * 
 * @param: id is a local unsigned character variable which will be used to assign the student id to the memory
 * 
 * @param: year is a local unsigned character variable which will be used to assign the student year to the memory
 * 
 * @param: course is a pointer to unsigned character will point to the courses ids variables which will be used to add the courses ids to the structure in the memory
 * 
 * @param: grades is a pointer to unsigned character will point to the course grade variables which will be used to add the courses grades to the structure in the memory
 * 
 * @param: the return value will be boolian (1 if it is the entry was successfull, 0 otherwise)
 */
bool SDB_AddEntry(uint8 ID)
{
    
SDB *SDB_AddEntry_ptr = NULL;
SDB_AddEntry_ptr = glpl_SDB;
uint8 *name = SDB_AddEntry_ptr->student_name;
ID = SDB_AddEntry_ptr->studint_ID;
uint8 year
uint8 *course = NULL;
uint8 *grades = NULL;
    if(SDB_AddEntry_ptr != NULL)
    {
        if (SDB_isFULL == 0)
        {
            for(int i = 1; i <= counter ; i++);
            {
                SDB_AddEntry_ptr = SDB_AddEntry_ptr->next;
            }
            printf("\nPlease enter the student ID:\r\t");
            scanf("%d", &ID);
            printf("\nPlease enter the student name:\r\t");
            fflush(stdin);
            fgets(name, 40, stdin);
            fflush(stdin);
            printf("\nPlease enter the first course ID:\r\t");
            course = &(SDB_AddEntry_ptr->course_1_ID);
            scanf("%d", course);
            printf("\nPlease enter the first course grade:\r\t");
            grades = &(SDB_AddEntry_ptr->course_1_grade);
            scanf("%d", grades);
            while (*grades >100)
            {
                printf("\nplease enter a valid grade:\t");
                scanf("%d", grades);
            }
            
            
            printf("\nPlease enter the second course ID:\r\t");
            course = &(SDB_AddEntry_ptr->course_2_ID);
            scanf("%d", course);
            printf("\nPlease enter the second course grade:\r\t");
            grades = &(SDB_AddEntry_ptr->course_2_grade);
            scanf("%d", grades);
            while (*grades >100)
            {
                printf("\nplease enter a valid grade:\t");
                scanf("%d", grades);
            }
            printf("\nPlease enter the third course ID:\r\t");
            course = &(SDB_AddEntry_ptr->course_3_ID);
            scanf("%d", course);
            printf("\nPlease enter the third course grade:\r\t");
            grades = &(SDB_AddEntry_ptr->course_3_grade);
            scanf("%d", grades);
            while (*grades >100)
            {
                printf("\nplease enter a valid grade:\t");
                scanf("%d", grades);
            }
            return 1;

            
        }
        else
        {
            return 0;
        }
        
    }
    else
    {
        return 0;
    }

}


/**
 * @brief: function that is used to delete an entery from the data base (the list will not be deleted just will take a zero values).
 * 
 * @param: ID is the token variable which will be used to check if the entry is the one to be deleted or not.
*/

void SDB_DeleteEntery(uint8 ID)
{
   SDB *SDB_DeleteEntery_ptr = glpl_SDB;
   while((SDB_DeleteEntery_ptr->studint_ID) != ID)
   {
    SDB_DeleteEntery_ptr = SDB_DeleteEntery_ptr->next;
   }
   if (SDB_DeleteEntery_ptr->studint_ID == ID)
   {
    SDB_DeleteEntery_ptr->student_name = 0;
    SDB_DeleteEntery_ptr->studint_year = 0;
    SDB_DeleteEntery_ptr->course_1_ID = 0;
    SDB_DeleteEntery_ptr->course_1_grade = 0;
    SDB_DeleteEntery_ptr->course_2_ID = 0;
    SDB_DeleteEntery_ptr->course_2_grade = 0;
    SDB_DeleteEntery_ptr->course_3_ID = 0;
    SDB_DeleteEntery_ptr->course_3_grade = 0;
    SDB_DeleteEntery_ptr->studint_ID = 0;
    printf("\nthe list of the student with id %d is Deleted successfully\r\n", ID);
   }
   else
   {
    printf("\nthe list you try to delete is not exist!\r\n");
   }
}



/**
 * @brief: function that will be used to read the entery information matching with the given ID
 * 
 * @param: input parameter id is a local unsigned character variable which will be given and used to match the student id withe the others in memory
 * 
 * @param: name is a pointer to unsigned character will point to the name array which will be used to read the student name from the array in the memory (output paramter)
 * 
 * @param: year is a pointer to unsigned character which will be used to read the student year from the memory (output paramter)
 * 
 * @param: course is a pointer to unsigned character will point to the courses ids variables which will be used to read the courses ids from the structure in the memory (output paramter)
 * 
 * @param: grades is a pointer to unsigned character will point to the course grade variables which will be used to read the courses grades from the structure in the memory (output paramter)
 * 
 * @param: the return value will be boolian (1 if it is the entry was exist, 0 otherwise)
 */
bool SDB_ReadEntry(uint8 ID)
{
 SDB *SDB_ReadEntry_ptr = glpl_SDB;
   while((SDB_ReadEntry_ptr->studint_ID) != ID)
   {
    SDB_ReadEntry_ptr = SDB_ReadEntry_ptr->next;
   }
   if (SDB_ReadEntry_ptr->studint_ID == ID)
   {
    
    uint8 *name   = SDB_ReadEntry_ptr->student_name;
    uint8 *year   = &(SDB_ReadEntry_ptr->studint_year);
    uint8 *course = NULL;
    uint8 *grades = NULL;
    
    
    ID     = SDB_ReadEntry_ptr->studint_ID;
    printf("\nthe student ID is:\t%d",ID);
    printf("\nthe student name is:%s\t", name);
    printf("\nthe student year is:\t%d",*year);

    course = &(SDB_ReadEntry_ptr->course_1_ID);
    grades = &(SDB_ReadEntry_ptr->course_1_grade);
    printf("\nthe first course ID is:\t%d",*course);
    printf("\nthe first course grade is:\t%d",*grades);
    course = &(SDB_ReadEntry_ptr->course_2_ID);
    grades = &(SDB_ReadEntry_ptr->course_2_grade);
    printf("\nthe second course ID is:\t%d",*course);
    printf("\nthe second course grade is:\t%d",*grades);
    course = &(SDB_ReadEntry_ptr->course_3_ID);
    grades = &(SDB_ReadEntry_ptr->course_3_grade);
    printf("\nthe third course ID is:\t%d",*course);
    printf("\nthe third course grade is:\t%d",*grades);
    return 1;
   }
   else
   {
    return 0;
   }
}



/**
 * @brief: function that gets a list of IDs of the students
 * 
 * @param:count is a pointer to the number of entries curruntlt exist in the data base
 * 
 * @param: list pointer to the list of IDs
*/
void SDB_GetIDList ()
{
 uint8 *count;
 uint8 *list;
count = &counter;
SDB *SDB_GetIDList_ptr =NULL;
SDB_GetIDList_ptr = glpl_SDB;
if ((SDB_GetIDList_ptr != NULL) && (*count <= N)) 
{ 
    printf("\nthe number of entries is:\t%d", *count);
    for (int i = 1; i <= *count; i++)
    {
        list = &(SDB_GetIDList_ptr->studint_ID);
        printf("\nstudent %d ID is:\t%d", i, *list);
        SDB_GetIDList_ptr = SDB_GetIDList_ptr->next;
    }
    printf("\nthe end of the list\n");
}
else
{
    printf("\nthere is no entery yet");
}

}


/**
 * @brief: function that checks if the provided student ID is Exist or no.
 * 
 * @param: the return value will be boolian (1 if it is the entry was exist, 0 otherwise)
*/
bool SDB_IsIdExist(uint8 ID)

{
    SDB *SDB_IsIdExist_ptr = NULL;
    SDB_IsIdExist_ptr = glpl_SDB;
    while((SDB_IsIdExist_ptr != NULL)&&(ID != SDB_IsIdExist_ptr->studint_ID))
    {
        SDB_IsIdExist_ptr = SDB_IsIdExist_ptr->next;
    }
    if(ID == SDB_IsIdExist_ptr->studint_ID)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}


/**
 * @brief : function that gives the choice to the user
*/
void main_menu(void)
{
uint8 choice = 0;
uint8 ID = 0;
uint8 retval = 0;
printf("\nplease enter a choice\n\
1- To enter a new entery\n\
2- To  read an entery\n\
3- To check if the entry is exist in the data base\n\
4- To get a list of IDs\n\
5- To check if the Data base is full\n\
6- To delete an entry\n");
scanf("%d",&choice);

switch (choice)
{
case 1:
    printf("\nplease enter the student ID:\t");
    scanf("%d", &ID);
    if (SDB_IsIdExist(ID) == 1)
    {
        printf("\nThe student data is already exist\nplease enter a new data!\n");
    }
    else if (SDB_isFULL() == 1)
    {
        printf("\nThe Data base is Full!");
    }
    
    else
    {
       retval = SDB_AddEntry(ID);
        if(retval == 1)
        {
            printf("\nThe entery is stored successfully");
        }
        else
        {
            printf("\nUnfortunatly and error happened please try to enter the data again!");
        }
    }
    
    break;
case 2:
printf("\nplease enter the student ID:\t");
scanf("%d", &ID);
retval = SDB_ReadEntry(ID);
if (retval == 1)
{
    printf("\nthe data is showen")
}
else
{
    prinf("\ndata is not found");
}

    
    break;
case 3:
    printf("\nplease enter the student ID:\t");
    scanf("%d", &ID);
    retval = SDB_IsIdExist(ID);
    if (retval == 1)
    {
        printf("\nthe student data is exist!\n ");
    }
    else
    {
        printf("\nthe student data is not exist!");
    }
    
    break;
case 4:
    SDB_GetIDList();
    
    break;
case 5:
    retval = SDB_isFULL();
    if (retval == 1)
    {
        printf("\nthe data base is full!");

    }
    else
    {
        printf("\nthe data base is not full yet!");
    }
    break;
case 6:
   printf("\nplease enter the student ID:\t");
    scanf("%d", &ID);
    retval = SDB_DeleteEntery(ID);
    if (retval == 1)
    {
        printf("\nthe student data is deleted succfully!\n ");
    }
    else
    {
        printf("\nerror ouccered when delete proccess!");
    }
    break;


default:
printf("\nerror please try again later!");
    break;
}

}