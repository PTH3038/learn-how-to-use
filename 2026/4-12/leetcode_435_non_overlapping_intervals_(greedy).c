#include <stdio.h>
#define INF 2147483648
int SELECT(int previous_end, int** intervals, int intervalsSize, int frequency[intervalsSize]) {
    int current_best = INF;
    for (int i = 0; i < intervalsSize; i ++) {
        int index_left = intervals[i][0];
        int index_right = intervals[i][1];

        if (frequency[i] != 0 || index_left < previous_end) continue;
        if (current_best == INF || index_right < intervals[current_best][1]) current_best = i;

    }
    return current_best;
}

int feasible () {
    return 1;
}

int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize) {
    int counter = 0;

    int previous_end = -INF;

    int frequency[intervalsSize];
    
    for (int i = 0; i < intervalsSize; i ++) frequency[i] = 0;

    while (1) {
        int current_interval = SELECT(previous_end, intervals, intervalsSize, frequency);
        if (current_interval == INF) break;

        frequency[current_interval] ++;

        if (feasible( )) {
            counter ++;
            previous_end = intervals[current_interval][1];
        }
    }

    return intervalsSize - counter;
}