#include <stdio.h>
void increment(int  *var)
{
    *var = *var+1;
}
int main()
{
    int num=20;
    printf("Value of num is: %d\n", num); /* 20 */

    increment(&num);

    printf("Value of num is: %d", num); /* 21 */
    return 0;
}
