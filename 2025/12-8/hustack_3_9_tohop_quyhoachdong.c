#include <stdio.h>
int main() {
    int k, N; scanf("%d %d", &k, &N);
    int C[N+1][N+1];
    for (int i = 0; i <= N; i ++) {
        for (int j = 0; j <= i; j ++) {
            if (j == 0 || j == i) {
                C[i][j] = 1;
            }
            else {
                C[i][j] = C[i-1][j-1] + C[i-1][j];
            }
        }
    }
    printf("%d\n", C[N][k]);
    return 0;
}