#include <stdio.h>
#include <math.h>
double f(double x) {
    double loi_can = pow(x, 5) + 3*pow(x, 3) + 2;
    double f = pow(x, 7) + 5*pow(loi_can, 1/3.0) + 12;
    return f;
}
int main() {
    double a, b, c; printf("Nhap a, b, c: "); scanf("%lf %lf %lf", &a, &b, &c);
    printf("Gia tri trung binh f(a), f(b), f(c) la: %lf\n", (f(a) + f(b) + f(c))/3);
    return 0;
}