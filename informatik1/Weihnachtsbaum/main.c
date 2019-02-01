/*****************************
 * Marc Schaufelberger *
 * HTW CHUR *
 * 3. Nov 2018 *
 * Aufgabe Weihnachtsbaum
******************************/

#include <stdio.h>
#include <stdlib.h>

int clean_stdin()
{
    while (getchar()!='\n');
    return 1;
}
int main() {
    int i,b,a,s,hoehe=0;
    char c;
    do
    {
        printf("\nEnter your first number from 1 to 99: ");

    } while (((scanf("%d%c", &hoehe, &c)!=2 || c!='\n') && clean_stdin()) || hoehe<1 || hoehe>99);

    for(i=1; i<=hoehe; i++) {

        /* Abstand */
        for (a=hoehe; a>i; a--){
            printf(" ");
        }

        /* Sterne */
        for (b=0; b<(i*2)-1; b++){
            printf("*");
        }
        printf("\n");

    }
    /* Stamm */
    for (s=hoehe; s>1; s--){
        printf(" ");
    }
    printf("|");


}