#ifndef LINKED_ARRAY_INT_H
#define LINKED_ARRAY_INT_H

#include <stdint.h>

#define NODE_VALUES_NUM 8


typedef struct linked_array_int_node
{
    int64_t                       values[NODE_VALUES_NUM];
    int64_t                       values_num;
    
    struct linked_array_int_node  *next;
}
linked_array_int_node_t;

typedef struct linked_array_int_head
{
    int64_t                       values_num;
    
    struct linked_array_int_node  *node_head;
    struct linked_array_int_node  *node_tail;
}
linked_array_int_t;


linked_array_int_t *  linked_array_int_create();

int32_t  linked_array_int_add      (linked_array_int_t *list, int64_t new_value);

void     linked_array_int_clear    (linked_array_int_t *list);
void     linked_array_int_print    (linked_array_int_t *list);

void     linked_array_int_destroy  (linked_array_int_t *list);

#endif
