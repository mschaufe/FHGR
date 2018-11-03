/* muster.c */

#include <stdio.h>

#define TAUSEND 1000

int oktal(int x){ /* Erste Funktion */
    printf("Oktalsystem : %5o\n", x);
}
int hexadezimal(int x){ /* Zweite Funktion */
    printf("Hexadezimalsystem :  %X\n", x);
}

int main() {

    int oktal(),hexadezimal();

    printf("Dezimalsystem : %d\n", TAUSEND);
    oktal(TAUSEND);
    hexadezimal(TAUSEND);
}
