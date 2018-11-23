#include <stdio.h>

int clean_stdin()
{
    while (getchar()!='\n');
    return 1;
}

int division (int *z1, int *z2, int *rest){
    *rest = *z1 % *z2;
}

int main() {
    int zahl1, zahl2 = 0;
    char c;
    do
    {
        printf("\nEnter first number from 1 to 99: ");

    } while (((scanf("%d%c", &zahl1, &c)!=2 || c!='\n') && clean_stdin()) || zahl1<1 || zahl1>99);

    do
    {
        printf("\nEnter second number from 1 to 99: ");

    } while (((scanf("%d%c", &zahl2, &c)!=2 || c!='\n') && clean_stdin()) || zahl2<1 || zahl2>99);

    int rest_division= 0;
    division(&zahl1, &zahl2, &rest_division);

    printf("\nDer Rest der Diviion betraegt: %d\n", rest_division);
}