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

    d1.daysSince2000();
    d2.daysSince2000();

    d1.daysUntil(&d2);
    d2.daysUntil(&d1);

    return 0;
}