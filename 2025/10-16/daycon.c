#include <stdio.h>
int main () {
    int N; printf("Nhap so luong phan tu: "); scanf("%d", &N);
    int a[N];
    for (int i = 0; i < N; i ++) {
        printf("Nhap phan tu a[%d]: ", i);
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < N; i ++) {printf("Phan tu a[%d] la: %d\n", i, a[i]);}
    printf(" +) STT:        ");
    for (int i = 0; i < N; i ++) {printf("a[%d]  ", i);}
    printf("\n");
    printf(" +) Day da nhap: ");
    for (int i = 0; i < N; i ++) {printf("%d     ", a[i]);}
    printf("\n");
    
    int L = 1, max = 1;
    for (int i = 0; i < N-1; i ++) {
        if (a[i] <= a[i+1]) {
            L = L + 1; if (L > max) {max = L;}
        }
        else {L = 1;}
    }
    printf(" +) Do dai day con khong giam dai nhat la: %d\n", max);
    return 0;
}