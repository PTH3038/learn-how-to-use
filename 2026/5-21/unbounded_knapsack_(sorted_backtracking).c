#include <stdio.h>
#include <stdlib.h>
int ANS = 0;

int comparator(const void* a, const void* b) {
    int* A = *(int**)a;
    int* B = *(int**)b;

    if ((double)A[0]/A[1] > (double)B[0]/B[1]) return -1;
    if ((double)A[0]/A[1] < (double)B[0]/B[1]) return 1;
    return 0;
}

void backtracking(int k, int N, int** items, int bag_capacity, int current_value, int current_weight) {
    if (k == N) {
        ANS = (ANS > current_value) ? ANS : current_value;
        return;
    }

    int remain_capacity = bag_capacity - current_weight;
    double bound = current_value + remain_capacity * ((double)items[0][0]/items[0][1]);
    if (bound <= ANS) return;

    if (current_weight + items[k][1] <= bag_capacity) {
        current_value += items[k][0];
        current_weight += items[k][1];

        backtracking(k, N, items, bag_capacity, current_value, current_weight);

        current_value -= items[k][0];
        current_weight -= items[k][1];
    }
    backtracking(k+1, N, items, bag_capacity, current_value, current_weight);
}

int main() {
    int N; scanf("%d", &N);

    int** items = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i ++) {
        items[i] = (int*)malloc(2 * sizeof(int));
        scanf("%d %d", &items[i][0], &items[i][1]);
    }

    int bag_capacity; scanf("%d", &bag_capacity);

    backtracking(0, N, items, bag_capacity, 0, 0);

    printf("ANS: %d\n", ANS);
    return 0;
}