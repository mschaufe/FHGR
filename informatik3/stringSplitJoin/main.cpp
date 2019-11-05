/*****************************
   * Marc Schaufelberger *
   * FHGR *
   * 23. Okt 2019 *
   * String splitting and joining *
  ******************************/

#include <iostream>
#include <list>
#include <string>

void join_string(std::list<std::string> *lst, char separator_char[], std::string *str){
    for (auto const& i: *lst) {
        *str = *str + i + separator_char;
    }
    str->pop_back();
    std::cout << *str << "\n";
}

void split_string(std::string * str,char separator_char[], std::list<std::string> *lst){
    for(int i = 0; i< *str->size();)
}

int main() {
    // Exercise 2.2.1
    std::list<std::string> lst {"first","second","third","fourth"};
    char sep[] = ";";
    std::string str;
    join_string(&lst, sep, &str);

    // Exercise 2.2.2
    std::string strA2("first.second.third.fourth");
    char sepA2[] = ".";
    std::list<std::string> lstA2;
    split_string(&strA2,sepA2,&lstA2);

    return 0;
}