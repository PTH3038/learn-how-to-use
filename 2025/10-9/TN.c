#include <stdio.h>
int main () {
    double N; printf("Nhap N: ");
    int scan_result = scanf("%lf", &N);
    int c;
    while ( scan_result!=1 || (N!=(unsigned int)N) && (N=!0) || (N==0) ) {
        printf("N phai la so tu nhien lon hon 0\nNhap lai N: ");
        do {c=getchar();} while (c!='\n' && c!=EOF);
        scan_result = scanf("%lf", &N);
    }
    printf("N= %lf\n", N);
    return 0;
}