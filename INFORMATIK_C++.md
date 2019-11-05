# Allgemein
   ### Header comment ###
   
      /*****************************
       * Marc Schaufelberger *
       * FHGR *
       * 00. XXX 2019 *
       * Projekt *
      ******************************/
# Operatoren
# Vector

## Deklarieren & Definieren
Import der `vector` library.
```c++
#include <vector>
```
Einen Vektor erstellen
```c++
std::vector<int> myvector_empty;
std::vector<int> myvector_empty ={};
std::vector<int> myvector = {3,1,1,2,1};
std::vector<int> second (4,100);    // four ints with value 100
std::vector<int> fourth (second);   // a copy of third
```
## Kapazität
### size
Gibt die Anzahl der Elemente im Vektor an.
```c++
myvector.size()
```
## Modifikatoren
### push_back
Fügt ein Element am Ende des Vectors an.
```c++
myvector.push_back(variable);
```
### pop_back
Verkleinert den Vektor um eins. Das letzte Element wird somit gelöscht.
```c++
myvector.pop_back();
```
### swap
Tauscht die Werte der Vectoren.
```c++
std::vector<int> foo (3,100);   // three ints with a value of 100
std::vector<int> bar (5,200);   // five ints with a value of 200
foo.swap(bar);
```
## Funktionen ##
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
# Liste

## Liste mit Strings anlegen
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

### Deklarieren & Definieren ###
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


