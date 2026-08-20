#include <stdio.h>
int fibonaci(int N) {
    int FIBO = 0;
    if (N < 1) {printf("ERROR"); return 0;}
    else if (N == 1) {FIBO = 1;}
    else if (N == 2) {FIBO = 2;}
    else {FIBO = fibonaci(N-1) + fibonaci(N-2);}
    return FIBO;
}
int main() {
    int N; printf("Nhap N: "); scanf("%d", &N);
    int sum = 0;
    for (int i = 1; i <= N; i ++) {
        sum += fibonaci(i);
    }
    printf("Tong la: %d\n", sum);
    return 0;
}
