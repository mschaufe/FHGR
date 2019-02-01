#include <stdio.h>

int main() {
    int a=4, b=7, *c=&a, *d=&b; printf("a=%d - b=%d - pointer c=%p - pointer d=%p\n", a, b, *c, *d);
    a = *c * *d; printf("a=%d - b=%d - pointer c=%p - pointer d=%p\n", a, b, *c, *d);
    *d-=3; printf("a=%d - b=%d - pointer c=%p - pointer d=%p\n", a, b, *c, *d);
    b=a*b; printf("a=%d - b=%d - pointer c=%p - pointer d=%p\n", a, b, *c, *d);
    c=d; printf("a=%d - b=%d - pointer c=%p - pointer d=%p\n", a, b, *c, *d);
    b=9; printf("a=%d - b=%d - pointer c=%p - pointer d=%p\n", a, b, *c, *d);
    a=*c+*d; printf("a=%d - b=%d - pointer c=%p - pointer d=%p\n", a, b, *c, *d);

}