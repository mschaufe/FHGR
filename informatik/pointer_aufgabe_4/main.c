#include <stdio.h>

int main() {
    int array_groesse =10, arr[array_groesse];

    int *array_pointer = &arr;
    printf("Array ops: %p\n", *array_pointer);

    for (int i=0; i<array_groesse; i++){
        arr[i]=i*4;
        printf("%d ",i*4);
    }
    printf("\n3. Element: %d\n10. Element: %d\n2.Element: %d\n",arr[*array_pointer+2],arr[*array_pointer+9],arr[*array_pointer+1]);

    for (int j = 0; j < 10; ++j) {
        printf("%d\n", arr[*array_pointer+j]);
    }
}