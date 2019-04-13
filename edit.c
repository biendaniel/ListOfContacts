#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

/**
 *
 * Funkcja pobiera od u¿ytkownika numer id kontaktu, który chce edytowaæ.
 *
 *
 * \return Funkcja zwraca numer id kontaktu.
 *
 */

int choice_id()
{
    system("cls");
    int data, option;
    puts("Znasz numer kontaktu, ktory chcesz edytowac? (1 - TAK, 0 - NIE)");
    scanf("%d", &option);
    if(option == 1)
    {
        puts("Podaj ID kontaktu, ktory chcesz edytowac: ");
        scanf("%d", &data);
        return data;
    }
    else
        puts("Wyszukaj kontakt, a nastepnie odczytaj ID.");
    system("pause");
    return 0;
}

/**
 *
 * Funkcja wyœwietla numery telefonu przypisane do danego id.
 *
 * \param[in]  number  -> poczatek list.
 * \param[in]  id  -> id kontaktu.
 *
 * \return Funkcja nie zwraca nic.
 *
 */

void print_number_edit(struct nr_tel *number, int id)
{
    while(number!=NULL)
    {
        if(number->ID != id)
            number = number->next;
        else
            break;
    }

    while(number!=NULL)
    {
        if(number->ID == id)
        {
            printf("%s - ID: %d \n ", number->number, number->id_tel);
            number = number->next;
        }
        else
            break;
    }
}

/**
 *
 * Funkcja wyœwietla adresy email przypisane do danego id.
 *
 * \param[in]  email  -> poczatek list.
 * \param[in]  id  -> id kontaktu.
 *
 * \return Funkcja nie zwraca nic.
 *
 */

void print_email_edit(struct email *email, int id)
{
    while(email!=NULL)
    {
        if(email->ID != id)
            email = email->next;
        else
            break;
    }

    while(email!=NULL)
    {
        if(email->ID == id)
        {
            printf("%s - ID: %d \n ", email->email, email->id_email);
            email = email->next;
        }
        else
            break;
    }
}

/**
 *
 * Funkcja wyszukuje numery telefonu przypisane do danego id.
 *
 * \param[in]  number_pointer  -> poczatek list.
 * \param[in]  id  -> id kontaktu.
 * \param[in]  id_tel  -> id numeru.
 *
 * \return Funkcja nie zwraca nic.
 *
 */

struct nr_tel* search_number(struct nr_tel* number_pointer, int id_tel, int id)
{
    while(number_pointer!=NULL)
    {
        if(number_pointer->ID != id)
        {
            number_pointer = number_pointer->next;

        }
        else
            break;
    }
    while(number_pointer!=NULL)
    {
        if(number_pointer->ID == id)
        {
            if(number_pointer->id_tel == id_tel)
            {
                return number_pointer;
            }
            number_pointer = number_pointer->next;
        }
    }
}

/**
 *
 * Funkcja wyszukuje adresy email przypisane do danego id.
 *
 * \param[in]  email_pointer  -> poczatek list.
 * \param[in]  id  -> id kontaktu.
 * \param[in]  email_tel  -> id email.
 *
 * \return Funkcja nie zwraca nic.
 *
 */

struct email* search_email(struct email* email_pointer, int id_email, int id)
{
    while(email_pointer!=NULL)
    {
        if(email_pointer->ID != id)
        {
            email_pointer = email_pointer->next;

        }
        else
            break;
    }
    while(email_pointer!=NULL)
    {
        if(email_pointer->ID == id)
        {
            if(email_pointer->id_email == id_email)
            {
                return email_pointer;
            }
            email_pointer = email_pointer->next;
        }
    }
}

/**
 *
 * W tej funkcji wybieramy, który element kontaktu chcemy edytowaæ.
 *
 * \return Funkcja wraca cyfre, która oznacza dany element kontaktu.
 *
 */

int choice()
{
    int data;
    puts("1. Imie.");
    puts("2. Nazwisko.");
    puts("3. Miasto.");
    puts("4. Ulice.");
    puts("5. Numer domu.");
    puts("6. Kod pocztowy.");
    puts("7. Poczte.");
    puts("8. Numer telefonu.");
    puts("9. Email.");
    puts(" ");
    puts("0. Wyjdz.");
    scanf("%d", &data);
    return data;
}


/**
 *
 * Funkcja edytuje numery telefonu
 *
 * \param[in]  number  -> kopia listy z numerami
 * \param[in]  number_pointer  -> pierwszy element listy z numerami.
 * \param[in]  id  -> id kontaktu.
 *
 * \return Funkcja nie zwraca nic.
 *
 */

