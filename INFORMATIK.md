# Semester I

## 0. Datentypen ##
   ### Signed / Unsigned ###
   Die ganzzahligen Typen können  `signed` oder `unsigned` sein (signed int, unsigned int): Dies weist darauf
   hin, ob im Binärwort für den Wert das erste Bit als Vorzeichenbit verwendet
   wird, oder nicht.
   ### Variablentypen in C ###
   | Type                                         | Keyword        | Bit | Bytes | Range                           |
   |----------------------------------------------|----------------|-----|-------|---------------------------------|
   | character                                    | char           | 8   | 1     | -128 .. 127                     |
   | unsigned character                           | unsigned char  | 8   | 1     | 0 .. 255                        |
   | integer                                      | int            | 16  | 2     | -32 768 .. 32 767               |
   | short integer                                | short          | 16  | 2     | -32 768 .. 32 767               |
   | long integer                                 | long           | 32  | 4     | -2 147 483 648 .. 2 147 483 647 |
   | unsigned integer                             | unsigned int   | 16  | 2     | 0 .. 65 535                     |
   | unsigned short integer                       | unsigned short | 16  | 2     | 0 .. 65 535                     |
   | unsigned long integer                        | unsigned long  | 32  | 4     | 0 .. 4 294 967 295              |
   | single-precision floating-point (7 Stellen)  | float          | 32  | 4     | 1.17E-38 .. 3.4E38              |
   | double-precision floating-point (19 Stellen) | double         | 64  | 8     | 2.2E-308 .. 1.8E308             |
## 1. Head ##
   ### Header comment ###
      /*****************************
       * Marc Schaufelberger *
       * HTW CHUR *
       * 00. XXX 2019 *
       * Projekt *
      ******************************/
## 2. Operatoren ##
   ### Zuweisungsoperatoren ###
   Der Zuweisungsoperator `operand_A` = `operand_B` weist dem linken Operanden, welcher eine Variable sein muß, den Wert des rechten Operanden zu.

   | Operator | Example | Same as |
   |----------|---------|---------|
   | =        | a = b   | a = b   |
   | +=       | a += b  | a = a+b |
   | -=       | a -= b  | a = a-b |
   | *=       | a *= b  | a = a*b |
   | /=       | a /= b  | a = a/b |
   | %=       | a %= b  | a = a%b |

## 3. Printf ##
   ### Formatelemente ###
   ``` C
   printf("Integer: %d\n", 42);
   printf("Double: %.6f\n", 3.141);
   printf("Zeichen: %c\n", 'z');
   printf("Zeichenkette: %s\n", "abc");
   printf("43 Dezimal ist in Oktal: %o\n", 43);
   printf("43 Dezimal ist in Hexadezimal: %x\n", 43);
   printf("Und zum Schluss geben wir noch das Prozentzeichen aus: %%\n\n");
   ```
   ### Flags ###
   ``` C
   printf("Zahl 67:%+i\n", 67);
   printf("Zahl 67:%-i\n", -67);
   printf("Zahl 67:% i\n", 67);
   printf("Zahl 67:%#x\n", 67);
   printf("Zahl 0:%0x\n", 10);
   ```
   #### Escape-Sequenzen ####
   Eine Escape-Sequenz ist eine Zeichenkombination in der technischen Informatik, die keinen Text repräsentiert, sondern vom Gerät abgefangen wird und eine Sonderfunktion ausführt. Bei einem Bildschirmterminal kann dies z. B. die Cursor-Positionierung sein, bei einem Drucker die Umschaltung auf eine andere Schriftgröße oder das Auswerfen der Seite (ANSI-Escapesequenz).
   ```
   \n (new line) = bewegt den Cursor auf die Anfangsposition der nächsten Zeile.
   \t (horizontal tab) = Setzt den Tabulator auf die nächste horizontale Tabulatorposition.
   \a (alert) = gibt einen hör- oder sichtbaren Alarm aus, ohne die Position des Cursors zu ändern
   \b (backspace) = Setzt den Cursor ein Zeichen zurück. Wenn sich der Cursor bereits am Zeilenanfang befindet, dann ist          das Verhalten unspezifiziert.
   \r (carriage return, dt. Wagenrücklauf) = Setzt den Cursor an den Zeilenanfang
   \f (form feed) = Setzt den Cursor auf die Startposition der nächsten Seite.
   \v (vertical tab) = Setzt den Cursor auf die nächste vertikale Tabulatorposition.
   \" " wird ausgegeben
   \' ' wird ausgegeben
   \? ? wird ausgegeben
   \\ \ wird ausgegeben
   \0 ist die Endmarkierung einer Zeichenkette
   ```

