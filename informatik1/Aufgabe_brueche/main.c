 /*****************************
   * Marc Schaufelberger *
   * HTW CHUR *
   * 08. JAN 2018 *
   * Brueche *
  ******************************/

#include <stdio.h>

 int clean_stdin()
 {
     while (getchar()!='\n');
     return 1;
 }

int main() {

    int z,z1,z2 = 1;
    int n,n1,n2 = 1;
    char c;
    /* Brueche einlesen */
    do
    {
        printf("\nZahl fuer den ersten Zaehler von 1 to 99: ");
    } while (((scanf("%d%c", &z1, &c)!=2 || c!='\n') && clean_stdin()) || z1<1 || z1>99);

    do
    {
        printf("\nZahl fuer den ersten Nenner von 1 to 99: ");
    } while (((scanf("%d%c", &n1, &c)!=2 || c!='\n') && clean_stdin()) || n1<1 || n1>99);

    do
    {
        printf("\nZahl fuer den zweiten Zaehler von 1 to 99: ");
    } while (((scanf("%d%c", &z2, &c)!=2 || c!='\n') && clean_stdin()) || z2<1 || z2>99);

    do
    {
        printf("\nZahl fuer den ersten Zaehler von 1 to 99: ");
    } while (((scanf("%d%c", &n2, &c)!=2 || c!='\n') && clean_stdin()) || n2<1 || n2>99);

    /* Bruch gleichnamig machen */
    z=n2*z1+z2*n1;
    n=n1*n2;

    /* kuerzen */
    

    /* Bruch Ausgabe */
    printf("Die Summe ist: %d / %d\n", z,n);
}