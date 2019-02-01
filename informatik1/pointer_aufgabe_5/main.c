#include <stdio.h>

void printString(char* str) {
    while(*str) {
        printf("%c",*str++);
    }
}
int countString(char *str, int *lenght) {
    while(*str) {
       *str++;
        *lenght++;
    }
    printf("l:%d\n",*lenght);
}

int main(void) {
    char string[100];
    printf("Geben Sie einen String ein: ");
    scanf("%99s", &string[0]);

    int lenght = 0;

    printString(&string);
    printf("\nLaenge: %d", countString(&string,&lenght));
}
//Nicht fertig!