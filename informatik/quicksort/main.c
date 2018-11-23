/*****************************
   * Marc Schaufelberger *
   * HTW CHUR *
   * 18. NOV 2018 *
   * Quicksort *
  ******************************/

#include <stdio.h>
#include <string.h>

/* Function to print an array */
void printArray(int arr[], int size){
    for (int i=0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}

/* Funtion to swop two elements */
void swop(int *p1, int *p2){
    int temp= *p1;
    *p1 = *p2;
    *p2 = temp;

}


/* Funtion to sort an array */
void quicksort (int *arr[],int a, int n){

            int pivot = *arr[n - 1];
            printf("Pivot: %d \n", pivot);
            int p = 0;

            for (int i = a; i < n && n > 0; i++) {
                if (*arr[i] <= pivot && p == i) {
                    p++;
                } else if (*arr[i] <= pivot) {
                    &
                    swop(&*arr[i], &*arr[p]);
                    p++;

                }
            }

}

int main() {
    int arr[] = {9,-3,5,2,6,8,-6,1,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    quicksort(&arr,0, n);
    printf("Sorted array: \n");
    printArray(arr, n);


}