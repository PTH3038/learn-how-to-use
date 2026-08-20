#include <stdio.h>
#include <stdlib.h>
int best = -1;
int scanned = 0;
int previous_end = 0;

int comparator(const void* a , const void* b) {
    int* A = *(int**)a;
    int* B = *(int**)b;

    if (A[1] < B[1]) return -1;
    else if (A[1] > B[1]) return 1;
    else return 0;
}

void sorted_backtracking(int k, int** intervals, int intervalsSize) {
    if (k == intervalsSize) {
        best = (scanned > best) ? scanned : best;
        return;
    }

    int remain = intervalsSize - k;
    if (scanned + remain <= best) return;

    if (intervals[k][0] >= previous_end) {
        scanned ++;
        int temp = previous_end;
        previous_end = intervals[k][1];

        sorted_backtracking(k+1, intervals, intervalsSize);

        scanned --;
        previous_end = temp;
    }
    sorted_backtracking(k+1, intervals, intervalsSize);
}

int main() {
    int intervalsSize; scanf("%d", &intervalsSize);

    int** intervals = (int**)malloc(intervalsSize * sizeof(int*));
    for (int i = 0; i < intervalsSize; i ++) {
        intervals[i] = (int*)malloc(2 * sizeof(int));
        scanf("%d %d", &intervals[i][0], &intervals[i][1]);
    }

    qsort(intervals, intervalsSize, sizeof(int*), comparator);

    sorted_backtracking(0, intervals, intervalsSize);

    printf("ANS: %d\n", best);
    return 0;
}