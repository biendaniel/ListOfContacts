#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 *
 * Funkcja zapisujaca cala baze do pliku.
 *
 * \param  front  -> glowna lista.
 * \param  number  -> lista z numerami telefonu.
 * \param  email  -> lista z emailami.
 *
 *
 */

void save_to_file(struct contacts* front, struct nr_tel* number, struct email* email)
{
    struct nr_tel* tmp_number = number;
    struct email* tmp_email = email;
    FILE* file = fopen("kontakty.txt", "w");
    while(front)
    {
    fprintf(file,"%d\n", front->ID);
    fprintf(file,"%s\n", front->name);
    fprintf(file,"%s\n", front->surname);
    fprintf(file,"%s\n", front->city);
    fprintf(file,"%s\n", front->street);
    fprintf(file,"%s\n", front->house_number);
    fprintf(file,"%s\n", front->postal_code);
    fprintf(file,"%s\n", front->post_office);

            number = tmp_number;
              while(number!=NULL)
              {
                  if(number->ID == front->ID)
                  {
                  fprintf(file,"%s|", number->number);
                  number = number->next;
              }
              else
                number = number->next;
                    }

                    fprintf(file,"\n");
                email = tmp_email;
                    while(email!=NULL)
              {
                  if(email->ID == front->ID)
                  {
                  fprintf(file,"%s|", email->email);
                  email = email->next;
              }
              else
                email = email->next;
                    }

fprintf(file,"\n");
front = front->next;
    }
    fclose(file);
}

