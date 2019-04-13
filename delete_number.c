#include "main.h"
#include <stdio.h>

void delete_front_number(struct nr_tel **front)
{
    struct nr_tel *next = (*front)->next;
    free(*front);
    *front = next;
}

struct nr_tel *find_prev_node_number(struct nr_tel *front, int data)
{
    struct nr_tel *prev = NULL;
    while ((NULL != front) && (front->ID != data))
    {
        prev = front;
        front = front->next;
    }
    return prev;
}

void delete_after_number(struct nr_tel *node)
{
    struct nr_tel *next = node->next;
    if (NULL != next)
    {
        node->next = next->next;
        free(next);
    }
}

void delete_node_number(struct nr_tel** front, int data)
{
    if (!(*front))
            puts("Lista jest pusta.");

    else
    {
        int data;

            if ((*front)->ID == data)
                delete_front_number(front);
            else
            {
                struct nr_tel *prev = find_prev_node_number(*front, data);
                delete_after_number(prev);
            }
        }
}



