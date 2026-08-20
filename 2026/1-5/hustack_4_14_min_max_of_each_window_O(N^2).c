#include <stdio.h>
#include <stdlib.h>
int max(int a, int b) {
    return (a > b) ? a : b;
}
int min(int a, int b) {
    return (a < b) ? a : b;
}
int *maxWindow(int *A, int N, int K) {
    int *mx = (int *)malloc((N-K+1)*sizeof(int));
    mx[0] = A[0]; 
    for (int i = 0; i < K; i ++) {
        if (A[i] > mx[0]) mx[0] = A[i];
    }
    for (int i = 1; i < N-K+1; i ++) {
        mx[i] = max(mx[i-1], A[i+K]);
    }
    return mx;
}
int *minWindow(int *A, int N, int K) {
    int *mn = (int *)malloc((N-K+1)*sizeof(int));
    mn[0] = A[0]; 
    for (int i = 0; i < K; i ++) {
        if (A[i] < mn[0]) mn[0] = A[i];
    }
    for (int i = 1; i < N-K+1; i ++) {
        mn[i] = min(mn[i-1], A[i+K]);
    }
    return mn;
}


int main() {
    int N, K; scanf("%d %d", &N, &K);
    int A[N];
    for (int i = 0; i < N; i ++) scanf("%d", &A[i]);
    int *mx = maxWindow(A, N, K);
    int *mn = minWindow(A, N, K);
    for (int i = 0; i < N-K+1; i ++) {
        printf("%d ", mn[i]);
    }
    printf("\n");
    for (int i = 0; i < N-K+1; i ++) {
        printf("%d ", mx[i]);
    }
    return 0;
}