/*****************************
 * Marc Schaufelberger *
 * HTW CHUR *
 * 20. OKT 2018 *
 * getchar
******************************/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    /* Wartet auf ein Enter */
    while( (getchar()) !='\n')
        printf("Enter Gedrueckt!");
    return EXIT_SUCCESS;
}
