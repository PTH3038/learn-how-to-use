#include <stdio.h>
int min_path = 1000000000;
int current_path = 0;
void backtracking(int M, int N, int a[M][N], int current_row, int current_col) {
    if (current_col == N) {
        if (current_path < min_path) {
            min_path = current_path;
        }
        return;
    }
    current_path += a[current_row][current_col];
    backtracking(M, N, a, current_row, current_col+1);
    current_path -= a[current_row][current_col];
    //
    //
    //
    if (current_row > 0) {
        current_path += a[current_row-1][current_col];
        backtracking(M, N, a, current_row-1, current_col+1);
        current_path -= a[current_row-1][current_col];
    }
    //
    //
    //
    if (current_row < M-1) {
        current_path += a[current_row+1][current_col];
        backtracking(M, N, a, current_row+1, current_col+1);
        current_path -= a[current_row+1][current_col];
    }
}
int main() {
    int M, N; scanf("%d %d", &M, &N);
    int a[M][N];
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    //
    //
    //
    for (int current_row = 0; current_row < M; current_row ++) {
        backtracking(M, N, a, current_row, 0);
    }
    printf("%d\n", min_path);
    return 0;
}