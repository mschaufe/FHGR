#include <stdio.h>

#include "rectangle.h"

int main()
{
    Rectangle r1(10, 20);
    printf("A rectangle with a width of %i and a height of %i has an area of %i.\n",
           r1.get_height(), r1.get_width(), r1.get_area());

    Rectangle r2(2, 3);
    printf("A rectangle with a width of %i and a height of %i has an area of %i.\n",
           r2.get_height(), r2.get_width(), r2.get_area());
}
