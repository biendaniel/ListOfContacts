#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "main.h"



int main()
{
    struct contacts* front = NULL;
    struct nr_tel* number = NULL;
    struct email* email = NULL;
    load_file(&front, &number, &email);
    int option = -1;
    while(option!=0)
    {
        puts("1. Dodaj kontakt.");
        puts("2. Usun kontakt.");
        puts("3. Edytuj kontakt");
        puts("4. Wyswietl liste kontaktow");
        puts("5. Wyszukaj kontakt");
        puts("6. Posortuj liste kontaktow");
        puts("0. Wyjdz");
        puts("");
        puts("Wybierz: ");
        scanf("%d", &option);

        if(option==1) insert_node(&front, &number, &email);
        if(option==2) delete_node(&front);
        if(option==3) edit_contact(front, &number, number, email, &email);
        if(option==4) print_list(front, number, email);
        if(option==5) search_contact(front, number, email);
        if(option==6) sort_menu(front);
        if(option==0)
        {
            sort_list(front,2,8);
            save_to_file(front, number, email);
            remove_list(&front);
            remove_list_nr_tel(&number);
            remove_list_email(&email);
        }
           system("cls");
    }
    return 0;
}
