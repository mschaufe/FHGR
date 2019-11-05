# Semester III (C++)

## Datentypen ##
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
       * FHGR *
       * 00. XXX 2019 *
       * Projekt *
      ******************************/
## Operatoren ##  
## Vector ##

#### Vektor anlegen ####
```c++
#include <vector>
```
```c++
std::vector<int> myvector = {3,1,1,2,1};
std::vector<int> myvector_empty ={};
```

### Capacity: ###
#### size ####
Gibt die Anzahl der Elemente im Vektor an.
```c++
myvector.size()
```
### Modifiers: ###
#### push_back ####
Fügt ein Element am Ende des Vectors an.
```c++
myvector.push_back(variable);
```
#### pop_back ####
Verkleinert den Vektor um eins. Das letzte Element wird somit gelöscht.
```c++
myvector.pop_back();
```
#### swap ####
Tauscht die Werte der Vectoren.
```c++
std::vector<int> foo (3,100);   // three ints with a value of 100
std::vector<int> bar (5,200);   // five ints with a value of 200
foo.swap(bar);
```


### Functions ###
#### print ####
Funktion um einen Vektor aus zu geben:
``` c++
void print(std::vector<int> const &input)
{
    for (int i = 0; i < input.size(); i++) {
        std::cout << input.at(i) << ' ';
    }
}
```
## Liste ##

### Liste mit Strings anlegen ###
```c++
#include <list>
```
```c++
std::list<std::string> lst {"first","second","third","fourth"};
```

### Capacity: ###
Gibt die Anzahl der Elemente in der Liste zurück
```c++
myints.size()
```
### Element access: ###
#### front ####
Zeigt auf das erste Element in der Liste
```c
mylist.front()
```
#### back ####
Zeigt auf das letzte Element in der Liste
```c
mylist.back()
```
### Modifiers: ###
#### push_back ####
Fügt ein Element am Ende der Liste an.
```c++
mylist.push_back(myint);
```
#### pop_back ####
Verkleinert die Liste um eins. Das letzte Element wird somit gelöscht.
```c++
mylist.pop_back();
```

### Functions ###
#### print ####
Funktion um einen Vektor aus zu geben:
``` c++
void print(std::list<std::string> const &list)
{
    for (auto const& i: list) {
        std::cout << i << "\n";
    }
}
```
## String ##

### Definieren ###
``` c++
std::string stringName("BlaBlablaa");
``` 

### Print ###

``` c++
std::cout << someString << "\n";
``` 
oder
``` c++
printf("%s\n",someString.c_str());
``` 

### substr ###
#### Beispiel ####
```c++
#include <iostream>
#include <string>

int main ()
{
  std::string str="We think in generalities, but we live in details.";
                                           // (quoting Alfred N. Whitehead)

  std::string str2 = str.substr (3,5);     // "think"

  std::size_t pos = str.find("live");      // position of "live" in str

  std::string str3 = str.substr (pos);     // get from "live" to the end

  std::cout << str2 << ' ' << str3 << '\n';

  return 0;
}
```
Ausgabe:
```c++
think live in details.
```
### stoi ###


