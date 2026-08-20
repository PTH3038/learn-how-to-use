#include <stdio.h>
int main() {
    int N; scanf("%d %d", &N);
    if (N <= 0) {
        printf("Error");
        return 0;
    }
    int a[N][N];
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) {
            if (a[i][j] != a[j][i]) {
                printf("No");
                return 0;
            }
        }
    }
    printf("Yes");
    return 0;
}