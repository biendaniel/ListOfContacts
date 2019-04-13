
/**
 *
 * Glowna struktura.
 *
 *\param ID ->  nr ID kontaktu.
 *  \param  name -> imie kontaktu.
 *  \param surname  -> nazwisko.
 *   \param city  -> miasto.
 *   \param street  -> ulica.
 *  \param house_number  -> numer domu.
 *  \param postal_code  -> kod pocztowy.
 *  \param post_office  -> poczta.
 *  \param *next  -> wskaznik na nastêpny element listy.
 *
 */
struct contacts
{
    int ID;
    char name[32];
    char surname[32];
    char city[32];
    char street[32];
    char house_number[32];
    char postal_code[7];
    char post_office[32];
    struct contacts *next;
};

/**
 *
 * Struktura numerów telefonu.
 *
 * \param ID -> numer ID kontaktu, do ktorego przypisany jest ten numer.
 * \param id_tel -> numer ID numeru telefonu.
 * \param number -> numer telefonu
 *  \param *next  -> wskaznik na nastêpny element listy.
 *
 * \return Funkcja nie zwraca nic.
 *
 */
struct nr_tel
{
    int ID;
    int id_tel;
    char number[10];
    struct nr_tel *next;
};

/**
 *
 * Struktura numerow telefonu.
 *
 * \param ID -> numer ID kontaktu, do ktorego przypisany jest ten numer.
 * \param id_tel -> numer ID numeru telefonu.
 * \param number -> numer telefonu
 * \param *next  -> wskaznik na nastepny element listy.
 *
 * \return Funkcja nie zwraca nic.
 *
 */

struct email
{
    int ID;
    int id_email;
    char email[32];
    struct email *next;
};

void create_list(struct contacts**, struct contacts* );
void insert_front(struct contacts**, struct contacts*);
struct contacts *find_spot(struct contacts* , int data);
void insert_after(struct contacts*, struct contacts *);
void scanf_data(struct contacts **);
int get_next_id();
int get_next_id_tel();
int get_next_id_email();
void insert_node(struct contacts**, struct nr_tel**, struct email**);
void delete_front(struct contacts**);
struct contacts *find_prev_node(struct contacts*, int);
void delete_after(struct contacts*);
void delete_node(struct contacts**);
void edit_contact(struct contacts*, struct nr_tel**, struct nr_tel*, struct email*, struct email**);
void remove_list(struct contacts**);
void remove_list_nr_tel(struct nr_tel**);
void remove_list_email(struct email**);

void print_list(struct contacts*, struct nr_tel*, struct email*);

struct nr_tel* add_phones_number(struct nr_tel*, struct contacts*);

void save_to_file(struct contacts*,struct nr_tel*, struct email*);
void read_from_file(struct contacts**);
void print_number(struct nr_tel*);
void create_list_number(struct nr_tel**);
void phones_menu(struct nr_tel**,struct contacts*);
void print_nr(struct nr_tel*);
void print_enail(struct nr_tel*);
void add_to_list(struct nr_tel**,struct contacts*, long int number);
void email_menu(struct email**, struct contacts*);
void load_file(struct contacts **, struct nr_tel **, struct email**);
void print_email(struct email*);
void delete_node_number(struct nr_tel**, int);
void delete_node_email(struct email**, int);
int choic();
void search_contact(struct contacts*, struct nr_tel*, struct email*);