## 4. Scanf ##
   ### Allgemein ###
   ### Eingabeprüfung ###
   Mit diesem Code wird eine Zahl eingelesen und geprüft, ob sie den Vorgaben entspricht.<br><br>
   Neue Funktion `clean_stdin()` erstellen
   ``` C
   int clean_stdin()
   {
       while (getchar()!='\n');
       return 1;
   }
   ```
   Im `main()`
   ``` C
   int rows1 = 0;
   char c;
   do
   {
       printf("\nEnter a number from 1 to 99: ");
       
   } while (((scanf("%d%c", &rows1, &c)!=2 || c!='\n') && clean_stdin()) || rows1<1 || rows1>99);

   ```
   > Wenn die eingegebene Zahl in diesem Fall zwischen 1 und 99 liegt, dann wird ihr Wert in rows1 gespeichert.
   ### Getchar ###
   Mit dem Befehl getchar wird das Programm angehalten und läuft erst weiter, wenn der Benutzer eine Taste drückt.
   ```C
   while( (getchar()) !='\n'){
      printf("Enter Gedrueckt!");
      }
   return EXIT_SUCCESS;
   ```
   > Wartet auf ein Enter
## 5. Schleifen ##
   ### Increment / Decrement ###
   `++i` Erhöht den Wert um eins und gibt den erhöhten Wert zurück.<br>
   `i++` gibt den Wert i weiter und erhöht ihn anschliessend.
   ### Static ###
   Variable wird nicht jedes Mal neu initialisiert.
   ```C
   static int i = 5;
    if (--i){           /* if(--i != false) - wird bei 0 beendet. */
        printf("%d ", i);
        main(10);
    }
   ```
   > Output: 4 3 2 1
   ### For ###
   Die for Schleife verwenden wir, wenn die Anzahl der Durchläufe bekannt ist. D.h. es ist eine Zähler-gesteuerte Schleife.
   ```C
   for (int i=1; i<=3; i++)
   {
       printf("%d\n", i);
   }
   ```
   ### While ###
   Die while Schleife läuft solange wie die Bedingung im Schleifenkopf wahr ist, und bricht dann ab, wenn diese falsch wird. Um Zählvariablen, in unserem Beispiel i, muß man sich selber kümmern.
   ```C
   int i=0;
   while(i < 10) {
      // weitere Anweisungen
      i++;
   }
   ```
   ### Do while ###
   Während die While-Schleife ausgeführt wird, solange die Bedingung gegeben ist, wird die Do-While-Schleife zunächst einmal ausgeführt und erst anschließend geprüft, ob die Bedingung zutrifft. 
   ```C
   int i = 0;  
    do  
    {  
        printf_s("\n%d",i++);  
    } while (i < 3);  
   ```
   ### Rekursion ###
   Das ist ein Beispiel für Rekursion. Es wird in einer Funktion die gleiche Funktion nochmals aufgerufen.
   ```C
   int fakultaet(int x) {
      if(x > 1) {
           return x * fakultaet(x-1);
       }else {
           return 1;
       }
   }
   ```
   
