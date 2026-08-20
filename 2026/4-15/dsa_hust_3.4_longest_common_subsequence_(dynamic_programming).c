#include <stdio.h>
#include <stdlib.h>
int max(int a, int b) {
    return (a > b) ? a : b;
}

int func(int N, int M, int a[N], int b[M]) {
    int ANS = 0;

    int** dp = (int**)malloc((N+1) * sizeof(int*));
    for (int i = 0; i <= N; i ++) {
        dp[i] = (int*)malloc((M+1) *  sizeof(int));
    }


    for (int i = 0; i <= N; i ++) {
        for (int j = 0; j <= M; j ++) {
            if (i == 0 || j == 0) dp[i][j] = 0;

            else if (b[j-1] != a[i-1]) dp[i][j] = max(dp[i][j-1], dp[i-1][j]);

            else dp[i][j] = dp[i-1][j-1] + 1;

            ANS = max(ANS, dp[i][j]);
        }
    }

    return ANS;
}

int main() {
    int N, M; scanf("%d %d", &N, &M);

    int* a = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i ++) scanf("%d", &a[i]);

    int* b = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < M; i ++) scanf("%d", &b[i]);

    int ANS = func(N, M, a, b);
    printf("%d", ANS);

    return 0;
}