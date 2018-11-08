/*****************************
 * Marc Schaufelberger *
 * HTW CHUR *
 * 29. OKT 2018 *
 * Bubble sort
******************************/

#include <stdio.h>

void mach_switch(int *p1, int *p2){
    int temp= *p1;
    *p1 = *p2;
    *p2 = temp;

}


void bubbleSort(int arr[], int n)
{
    int i,j;

    for (i=n; i>0; i--){
        for (j=0; i>(j+1); j++ ) {
            if (arr[j] > arr[j+1]) {
                mach_switch(&arr[j], &arr[j+1]);
            }
        }
    }
}
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
}


int main()
{
    int arr[] = {2, 11, 3, 5, 4,1,9,8,4,7,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
}