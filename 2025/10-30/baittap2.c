#include <stdio.h>
#include <math.h>
int main() {
    double a, b, c; printf("Nhap a b c: "); scanf("%lf %lf %lf", &a, &b, &c);
    if (a+b > c && a+c > b && b+c > a) {
    double p = (a + b + c)/2;
    double S = sqrt(p*(p-a)*(p-b)*(p-c));
    double ha = S*2/a;
    double hb = S*2/b;
    double hc = S*2/c;
    printf("Dien tich: %lf, cac chieu cao: %lf %lf %lf", S, ha, hb, hc);
    }
    else {printf("Khong phai tam giac");}
    return 0;
//ngoai ra con co kiem tra xem ki tu nhap vao co dung la so nguyen khong, co dung la ki tu so khong nhung bai nay em xin phep bo qua a!
}