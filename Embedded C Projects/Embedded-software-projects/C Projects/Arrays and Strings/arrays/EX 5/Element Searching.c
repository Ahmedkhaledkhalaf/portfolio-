/**
 * @file Element Searching.c
 * @author  Ahmed khaled khalaf (https://github.com/Ahmedkhaledkhalaf)
 * @brief 
 * @version 0.1
 * @date 2024-03-16
 * 
 * @copyright Copyright (c) 2024
 * 
 */


#include <stdio.h>

void Array_Print(int x, int array[]);
void Array_setting(int x, int array[]);
int swap(int *first, int *second);
void selection_sorting(int *array, int arr_len);
int binary_search(int* ptr_arr, int arr_len, int value_to_find);
void main()
{

    int n = 0, value = 0, index = 0;
    printf("please enter the number of elements n = \t");
    scanf("%d", &n);



    int Arr[n];
    Array_setting(n,Arr);

    selection_sorting(Arr, n);
    Array_Print(n,Arr);
    printf("please enter the Value to be found = \t");
    scanf("%d", &value);

    index = binary_search(Arr, n, value);

    
    printf("the index of the value is: %d", index);



}

int swap(int *first, int *second)
{
    *first = *first + *second;
    *second = *first - *second;
    *first = *first - *second;
}
void selection_sorting(int *array, int arr_len)
{

    for (int i = 0; i<arr_len ; i++)
    {
        //int min_index = i;
        for (int j = i; j<arr_len ; j++)
        {
            if (array[i/*min_index*/]>array[j])
            {
                swap(&array[j], &array[/*min_index*/i]);

            }

        }
    }
}

/**
 * @brief: Function that is used to implement the binary search algorithm
 *
 * @param ptr_arr: Pointer to the array containing list of values
 * @param arr_len:  Array Length
 * @param value_to_find:    Value to search upon
 * @return Index in case of data found. -1 if the data is not present.
 */
int binary_search(int* ptr_arr, int arr_len, int value_to_find)
{
    int start_index = 0;
    int end_index = arr_len - 1;
    int middle_index = ((start_index + end_index) / 2);

    while(ptr_arr[middle_index] != value_to_find)
    {
        if((end_index-start_index) == 1)
        {
            /*This means that the data is either exist on End index or Start Index.
            OTherwise, the data is not existed*/
            if(ptr_arr[end_index] == value_to_find)
            {
                middle_index = end_index;
                break;
            }
            else if(ptr_arr[start_index] == value_to_find)
            {
                middle_index = start_index;
                break;
            }
            else
            {
                middle_index = -1;
                break;
            }
        }

        /*Select the proper array start & end indices to point to the right array side*/
        if(ptr_arr[middle_index] > value_to_find)
        {
            /*This means that the data exists on the left side of the middle element.*/
            end_index = middle_index;
        }
        else if(ptr_arr[middle_index] < value_to_find)
        {
            /*This means that the data exists on the right side of the middle element.*/
            start_index = middle_index;
        }
        
        else
        {
            /*Data is found in the middle element*/
            break;
        }

        middle_index = ((start_index + end_index) / 2);
    }

    return middle_index;
}

void Array_Print(int x, int array[])
{
    printf("\nThe elements of your array are: \n");
    for (int i = 0; i<x; i++)
    {


            printf("%d\t", array[i]);

        printf("\t");
    }

            printf("\n");

}
void Array_setting(int x, int array[])
{

printf("please enter the elements of your array \n");
    for (int i = 0; i<x; i++)
    {

            scanf("%d", &array[i]);

    }

    printf("\n your original array is:\n");
    Array_Print(x, array);

}