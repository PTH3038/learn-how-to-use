#include <stdio.h>
#include <math.h>
long double factorial(unsigned int a) {
    long double giai_thua = 1L;
    for (unsigned int i = 1; i<=a; i++) {giai_thua *= i;}
    return giai_thua;
}

int main()
{
    long double x;
    unsigned long long int n;
    scanf("%Lf %llu", &x, &n);
    if (n < 1 || x < 0) {printf("ERROR"); return 0;}
    long double ans = 0;
    for (int i = 0; i <= 2*n; i += 2) {
        ans += pow(x, i)/factorial(i);
    }
    printf("%.4Lf", ans);
    return 0;

}