#include <stdio.h>
int factorial(int value) {
    int i = 1;
    for (int j = 1; j <= value; j ++) {
        i = i * j;
    }
    return i;
}
int main() {
    int k, N; scanf("%d %d", &k, &N);
    int C = factorial(N) / (factorial(k) * factorial(N - k));
    printf("%d\n", C);
    return 0;
}