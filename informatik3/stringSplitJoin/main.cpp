/*****************************
   * Marc Schaufelberger *
   * FHGR *
   * 23. Okt 2019 *
   * String splitting and joining *
  ******************************/

#include <iostream>
#include <list>
#include <vector>
#include <string>

void print_list(std::list<std::string> const &list)
{
    for (auto const& i: list) {
        std::cout << i << "\n";
    }
}

void join_string(std::list<std::string> *lst, char separator_char, std::string *str){
    for (auto const& i: *lst) {
        *str = *str + i + separator_char;
    }
    str->pop_back();
    std::cout<< "\n" << *str <<"\n";
}

void split_string(std::string * str,char separator_char, std::list<std::string> *lst){
    std::vector<int> p1 (1);
    int i=0;
    for(char& c : *str) {
        i++;
        if (c == separator_char){
            p1.push_back(i);
        }
    }
    p1.push_back(str->size());

    for(decltype(p1.size()) j=0;j<p1.size();j++){
        unsigned n1 = p1[j];
        unsigned n2 = p1[j+1];
        lst->push_back(str->substr(n1,n2-n1-1));
    }
    print_list(*lst);
}

int main() {
    // Exercise 2.2.1
    std::list<std::string> lst {"first","second","third","fourth"};
    char sep = ';';
    std::string str;
    join_string(&lst, sep, &str);

    // Exercise 2.2.2
    std::string strA2("first.second.third.fourth");
    char sepA2 = '.';
    std::list<std::string> lstA2;
    split_string(&strA2,sepA2,&lstA2);

    return 0;
}