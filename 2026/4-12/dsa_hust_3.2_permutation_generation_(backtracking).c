#include <stdio.h>
void backtracking(int k, int N, int* a, int used) {
    if (k == N) {
        for (int i = 0; i < N; i ++) printf("%d ", a[i]);
        printf("\n");
        return;
    }

    for (int i = 1; i <= N; i ++) {
        if (!(used & (1<<i))) {
            a[k] = i;
            used |= (1<<i);

            backtracking(k+1, N, a, used);

            used &= ~(1<<i);
        }
    }
}
int main() {
    int N; scanf("%d", &N);
    int a[N];
    backtracking(0, N, a, 0);
    return 0;
}