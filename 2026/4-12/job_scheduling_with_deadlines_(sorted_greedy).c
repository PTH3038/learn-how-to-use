#include <stdio.h>
#include <stdlib.h>
int comparator(const void* a, const void* b) {
    int* A = *(int**)a;
    int* B = *(int**)b;

    if (A[1] > B[1]) return -1;
    else if (A[1] < B[1]) return 1;
    else return 0;
}

int greedy(int N, int** dp) {
    int current_profit = 0;

    int frequency = 0;

    int max_deadline = 0;
    for (int i = 0; i < N; i ++) {
        max_deadline = (dp[i][0] > max_deadline) ? dp[i][0] : max_deadline;
    }

    qsort(dp, N, sizeof(int*), comparator);

    for (int i = 0; i < N; i ++) {
        for (int j = dp[i][0]; j >= 1; j --) {
            if ( !(frequency & (1<<j)) ) {
                current_profit += dp[i][1];
                frequency |= (1<<j);
                break;
            }
        }
    }
    return current_profit;
}

int main() {
    int N; scanf("%d", &N);

    int** dp = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i ++) {
        dp[i] = (int*)malloc(2 * sizeof(int));
        scanf("%d %d", &dp[i][0], &dp[i][1]);
    }

    int ANS = greedy(N, dp);
    printf("%d", ANS);
    return 0;
}