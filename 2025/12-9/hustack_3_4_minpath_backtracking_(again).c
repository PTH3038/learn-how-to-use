#include <stdio.h>
int min_path = 1000000000;
int current_path = 0;
void backtracking(int M, int N, int a[M][N], int current_row, int current_col) {
    current_path += a[current_row][current_col];
    if (current_col == N-1) {
        if (current_path < min_path) {
            min_path = current_path;
        }
        current_path -= a[current_row][current_col];
        return;
    }
    //
    //
    //
    backtracking(M, N, a, current_row, current_col+1);
    if (current_row > 0) {
        backtracking(M, N, a, current_row-1, current_col+1);
    }
    if (current_row < M-1) {
        backtracking(M, N, a, current_row+1, current_col+1);
    }
    current_path -= a[current_row][current_col];
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
    printf("%d", min_path);
    return 0;
}