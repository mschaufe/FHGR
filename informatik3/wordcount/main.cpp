#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

int readWordsFromFile(std::string &filename,
                      std::vector<std::string> &words)
{
    words.clear();
    std::ifstream myfile(filename);
    if (!myfile.is_open())
    {
        return -1;
    }
    std::string line;
    while (std::getline(myfile, line))
    {
        std::stringstream ssline(line);
        std::string word;
        while (std::getline(ssline, word, ' '))
        {
            std::string cleanword;
            for (size_t i = 0; i < word.size(); i++)
            {
                if (word[i] >= 'a' && word[i] <='z')
                {
                    cleanword += word[i];
                }
                else if (word[i] >= 'A' && word[i] <='Z')
                {
                    cleanword += word[i] - ('Z' - 'z');
                }
            }
            if (!cleanword.empty())
            {
                words.push_back(cleanword);
            }
        }
    }
    return 0;
}

void countWords(std::vector<std::string> &words,
                std::vector<std::string> &unique_words,
                std::vector<size_t> &word_counts)
{
    // TODO
}

bool pair_le(const std::pair<std::string,size_t> &a,
             const std::pair<std::string,size_t> &b)
{
    return a.second > b.second;
}

void showHighestCounts(
        std::vector<std::string> &unique_words,
        std::vector<size_t> &word_counts,
        size_t max_num_results)
{
    std::vector<std::pair<std::string,size_t>> pairs;
    for (size_t i = 0; i < unique_words.size(); i++)
    {
        pairs.push_back(std::make_pair(unique_words[i], word_counts[i]));
    }
    sort(pairs.begin(), pairs.end(), pair_le);
    for (size_t i = 0; i < std::min(max_num_results, pairs.size()); i++)
    {
        std::cout << pairs[i].first << " - " << pairs[i].second << std::endl;
    }
}

int main()
{
    // Read word list; more books from https://www.gutenberg.org/
    //std::string filename = "frankenstein.txt";
    //std::string filename = "dracula.txt";
    std::string filename = "mobydick.txt";
    //std::string filename = "war_and_peace.txt";

    // Read word list
    std::vector<std::string> words;
    if (readWordsFromFile(filename, words) != 0)
    {
        std::cout << "Unable to open file " << filename << "." << std::endl;
        return -1;
    }
    std::cout << "File contains " << words.size() << " words." << std::endl;

    // Make word count statistics
    std::vector<std::string> unique_words;
    std::vector<size_t> word_counts;
    countWordsFast(words, unique_words, word_counts);
    std::cout << "File contains " << unique_words.size() << " unique words." << std::endl;

    // Print statistics to console
    showHighestCounts(unique_words, word_counts, 100);

    return 0;
}

