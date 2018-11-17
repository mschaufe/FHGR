/* Array.c

Autor: Rabus Dominik
Version: 0.1
Datum: 22.10.2018
Änderungen:

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int clean_stdin()
{
    while (getchar()!='\n');
    return 1;
}

//Function for printing 3D Arrays
void print_3D_Array(int x, int y, int z, int arr[x][y][z]){

    for (int i = 0; i < z; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < x; k++)
            {
                printf("%d\t", arr[k][j][i]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

int main()
{
    char eingabestring[10];
    char ca;

    do
    {
        printf("\nBitte geben Sie start ein um das Programm zu starten: ");

    } while (((scanf("%99s%c", &eingabestring[0], &ca)!=2 || ca!='\n' ) && clean_stdin()) || strcmp(eingabestring,"start")!=0);


    // Werte einlesen

    int dimension1,dimension2,dimension3 = 0;
    char c;
    do
    {
        printf("\nEnter a number from 1 to 99 for: x = ");

    } while (((scanf("%d%c", &dimension1, &c)!=2 || c!='\n') && clean_stdin()) || dimension1<1 || dimension1>99);
    do
    {
        printf("\nEnter a number from 1 to 99 for: y = ");

    } while (((scanf("%d%c", &dimension2, &c)!=2 || c!='\n') && clean_stdin()) || dimension2<1 || dimension2>99);


    dimension3=2;
    int arrayd[dimension1][dimension2][dimension3];

    //Write the Array

    /* data */
    for (int k = 0; k< dimension3; k++) {
        for (int i = 0; i < dimension2; i++) {
            for (int j = 0; j < dimension1; j++) {
                arrayd[j][i][k] = ((dimension2 * i) + j + 1)*(k+1);
            }
        }
    }

    print_3D_Array(dimension1, dimension2, dimension3, arrayd);

    return 0;
}