#include <stdio.h>
int main() {
    double a, b,c; scanf("%lf %lf %lf", &a, &b, &c);
    if (a+b > c && a+c > b && b+c > a) {
        if (a==b || b==c || c==a) {
            if (a!=b || b!=c || c!=a) {printf("Đây là tam giác cân.");}
            else {printf("Đây là tam giác đều.");}
        }
        else if (a*a+b*b == c*c || a*a+c*c == b*b || b*b+c*c == a*a) {printf( "Đây là tam giác vuông.");}
        else {printf("Đây là tam giác thường.");}
    }
    else {printf("Ba cạnh không tạo thành tam giác.");}
    return 0;
}