/*****************************
 * Marc Schaufelberger *
 * HTW CHUR *
 * 12. Nov 2018 *
 * Array Aufgabe
******************************/

#include <stdio.h>
#include <stdlib.h>

int clean_stdin()
{
    while (getchar()!='\n');
    return 1;
}
/* Function to print an array */
void printArray(int arr[], int size)
{
    for (int i=0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}

int main()
{
    /* Get 2 Numbers from User and check them*/
    int arr[5];
    char c;
    for (int i=0; i<5; i++){
        do
        {
            printf("\nEnter your first number from 1 to 99: ");

        } while (((scanf("%d%c", &arr[i], &c)!=2 || c!='\n') && clean_stdin()) || arr[i]<1 || arr[i]>99);
    }
    printf("\nArray; \n");
    printArray(arr, 5);

    return 0;
}