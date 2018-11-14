# Überblick C

## 1. Datentypen ##
   #### Signed / Unsigned ####
   Die ganzzahligen Typen können  `signed` oder `unsigned` sein (signed int, unsigned int): Dies weist darauf
   hin, ob im Binärwort für den Wert das erste Bit als Vorzeichenbit verwendet
   wird, oder nicht.
   #### Variablentypen in C ####
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
## 1. Printf ##
   #### Formatelemente ####
   Formatelemente von printf:
   ```
   printf("Integer: %d\n", 42);
   printf("Double: %.6f\n", 3.141);
   printf("Zeichen: %c\n", 'z');
   printf("Zeichenkette: %s\n", "abc");
   printf("43 Dezimal ist in Oktal: %o\n", 43);
   printf("43 Dezimal ist in Hexadezimal: %x\n", 43);
   printf("Und zum Schluss geben wir noch das Prozentzeichen aus: %%\n\n");
   ```
   Flags:
   ```
   printf("Zahl 67:%+i\n", 67);
   printf("Zahl 67:%-i\n", -67);
   printf("Zahl 67:% i\n", 67);
   printf("Zahl 67:%#x\n", 67);
   printf("Zahl 0:%0x\n", 10);
   ```

## 1. Scanf ##
## 1. Schleifen ##
   #### for ####
   #### while ####
   #### do while ####
   #### do while ####
## 1. Array ##
  #### 1. 2D Array   ####
  #### 1. Bubbelsort   ####
  #### 1. Selectionsort   ####
  

