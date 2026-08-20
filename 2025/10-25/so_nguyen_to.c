#include <stdio.h>
#include <math.h>
int main() {
    int N; printf("Nhap N: "); scanf("%d", &N);
    if ((N%2 == 0 && N != 2) || N <= 1) {printf("Khong phai so nguyen to"); return 0;}
    if (N == 2) {printf("La so nguyen to"); return 0;}
    for (int i = 3; i <= sqrt(N); i += 2) {
        if (N%i == 0) {printf("Khong phai so nguyen to"); return 0;}
    }
    printf("La so nguyen to");
    return 0;
}