void edit_tel(struct nr_tel* number, struct nr_tel** number_pointer, int id)
{
    char text[10];
    int id_tel;
    int option = -1;

    if (!(number))
    {
        puts("Lista kontaktow jest pusta.");
        return;
    }
    else
    {
        while(option!=0)
        {
            puts("EDYCJA NUMEROW TELEFONU");
            puts("1. Dodaj numer.");
            puts("2. Usun numer.");
            puts("0. Wyjdz.");
            scanf("%d", &option);

            if(option == 1)
            {
                printf("Podaj numer: ");
                scanf("%s|", text);
                add_to_list_tel(number_pointer,id, text);
            }
            else if(option == 2)
            {
                printf("Numery przypisane do tego kontaktu: ");
                print_number_edit(number, id);
                puts(" ");
                printf("Wpisz numer ID numeru, ktory chcesz usunac ");
                scanf("%d", &id_tel);

                struct nr_tel* tmp = search_number(*number_pointer, id_tel, id);
                printf("NUMER: %s", tmp->number);
                delete_node_number(&tmp, id_tel);

            }
            else if(option == 0)
                break;
            else
                puts("Wybierz jedna z opcji");
        }
    }

}

/**
 *
 * Funkcja edytuje adresy email.
 *
 * \param[in]  email  -> kopia listy z adresami email.
 * \param[in]  email_pointer  -> pierwszy element listy z adresami email.
 * \param[in]  id  -> id kontaktu.
 *
 * \return Funkcja nie zwraca nic.
 *
 */

void edit_email(struct email* email, struct email** email_pointer, int id)
{
    char text[10];
    int id_email;
    int option = -1;

    if (!(email))
    {
        puts("Lista kontaktow jest pusta.");
        return;
    }
    else
    {
        while(option!=0)
        {
            puts("EDYCJA ADRESOW EMAIL");
            puts("1. Dodaj email.");
            puts("2. Usun email.");
            puts("0. Wyjdz.");
            scanf("%d", &option);

            if(option == 1)
            {
                printf("Podaj email: ");
                scanf("%s|", text);
                add_to_list_email(email_pointer,id, text);
            }
            else if(option == 2)
            {
                printf("Adresy email przypisane do tego kontaktu: ");
                print_email_edit(email, id);
                puts(" ");
                printf("Wpisz numer ID adresu email, ktory chcesz usunac ");
                scanf("%d", &id_email);
                system("pause");

                struct email* tmp = search_email(*email_pointer, id_email, id);
                printf("NUMER: %s", tmp->email);
                delete_node_email(&tmp, id_email);

            }
            else if(option == 0)
                break;
            else
                puts("Wybierz jedna z opcji");
        }
    }

}

/**
 *
 * G³ówna funkcja edytuj¹ca bazê.
 *
 * \param[in]  front  -> g³ówna lista.
 * \param[in]  number_pointer  -> pierwszy element listy z numerami.
 * \param[in]  number  -> kopia listy z numerami
 * \param[in]  number_pointer  -> pierwszy element listy z numerami.
 * \param[in]  email  -> kopia listy z numerami
 * \param[in]  email_pointer  -> pierwszy element listy z numerami.
 *
 * \return Funkcja nie zwraca nic.
 *
 */

void edit_contact(struct contacts *front,struct nr_tel** number_pointer, struct nr_tel* number, struct email* email, struct email** email_pointer)
{
    if (!(front))
    {
        puts("Lista kontaktow jest pusta.");
        return;
    }
    else
    {

        int data = choice_id();
        struct contacts *new_node = front;
        while(new_node)
        {
            if(!new_node && (new_node->ID)!=data)
            {
                puts("Kontakt o takim ID nie istnieje!");
                return;
            }
            else if(new_node->ID == data)
            {
                int option = -1;
                puts("EDYTUJ: ");
                while(option!=0)
                {
                    option = choice();
                    switch(option)
                    {
                    case 0:
                    {
                        break;

                    }
                    break;
                    case 1:
                    {
                        printf("Podaj imie: ");
                        scanf("%s", (new_node)->name);
                    }
                    break;
                    case 2:
                    {
                        printf("Podaj nazwisko: ");
                        scanf("%s", (new_node)->surname);
                    }
                    break;
                    case 3:
                    {
                        printf("Podaj miasto: ");
                        scanf("%s", (new_node)->city);
                    }
                    break;
                    case 4:
                    {
                        printf("Podaj ulice: ");
                        scanf("%s", (new_node)->street);
                    }
                    break;
                    case 5:
                    {
                        printf("Podaj numer domu: ");
                        scanf("%s", (new_node)->house_number);
                    }
                    break;
                    case 6:
                    {
                        printf("Podaj kod pocztowy: ");
                        scanf("%s", (new_node)->postal_code);
                    }
                    break;
                    case 7:
                    {
                        printf("Podaj poczte: ");
                        scanf("%s", (new_node)->post_office);
                    }
                    break;
                    case 8:
                    {
                        edit_tel(number, number_pointer, data);
                    }
                    break;
                    case 9:
                    {
                        edit_email(email, email_pointer, data);
                    }
                    break;
                    }
                }
                return;
            }
            else
            {
                front = (front)->next;
                new_node = front;

            }
        }
    }
}
