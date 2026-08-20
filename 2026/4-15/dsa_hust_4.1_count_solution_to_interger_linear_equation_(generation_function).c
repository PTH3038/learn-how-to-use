#include <stdio.h>
int func(int N, int M, int *coe) {
    int ANS = 0;

    //max_power la so mu lon nhat cua ham sinh 1/M(x) (M(x) dinh nghia o ben duoi)
    int max_power = 0;
    for (int i = 0; i < N; i ++) max_power += coe[i];

    // tim he so c_i cua x^so_mu trong da thuc M(x) = (1-x^coe[1]).(1-x^coe[2])...(1-x^coe[N-1])
    int c[max_power + 1];
    for (int i = 1; i <= max_power; i ++) c[i] = 0;
    c[0] = 1;
    for (int i = 0; i < N; i ++) {
        int so_mu = coe[i];
        for (int power = max_power; power >= so_mu; power --) {
            c[power] = c[power] - c[power - so_mu];
        }
    }

    // dp[n] = -c[1]*dp[n-1] -c[2]*dp[n-2] ...
    int dp[M+1];
    for (int i = 0; i <= M; i ++) dp[i] = 0;
    dp[0] = 1;
    for (int i = 1; i <= M; i ++) {
        for (int j = 1; j <= max_power; j ++) {
            if (i-j >= 0) dp[i] -= c[j] * dp[i-j];
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