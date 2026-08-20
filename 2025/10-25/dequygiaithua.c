#include <stdio.h>
long double factorial(int n) {
    long double fac = 1;
    if (n == 0) {fac = 1;}
    else if (n < 0) {return -1912;}
    else {fac = factorial(n-1)*n;}
    return fac;
}
int main() {
    int N; printf("Nhap N: "); scanf("%d", &N);
    long double kq = factorial(N);
    if (kq != -1912) {printf("%Lf", kq); return 0;}
    else {printf("ERROR"); return 0;}
}