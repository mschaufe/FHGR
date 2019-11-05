#include "date.h"
#include <iostream>
#include <ctime>

Date::Date() {}

Date::Date(int year, int month, int day){
    y = year;
    m = month;
    d = day;
}

void Date::setYear(int year){
    y = year;
}

void Date::setMonth(int month){
    m = month;
}

void Date::setDay(int day){
    d = day;
}


int Date::getYear(){
    return y;
}
int Date::getMonth() {
    return m;
}
int Date::getDay() {
    return d;
}


void Date::print(){
    printf("%d-%d-%d",y,m,d);
}


void Date::daysSince2000(){
    struct std::tm a = {0,0,0,1,0,2000-1900};
    struct std::tm b = {0,0,0,d,m-1,y-1900};
    std::time_t x = std::mktime(&a);
    std::time_t y = std::mktime(&b);
    if ( x != (std::time_t)(-1) && y != (std::time_t)(-1) )
    {
        double difference = std::difftime(y, x) / (60 * 60 * 24);
        //std::cout << std::ctime(&x);
        //std::cout << std::ctime(&y);
        std::cout <<difference << std::endl;
    }
}

void Date::daysUntil(Date* reference_date){
    struct std::tm a = {0,0,0,d,m-1,y-1900};
    struct std::tm b = {0,0,0,reference_date->getDay(),reference_date->getMonth()-1,reference_date->getYear()-1900};
    std::time_t x = std::mktime(&a);
    std::time_t y = std::mktime(&b);
    if ( x != (std::time_t)(-1) && y != (std::time_t)(-1) )
    {
        double difference = std::difftime(y, x) / (60 * 60 * 24);
        std::cout <<difference << std::endl;
    }
}

