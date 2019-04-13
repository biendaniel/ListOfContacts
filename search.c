#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "main.h"

/**
 *
 * Funkcja ma za zadanie wyswietlenie wyszukanego kontaktu.
 *
 * \param  pointer  -> pierwszy element glownej listy.
 * \param  tel_pointer  -> pierwszy element listy z numerami tel.
 * \param  email_pointer  -> pierwszy element  listy z emailami.
 * \param  id -> id wyswietlanego kontaktu.
 *

 *
 */


void print_contact(struct contacts* pointer, struct nr_tel* tel_pointer, struct email* email_pointer, int id)
{
            printf("\n ID: %d \n", pointer->ID);
            printf("Imie: %s \n", pointer->name);
            printf("Nazwisko: %s \n", pointer->surname);
              printf("Miasto: %s \n", pointer->city);
              printf("Ulica: %s \n", pointer->street);
              printf("Nr domu: %s \n",   pointer->house_number);
              printf("Kod pocztowy: %s \n", pointer->postal_code);
              printf("Poczta: %s \n",   pointer->post_office);
              printf("Numery telefonow: ");
              while(tel_pointer!=NULL)
              {
              if(tel_pointer->ID != pointer->ID)
                tel_pointer = tel_pointer->next;
                else
                    break;
              }

              while(tel_pointer!=NULL)
              {
                  if(tel_pointer->ID == pointer->ID)
                  {
                  printf("%s ", tel_pointer->number);
                  tel_pointer = tel_pointer->next;
              }
              else
                break;
                    }
                puts(" ");
             printf("e-mail: ");
              while(email_pointer!=NULL)
              {
              if(email_pointer->ID != pointer->ID)
                email_pointer = email_pointer->next;
                else
                    break;
              }
              while(email_pointer!=NULL)
              {
                  if(email_pointer->ID == pointer->ID)
                  {
                  printf("%s ", email_pointer->email);
                  email_pointer = email_pointer->next;
              }
              else
                break;
                    }
        puts("");
}


/**
 *
 * Funkcja ma za zadanie wyszukanie kontaktu o parametrze, który poda uzytkownik.
 *
 * \param  pointer  -> glowna lista.
 * \param  tel_pointer  -> lista z numerami telefonu.
 * \param  email_pointer  -> lista z emailami.
 *
 *
 */
void search_contact(struct contacts* pointer, struct nr_tel* tel_pointer, struct email* email_pointer)
{
    system("cls");
    char text[32];
    bool check = false;
    puts("Podaj wyraz: ");
    scanf("%s", text);
    while(pointer)
    {
        if(!(strcmp(pointer->name, text)))
        {
            print_contact(pointer,tel_pointer,email_pointer, pointer->ID);
            check = true;
        }
        else if(!(strcmp(pointer->surname, text)))
        {
            print_contact(pointer,tel_pointer,email_pointer, pointer->ID);
             check = true;
        }
        else if(!(strcmp(pointer->city, text)))
        {
            print_contact(pointer,tel_pointer,email_pointer, pointer->ID);
             check = true;
        }
        else if(!(strcmp(pointer->street, text)))
        {
            print_contact(pointer,tel_pointer,email_pointer, pointer->ID);
             check = true;
        }
        else if(!(strcmp(pointer->house_number, text)))
        {
            print_contact(pointer,tel_pointer,email_pointer, pointer->ID);
             check = true;
        }
        else if(!(strcmp(pointer->postal_code, text)))
        {
            print_contact(pointer,tel_pointer,email_pointer, pointer->ID);
             check = true;
        }
        else if(!(strcmp(pointer->post_office, text)))
        {
            print_contact(pointer,tel_pointer,email_pointer, pointer->ID);
             check = true;
        }
        pointer = pointer->next;

    }
    if(!pointer && check == false)
            puts("Nie ma takiego kontaktu");
            system("pause");

}
