/*****************************
 * Marc Schaufelberger *
 * HTW CHUR *
 * 26. OKT 2018 *
 * scanf
******************************/


#include <stdio.h>


int main() {

    int zahl;
    printf("Bitte geben Sie eine Zahl ein :");
    int test2 = scanf("%d", &zahl);
    printf("Hast du %d eingegeben?", zahl);

}

