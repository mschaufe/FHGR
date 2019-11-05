#ifndef DATECLASS_DATE_H
#define DATECLASS_DATE_H

class Date {
public:
    Date();
    Date(int year, int month, int day);

    void setYear(int year);
    void setMonth(int month);
    void setDay(int day);

    int getYear();
    int getMonth();
    int getDay();

    void print();

    void daysSince2000();
    void daysUntil(Date* reference_date);

private:
    int y;
    int m;
    int d;
};



#endif //DATECLASS_DATE_H
