#include <stdio.h>
void backtracking(int k, int N, char *a) {
    a[k] = '0';
    if (k + 1 == N) {
        a[k + 1] = '\0';
        printf("%s\n", a);
    }
    else backtracking(k + 1, N, a);

    a[k] = '1';
    if (k + 1 == N) {
        a[k + 1] = '\0';
        printf("%s\n", a);
    }
    else backtracking(k + 1, N, a);
}

int main() {
    int N; scanf("%d", &N);
    char a[N+1];
    backtracking(0, N, a);
    return 0;
}