/*****************************
   * Marc Schaufelberger *
   * FHGR *
   * 00. XXX 2019 *
   * Projekt *
  ******************************/
#include <stdio.h>
#include <stdlib.h>

int parse_numbers(const char *str, double *values, size_t n)
{
    char *next = str-1;
    for (int i =0; i<=n ;i++){
        values[i] = strtod(next + 1, &next);
    }
    return 1;
}
int main() {
    char *string = "-12.2,45.6,23.2,5";
    size_t n = 4;
    double values[n];
    if (parse_numbers(string, values, n))
    {
        for (size_t i = 0; i < n; i++)
        {
            printf("%f\n", values[i]);
        }
    }
    else  {
        printf("Parse error.\n");
    } }