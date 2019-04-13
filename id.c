#include "main.h"

/**
 *
 * Ta funkcja sprawia, ze kazde ID jest unikalne.
 *
 *
 * \return Zwraca numer, ktory staje sie ID.
 *
 */

int get_next_id()
{
    static int id;
    return ++id;
}
/**
 *
 * Ta funkcja sprawia, ze kazde ID jest unikalne.
 *
 *
 * \return Zwraca numer, ktory staje sie ID.
 *
 */
int get_next_id_tel()
{
    static int id_tel;
    return ++id_tel;
}
/**
 *
 * Ta funkcja sprawia, ze kazde ID jest unikalne.
 *
 *
 * \return Zwraca numer, ktory staje sie ID.
 *
 */
int get_next_id_email()
{
    static int id_email;
    return ++id_email;
}
