#include <stdio.h>
#include <stdlib.h>
#define INF 2147483647
int comparator(const void* a , const void* b) {
    int* A = *(int**)a;
    int* B = *(int**)b;

    if (A[1] < B[1]) return -1;
    else if (A[1] > B[1]) return 1;
    else return 0;
}

int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize) {
    int counter = 0;
    
    int previous_end = -INF;

    qsort(intervals, intervalsSize, sizeof(int*), comparator);

    for (int i = 0; i < intervalsSize; i ++) {
        if (intervals[i][0] >= previous_end) {
            counter ++;
            previous_end = intervals[i][1];
        }
    }
    return counter;
}