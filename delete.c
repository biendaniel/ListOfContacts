#include "main.h"
#include <stdio.h>
#include <stdlib.h>


/**
 *
 * Funkcja pomocnicza.
 * Usuwa element z przodu listy.
 *
 * \param  front  -> pierwszy element listy.
 *
 *
 */

void delete_front(struct contacts **front)
{
    struct contacts *next = (*front)->next;
    free(*front);
    *front = next;
}

/**
 *
 * Funkcja pomocnicza.
 * Wyszukuje element listy, który chcemy usunac
 *
 * \param  front  -> glowna lista.
 * \param  data  -> id kontaktu.
 *
 * \return Funkcja zwraca element przed tym, ktory usuwamy.
 *
 */

struct contacts *find_prev_node(struct contacts *front, int data)
{
    struct contacts *prev = NULL;
    while ((NULL != front) && (front->ID != data))
    {
        prev = front;
        front = front->next;
    }
    return prev;
}

/**
 *
 * Funkcja pomocnicza.
 * Usuwa element z srodka lub konca listy.
 *
 * \param  node  -> element listy, który usuwamy.
 *
 *
 */

void delete_after(struct contacts *node)
{
    struct contacts *next = node->next;
    if (NULL != next)
    {
        node->next = next->next;
        free(next);
    }
}

/**
 *
 * Glowna funkcja usuwajaca kontakt.
 *
 * \param  front  -> pierwszy element listy.
 *
 *
 */

void delete_node(struct contacts** front)
{
    if (!(*front))
            puts("Lista jest pusta.");

    else
    {
        int data;
        puts("Podaj ID kontaktu, ktory chcesz usunac: ");
            scanf("%d", &data);

            if ((*front)->ID == data)
                delete_front(front);
            else
            {
                struct contacts *prev = find_prev_node(*front, data);
                delete_after(prev);

            }
        }
}


