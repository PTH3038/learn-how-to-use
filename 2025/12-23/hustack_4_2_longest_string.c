#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int max(int a, int b) {
    return (a > b) ? a : b;
}
char *func(char *s1, char *s2, /*int *returnRow, int *returnCol,*/ int *returnSize) {
    int M = strlen(s1);
    int N = strlen(s2);
    int **dp = (int **)malloc((M+1) * sizeof(int *));
    for (int i = 0; i < M+1; i ++) {
        dp[i] = (int *)malloc((N+1) * sizeof(int));
    }
    for (int i = 0; i < M+1; i ++) {
        for (int j = 0; j < N+1; j ++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
            }
        }
    }
    /**returnRow = M+1;
    *returnCol = N+1;*/
   *returnSize = dp[M][N];
    char *similarity = (char *)malloc((*returnSize + 1)* sizeof(char));
    
    int i = M;
    int j = N;
    int count = *returnSize; 
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            similarity[count - 1] = s1[i - 1];
            i--;
            j--;
            count--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    return similarity;
}
int main() {
    char s1[100]; char s2[100];
    scanf("%s %s", s1, s2);
    /*int rtnc = 0, rtnr = 0;
    *int *returnRow = &rtnr;
    int *returnCol = &rtnc;*/
    int rts = 0;
    int *returnSize = &rts;
    char *ans = func(s1, s2, /*returnRow, returnCol,*/ returnSize);
    /*for (int i = 0; i < *returnRow; i ++) {
        for (int j = 0; j < *returnCol; j ++) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }*/
    printf("%s\n%d", ans, *returnSize);
    return 0;
}