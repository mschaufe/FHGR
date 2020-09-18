/*****************************
   * Marc Schaufelberger *
   * FHGR *
   * 25. Feb 2020 *
   * MacOSX 10.15.3 *
   * CLion JetBrains *
   * Bundled LLED v9*
   * OpenCV – 4.2.0 *
  ******************************/
/*****************************
 * Tasks *
 * 1. print path from local variable *
 * 2. print passed arguments *
 * 3. print project path
******************************/
#include <stdio.h>  /* defines FILENAME_MAX */
// #define WINDOWS  /* uncomment this line to use it for windows.*/
#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif
#include<iostream>

std::string GetCurrentWorkingDir( void ) {
    char buff[FILENAME_MAX];
    GetCurrentDir( buff, FILENAME_MAX );
    std::string current_working_dir(buff);
    return current_working_dir;
}

int main(int argc, char** argv) {
    // save path to variable
    std::cout << "local variable:" << std::endl;
    std::string search_directory = "/home";
    std::cout << "path: " + search_directory << std::endl;
    std::cout << std::endl;


    // pass path to parameter
    std::cout << argc << " arguments were passed on:" << std::endl;
    for (size_t i = 0; i < argc; ++i) {
        std::cout << "arg" << i << ": " << argv[i] << std::endl;
    }
    std::cout << std::endl;

    // print project path
    std::cout << "Project path:" << std::endl;
    std::cout << "path: " + GetCurrentWorkingDir() << std::endl;
    return 1;
}
