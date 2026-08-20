#include <stdio.h>
int sum(int n) {
    int s = 0;
    if (n == 0) {s = 0;}
    else if (n < 0) {return -1;}
    else {s = sum(n-1) + n;}
    return s;
}
int main () {
    int N; printf("Nhap N: "); scanf("%d", &N);
    int kq = sum(N);
    if (kq != -1) {printf("Tong la: %d", kq); return 0;}
    else {printf("ERROR"); return 0;}
}