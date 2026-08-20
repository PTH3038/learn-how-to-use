#include <stdio.h>
int func(int N, int M, int* coe) {
    int dp[M+1];
    for (int i = 0; i <= M; i ++) dp[i] = 0;
    dp[0] = 1;

    for (int i = 0; i < N; i ++) {
        int he_so = coe[i];
        for (int j = 1; j <= M; j ++) {
            if (j >= he_so) dp[j] = dp[j] + dp[j - he_so];
        }
    }

    return dp[M];
}

int main() {
    int N, M; scanf("%d %d", &N, &M);

    int coe[N];
    for (int i = 0; i < N; i ++) scanf("%d", &coe[i]);

    printf("%d", func(N, M, coe));

    return 0;
}