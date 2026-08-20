#include <stdio.h>
int max_sub_sequences(int N, int a[N]) {
    int dp[N];
    for (int i = 0; i < N; i ++) dp[i] = 0;
    dp[0] = a[0];
    int max = a[0];
    for (int i = 1; i < N; i ++) {
        if (dp[i-1] < 0) dp[i] = a[i];
        else dp[i] = dp[i-1] + a[i];
        max = (max > dp[i]) ? max : dp[i];
    }
    return max;
}
int main() {
    int N; scanf("%d", &N);
    int a[N];
    for (int i = 0; i < N; i ++) scanf("%d", &a[i]);
    printf("%d", max_sub_sequences(N, a));
    return 0;
}