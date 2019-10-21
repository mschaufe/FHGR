#include "complex.h"
#include <iostream>

complex::complex(double re, double im)
{
    real = re;
    imaginary = im;
}

double complex::get_real()
{
    return real;
}

double complex::get_imaginary()
{
    return imaginary;
}

void complex::print_complex()
{
    printf("\n %.2f + i %.2f",get_imaginary(), get_real());
}

