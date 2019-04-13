#include <stdio.h>
#include "main.h"


/**
 *
 * Funkcja tworzy liste z adresami email.
 *
 * \param  front  -> pierwszy element listy.
 * \param  new_node  -> nowy element list z adresami email.
 *
 *
 */

void create_email(struct email** front, struct email* new_node)

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

struct email* find_spot_email(struct email* front, int data)
{
    struct email* prev = NULL;
    while(front && front->ID < data)
    {
        prev = front;
        front = front->next;
    }
    return prev;
}

void add_front_email(struct email** front, struct email* new_node)
{
    new_node->next = *front;
    *front = new_node;
}



void add_midle_email(struct email* prev, struct email* new_node)
{
    new_node->next = prev->next;
    prev->next = new_node;
}

void add_to_list_email(struct email** front, int id, char email[10])
{
    struct email* new_node = (struct email*)malloc(sizeof(struct email));
    new_node -> ID = id;

    strcpy(new_node->email, email);
    if(!(*front))
        create_email(front, new_node);
    else
    {
        if(new_node)
        {

            if((*front)->ID>=id) add_front_email(front, new_node);
            else
            {
                struct email* prev = find_spot_email(*front, id);
                add_midle_email(prev, new_node);
            }
        }
    }
}

/**
 *
 * Funkcja przypominajaca menu.
 * Wpisujemy numer, ktory chcemy dodac.
 * Nastepnie wybieramy czy chcemy dodac kolejny.
 *
 * \param  front  -> pierwszy element listy.
 * \param  new_node  -> nowy element listy.
 *
 *
 */


void email_menu(struct email** email_list, struct contacts* new_contact)
{
    int id, option = -1;

    id = new_contact->ID;
    char email[32];
    printf("Podaj email: ");
    scanf("%s", email);
    add_to_list_email(email_list, id, email);
    while(option!=0)
    {
        puts("Chcesz dodac nowy e-mail? (1 - TAK/ 0 - NIE)");
        scanf("%D", &option);
        if(option == 1)
        {
            puts("Podaj email");
            scanf("%s", email);
            add_to_list_email(email_list, id, email);


        }
        else if(option == 0)
            break;
        else
            puts("Prosze podac TAK(1) lub NIE(0)!");
    }

}
