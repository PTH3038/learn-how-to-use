#include <stdio.h>
int main() {
    int N; scanf("%d", &N);
    int a[N][3];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 10; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}