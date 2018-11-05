#include <stdio.h>

int main()
{
    /* Formatelemente von printf */
    printf("Integer: %d\n", 42);
    printf("Double: %.6f\n", 3.141);
    printf("Zeichen: %c\n", 'z');
    printf("Zeichenkette: %s\n", "abc");
    printf("43 Dezimal ist in Oktal: %o\n", 43);
    printf("43 Dezimal ist in Hexadezimal: %x\n", 43);
    printf("Und zum Schluss geben wir noch das Prozentzeichen aus: %%\n\n");

    /* Flags */
    printf("Zahl 67:%+i\n", 67); /* Es wird auch bei einem positiven Wert ein Vorzeichen ausgegeben. */
    printf("Zahl 67:%-i\n", -67);
    printf("Zahl 67:% i\n", 67);
    printf("Zahl 67:%#x\n", 67);
    printf("Zahl 0:%0x\n", 10);

    /*
     * Escape-Sequenzen
     *
     * \n (new line) = bewegt den Cursor auf die Anfangsposition der nächsten Zeile.
        \t (horizontal tab) = Setzt den Tabulator auf die nächste horizontale Tabulatorposition.
        \a (alert) = gibt einen hör- oder sichtbaren Alarm aus, ohne die Position des Cursors zu ändern
        \b (backspace) = Setzt den Cursor ein Zeichen zurück. Wenn sich der Cursor bereits am Zeilenanfang befindet, dann ist das Verhalten unspezifiziert.
        \r (carriage return, dt. Wagenrücklauf) = Setzt den Cursor an den Zeilenanfang
        \f (form feed) = Setzt den Cursor auf die Startposition der nächsten Seite.
        \v (vertical tab) = Setzt den Cursor auf die nächste vertikale Tabulatorposition.
        \" " wird ausgegeben
        \' ' wird ausgegeben
        \? ? wird ausgegeben
        \\ \ wird ausgegeben
        \0 ist die Endmarkierung einer Zeichenkette
     */
}