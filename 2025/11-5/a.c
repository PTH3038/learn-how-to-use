#include <stdio.h>
#include <math.h>
int main() {
    const double pi = 3.141592653589793;
    const double e = 2.718281828459045;
    double x; printf("Nhap x: "); scanf("%lf", &x);
    double loi_a = pow(2, x) + pi;
    double a = sqrt(loi_a);
    double loi_b = pow(e, x+1.23) + 1;
    double b = log(loi_b);
    double loi_can = 2*x*x*x + x + 1;
    double tu_so = cos(3*a) + pow(loi_can, 1/5.0);
    double loi_loga_7 = pow(3, x*x) + 2.14*b;
    double mau_so = log(loi_loga_7)/log(7);
    printf("A = %.15lf\n", tu_so/mau_so);
    return 0;
}