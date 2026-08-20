#include <stdio.h>

int main()
{
    unsigned long long int a, b;
    if (scanf("%llu %llu", &a, &b) != 2) {return 1;}
    printf("%llu\n", a+b);
    return 0;
}
