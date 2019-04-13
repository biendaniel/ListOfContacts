#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 *
 * Funkcja wyswietlajaca cala baze kontaktow.
 *
 * \param  front  -> glowna lista.
 * \param  number  -> lista z numerami telefonu.
 * \param  email  -> lista z emailami.
 *
 *
 */

void print_list(struct contacts *front, struct nr_tel* number, struct email* email)
{
    system("cls");
    struct nr_tel* tmp_number = number;
    struct email* tmp_email = email;
    int i;
    if(front==NULL)
    {
        puts("Brak elementow");
        system("pause");
    }

    else while(front!=NULL)
        {
            printf("\n ID: %d \n", front->ID);
            printf("Imie: ");
            for (i=0; i<strlen(front->name); i++)
                if (front->name[i] != '_')
                    printf("%c", front->name[i]);
                else
                    printf(" ");
            puts("");
            printf("Nazwisko: ");
            for (i=0; i<strlen(front->surname); i++)
                if (front->surname[i] != '_')
                    printf("%c", front->surname[i]);
                else
                    printf(" ");
            puts("");
            printf("Miasto: ");
            for (i=0; i<strlen(front->city); i++)
                if (front->city[i] != '_')
                    printf("%c", front->city[i]);
                else
                    printf(" ");
            puts("");
            printf("Ulica: ");
            for (i=0; i<strlen(front->street); i++)
                if (front->street[i] != '_')
                    printf("%c", front->street[i]);
                else
                    printf(" ");
            puts("");
            printf("Numer domu: ");
            for (i=0; i<strlen(front->house_number); i++)
                if (front->house_number[i] != '_')
                    printf("%c", front->house_number[i]);
                else
                    printf(" ");
            puts("");
            printf("Kod pocztowy: %s ", front->postal_code);
            puts("");
            printf("Poczta: ");
            for (i=0; i<strlen(front->post_office); i++)
                if (front->post_office[i] != '_')
                    printf("%c", front->post_office[i]);
                else
                    printf(" ");
            puts("");
            printf("Numery telefonow: ");

            number = tmp_number;
            while(number!=NULL)
            {
                if(number->ID == front->ID)
                {
                    printf("%s ", number->number);
                    number = number->next;
                }
                else
                    number = number->next;
            }

            puts(" ");
            printf("e-mail: ");
           email = tmp_email;
            while(email!=NULL)
            {
                if(email->ID == front->ID)
                {
                    printf("%s ", email->email);
                    email = email->next;
                }
                else
                    email = email->next;
            }
            front=front->next;
            puts("");
        }
    puts("");
    system("pause");
}



