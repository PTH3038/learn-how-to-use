#include <stdio.h>
#define INF 2147483646
int min(int a, int b) {
    return (a < b) ? a : b;
}

int func(int N, int M, int* coe) {
    int dp[N+1][M+1];
    for (int i = 0; i <= N; i ++) {
        for (int j = 0; j <= M; j ++) {
            if (j == 0) dp[i][j] = 0;
            else dp[i][j] = INF;
        }
    }

    for (int i = 1; i <= N; i ++) {
        int he_so = coe[i-1];

        for (int j = 1; j <= M; j ++) {
            dp[i][j] = dp[i-1][j];
            if (j >= he_so) dp[i][j] = min(dp[i][j], dp[i][j - he_so] + 1);
        }
    }

    return dp[N][M];
}

int main() {
    int N, M; scanf("%d %d", &N, &M);

    int coe[N];
    for (int i = 0; i < N; i ++) scanf("%d", &coe[i]);

    printf("%d", func(N, M, coe));
    return 0;
}