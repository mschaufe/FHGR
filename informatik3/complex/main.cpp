#include <stdio.h>

#include "complex.h"

int main()
{
    complex r1(10.5, 25.11);
    printf("%.3f \n %.3f",r1.get_imaginary(), r1.get_real());
    r1.print_complex();
}
