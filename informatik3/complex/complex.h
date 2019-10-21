#ifndef __COMPLEX_H__
#define __COMPLEX_H__


class complex {
public:
    complex(double re, double im);
    double get_real();
    double get_imaginary();
    void print_complex();
private:
    double real = 0.0;
    double imaginary = 0.0;
};

#endif	// _COMPLEX_H_
