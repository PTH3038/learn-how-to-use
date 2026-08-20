#include <stdio.h>
int main () {
    int N; printf("Nhap N: "); scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= (N-i); j++) {
            printf("  ");
        }
        for (int k = 0; k <= (i-1); k++) {
            printf("%d ", (k+N-i+1));
        }
        printf("\n");
    }
}