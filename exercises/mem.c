#include <stdio.h>

int my_func(int m);

int main()
{
    int a = 1234;
    int b = 5678;
    
    b = a;
    a = 17;

    printf("--- b=a, a=17 ---\n");
    printf("Value of   a: %d\n", a);
    printf("Address of a: %d\n", &a);

    printf("Value of   b: %d\n", b);
    printf("Address of b: %d\n", &b);

    b = my_func(b);

    printf("Value of   b: %d\n", b);
    printf("Address of b: %d\n", &b);
  
    return 0;
}

int my_func(int m) 
{
    int a = 512;

    printf("--- inde i my_func ---\n");

    printf("Value of   a: %d\n", a);
    printf("Address of a: %d\n", &a);

    m = a;
    printf("Value of   m: %d\n", m);
    printf("Address of m: %d\n", &m);

    a = 0;
    printf("Value of   a: %d\n", a);
    printf("Address of a: %d\n", &a);
    printf("Value of   m: %d\n", m);
    printf("Address of m: %d\n", &m);
    m = 21;

    printf("Value of   m: %d\n", m);
    printf("Address of m: %d\n", &m);

    printf("--- afslut my_func ---\n");
    return m;
}