## 6. Array ##
  ### Print Array ###
  Das ist eine Funktion um ein eindimensionales Array au zu geben.
  ```C
  /* Function to print an array */
   void printArray(int arr[], int size){
       for (int i=0; i < size; i++) {
           printf("%d ", arr[i]);
           }
       }
  ```
  ```C
  printArray(arr, 5);
  ```
  Mit dieser Funktion kannst du ein 2D Array ausgeben
  ```C
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
  ```
   ```C
  print_2D_Array(8, 8, arr);
  ```
  ### 2D Array ###
  ### Selectionsort ###
   ``` C
      void selectionSort (int arr[], int n) {
          int j, i, min, pos;

          for (j=0; j<n-1; j++){
              min = arr[j];
              pos = j;
              for (i = j; i < n; i++) {
                  if (arr[i]<min){
                      min = arr[i];
                      pos = i;
                  }
              }
              arr[pos] = arr[j];
              arr[j] = min;
          }
      }
   ```
  ### Bubbelsort ###
  ```C
  void swop(int *p1, int *p2){
       int temp= *p1;
       *p1 = *p2;
       *p2 = temp;

   }
  ```
  ``` C
  void bubbleSort(int arr[], int n)
   {
       int i,j;

       for (i=n; i>0; i--){
           for (j=0; i>(j+1); j++ ) {
               if (arr[j] > arr[j+1]) {
                   swop(&arr[j], &arr[j+1]);
               }
           }
       }
   }
  ```
  ## 7. Pointer ##
  ### Zeiger ###
  Die Definition eines Zeigers besteht aus dem Datentyp des Zeigers und dem gewünschten Zeigernamen. Zeiger werden bei der Deklaration durch ein `*` gekennzeichnet, `int* u` ist ein Zeiger auf ein `int`, `double* f` ein Zeiger auf ein `double` etc.
  ```C
  int* zeiger1;           /* kann eine Adresse aufnehmen, die auf einen Wert vom Typ Integer zeigt */
  int *zeiger2;           /* das Leerzeichen kann sich vor oder nach dem Stern befinden */
  int * zeiger3;          /* ebenfalls möglich */
  int *zeiger4, *zeiger5; /* Definition von zwei Zeigern */
  int *zeiger6, ganzzahl; /* Definition eines Zeigers und einer Variablen vom Typ Integer */
  int **zeiger;           /* Es ist möglich einen Pointer auf einen Pointer zu definieren!*/
  ```
  ### Adressen ###
  Der Adress-Operator `&` liefert die Adresse einer Variablen (nicht zu verwechseln mit Bit-AND!). Das Codefragment zeigt drei Variablen i, l, p vom Typ int, long und Zeiger auf int.
  ```C
  int i = 5;
  long l = 2;
  int* p = &i;
  ```
  
   | var | adress       | value        |
   |-----|--------------|--------------|
   | i:  | <b>0xFF00<b> | 5            |
   | l:  | 0xFF04       | 2            |
   | p:  | 0xFF10       | <b>0xFF00<b> |
   
   Die Variable `i` mit dem Wert 5 hat die (willkürliche) Speicheradresse `0xFF00`. Dem Zeiger `p` wurde die Adresse von `i` zugewiesen. Er hat den Wert `0xFF00`.
   
  ### Zuweisung ###
  Die Zuweisung einer Adresse an einen Zeiger erfolgt mit hilfe des Adressoperators, eines Arrays, eines weiteren Zeigers oder des Wertes von `NULL`.
  ```C
      int * zeiger, wert;
       wert = 5;
       zeiger = &wert;
       printf("Die Variable ist: %d und der Ort im Speicher ist: %p", wert, *zeiger);
  ```
  
  ## 8. Strings ##
  Damit wir im Umgang mit Strings wissen, wo das Ende in der Zeichenkette ist, werden Strings in C mit dem ASCII-Zeichen 0 abgeschlossen: `\0` . D.h. im Hauptspeicher steht nicht nur `Hallo`, sondern `Hallo\0`. Bei der Initialisierung ohne die geschweiften Klammern und bei den String-Funktionen wird das Ende-Zeichen automatisch gesetzt. <br> Das Ende-Zeichen dient nur zur Markierung, deshalb ist es bei der Ausgabe auch nicht zu sehen. Wir sprechen hierbei von sogenannten nullterminierten Strings.
  ```C
  char text[6] = "Hallo";
  ```
  In der Anwendung:
  ```C
  char string[] = "die schoenen Dinge im Leben sind umsonst.";
  printf("Denke daran, %s\n", string);
  ```
  > Denke daran, die schoenen Dinge im Leben sind umsonst.
   ### String einlesen ###
   Texteingabe:
   ```C
   char string[100];
   printf("Geben Sie einen String ein: ");
   scanf("%99s", &string[0]);
   printf("Ihre Eingabe: %s\n",string);
   ```
   ### String ausgeben ###
   Verständlichere Variante
   ```C
   void printString(char* str) {
    char c = *str;
      while(c) {
      printf("%c", c);
         str++;
         c = *str;
      }
   }
   char str[] ="hallo world\n";
   printString(&str[0]);
   ```
   Kurzversion
   ```C
   void printString(char* str) {
      while(*str) {
         printf("%c",*str++);
      }
   }
   ```
   ### String Library <string.h> ###
   `#include <string.h>`<br>
   #### strcmp ####
   Lexikographischer Vergleich zweier Strings. Das Ergebnis ist 0; wenn die beiden Strings identisch sind, kleiner 0, wenn der erste String lexikographisch kleiner ist und grösser 0, wenn der erste String lexikographisch grösser ist.
   ```C
   if(strcmp(string,"string")==0){
        printf("sind identisch");
    }
   ```
   #### strncpy ####
   Mit `strncpy` kopiert man n Zeichen von `src` nach `dest`. Wichtig: Ist die Länge des zu kopierenden Strings kleiner als die Länge des Quell-Strings, wird das Ende-Zeichen im Ziel-String nicht gesetzt. Dies muss also manuell gesetzt werden.
   ```C
   char * strncpy(char *dest, char *src, int n);
   ```
   ```C
   char textA[10] = "123456";
   char textB[10];

   // kopiere in textB 3 Zeichen von textA
   strncpy(textB, textA, 3);

   // Ende-Zeichen setzen
   textB[3] = '\0';

   printf("Text A: %s\nText B: %s\n\n", textA, textB);
   ```
   >Text A: 123456<br>
   >Text B: 123
