#include <stdio.h>
int main() {
    int M, N; scanf("%d" "%d", &M, &N);
    if (M <= 0 || N <= 0) {
        printf("Error");
        return 0;
    }
    int a[M][N];
    for (int i = 0; i < M; i ++) {
        for (int j = 0; j < N; j ++) {
            scanf("%d", &a[i][j]);
        }
    }
    int col1, col2; scanf("%d %d", &col1, &col2);
    for (int j = 0; j < N; j ++) {
        int temp = a[j][col1];
        a[j][col1] = a[j][col2];
        a[j][col2] = temp;
    }
    for (int i = 0; i < M; i ++) {
        for (int j = 0; j < N; j ++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}