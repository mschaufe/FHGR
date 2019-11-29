#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <locale>
#include <stdio.h>
#include "dictionary.h"

Dictionary::Dictionary()
{
}

void Dictionary::loadFromFile(const std::string &filename)
{
    // Clear any input that existed previously
    dictionary.clear();
    // Open input file and check if it exists
    // Read file line by line: each line contains one word
    std::string line;
    std::ifstream myfile (filename);
    if (myfile.is_open())
    {
        while(getline(myfile, line))
        {
            //std::cout << line << std::endl;
            dictionary.insert(line);
        }
        myfile.close();
    }

    else std::cout << "Unable to open file";

    std::cout << "Number of words in dictionary: " << dictionary.size() << std::endl;
}




void Dictionary::checkFile(const std::string &inFilename, const char *outFilename)
{
    using namespace std;

    // Create output file and check if that was successful
    if (remove(outFilename) == 0)
        cout << "Old File deleted successfully"<< endl;
    else
        cout << "Unable to delete the file"<< endl;

    std::ofstream outfile (outFilename);
    cout << "File "<< outFilename << " was created successfully"<< endl;


    std::ifstream in(inFilename);

    std::string word;

    if (in.is_open()) {
        while (in >> word) {
            std::string word_norm = normalizeWord(word);
            if(wordIsOkay(word_norm)==1){
                outfile << toUppercase(word) << " " ;
            }else{
                outfile << word << " " ;
            }
        }
    }
    outfile.close();
}



bool Dictionary::wordIsOkay(const std::string &word)
{
    // Check if normalized word is in dictionary
    const bool is_in = dictionary.find((word)) != dictionary.end();
    if (!is_in){
        return true;
    }
    return false;
}



std::string Dictionary::normalizeWord(const std::string &word)
{
    // and put everything in lowercase
    std::string out = toLowercase(word);

    // Remove everything from word that is not A-Z or a-z (e.g. spaces or '.' or ',')
    std::stringstream sc_stream(out); //create string stream from the string
    getline(sc_stream, out, ','); //get first string delimited by comma

    std::stringstream sp_stream(out); //create string stream from the string
    getline(sp_stream, out, '.'); //get first string delimited by comma

    return out;
}

std::string Dictionary::toLowercase(const std::string &word){
    // and put everything in lowercase
    std::string out;
    std::locale loc;
    for(auto elem : word) {
        out.push_back(std::tolower(elem, loc));
    }
    return out;
}


std::string Dictionary::toUppercase(const std::string &word){
    // and put everything in lowercase
    std::string out;
    std::locale loc;
    for(auto elem : word) {
        out.push_back(std::toupper(elem, loc));
    }
    return out;
}
