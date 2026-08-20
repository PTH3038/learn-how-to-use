#include <stdio.h>
int select(int current_time_slot, int N, int dp[N][2], int frequency) {
    int max = -1;
    for (int i = 0; i < N; i ++) {
        int index_profit = dp[i][1];
        int index_deadline = dp[i][0];

        if ( frequency & (1<<i)  ||  index_deadline < current_time_slot ) continue;
        if (max == -1 || index_profit > dp[max][1]) max = i;
    }
    return max;
}

int feasible( ) {
    return 1;
}

int greedy(int N, int dp[N][2]) {
    int current_profit = 0;

    int frequency = 0;

    int current_time_slot = 0;
    for (int i = 0; i < N; i ++) {
        current_time_slot = (dp[i][0] > current_time_slot) ? dp[i][0] : current_time_slot;
    }

    while (current_time_slot) {
        int current_job = select(current_time_slot, N, dp, frequency);
        if (current_job == -1) {
            current_time_slot --;
            continue;
        }

        frequency |= (1<<current_job);

        if (feasible( )) {
            current_profit += dp[current_job][1];
            current_time_slot --;
        }
    }
    return current_profit;
}



int main( ) {
    int N; scanf("%d", &N);
    int dp[N][2];
    for (int i = 0; i < N; i ++) {
        scanf("%d %d", &dp[i][0], &dp[i][1]);
    }
    int ANS = greedy(N, dp);
    printf("%d\n", ANS);
}