#ifndef LINKED_ARRAY_INT_H
#define LINKED_ARRAY_INT_H

#define VALUES_NUM 8

typedef struct linked_array_int_node
{
    int64_t                       values[VALUES_NUM];
    int64_t                       values_count;
    
    struct linked_array_int_node  *next;
}
linked_array_int_node_t;

typedef struct linked_array_int_head
{
    int64_t                       nodes_count;
    
    struct linked_array_int_node  *node_head;
    struct linked_array_int_node  *node_tail;
}
linked_array_int_t;

#endif
