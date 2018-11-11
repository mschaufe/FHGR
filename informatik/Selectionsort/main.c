/*****************************
 * Marc Schaufelberger *
 * HTW CHUR *
 * 11. Nov 2018 *
 * Selectionsort
******************************/

#include <stdio.h>
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
}

void selectionsort (int arr[], int n) {
    int j, i, min, pos;

    for (j=0; j<n-1; j++){
        min = arr[j];
        pos = j;
        for (i = j; i < n; i++) {
            if (arr[i]<min){
                min = arr[i];
                pos = i;
            }
        }
        arr[pos] = arr[j];
        arr[j] = min;
    }
}



int main() {
    int arr[] = {99,3,9,9,72,11,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionsort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);

}