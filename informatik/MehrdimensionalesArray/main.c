/*****************************
 * Marc Schaufelberger *
 * HTW CHUR *
 * 12. NOV 2018 *
 * Mehrdimensionales Array 8x8*
******************************/

#include <stdio.h>

/* Function to print an 2D array */
void print_2D_Array(int x, int y, int arr[x][y])
{
    for (int i=0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            printf("%d \t", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int m_arr[8][8];

    /* data */
    for (int i = 0; i<8; i++){
        for (int j = 0; j<8; j++){
            m_arr[i][j] = (8*i)+j+1;
        }
    }

    /* print */
    print_2D_Array( 8, 8 ,m_arr);

    return 0;
}