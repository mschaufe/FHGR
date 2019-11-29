#include <iostream>   // std::cout
#include <string>     // std::string, std::to_string
#include <iomanip>
#include <tgmath.h>
#include <cmath>

int main() {
    double mittelwert = 2.5437;
    double fehler = 82.543;

    // Zunächst wird der Fehler Δ􏰢x verwendet um die Rundungsstelle festzulegen.
    // Dazu identifiziert man von links beginnend und ohne Beachtung des Dezimalpunktes, die erste von Null verschiedene Stelle.

    std::string str_fehler = std::to_string(fehler);

    int position=0;
    int found = 0;
    int i=0;
    for(char& c : str_fehler) {
        std::cout << str_fehler[i];
        if(found == 0) {
            if (str_fehler[i] == '0' || str_fehler[i] == '.') {
                position++;
            }else{
                found = 1;
            }
            i++;
        }

    }

    //Ist diese Ziffer grösser als 2, so wird an dieser Stelle gerundet. Ist die Ziffer 1 oder 2, so wird an der
    //nächstfolgenden Stelle gerundet.

    if(str_fehler[position]=='1' || str_fehler[position]=='2'){
        position=position+1;
    }

    //Der Fehler wird stets aufgerundet, unabhängig davon wie gross die Ziffer der nachfolgenden Stelle ist.

    int scale =  pow(10,position);

    std::cout << "\n" << std::ceil(fehler * scale) / scale;;

    //Der Mittelwert wird nun an der gleichen Rundungsstelle wie die Messunsicherheit ab- (Wert der
    //nachfolgenden Stelle kleiner als 5) oder aufgerundet (Wert der nachfolgenden Stelle 5 oder grösser).

    std::cout << std::setprecision(position);


    return 0;

}