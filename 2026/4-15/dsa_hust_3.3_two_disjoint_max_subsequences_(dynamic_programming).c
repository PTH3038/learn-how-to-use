#include <stdio.h>
#include <stdlib.h>
int max(int a, int b) {
    return (a > b) ? a : b;
}

int func(int N, int* a) {
    int ANS = 0;

    int dp = a[0];
    int* L = (int*)malloc(N * sizeof(int));
    L[0] = a[0];
    for (int i = 1; i < N; i ++) {
        if (dp < 0) dp = a[i];
        else dp += a[i];

        L[i] = max(dp, L[i-1]);
    }

    dp = a[N-1];
    int* R = (int*)malloc((N+1) * sizeof(int));
    R[N-1] = a[N-1];
    for (int i = N-2; i >= 0; i --) {
        if (dp < 0) dp = a[i];
        else dp += a[i];

        R[i] = max(dp, R[i+1]);
    }
    R[N] = 0;

    for (int i = 0; i < N; i ++) {
        ANS = max(ANS, L[i] + R[i+1]);
    }

    return ANS;
}

int main() {
    int N; scanf("%d", &N);

    int* a = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i ++) scanf("%d", &a[i]);

    int ANS = func(N, a);
    printf("%d", ANS);
    
    return 0;
}