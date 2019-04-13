#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "main.h"


/**
 *
 * Funkcja sprawdza rozmiar listy.
 *
 * \param  pointer  -> glowna struktura.
 *
 * \return Funkcja zwraca rozmiar listy.
 *
 */

int counter(struct contacts* pointer)
{
    int i = 0;
    while(pointer)
    {
        pointer = pointer->next;
        ++i;
    }
    return i;
}

/**
 *
 * Funkcja pomocnicza przy sortowaniu.
 *
 * \param  pointer  -> przez ten parametr podajemy liste, która chcemy posortowac.
 * \param  index  -> licznik.
 *
 * \return Funkcja zwraca element listy, ktory nalezy zamienic.
 *
 */

struct contacts* at(struct contacts* pointer, int index)
{
    while(pointer && index>0)
    {
        pointer = pointer->next;
        index--;
    }
    return pointer;
}

/**
 *
 * Funkcja zamienia kazdy element struktury.
 *
 * \param  a  -> jedna ze struktur, ktora bedzie uczestniczyla w zamianie.
 * \param  b  -> druga ze struktur, ktora bedzie uczestniczyla w zamianie.
 *
 *
 */
void swap(struct contacts* a, struct contacts* b)
{
    int tmpint;
    char tmpchar[32];

    tmpint = a->ID;
    a->ID = b->ID;
    b->ID = tmpint;
    //
    strcpy(tmpchar, a->city);
    strcpy(a->city, b->city);
    strcpy(b->city, tmpchar);
    //
    strcpy(tmpchar, a->house_number);
    strcpy(a->house_number, b->house_number);
    strcpy(b->house_number, tmpchar);
    //
    strcpy(tmpchar, a->name);
    strcpy(a->name, b->name);
    strcpy(b->name, tmpchar);
    //
    strcpy(tmpchar, a->postal_code);
    strcpy(a->postal_code, b->postal_code);
    strcpy(b->postal_code, tmpchar);
    //
    strcpy(tmpchar, a->post_office);
    strcpy(a->post_office, b->post_office);
    strcpy(b->post_office, tmpchar);
    //
    strcpy(tmpchar, a->street);
    strcpy(a->street, b->street);
    strcpy(b->street, tmpchar);
    //
    strcpy(tmpchar, a->surname);
    strcpy(a->surname, b->surname);
    strcpy(b->surname, tmpchar);
}

/**
 *
 * Funkcja ma za zadanie posortowac liste.
 *
 * \param  pointer  -> przez ten parametr podajemy liste, ktora chcemy posortowac.
 * \param  inverse  -> informuje nas o kolejnosci sortowania.
 * \param  option  -> element struktury, po ktorym bedziemy sortowac.
 *
 *
 */

void sort_list(struct contacts* pointer, int inverse, int option)
{
    if (inverse == 2)
    {
        int i,j;
        int size_of_list = counter(pointer);
        for (i=0;i<size_of_list-1;++i)
        {
            int min = i;
            for (j=i+1;j<size_of_list;++j)
            {
                switch(option)
                {
                case 1:
                    if (strcmp(at(pointer,min)->name, at(pointer, j)->name)>0)
                        min = j; break;
                case 2:
                    if (strcmp(at(pointer,min)->surname, at(pointer, j)->surname)>0)
                        min = j; break;
                case 3:
                    if (strcmp(at(pointer,min)->city, at(pointer, j)->city)>0)
                        min = j; break;
                case 4:
                    if (strcmp(at(pointer,min)->street, at(pointer, j)->street)>0)
                        min = j; break;
                case 5:
                    if (strcmp(at(pointer,min)->house_number, at(pointer, j)->house_number)>0)
                        min = j; break;
                case 6:
                    if (strcmp(at(pointer,min)->postal_code, at(pointer, j)->postal_code)>0)
                        min = j; break;
                case 7:
                    if (strcmp(at(pointer,min)->post_office, at(pointer, j)->post_office)>0)
                        min = j; break;
                case 8:
                    if (at(pointer, min)->ID > at(pointer, j)->ID)
                        min = j; break;
                }
            }
            if (min != i)
                swap(at(pointer, i), at(pointer,min));
        }
    }else if(inverse == 1){
        int i,j;
        int size_of_list = counter(pointer);
        for (i=0;i<size_of_list-1;++i)
        {
            int min = i;
            for (j=i+1;j<size_of_list;++j)
            {
                switch(option)
                {
                case 1:
                    if (strcmp(at(pointer,min)->name, at(pointer, j)->name)<0)
                        min = j; break;
                case 2:
                    if (strcmp(at(pointer,min)->surname, at(pointer, j)->surname)<0)
                        min = j; break;
                case 3:
                    if (strcmp(at(pointer,min)->city, at(pointer, j)->city)<0)
                        min = j; break;
                case 4:
                    if (strcmp(at(pointer,min)->street, at(pointer, j)->street)<0)
                        min = j; break;
                case 5:
                    if (strcmp(at(pointer,min)->house_number, at(pointer, j)->house_number)<0)
                        min = j; break;
                case 6:
                    if (strcmp(at(pointer,min)->postal_code, at(pointer, j)->postal_code)<0)
                        min = j; break;
                case 7:
                    if (strcmp(at(pointer,min)->post_office, at(pointer, j)->post_office)<0)
                        min = j; break;
                case 8:
                    if (at(pointer, min)->ID < at(pointer, j)->ID)
                        min = j; break;
                }
            }
            if (min != i)
                swap(at(pointer, i), at(pointer,min));
        }
    }
}

/**
 *
 * Funkcja pelniaca role menu.
 * Tutaj wybieramy w jaki sposob chcemy posortowac liste.
 *
 * \param  pointer  -> przez ten parametr podajemy liste, która chcemy posortowac.
 *
 *
 */

void sort_menu(struct contacts* pointer)
{
    system("cls");
    int type, option;
    int isgood = 0;
    do{
        puts("Chce posortowac malejaco/rosnaco.  [1/2]");
        isgood = scanf("%d", &type);
        if(type == 1 || type == 2)
            isgood = 1;
        else
        {
            isgood = 0;
            puts("Wybierz 1 lub 2.");
            system("pause");
        }

        while(getchar()!='\n');
        system("cls");
    }while(!isgood);
    isgood = 0;
    do{
        puts("Chce posortowac wedlug:");
        puts("1. Imie.");
        puts("2. Nazwisko.");
        puts("3. Miasto.");
        puts("4. Ulice.");
        puts("5. Numer domu.");
        puts("6. Kod pocztowy.");
        puts("7. Poczte.");
        puts("8. ID.");
        isgood = scanf("%d", &option);
        if(option == 1 || option == 2 || option == 3 || option == 4 || option == 5 || option == 6 || option == 7 || option == 8)
            isgood = 1;
        else
        {
            isgood = 0;
            puts("Wybierz jedna z ponizszych opcji.");
            system("pause");
        }
        while(getchar()!='\n');
        system("cls");
    }while(!isgood);
    sort_list(pointer, type, option);
}
