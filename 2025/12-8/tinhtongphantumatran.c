#include <stdio.h>
int main() {
    int M, N; scanf("%d %d", &M, &N);
    int a[M][N];
    if (M <= 0 || N <= 0) {
        printf("Error");
        return 0;
    }
    for (int i = 0; i < M; i ++) {
        for (int j = 0; j < N; j ++) {
            scanf("%d", &a[i][j]);
        }
    }
    int row, col; scanf("%d %d", &row, &col);
    int sum_row = 0; int sum_col = 0;
    for (int i = 0; i < N; i ++) {
        sum_row += a[row][i];  
    }
    for (int i = 0; i < M; i ++) {
        sum_col += a[i][col];
    }
    printf("%d %d", sum_row, sum_col);
    return 0;
}