/*****************************
   * Marc Schaufelberger *
   * HTW CHUR *
   * 00. XXX 2018 *
   * Pointer Aufgabe 1 *
  ******************************/

#include <stdio.h>

int main() {
    int * zeiger, wert;

    wert = 5;
    zeiger = &wert;


    printf("Die Variable ist: %d und der Ort im Speicher ist: %p", wert, *zeiger);
}