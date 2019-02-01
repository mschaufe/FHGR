/*****************************
 * Marc Schaufelberger *
 * HTW CHUR *
 * 29. OKT 2018 *
 * Funktion Aufgabe 3
******************************/

#include <stdio.h>
#include <stdlib.h>

int clean_stdin()
{
    while (getchar()!='\n');
    return 1;
}

int add(int z1, int z2){
    return(z1+z2);
}
int mul(int z1, int z2){
    return(z1*z2);
}
int divi(int z1, int z2){
    return(z1/z2);
}
int sub(int z1, int z2){
    return(z1-z2);
}

int main()
{
    /* Get numbers from user and check them*/
    int z1, z2, o =0;
    char c;
    do
    {
        printf("\nEnter your first number from 1 to 99: ");

    } while (((scanf("%d%c", &z1, &c)!=2 || c!='\n') && clean_stdin()) || z1<1 || z1>99);

    do
    {
        printf("\nEnter for add (1), multiply (2), divide (3) and subtract (4): ");

    } while (((scanf("%d%c", &o, &c)!=2 || c!='\n') && clean_stdin()) || o<1 || o>5);

    do
    {
        printf("\nEnter your second number from 1 to 99: ");

    } while (((scanf("%d%c", &z2, &c)!=2 || c!='\n') && clean_stdin()) || z2<1 || z2>99);

    if(o==1){
        printf("Result is: \n%d",add(z1,z2));
    }else if(o==2){
        printf("Result is: \n%d",mul(z1,z2));
    }else if(o==3){
        printf("Result is: \n%d",divi(z1,z2));
    }else if(o==4){
        printf("Result is: \n%d",sub(z1,z2));
    }

    return 0;
}