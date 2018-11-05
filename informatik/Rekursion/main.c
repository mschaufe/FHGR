/*****************************
 * Marc Schaufelberger *
 * HTW CHUR *
 * 20. OKT 2018 *
 * Rekursion
******************************/

#include<stdio.h>

int fakultaet(int x) {
    if(x > 1) {
        return x * fakultaet(x-1);
    }else {
        return 1;
    }
}

int main() {
    int a = 5;
    printf("Fakultaet von %d ist %d\n", a, fakultaet(a));
    return 0;
}