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
void quicksort (int arr[],int a, int n){
    if (n>1){
        int pivot = arr[n-1];
        int p = a;

        for (int i = a; i < n; i++) {
            if (arr[i] <= pivot && p == i) {
                p++;
            } else if (arr[i] <= pivot) {
                swop(&arr[i], &arr[p]);
                p++;

            }
        }

        if (p > a) {
            int numbers_under_pivot = 0;
            for (int i = 0; i < p - 1; i++) {
                numbers_under_pivot++;
            }
            //printf("\n- Unter dem Pivot %d sind %d Elemente und der Start ist bei %d\n",pivot, numbers_under_pivot, p-1-numbers_under_pivot);
            quicksort(arr, p-1-numbers_under_pivot, numbers_under_pivot);
        }

        if ((n - p) > 1) {
            int numbers_over_pivot=0;
            for (int i = 0; i < (n - p); i++) {
                numbers_over_pivot++;
            }
            //printf("\n- Ueber dem Pivot %d sind %d Elemente und der Start ist bei %d\n",pivot, numbers_over_pivot, p);
            quicksort(arr, p, numbers_over_pivot+p);
        }
    }
}

int main() {
    int arr[] = {5,102,8,-9,3,0,-4,0,23,-6,100,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    quicksort(arr,0, n);
    printf("Sorted array: \n");
    printArray(arr, n);
}