#include <stdio.h>
int min (int a, int b) {
    return (a > b) ? b : a;
}
int main() {
    int M, N; scanf("%d %d", &M, &N);
    int a[M][N];
    for (int i = 0; i < M; i ++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    int path[M][N];
    for (int i = 0; i < M; i ++) {
        for (int j = 0; j < N; j ++) {
            if (j == 0) {
                path[i][j] = a[i][j];
            } else {
                path[i][j] = 0;
            }
        }
    }
    //
    //
    //
    for (int col = 1; col < N; col ++) {
        for (int row = 0; row < M; row ++) {
            if (row == 0) {
                path[row][col] = a[row][col] + min(path[row][col-1], path[row+1][col-1]);
            } else if (row == M-1) {
                path[row][col] = a[row][col] + min(path[row][col-1], path[row-1][col-1]);
            } else {
                path[row][col] = a[row][col] + min(path[row][col-1], min(path[row-1][col-1], path[row+1][col-1]));
            }
        }
    }
    //
    //
    //
    int min_path = path[0][N-1];
    for (int i = 1; i < M; i ++) {
        if (path[i][N-1] < min_path) {
            min_path = path[i][N-1];
        }
    }
    printf("%d", min_path);
    return 0;
}