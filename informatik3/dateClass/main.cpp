/*****************************
   * Marc Schaufelberger *
   * FHGR *
   * 22. Okt 2019 *
   * Exercise 2.1: Date Class  *
  ******************************/

#include <iostream>
#include "date.h"

int main() {
    Date d1;
    d1.setYear(2000);
    d1.setMonth(2);
    d1.setDay(1);
    d1.print();

    std::cout << "\n";

    Date d2(2000,3,3);
    d2.print();

    std::cout << "\n";

    std::cout << d1.daysSince2000() << "\n";
    std::cout << d2.daysSince2000() << "\n";

    std::cout << d1.daysUntil(&d2) << "\n";
    std::cout << d2.daysUntil(&d1) << "\n";

    return 0;
}