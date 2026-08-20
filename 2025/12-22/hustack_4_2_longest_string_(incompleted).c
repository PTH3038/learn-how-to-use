#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *longest_string(char *s1, char *s2, int *returnSize) {
    char *ptr = (strlen(s1) > strlen(s2)) ? s1 : s2;
    *returnSize = (strlen(s1) > strlen(s2)) ? strlen(s1) : strlen(s2);
    int counter[256] = {0};
    for (int i = 0; s1[i] != '\0'; i++) {
        counter[(unsigned char)s1[i]] ++;
    }
    for (int i = 0; i < s2[i] != '\0'; i ++) {
        counter[(unsigned char)s2[i]]--;
    }
    char *ans = (char *)malloc(*returnSize*sizeof(char));
    int index = 0;
    for (int i = 0; *(ptr + i) != '\0'; i ++) {
        if (counter[(unsigned char)*(ptr + i)] == 0) {
            ans[index] = *(ptr + i);
            index ++;
        } 
    }
    ans[index] = '\0';
    *returnSize = strlen(ans);
    return ans;
}
int main() {
    char s1[100], s2[100];
    scanf("%s %s", s1, s2);
    int rtsize = 0;
    int *returnSize = &rtsize;
    char *ans = longest_string(s1, s2, returnSize);
    printf("%s\n%d", ans, *returnSize);
    return 0;
}