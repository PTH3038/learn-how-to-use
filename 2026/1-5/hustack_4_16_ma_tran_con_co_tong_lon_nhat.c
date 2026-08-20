#include <stdio.h>
int main() {
    int M, N, K; scanf("%d %d %d", &M, &N, &K);
    int a[M][N];
    for (int i = 0; i < M; i ++) {
        for (int j = 0; j < N; j ++) {
            scanf("%d", &a[i][j]);
        }
    }
    int ans[M-K+1][N-K+1];
    for (int i = 0; i < M-K+1; i ++) {
        for (int j = 0; j < N-K+1; j ++) {
            ans[i][j] = 0;
            for (int index = i; index < i+K; index ++) {
                for (int jndex = j; jndex < j+K; jndex ++) {
                    ans[i][j] += a[index][jndex];
                }
            }
        }
    }

    int row = 0, col = 0;
    int max = ans[0][0];
    for (int i = 0; i < M-K+1; i ++) {
        for (int j = 0; j < N-K+1; j ++) {
            if (ans[i][j] > max ||
                ans[i][j] == max && i < row ||
                ans[i][j] == max && i == row && j < col) {
                    max = ans[i][j];
                    row = i;
                    col = j;
            }
        }
    }
    printf("%d %d %d", max, row+1, col+1);
    return 0;
}