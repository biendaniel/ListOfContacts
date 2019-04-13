#include <stdio.h>
#include <stdlib.h>
#include "main.h"


/**
 *
 * Funkcja pobiera od uzytkownika dane dotyczace kontaktu.
 *
 * \param new_node  -> glowna lista.
 *
 */

void scanf_list(struct contacts* new_node)
{
    system("cls");
        int i;
        new_node->ID = get_next_id();
        while(getchar()!='\n');
        printf("Podaj imie: ");
        scanf("%[^\n]s", new_node->name);
         for (i=0;i<strlen(new_node->name);i++)
            if (new_node->name[i] == ' ')
                    new_node->name[i] = '_';
        while(getchar()!='\n');
        printf("Podaj nazwisko: ");
         scanf("%[^\n]s", new_node->surname);
         for (i=0;i<strlen(new_node->surname);i++)
            if (new_node->surname[i] == ' ')
                    new_node->surname[i] = '_';
        while(getchar()!='\n');
         printf("Adres: \n");
         printf("\t Podaj miasto, w ktorym mieszkasz: ");
         printf("\t");
         scanf("%[^\n]s", new_node->city);
         for (i=0;i<strlen(new_node->city);i++)
            if (new_node->city[i] == ' ')
                    new_node->city[i] = '_';
        while(getchar()!='\n');
         printf("\t Podaj ulice na ktorej mieszkasz: ");
         printf("\t");
         scanf("%[^\n]s", new_node->street);
         for (i=0;i<strlen(new_node->street);i++)
            if (new_node->street[i] == ' ')
                    new_node->street[i] = '_';
        while(getchar()!='\n');
         printf("\t Podaj numer domu: ");
         printf("\t");
         scanf("%[^\n]s", new_node->house_number);
         for (i=0;i<strlen(new_node->house_number);i++)
            if (new_node->house_number[i] == ' ')
                    new_node->house_number[i] = '_';
        while(getchar()!='\n');
         printf("Kod pocztowy: ");
         scanf("%s", new_node->postal_code);
         while(getchar()!='\n');
         printf("\t Poczta: ");
         printf("\t");
         scanf("%[^\n]s", new_node->post_office);
         for (i=0;i<strlen(new_node->post_office);i++)
            if (new_node->post_office[i] == ' ')
                    new_node->post_office[i] = '_';
        while(getchar()!='\n');
}

/**
 *
 * Funkcja tworzaca liste
 *
 * \param  front  -> pierwszy element listy.
 * \param  new_node -> nowy element listy.
 *
 *
 */

void create_list(struct contacts** front, struct contacts* new_node)

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
 * Funkcja pomocnicza.
 * Dodaje element na poczatek listy.
 *
 * \param  front  -> pierwszy element listy z adresami email.
 * \param  new_node  -> nowy element listy.
 *
 *
 */

void insert_front(struct contacts **front, struct contacts *new_node)
{
    new_node->next = *front;
    *front = new_node;
}
/**
 *
 * Funkcja wyszukujaca miejsce, gdzie nalezy dodac nowy element.
 *
 * \param  front  -> glowna lista.
 * \param  data -> id noweg kontaktu.
 *
 * \return Funkcja zwraca element za ktorym nalezy dodac nowy kontakt.
 *
 */

struct contacts *find_spot(struct contacts *front, int data)
{
    struct contacts *prev = NULL;
    while ((NULL != front) && (front->ID < data))
    {
        prev = front;
        front = front->next;
    }
    return prev;
}

/**
 *
 * Funkcja pomocnicza.
 * Dodaje element w srodku lub na koncu listy.
 *
 * \param  node  -> element za ktorym nalezy dodac element.
 * \param  new_node  -> nowy element listy.
 *
 *
 */
void insert_after(struct contacts *node, struct contacts *new_node)
{
    new_node->next = node->next;
    node->next = new_node;
}

/**
 *
 * Jest to glowna funkcja dodajaca element do glownej listy.
 * Alokowana jest w niej pamiec i nastepuje decyzja czy nalezy tworzyc liste, czy dodac nowy element.
 *
 * \param  front  -> pierwszy element listy.
 * \param  number -> pierwszy element listy z numerami telefonu.
 * \param  email -> pierwszy element listy z adresami email.
 *
 *
 */
void insert_node(struct contacts **front, struct nr_tel** number, struct email** email)
{
    struct contacts *new_node = (struct contacts *)malloc(sizeof(struct contacts));
    scanf_list(new_node);
    phones_menu(number, new_node);
    email_menu(email, new_node);
    if (!(*front))
        create_list(front, new_node);
    else
    {
        if (new_node)
        {

            if ((*front)->ID >= new_node->ID)
                insert_front(front, new_node);

            else
            {
                struct contacts *node = find_spot(*front, new_node->ID);
                insert_after(node, new_node);
            }
        }
    }
}

/**
 *
 * Funkcja dodaj¹ca z pliku nowy element listy.
 *
 * \param[in]  front  -> pierwszy element listy.
 * \param[in]  new_node  -> nowy element list z numerami telefonów.
 *
 * \return Funkcja zwraca poprzez parametr pierwszy element listy.
 *
 */
void insert_from_file(struct contacts** front, struct contacts* new_node)
{

    if (!(*front))
        create_list(front, new_node);
    else
    {
        if (new_node)
        {

            if ((*front)->ID >= new_node->ID)
                insert_front(front, new_node);

            else
            {
                struct contacts *node = find_spot(*front, new_node->ID);
                insert_after(node, new_node);
            }
        }
    }
}



