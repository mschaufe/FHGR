/*****************************
 * Marc Schaufelberger *
 * HTW CHUR *
 * 29. OKT 2018 *
 * Aufgabe if - Anweisung 2
******************************/

#include <stdio.h>
#include <stdlib.h>

int clean_stdin()
{
    while (getchar()!='\n');
    return 1;
}

int main()
{
    /* Get 2 Numbers from User and check them*/
        int rows1, rows2 =0;
        char c;
        do
        {
            printf("\nEnter your first number from 1 to 99: ");

        } while (((scanf("%d%c", &rows1, &c)!=2 || c!='\n') && clean_stdin()) || rows1<1 || rows1>99);

        /* Das Programm geht weiter wenn                        bis
         * scanf  2 ist (also zwei Elemente erfasst wurden)     oder
         * der Zweite Wert ein Enter war ("\n")                 und
         * clean_stdin()==1 ist (gibt immer 1 zurueck)          oder
         * der erste Wert kleiner als 1                         oder
         * der erste Wert groesser als 99 ist
         * */
        do
        {
            printf("\nEnter your second number from 1 to 99: ");

        } while (((scanf("%d%c", &rows2, &c)!=2 || c!='\n') && clean_stdin()) || rows2<1 || rows2>99);

        printf("\nYour numbers are: %d & %d\n\n", rows1, rows2);

    /* Logic */
    if (rows1 > rows2){
        printf("The first number ist higher then the second one!\n\n");
        int sub=rows1-rows2;
        printf("So we subtract them: %d - %d = %d\n",rows1,rows2,sub);
    }else if (rows1 < rows2){
        printf("The first number ist smaller then the second one!\n\n");
        int add=rows1+rows2;
        printf("So we add them together: %d + %d = %d\n",rows1,rows2,add);
    }else if (rows1 == rows2){
        printf("The two numbers are equal!\n\n");
        int add=rows1*rows2;
        printf("So we multiply them: %d * %d = %d\n",rows1,rows2,add);
    }

    return 0;
}


