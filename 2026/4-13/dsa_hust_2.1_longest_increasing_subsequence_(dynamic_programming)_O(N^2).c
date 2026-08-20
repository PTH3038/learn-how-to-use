#include <stdio.h>
int func(int N, int a[N]) {
    int max = 0;

    int dp[N];
    for (int i = 0; i < N; i ++) dp[i] = 1;

    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < i; j ++) {
            if (a[j] < a[i]) dp[i] = (dp[j]+1 > dp[i]) ? dp[j]+1 : dp[i];
            max = (dp[i] > max) ? dp[i] : max;
        }
    }
    
    return max;
}

int main() {
    int N; scanf("%d", &N);

    int a[N];
    for (int i = 0; i < N; i ++) scanf("%d", &a[i]);

    int ans = func(N, a);
    printf("%d\n", ans);
    return 0;
}