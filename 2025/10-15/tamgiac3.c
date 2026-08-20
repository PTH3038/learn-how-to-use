#include <stdio.h>
int main () {
    int N; printf("Nhap N: "); scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < (i-1); j++) {
            printf("  ");
        }
        for (int k = 0; k <= (N-i); k++) {
            printf("# ");
        }
        printf("\n");
    }
}