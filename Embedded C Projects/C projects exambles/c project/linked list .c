/**
 * @file : linked list.c
 * @author : Ahmed Khaled Khalaf
 * @brief : File contains the implementation of the linked list data structure
 * @version : 1.0
 * @date : 13-9-2022
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include "linked list.h"

static node_t* glpl_ptr_head_node = NULL;
static int glpl_total_node_length = 0;



node_t* add_head_node(void)
{
    if (glpl_ptr_head_node ==NULL)
    {
        glpl_ptr_head_node = (node_t*) calloc(1,sizeof(node_t));
        if (glpl_ptr_head_node != NULL)
        {
            glpl_ptr_head_node -> next_node = NULL;
            glpl_total_node_length++;
            glpl_ptr_head_node -> node_id = 1;
            printf("the %d node is created successfully\n",glpl_ptr_head_node ->node_id );
            printf("the head node is created successfully\n");

        }
        else
        {
            printf ("the memory allocation faild\r\n");
        }
    }
    else
    {
        printf("the head node is already exist");
    }
    return glpl_ptr_head_node;

}
node_t* add_node(void)
{
    node_t *previous_node = glpl_ptr_head_node;
    node_t *ptr_to_allocate_node = NULL;
    if(glpl_ptr_head_node != NULL)
    {
        while (previous_node->next_node != NULL)
        {
            previous_node = previous_node ->next_node;
        }

        ptr_to_allocate_node = (node_t*) calloc(1,sizeof(node_t));
        if(ptr_to_allocate_node != NULL)
        {
            ptr_to_allocate_node ->next_node = NULL;
            previous_node ->next_node = ptr_to_allocate_node;
            glpl_total_node_length++;
            (ptr_to_allocate_node ->node_id) = (previous_node->node_id)+1;
            printf("the %d node is created successfully\n",ptr_to_allocate_node ->node_id );
        }
        else
        {
            printf("failed to create a node\r\n");
        }

    }
    return ptr_to_allocate_node;
}
void delete_node (int index)
{
    node_t *current_node = glpl_ptr_head_node;
    node_t *previous_node = NULL;
    if(glpl_total_node_length < index)
    {
        printf ("the node is note found\r\n");
    }
    else
    {
        while ((current_node->next_node != NULL) && (index != current_node -> node_id))
        {
            previous_node = current_node;
            current_node = current_node->next_node;
        }
        if(current_node -> node_id == index)
        {
             printf("the %d node is deleted successfully\r\n",current_node->node_id);
            previous_node ->next_node = current_node ->next_node;
            free(current_node);


        }
        else
        {
        printf("delete process is failed");
        }


    }
}
void fined_data (int index)
{

    node_t *ptr_to_find_data = glpl_ptr_head_node;
if (glpl_total_node_length > index)
{


    while ((ptr_to_find_data != NULL) && (ptr_to_find_data->node_id != index))
    {
        ptr_to_find_data = ptr_to_find_data->next_node;
    }
    if ((ptr_to_find_data != NULL) && (ptr_to_find_data->node_id == index))
    {

         printf("\nthe data is found at list %d", ptr_to_find_data->node_id);
         printf("\nthe name is\t %s", (char *)ptr_to_find_data->array);
         printf("\nthe id is\t%d", ptr_to_find_data->id);
         printf("\nthe garde is\t%f", ptr_to_find_data->grade);
         printf("\nthe number of the student is\t%d", ptr_to_find_data->node_id);
         printf("\n\n\n");

    }
    else
    {
        printf("\nthe data is not found");
    }

}
}
void fill_data (int index)
{
    node_t *ptr_to_fill_data = glpl_ptr_head_node;
    int choice =0;
    if(glpl_total_node_length < index)
           {
               printf("do yo want to create a new node?\npress 1 for yes or 0 for no:\t");
               scanf("%d", &choice);
               if (choice == 1)
                    {
                     add_node();
                    }
           }



    if(glpl_total_node_length >= index)
           {
               while ((ptr_to_fill_data->next_node != NULL) && (index != ptr_to_fill_data -> node_id))
                   {

                       ptr_to_fill_data= ptr_to_fill_data->next_node;
                   }
               if((ptr_to_fill_data->node_id) == index)
                   {
                       printf("\nplease enter the name\t");
                       scanf("%s", ptr_to_fill_data->array);

                       printf("\nplease enter the id\t");
                       scanf("%d", &(ptr_to_fill_data->id));
                       printf("\nplease enter the grade\t");
                       scanf("%f", &(ptr_to_fill_data->grade));

                       printf("the data is saved at list %d", (ptr_to_fill_data->node_id));
                   }
           }
     else
            {
                  printf("the data you tried to enter has no place:(");
            }


}


void print_list(void)
{
 node_t *print_ptr = glpl_ptr_head_node;

   while (print_ptr!= NULL)
   {
    printf("\nthe name is\t %s", (char *) print_ptr->array );
    printf("\nthe id is\t%d", (print_ptr->id));
    printf("\nthe garde is\t%f", (print_ptr->grade));
    printf("\nthe number of the student is\t%d", (print_ptr->node_id ));
    print_ptr = print_ptr->next_node;
    printf("\n\n\n");
   }
   printf("\nthe end of the list\r\n");
}



void main_menu(void)
{
    int del = 0;
    int fill = 0;
    int find = 0;
    int choice = 0;
    printf ("\nwelcome to my data base application\r\n");
    printf("please enter a number refers to your choice\n\
    1-to create a head node\n\
    2-to create a new node\n\
    3-to enter a new data\n\
    4-to find an old data\n\
    5-to delete a list of data\n\
    6-to print a list of all of the data\n");

    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
    add_head_node();

        break;
    case 2:
    add_node();
        break;
    case 3:

    printf("please enter the index of the list you wish to fill:\t");
    scanf("%d", &fill);
    fill_data (fill);
        break;
    case 4:

    printf("please enter the index of the list you wish to find:\t");
    scanf("%d", &find);
    fined_data(find);
        break;
    case 5:

    printf("please enter the index of the list you wish to delete:\t");
    scanf("%d", &del);
    delete_node(del);
        break;
    case 6:
    print_list();
        break;


    default:
    printf("error!!!!!!!!!!!!!!!!!!!!!!");
        break;
    }
}
