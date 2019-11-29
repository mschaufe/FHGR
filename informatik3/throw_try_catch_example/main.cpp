#include <iostream>
#include <stdexcept>

int divide(int dividend, int divisor){
    if (divisor == 0){
        throw std::runtime_error("Divide by zero");
    }
    return dividend / divisor;
}

int main() {
    try {
        std::cout << "Trying to divide by zero ...\n";
        std::cout << divide(23, 0) << "\n";
    }
    catch (std::exception &ex){
        std::cout << "Error: " << ex.what() << "\n";
    }
    return 0;
}