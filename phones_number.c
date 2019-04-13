#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 *
 * Funkcja tworzy liste z numerami telefonow.
 *
 * \param  front  -> pierwszy element listy.
 * \param  new_node  -> nowy element list z numerami telefonow.
 *
 */

void create_nr_tel(struct nr_tel** front, struct nr_tel* new_node)

{
    if (NULL != new_node)
    {
        new_node->next = NULL;
        *front = new_node;
    }
    else
        puts("Nie udalo sie stworzyc listy.");
}


/**
 *
 * Funkcja wyszukuje odpowiednie miejsce, do wstawienia nowego elementu.
 * W tym przypadku bedzie to zawsze miejsce po ostatnim elemencie.
 *
 * \param  front  -> pierwszy element listy.
 * \param  data  -> id elementu.
 *
 * \return Funkcja zwraca miejsce gdzie nalezy dodac nowy element.
 *
 */

struct nr_tel* find_spot_tel(struct nr_tel* front, int data)
{
    struct nr_tel* prev = NULL;
    while(front && front->ID < data)
    {
        prev = front;
        front = front->next;
    }
    return prev;
}

/**
 *
 * Funkcja dodaje element w odpowiednim miejscu.
 *
 * \param  prev  -> element za którym trzeba dodac nowy.
 * \param  new_node  -> nowy element listy.
 *
 *
 */
void add_midle(struct nr_tel* prev, struct nr_tel* new_node)
{
    new_node->next = prev->next;
    prev->next = new_node;
}

/**
 *
 * Jest to glowna funkcja dodajaca element do listy z numerami.
 * Alokowana jest w niej pamiec i nastepuje decyzja czy nalezy tworzyc liste, czy dodac nowy element.
 *
 * \param  front  -> pierwszy element listy.
 * \param  new_node  -> nowy element list z numerami telefonow.
 *
 *
 */

void add_to_list_tel(struct nr_tel** front, int id, char* number)
{
    struct nr_tel* new_node = (struct nr_tel*)malloc(sizeof(struct nr_tel));
    new_node -> ID = id;
    new_node -> id_tel = get_next_id_tel();

    strcpy(new_node->number, number);
    if(!(*front))
        create_nr_tel(front, new_node);
    else
    {
        if(new_node)
        {
            if(!((*front)->ID>=id))
            {
                struct nr_tel* prev = find_spot_tel(*front, id);
                add_midle(prev, new_node);
            }
        }
    }
}

/**
 *
 * Funkcja przypominajaca menu.
 * Wpisujemy numer, który chcemy dodac.
 * Nastepnie wybieramy czy chcemy dodac kolejny.
 *
 * \param  front  -> pierwszy element listy.
 * \param  new_node  -> nowy element listy.
 *
 *
 */

void phones_menu(struct nr_tel** front, struct contacts* new_contact)
{
    int id, option = -1;
    id = new_contact->ID;
    char nr_tel[10];
    printf("Podaj numer telefonu: ");
    scanf("%s", nr_tel);
    add_to_list_tel(front, id, nr_tel);
    while(option!=0)
    {
        puts("Chcesz dodac nowy nr? (1 - TAK/ 0 - NIE)");
        scanf("%d", &option);
        if(option == 1)
        {
            puts("Podaj numer telefonu:");
            scanf("%s|", nr_tel);
            add_to_list_tel(front, id, nr_tel);


        }
        else if(option == 0)
            break;
        else
            puts("Prosze podac TAK(1) lub NIE(0)!");
    }

}
