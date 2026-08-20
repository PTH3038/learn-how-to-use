#include <stdio.h>
#include <string.h>
int max(int a, int b) {
    return (a > b) ? a : b;
}
int func(char *s) {
    int N = strlen(s);
    int dp[N];
    for (int i = 0; i < N; i ++) dp[i] = 1;
    for (int i = 1; s[i] != '\0'; i ++) {
        for (int j = 0; j < i; j ++) {
            if (s[j] < s[i]) {
                dp[i] = max(dp[j]+1, dp[i]);
            }
        }
    }
    int max = dp[0];
    for (int i = 0; i < N; i ++) {
        if (dp[i] > max) max = dp[i];
    }
    return max;
}

int main() {
    char s[20001]; scanf("%s", s);
    int ans = func(s);
    printf("%d\n", ans);
    return 0;
}