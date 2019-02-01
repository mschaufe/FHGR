#include <stdio.h>
#include <string.h>

int main() {
    char sting[100];
    printf("Geben Sie einen String ein: ");
    scanf("%99s", &sting[0]);
    printf("Ihre Eingabe: %s\n",sting);
    char vergleichsstring[5] = "sali";

    if(strcmp(sting,"string")==0){
        printf("sind identisch");
    }


}