#include <stdio.h>
#include <math.h>
#include <stdlib.h>
double deviation(double *a, int N) {
    double S = 0;
    for (int i = 0; i < N; i ++) {
        S += *(a+i);
    }
    double M = S/N;
    double P = 0;
    for (int i = 0; i < N; i ++) {
        P += pow((a[i] - M), 2)/N;
    }
    return sqrt(P);
}
int main() {
    int N; printf("Nhap so luong phan tu: "); scanf("%d", &N);
    double* a = (double*) calloc(N, sizeof(double));
    if (a == NULL) {return 1;}
    for (int i = 0; i < N; i ++) {
        printf("Nhap phan tu: ");
        scanf("%lf", &*(a+i));
    }
    printf("%lf", deviation(a, N));
    free(a);
    a = NULL;
    return 0;
}