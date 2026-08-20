#include <stdio.h>
int max(int a, int b) {
    return (a > b) ? a : b;
}
int main() {
    int N; scanf("%d", &N);
    int a[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
    int L[N];
    for (int i = 0; i < N; i ++) L[i] = 1;
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < i; j ++) {
            if (a[j] < a[i]) {
                L[i] = max(L[i], L[j]+1);
            }
        }
    }
    for (int i = 0; i < N; i++) {
        printf("%d ", L[i]);
    }
    return 0;
}