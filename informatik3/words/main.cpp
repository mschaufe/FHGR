#include <iostream>
#include "dictionary.h"



int main()
{
	try
	{
		Dictionary dict;
		dict.loadFromFile("/usr/share/dict/words");
		dict.checkFile("input.txt", "output.txt");
	}
	catch (std::exception &ex)
	{
		std::cout << "Something went wrong: " << ex.what() << std::endl;
	}
	return 0;
}
