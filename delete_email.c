#include "main.h"
#include <stdio.h>

/**
 *
 * Funkcja pomocnicza.
 * Usuwa element z przodu listy.
 *
 * \param  front  -> pierwszy element listy z adresami email.
 *
 *
 */

void delete_front_email(struct email **front)
{
    struct email *next = (*front)->next;
    free(*front);
    *front = next;
}

/**
 *
 * Funkcja pomocnicza.
 * Wyszukuje element listy, ktory chcemy usunac
 *
 * \param  front  -> lista z adresami email.
 * \param  data  -> id kontaktu.
 *
 * \return Funkcja zwraca element przed tym, ktory usuwamy.
 *
 */

struct email *find_prev_node_email(struct email *front, int data)
{
    struct email *prev = NULL;
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
 * \param  node  -> element listy, ktory usuwamy.
 *
 *
 */
void delete_after_email(struct email *node)
{
    struct email *next = node->next;
    if (NULL != next)
    {
        node->next = next->next;
        free(next);
    }
}

/**
 *
 * Glowna funkcja usuwajaca adresy email.
 *
 * \param  front  -> pierwszy element listy z adresami email.
 * \param  data -> numer id.
 *
 *
 */
void delete_node_email(struct email** front, int data)
{
    if (!(*front))
            puts("Lista jest pusta.");

    else
    {
        int data;

            if ((*front)->ID == data)
                delete_front_email(front);
            else
            {
                struct email *prev = find_prev_node_email(*front, data);
                delete_after_email(prev);
            }
        }
}




