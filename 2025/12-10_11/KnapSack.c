#include <stdio.h>
int max(int a, int b) {
    return (a > b) ? a : b;
}
int main() {
    int N; scanf("%d", &N);
    int w[N+1], v[N+1];
    w[0] = v[0] = 0;
    for (int i = 1; i <= N; i ++) {
        scanf("%d %d", &w[i], &v[i]);
    }
    int S; scanf("%d", &S);
    //
    //
    //
    int s[N+1][S+1];
    for (int i = 0; i < N+1; i ++) {
        for (int weight = 0; weight < S+1; weight ++) {
            if (i == 0 || weight == 0) {
                s[i][weight] = 0;
                continue;
            }
            s[i][weight] = s[i-1][weight];
            if (w[i] <= weight) {
                s[i][weight] = max(s[i-1][weight - w[i]] + v[i], s[i][weight]);
            }
        }
    }
    //
    //
    //
    for (int i = 0; i <= N; i ++) {
        for (int j = 0; j < S+1; j ++) {
            printf("%d ", s[i][j]);
        }
        printf("\n");
    }
    return 0;
}