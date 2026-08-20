#include <stdio.h>
#include <stdlib.h>
long long int max(long long int a, long long int b) { return (a > b) ? a : b; }
long long int min(long long int a, long long int b) { return (a < b) ? a : b; }

long long int *maxWindow(long long int *A, int N, int K) {
    long long int *mx = (long long int *)malloc((N-K+1)*sizeof(long long int));
    for (long long int i = 0; i < N-K+1; i++) {
        long long int currentMax = A[i];
        for (long long int j = 1; j < K; j++) {
            currentMax = max(currentMax, A[i + j]);
        }
        mx[i] = currentMax;
    }
    return mx;
}
long long int *minWindow(long long int *A, int N, int K) {
    long long int *mn = (long long int *)malloc((N-K+1)*sizeof(long long int));
    for (long long int i = 0; i < N-K+1; i++) {
        long long int currentMin = A[i];
        for (long long int j = 1; j < K; j++) {
            currentMin = min(currentMin, A[i + j]);
        }
        mn[i] = currentMin;
    }
    return mn;
}

int main() {
    int N, K; scanf("%d %d", &N, &K);
    
    long long int A[N];
    for (int i = 0; i < N; i++) scanf("%lld", &A[i]);

    long long int *mx = maxWindow(A, N, K);
    long long int *mn = minWindow(A, N, K);

    for (int i = 0; i < N-K+1; i++) printf("%lld ", mn[i]);
    printf("\n");
    for (int i = 0; i < N-K+1; i++) printf("%lld ", mx[i]);

    return 0;
}