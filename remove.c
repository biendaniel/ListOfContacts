#include <stdio.h>
#include <stdlib.h>
#include "main.h"


/**
 *
 * Wszystkie te trzy funkcje maj¹ za zadanie usun¹æ elementy listy i zwolniæ pamiêæ.
 *
 * \param[in]  front -> pierwszy element listy.
 *
 * \return Funkcje zwracaj¹ przez parametr pierwszy element listy (W tym przypadku powinny zwróciæ NULL).
 *
 */


void remove_list(struct contacts **front)
{
    while (NULL != *front)
    {
        struct contacts *next = (*front)->next;
        free(*front);
        *front = next;
    }
}

void remove_list_nr_tel(struct nr_tel **front)
{
    while (NULL != *front)
    {
        struct nr_tel *next = (*front)->next;
        free(*front);
        *front = next;
    }
}

void remove_list_email(struct email **front)
{
    while (NULL != *front)
    {
        struct nr_tel *next = (*front)->next;
        free(*front);
        *front = next;
    }
}




