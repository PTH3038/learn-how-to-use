#include <stdio.h>
int ans = 0;
int row_mark[10] = {0};
int col_mark[10] = {0};
int box_mark[10] = {0};

int checker (int i, int row, int col) {
    if (row_mark[row] & (1<<i)) return 0;
    if (col_mark[col] & (1<<i)) return 0;
    int box = (row/3)*3 + col/3;
    if (box_mark[box] & (1<<i)) return 0;
    return 1;
}

void mark (int i, int row, int col) {
    row_mark[row] |= (1<<i);
    col_mark[col] |= (1<<i);
    int box = (row/3)*3 + col/3;
    box_mark[box] |= (1<<i);
}

void un_mark(int i, int row, int col) {
    row_mark[row] &= ~(1<<i);
    col_mark[col] &= ~(1<<i);
    int box = (row/3)*3 + col/3;
    box_mark[box] &= ~(1<<i);
}

void print_sudoku(int sudoku[9][9]) {
    printf("\n");
    for (int i = 0; i < 9; i ++) {
        for (int j = 0; j < 9; j ++) printf("%d ", sudoku[i][j]);
        printf("\n");
    }
    printf("\n");
}

void backtracking(int row, int col, int sudoku[9][9]) {
    if (row > 8) {     
        print_sudoku(sudoku);
        ans ++;
        return;
    }

    if (sudoku[row][col]) {
        if (col == 8) backtracking(row+1, 0, sudoku);
        else backtracking(row, col+1, sudoku);
        return;
    }

    for (int i = 1; i <= 9; i ++) {
        if (checker(i, row, col)) {
            sudoku[row][col] = i;
            mark(i, row, col);

            if (col == 8) backtracking(row+1, 0, sudoku);
            else backtracking(row, col+1, sudoku);

            sudoku[row][col] = 0;
            un_mark(i, row, col);
        }
    }
}

int main() {
    int sudoku[9][9];
    for (int r = 0; r < 9; r ++) {
        for (int c = 0; c < 9; c ++) {
            scanf("%d", &sudoku[r][c]);
            if (sudoku[r][c] != 0) mark(sudoku[r][c], r, c);
        }
    }

    backtracking(0, 0, sudoku);
    printf("\nSo cach giai: %d\n", ans);

    return 0;
}