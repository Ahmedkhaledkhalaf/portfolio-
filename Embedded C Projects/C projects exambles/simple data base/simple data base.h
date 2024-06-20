/**
 * @file : data_base.h
 * @brief :file contains the prototypes and definations of the functions and varibles
 * @author : Ahmed khaled khalaf
 * @version : 1.0
 * @date : 14/9/2022
*/

//HEADER file guard 
#ifndef _SIMPLE_DATA_BASE_H_
#define _SIMPLE_DATA_BASE_H_
#endif /* _SIMPLE_DATA_BASE_H_ */


#define N 10  //a macro to the number of entries
typedef unsigned char uint8; //renaming the type usigned character 
/**
 * @brief :structure that contains the variables which will carry the information of student.
 * @param :studint_ID the student ID which will be concedered as the main id of the list.
 * @param :studint_year 
 * @param :course_1_ID, course_2_ID, course_3_ID 
 * @param :course_1_grade, course_2_grade, course_3_grade
 * @param :next a pointer for the next list (self refrential).
 * @param : student_name an array of type characters which carrys a string of the student name.
*/
typedef struct 
{
uint8 studint_ID;
uint8 studint_year;
uint8 course_1_ID;
uint8 course_1_grade;
uint8 course_2_ID;
uint8 course_2_grade;
uint8 course_3_ID;
uint8 course_3_grade;
struct SDB *next;
uint8 student_name[50];
}SDB; //the name of the type structure.

/**
 * @brief: function that check if the data base is full or no.
 * 
 * @param:  the return value will be boolian(1 if it is full, 0 otherwise)
*/
bool SDB_isFULL(void);
/**
 * @brief: function that gets the number of entries into the data base (a counter function)
 * 
 * @param: the return value will be the number of entries 
*/
uint8 SDB_GetUsedSize(void);
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
bool SDB_AddEntry(uint8 ID);
/**
 * @brief: function that is used to delete an entery from the data base (the list will not be deleted just will take a zero values).
 * 
 * @param: ID is the token variable which will be used to check if the entry is the one to be deleted or not.
*/
void SDB_DeleteEntery(uint8 ID);
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
bool SDB_ReadEntry(uint8 ID);
/**
 * @brief: function that gets a list of IDs of the students
 * 
 * @param:count is a pointer to the number of entries curruntlt exist in the data base
 * 
 * @param: list pointer to the list of IDs
*/
void SDB_GetIDList ();
/**
 * @brief: function that checks if the provided student ID is Exist or no.
 * 
 * @param: the return value will be boolian (1 if it is the entry was exist, 0 otherwise)
*/
bool SDB_IsIdExist(uint8 ID);
/**
 * @brief : function that gives the choice to the user
*/
void main_menu(void);