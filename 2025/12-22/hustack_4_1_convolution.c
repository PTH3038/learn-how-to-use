#include <stdio.h>
#include <stdlib.h>
int tongchap(int a, int b, int M, int N, int I[M][N], int K[3][3]) {
    int ans = 0;
    for (int i = 0; i < 3; i ++) {
        for (int j = 0; j < 3; j ++) {
            ans += I[a+i][b+j]*K[i][j];
        }
    }
    return ans;
}
int **convolution(int M, int N, int I[M][N], int K[3][3]) {
    int **ans = (int **)malloc((M-2)*sizeof(int *));
    for (int i = 0; i < M-2; i ++) {
        *(ans + i) = (int *)malloc((N-2)*sizeof(int));
    }
    for(int i = 0; i < M-2; i ++) {
        for (int j = 0; j < N-2; j ++) {
            ans[i][j] = tongchap(i, j, M, N, I, K);
        }
    }
    return ans;
}
int main() {
    int M, N; scanf("%d %d", &M, &N);
    int I[M][N];
    for (int i = 0; i < M; i ++) {
        for (int j = 0; j < N; j ++) {
            scanf("%d", &I[i][j]);
        }
    }
    int K[3][3];
    for (int i = 0; i < 3; i ++) {
        for (int j = 0; j < 3; j ++) {
            scanf("%d", &K[i][j]);
        }
    }
    int **ans = convolution(M, N, I, K);
    for (int i = 0; i < M-2; i ++) {
        for (int j = 0; j < N-2; j ++) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}