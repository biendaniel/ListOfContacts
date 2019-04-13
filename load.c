#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 *
 * Funkcja wczytujaca dane z pliku.
 *
 * \param  list_pointer  -> glowna lista.
 * \param  phone_pointer  -> lista z numerami telefonu.
 * \param  email_pointer  -> lista z emailami.
 *
 *
 */

void load_file(struct contacts **list_pointer, struct nr_tel **phone_pointer, struct email **email_pointer){
    int line_counter = -1;
    int id;
    FILE *load = NULL;
    load = fopen("kontakty.txt", "r");
	char buffer[128];

    while (fscanf(load, "%s", buffer) != EOF){
        id = get_next_id();
        struct contacts * new_node = (struct contacts*)malloc(sizeof(struct contacts));
        if(new_node){
            line_counter++;
            switch(line_counter){
                case 0:
                {
                    line_counter ++;

                };
                case 1: {
                    fscanf(load, "%s\n", buffer);
                    strcpy(new_node->name, buffer);

                    line_counter++;
                };
                case 2: {
                    fscanf(load, "%s\n", buffer);
                    strcpy(new_node->surname, buffer);
                    line_counter++;
                };
                case 3: {
                    fscanf(load, "%s\n", buffer);
                    strcpy(new_node->city, buffer);
                    line_counter++;
                };
                case 4: {
                    fscanf(load, "%s\n", buffer);
                    strcpy(new_node->street, buffer);
                    line_counter++;
                };
                case 5: {
                    fscanf(load, "%s\n", buffer);
                    strcpy(new_node->house_number, buffer);
                    line_counter++;

                };
                case 6: {
                    fscanf(load, "%s\n", buffer);
                    strcpy(new_node->postal_code, buffer);
                    line_counter++;
                };
                case 7: {
                    fscanf(load, "%s\n", buffer);
                    strcpy(new_node->post_office, buffer);
                    line_counter++;
                };

                case 8: {
                    char* safe;
                    fscanf(load, "%s\n", buffer);
                    safe = strtok(buffer, "|" );
                    while(safe != NULL)
                    {

                        add_to_list_tel(phone_pointer,id, safe);
                        safe = strtok( NULL, "|" );
                    }
                    line_counter++;
                    };
                    case 9: {

                        char* safe;
                    fscanf(load, "%s\n", buffer);
                    safe = strtok(buffer, "|" );
                    while(safe != NULL)
                    {
                        add_to_list_email(email_pointer,id, safe);
                        safe = strtok( NULL, "|" );
                    }
                    line_counter++;

                    };

                case 10: {
                    new_node->ID = id;
                    line_counter = 0;
                    insert_from_file(list_pointer,new_node);
                    };
                };
            }
        }
    fclose(load);
}