## 9. Funktionen ##
  ### Call by Value ###
  In vielen Programmiersprachen werden im Normalfall Parameter an Funktionen mithilfe einer Kopie übergeben. Das wird als `call-by-value` bezeichnet. Das bedeutet, dass innerhalb der aufgerufenen Funktion mit der Kopie gearbeitet wird und sich Änderungen nicht auf den ursprünglichen Wert auswirken.
### Call by Reference ###
Bei einer Übergabe als Referenz wirken sich Änderungen an den Parametern auf die Ursprünglichen Werte aus. In der Praxis wird das zum Beispiel verwendet, wenn eine Funktion mehrere Rückgabewerte hätte. Nachfolgend ein Beispiel für eine Funktion, die `call-by-reference` nutzt:
```C
   void increment(int  *var)
   {
       *var = *var+1;
   }
```
Im Main:
```C
increment(&num);
```
## 10. Struct ##
   ### Datentyp struct ###
   Um einen neuen Datentyp zu erstellen, geben Sie zuerst das Schlüsselwort `struct` an. Hinter struct folgt der Name des neuen Datentyps. Im folgenden Beispiel heisst der neue Datentyp also adresse. 
   ```C
   struct Person
   {
       char name[50];
       int citNo;
       float salary;
   };
   typedef struct person
   {
      int age;
      float weight;
   };
   ```
   > Mit `typedef` kann man neue Datentypnamen definieren. Danach muss man `struct` nicht eingaben.

   ### malloc ###
   
   ## 11. Mathematik ##
   
   ### GGT ###
   a und b sind die beiden Zahlen von denen man den größten Teiler haben möchte.

   ```
   int Euklid(int a, int b)
{
    if (a == 0)                          //Wenn a=0 ist b der größte gemeinsame Teiler laut Definition
    {
    	return b;
    }
    while(b != 0)                        //So lange wiederholen, wie b nicht 0 ist.
    {
    	if (a > b)
    	{
    		a = a - b;               //Wenn a größer als b, subtrahiere b von a.
    	}
        else
    	{
    		b = b - a;               //In jedem anderen Fall subtrahiere a von b.
    	}
    }
    return a;                            //In a steht jetzt der größte gemeinsame Teiler von a und b.
}
   ```
   ### Rest (Modulo) ###
   Der Rest-Operator liefert den Divisionsrest. Die Operanden des Rest-Operators müssen vom ganzzahligen Typ sein.
   
   ```
   int a = 5, b = 2;
   int ergebnis;
   ergebnis = a % b; // Ergebnis hat den Wert 1
   ```
   
   # Semester II
   
   

   ## 0. Gscheiduino ##
   
   Grundlegend ist er Gscheiduino absolut kompatibel zum Original (Arduino). Der Gscheiduino hat aber ein paar neue Features erhalten.
   
   ### Pinout ###

   <img src="https://github.com/mschaufe/htw/blob/master/informatik2/pictures_md/Gscheiduino.png" width="700">
   
   ### Datasheet
   
   [ATmega328P-PU](https://www.sparkfun.com/datasheets/Components/SMD/ATMega328.pdf)
   
   ## 1. Bitshiftleft ##

   In der Informatik ist ein bitweiser Operator ein Operator, der auf ein oder zwei Bitfolgen oder Binärzahlen auf der Ebene einzelner Bits angewendet wird.
   
   ```
   int a = 5;      // binary: 0000000000000101
   int b = a << 3; // binary: 0000000000101000, or 40 in decimal
   ```
   
   ```
Operation  Result
---------  ------
 1 <<  0      1
 1 <<  1      2
 1 <<  2      4
 1 <<  3      8
 ...
 1 <<  8    256
 1 <<  9    512
 1 << 10   1024
 ...
```
 
   ## 2. Serial Monitor ##
   Im `setup()` die Verbindung und geschwindigkeitsübertragung angeben.
   ```
      Serial.begin(9600);  
   ```
   Text ausgeben
   ```
      Serial.print("Text");  
   ```
   Variable ausgeben
   ```
      Serial.print(var);  
   ```
   Ausgebe mit Zeilenumbruch
   ```
      Serial.println("Sali!");  
   ```
   ## 3. Pulsweitenmodulation PWM ##
   Die Pulsdauermodulation ist eine Modulationsart, bei der eine technische Größe (z. B. elektrische Spannung) zwischen zwei Werten wechselt.

   ![PWM](https://github.com/mschaufe/htw/blob/master/informatik2/pictures_md/pwm_2.jpg)
   
   - **TON** (On Time): Wenn das Signal high ist.

   - **TOFF** (Off Time): Wenn das Signal low ist.

   - **Period** Ist die lie Länge eines TON und TOFF .

   - **Duty Cycle** Die Prozentzahl, in der das Signal high war. (TON * (Ton-TOFF) * 100
   
   ### analogWrite ###
   Schreibt einen Analogwert (PWM-Welle) auf einen Pin. Kann z.B. benutzt werden, um eine LED mit verschiedener Helligkeit leuchten zu lassen oder einen Motor mit unterschiedlicher Geschwindigkeit laufen zu lassen.
   
   Die Syntax ist wie folgt aufgebaut: `analogWrite(pin, value)`. Als erstes ist der Pin auf den geschrieben werden soll als Integer. Achtung! Auf den meisten Arduino-Boards (Die Boards mit dem ATmega168 oder ATmega328P) funktioniert diese Funktion auf den **Pins 3, 5, 6, 9, 10, und 11**. Der zweite Wert ist die Zykluszeit. Werte zwischen **0**(immer aus) und **255**(immer an) sind gültig.
   
   Setzt die Ausgabe auf dem LED-Pin proportional zu dem Wert, der von einem Potentiometer gelesen wird.
   ```c
   int ledPin = 9; // LED auf Digitalpin 9 verbunden
   int analogPin = 3; // Potentiometer auf Pin 3 verbunden
   int val = 0; // Variable, um den gelesenen Wert zu speichern

   void setup() {
     pinMode(ledPin, OUTPUT); // Setzt den Pin als output.
   }

   void loop() {
     val = analogRead(analogPin); // Liest den Wert vom Pin ein
     analogWrite(ledPin, val / 4); // analogRead: Werte von 0 bis 1023, analogWrite: Werte von 0 bis 255
   }
   ```
 
   ## 4. Timer ##
   
   ### 8-bit Timer/Counter0
   
   ### 16-bit Timer/Counter1
   

   <img src="https://github.com/mschaufe/htw/blob/master/informatik2/pictures_md/blockschaltbild.png" width="700">
## 5. Watchdog ## 
   Um einfach mal die Funktion des Watchdogs zu verdeutlichen hilft folgender Sketch:
      
      ```c
         #include <avr/wdt.h>

         void setup() {
         Serial.begin(9600); Serial.println("Sketch gestartet"); 
         //Aktiviere Watchdog mit 4s Zeitkonstante 
         wdt_enable(WDTO_4S);
         }

         void loop() {
           Serial.println("Warte einen Moment");
           delay(5000);
           Serial.println("Bin wieder da, aber das wirst Du nie zu sehen bekommen,vorher beisst der Watchdog zu."); 
           // Setze Watchdog Zähler zurück 
           wdt_reset();
         } 
      ```
   ## 6. Analog Digital Converter ADC ##
   Der ADC wandelt ein analoges (kontinuierliches) Signal in ein digitales (zeitdiskretes) Signal um.
   
   <img src="https://github.com/mschaufe/htw/blob/master/informatik2/pictures_md/adc.png" width="300">
   
   
   ### analogRead ###
   Liest den Wert vom angegebenen analogen Pin ein. Die Arduino-Boards enthalten einen 10-Bit-Analog-zu-Digital-Konverter. D.h. das Board mappt Eingangsspannungen zwischen 0 und 5 V auf Integer-Werte zwischen 0 und 1023. 
   
   Die Syntax von `analogRead(pin)` besteht aus einem Parameter. Nämlich von dem Pinname, der gelesen werden soll. Den analog gelesenen Wert auf dem Pin (int). Allerdings ist der Wert limitiert durch die Auflösung des Digital-Konverters (0-1023 für 10 Bit und 0-4095 für 12 Bit).


   Folgender Code liest die Spannung auf einem Analogpin und zeigt diese an.
   ```c
   int analogPin = A3; // Pin, der gelesen werden soll: Pin A3
   int val = 0; // Variable, die den gelesenen Wert speichert

   void setup() {
     Serial.begin(9600); // Setup der seriellen Verbindung
   }

   void loop() {
     val = analogRead(analogPin); // Pin einlesen
     Serial.println(val); // Wert ausgeben
   }
   ```
   ### analogReadResolution
   
   Mit `analogReadResolution(bits)` kann man die genauigkeit angeben, meist bis auf 12-bit. Das würde dann bedeuten, dass `analogRead()` einen Wert zwischen 0 und 4095 ausgibt.
   
   ### Library
   [ResponsiveAnalogRead Library](https://github.com/dxinteractive/ResponsiveAnalogRead)
   
   ### Register
   
   Der ADC benötigt 13 ADC-Taktzyklen, um eine Umwandlung durchzuführen, mit Ausnahme der ersten nach der Aktivierung des ADC. Zu diesem Zeitpunkt werden 25 ADC-Zyklen benötigt, während die Schaltung initialisiert wird.

Sie können verschiedene Voreinstellungen von 2 bis 128 wählen. Dadurch wird die Taktrate des Prozessors heruntergerechnet, um einen ADC-Takt zu erhalten. Sie können dies tun, indem Sie das ADCSRA-Register wie folgt ändern:

   ```c
      ADCSRA &= ~(bit (ADPS0) | bit (ADPS1) | bit (ADPS2)); // clear prescaler bits

      ADCSRA |= bit (ADPS0);                               //   2  
      ADCSRA |= bit (ADPS1);                               //   4  
      ADCSRA |= bit (ADPS0) | bit (ADPS1);                 //   8  
      ADCSRA |= bit (ADPS2);                               //  16 
      ADCSRA |= bit (ADPS0) | bit (ADPS2);                 //  32 
      ADCSRA |= bit (ADPS1) | bit (ADPS2);                 //  64 
      ADCSRA |= bit (ADPS0) | bit (ADPS1) | bit (ADPS2);   // 128
   ```
   
   
   ## 7. Interrupts ##
   
   Das auslösende Ereignis wird Unterbrechungsanforderung (englisch Interrupt Request, IRQ) genannt. Nach dieser Anforderung führt der Prozessor eine Unterbrechungsroutine aus. Anschließend wird das unterbrochene Programm dort fortgeführt, wo es unterbrochen wurde.
   
   Das Gscheiduino hat die Pins `2`und `3`als Interrupt-Pins definiert. Der erste Parameter von `attachInterrupt()`ist die Interrupt-Nummer. Am besten man verwendet `digitalPinToInterrupt(pin)`. Der zweite Parameter ist `ISR (Interrupt Service Routine)`. Dort gibt man den Funktionsnamen ein, von der Funktion, die dann ausgeführt werden muss. Der letzte Parameter ist der `mode`:
   + **LOW** löst den Trigger aus, wenn der Pin low ist
   + **CHANGE** löst den Trigger aus, wenn der Pin sich änder
   + **RISING** löst den Trigger aus, wenn der Pin von low zu high geht.
   + **FALLING** löst den Trigger aus, wenn der Pin von high zu low geht.
   + **HIGH** löst den Trigger aus, wenn der Pin high ist.   
   
   LED-Status ändert nach Interrupt:
   ```c
      const byte ledPin = 13;
      const byte interruptPin = 2;
      volatile byte state = LOW;

      void setup() {
        pinMode(ledPin, OUTPUT);
        pinMode(interruptPin, INPUT_PULLUP);
        attachInterrupt(digitalPinToInterrupt(interruptPin), blink, CHANGE);
      }

      void loop() {
        digitalWrite(ledPin, state);
      }

      void blink() {
        state = !state;
      }
   ```
   
