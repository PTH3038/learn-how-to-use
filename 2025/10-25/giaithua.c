#include <stdio.h>
long double factorial(unsigned int a) {
    long double giai_thua = 1L;
    for (unsigned int i = 1; i<=a; i++) {giai_thua *= i;}
    return giai_thua;
}
int main() {
    unsigned int a; printf("Nhap a: "); scanf("%u", &a);
    long double kq = factorial(a);
    printf("%Lf", kq);
    return 0;
}
