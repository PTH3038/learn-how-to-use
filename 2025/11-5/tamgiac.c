#include <stdio.h>
#include <math.h>
int main() {
    double x1, y1; printf("Nhap toa do diem A: "); scanf("%lf %lf", &x1, &y1);
    double x2, y2; printf("Nhap toa do diem B: "); scanf("%lf %lf", &x2, &y2);
    double x3, y3; printf("Nhap toa do diem C: "); scanf("%lf %lf", &x3, &y3);
    if ( (x1-x3)*(y1-y2) == (x1-x2)*(y1-y3) ) {printf("Khong phai tam giac"); return 0;}
    double c = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
    double a = sqrt((x3-x2)*(x3-x2) + (y3-y2)*(y3-y2));
    double b = sqrt((x1-x3)*(x1-x3) + (y1-y3)*(y1-y3));
    double AM = sqrt(b*b/2 + c*c/2 - a*a/4);
    printf("Do dai AB, BC, CA, AM lan luot la: %lf %lf %lf %lf", c, a, b, AM);
    return 0;
}