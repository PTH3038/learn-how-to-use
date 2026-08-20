#include <stdio.h>
int main() {
    int N; printf("Nhap N: "); scanf("%d", &N);
    printf("*    |    ");
    for (int i = 1; i <= N; i++) {printf("%-5d", i);}
    printf("\n");
    for (int i = 1; i <= (N + 2); i++) {printf("---  ");}
    printf("\n");
    for (int i = 1; i <= N; i++) {
        printf("%-5d|    ", i);
        for (int j = 1; j <= N; j ++) {printf("%-5d", (i*j));}
        printf("\n");
    }
    return 0;
}