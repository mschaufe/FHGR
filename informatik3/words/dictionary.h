#ifndef DICTIONARY_H
#define DICTIONARY_H



#include <set>
#include <string>



class Dictionary
{
public:
    Dictionary();
    void loadFromFile(const std::string &filename);
    void checkFile(const std::string &inFilename,
                   const char *outFilename);

private:
    std::set<std::string> dictionary;
    std::set<std::string> inputwords;

    bool wordIsOkay(const std::string &word);
    std::string normalizeWord(const std::string &word);
    std::string toUppercase(const std::string &word);
    std::string toLowercase(const std::string &word);
};



#endif // DICTIONARY_H
