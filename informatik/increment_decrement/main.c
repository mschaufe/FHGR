/*****************************
 * Marc Schaufelberger *
 * HTW CHUR *
 * 4. Nov 2018 *
 * Increment und Decrement
******************************/

#include <stdio.h>

int main() {
    /* ++i */
        int i = 1;
        int j = ++i; /* Erhoeht den Wert um eins ung gibt den erhoehten Wert zurueck */
        printf("i ist: %d\n",i);    /* Wert 2 */
        printf("j ist: %d\n",j);    /* Wert 2 */

    /* i++ */
        i = 1;
        j = i++; /* gibt den Wert i weiter und erhöht ihn anschliessend */
        printf("i ist: %d\n",i);    /* Wert 2 */
        printf("j ist: %d\n",j);    /* Wert 1 */
}