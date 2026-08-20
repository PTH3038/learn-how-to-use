#include <stdio.h>
#include <math.h>
int main() {



    double a; printf("Nhap canh ben a: "); scanf("%lf", &a);
    while (a<=0) {
        printf("Nhap lai a: "); scanf("%lf", &a);
    }
    double b; printf("Nhap canh day b: "); scanf("%lf", &b);
    while (b<=0) {
        printf("Nhap lai b: "); scanf("%lf", &b);
    }
    double c; printf("Nhap canh ben c: "); scanf("%lf", &c);
    while (c<=0) {
        printf("Nhap lai c: "); scanf("%lf", &c);
    }
    double d; printf("Nhap canh day d: "); scanf("%lf", &d);
    while (d<=0) {
        printf("Nhap lai d: "); scanf("%lf", &d);
    }



    if (d<b) {
        double temp = b; b = d; d = temp;
    }



    if (d==b) {
        if (a==c) {
            printf("Day la hinh binh hanh, nhung thieu du kien ve goc de tinh dien tich\n");
            double alpha; printf("Nhap mot goc alpha bat ki: "); scanf("%lf", &alpha);
            while (alpha<=0 || alpha>=180) {
                printf("Alpha khong hop le, nhap lai: \n");
                scanf("%lf", &alpha);
            }
            if (alpha==90) {
                printf("Day la hinh chu nhat\n");
                double S = a*b;
                printf("Dien tich hinh chu nhat la: %lf\n", S);
                return 0;
            }
            else {
                printf("Day la hinh binh hanh\n");
                const double pi = 3.14159265358979323846;
                double S = a*b*sin(alpha*pi/180);
                printf("Dien tich hinh binh hanh la: %lf\n", S);
                return 0;
            }        
        } 
        else {
            printf("Khong ton tai hinh thang voi cap canh day bang nhau va hai canh ben khac nhau\n");
            return 1;
        }
    }



    else {
        if ((a+c)<=(d-b)|| (d-b+c<=a)|| (d-b+a<=c)) {
            printf("Khong ton tai hinh thang\n");
            return 1;
        }
        else {
            double p = (a+c+d-b)/2;
            double s1 = sqrt(p*(p-a)*(p-c)*(p-(d-b)));
            double h = (2*s1)/(d-b);
            double S = ((b+d)*h)/2;
            printf("Dien tich hinh thang la: %lf\n", S);
            return 0;
        }
    }
}