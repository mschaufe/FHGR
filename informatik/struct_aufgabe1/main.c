/*****************************
  * Marc Schaufelberger *
  * HTW CHUR *
  * 26. NOV 2018 *
  * Strukturen Aufgabe 1 *
 ******************************/

#include <stdio.h>
struct wohnort {
    char name[50];
    char vorname[50];
    char strasse[50];
    int strassen_nummer;
    char ort[50];
    char land[50];
} person1 ;

void output_struct_wohnort (struct wohnort x){
    printf("Vorname.........:%s\n",   x.vorname);
    printf("Nachname........:%s\n",   x.name);
    printf("Strasse.........:%s %d\n",   x.strasse,x.strassen_nummer);
    printf("Ort.............:%s\n",   x.ort);
    printf("Land............:%s\n",x.land);

}

int main() {

    printf("Geben Sie einen String ein: ");
    scanf("%99s", &person1.strasse[0]);
    printf("Die Strasse wurde auf %s geaendert.\n",person1.strasse);
    output_struct_wohnort(person1);


}