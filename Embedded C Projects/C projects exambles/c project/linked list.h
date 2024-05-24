

/**
 * @file : linked list.h
 * @author : Ahmed Khaled Khalaf
 * @brief : File contains the Prototypes and the declaration of the used types between layers.
 * @version : 1.0
 * @date : 13-9-2022
 *
*/

#if !defined (_LINKED_LIST_H_)
#define _LINKED_LIST_H_

#endif /*_LINKED_LIST_H_*/

typedef struct _node_t
{
    char array[20];
    int id;
    float grade;
    char node_id;
    struct _node_t *next_node;


}node_t;

node_t* add_head_node(void);
node_t* add_node(void);
void delete_node (int index);
void fined_data (int index);
void fill_data (int index);
void print_list(void);
void main_menu(void);
