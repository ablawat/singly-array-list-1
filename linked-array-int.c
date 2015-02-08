#include <stdio.h>
#include <stdlib.h>
#include "linked-array-int.h"

linked_array_int_t * linked_array_int_create()
{
    linked_array_int_t *new_list = malloc(sizeof(linked_array_int_t));
    
    if (new_list != NULL)
    {
        new_list -> values_num = 0;
        new_list -> node_head  = NULL;
        new_list -> node_tail  = NULL;
    }
    
    return new_list;
}

int32_t linked_array_int_add(linked_array_int_t *list, int64_t new_value)
{
    linked_array_int_node_t *list_node;
    
    int64_t list_values_num;
    int32_t result;
    
    list_values_num = list -> values_num;
    
    if (list_values_num % NODE_VALUES_NUM == 0)
    {
        list_node = malloc(sizeof(linked_array_int_node_t));
        
        if (list_node != NULL)
        {
            list_node -> values[0]  = new_value;
            list_node -> values_num = 1;
            list_node -> next       = NULL;
            
            if (list_values_num == 0)
            {
                list -> node_head  = list_node;
                list -> node_tail  = list_node;
            }
            else
            {
                list -> node_tail -> next = list_node;
                list -> node_tail = list_node;
            }
            
            list -> values_num += 1;
            
            result = 0;
        }
        else
        {
            result = -1;
        }
    }
    else
    {
        list_node = list -> node_tail;
        
        list_node -> values[list_node -> values_num] = new_value;
        list_node -> values_num += 1;
        
        list -> values_num += 1;
        
        result = 0;
    }
    
    return result;
}

void linked_array_int_clear(linked_array_int_t *list)
{
    linked_array_int_node_t *list_node = list -> node_head;
    linked_array_int_node_t *node_to_remove;
    
    while (list_node != NULL)
    {
        node_to_remove = list_node;
        list_node = list_node -> next;
        free(node_to_remove);
    }
    
    list -> values_num = 0;
    list -> node_head  = NULL;
    list -> node_tail  = NULL;
}

void linked_array_int_print(linked_array_int_t *list)
{
    linked_array_int_node_t *list_node = list -> node_head;
    int32_t i;
    
    printf("L");
    
    while (list_node != NULL)
    {
        printf("-|");
        
        for (i = 0; i < list_node -> values_num; i++)
        {
            if (i > 0)
            {
                putchar(',');
            }
            
            printf("%ld", list_node -> values[i]);
        }
        
        printf("|");
        
        list_node = list_node -> next;
    }
    
    printf("\n");
}

void linked_array_int_destroy(linked_array_int_t *list)
{
    linked_array_int_node_t *list_node = list -> node_head;
    linked_array_int_node_t *node_to_remove;
    
    free(list);
    
    while (list_node != NULL)
    {
        node_to_remove = list_node;
        list_node = list_node -> next;
        free(node_to_remove);
    }
}
