// ------------------------ About ----------------------
// Datentypen
// Marc Schaufelberger
// HTW Chur
// 08.10.2018
// ----------------------- Version ---------------------
// v1 - Programm erstellt

#include <stdio.h>

int main() {
    char zeichen = '@';
    // Das Zeichen wird ausgegeben
    printf("%c\n", zeichen);

    // ASCII Wert wird ausgegeben
    printf("%d\n", zeichen);

    // Groesse Speicherplatz in Byte
    printf("%d\n", sizeof(zeichen));

// ------------- ganzzahlig Signed ----------------------

    //Es wird immer von signed ausgegangen, falls nichts deklariert wurde

    // Datentyp signed Char min 8 Bit
    char ganzzahl_top = 127;
    char ganzzahl_bottom = -128;
    unsigned char char_ganzzahl_unsigned = 255;
    printf("\nMaximale Werte in char: %d,%d - bei unsigned: %d\n", ganzzahl_top, ganzzahl_bottom,char_ganzzahl_unsigned);

    // Datentyp signed short min 16 Bit
    short short_ganzzahl_top = 32767;
    short short_ganzzahl_bottom = -32768;
    unsigned short unsigend_short_ganzzahl = 65535;
    printf("\nMaximale Werte in short: %d,%d - bei unsigned: %d\n", short_ganzzahl_top, short_ganzzahl_bottom, unsigend_short_ganzzahl);

    // Datentyp signed long min 32 Bit -- Achtung bei printf %ld verwenden bei unsigned long %lu
    long long_short_ganzzahl_top = 2147483647;
    long long_short_ganzzahl_bottom = -2147483648;
    unsigned long unsigned_long_short = 4294967295;
    printf("\nMaximale Werte in long: %ld,%ld - bei unsigned: %ld\n", long_short_ganzzahl_top, long_short_ganzzahl_bottom, unsigned_long_short);


// ---------------------- Float  -------------------------

    // Datentyp float genauigkeit ist implementierungsabhaengig meist  7 geltenden ziffern
    // Wichtig bei float printf - %f - verwenden! oder &.6f zeigt 6 stellen nach dem Komma an.

    float kommazahl = 0.000001;
    printf("\nDie maxmimal geltende Anzahl Ziffern betraegt 7 Zeichen: %f\n",kommazahl);

    // Wichtig bei double printf - %e - verwenden!
    double groessere_kommazahl = 0.000000000000002;
    printf("\nDie maxmimal geltende Anzahl Ziffern betraegt 16 Zeichen / 8 bytes: %e\n",groessere_kommazahl);


    long double sehr_grosse_kommazahlen = 3.14159265358979323846264338327950288;
    printf("\nDie maxmimal geltende Anzahl Ziffern betraegt x Zeichen: %Lf\n",sehr_grosse_kommazahlen);





    return 0;
}