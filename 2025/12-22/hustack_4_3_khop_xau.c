#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int *match_string(char *s, char *t, int *returnSize) {
    int N = strlen(s);
    int *ans = (int *)malloc((N+1)*sizeof(int));
    for (int i = 0; i < N; i ++) {
        ans[i] = -1;
    }
    int level = 0;
    int index_ans = 0;
    for (int i = 0; s[i] != '\0'; i ++) {
        if (s[i] == t[level]) {
            level ++;
        }
        else {
            i -= level; 
            level = 0;
            continue;
        }
        if (level == strlen(t)) {
            ans[index_ans ++] = i - strlen(t) + 2;
            i -= level - 1;
            level = 0;
        }
    }
    *returnSize = index_ans;
    return ans;
}
int main() {
    char s[2001], t[2001];
    scanf("%s %s", s, t);
    int rts = 0;
    int *returnSize = &rts;
    int *ans = match_string(s, t, returnSize);
    if (rts == 0) {
        printf("-1");
    }
    for (int i = 0; i < *returnSize; i ++) {
        printf("%d ", ans[i]);
    }
    return 0;
}