#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* reverseParentheses(char* s) {
    int top = -1;
    int stack[2000] = {0};
    int pair[2000] = {0};
    for (int i = 0; s[i] != '\0'; i ++) {
        if (s[i] == '(') {
            stack[++ top] = i;
        }
        else if (s[i] == ')') {
            int temp = stack[top --];
            pair[temp] = i;
            pair[i] = temp;
        }
    }

    int direct = 1;
    int write_index = -1;
    int N = strlen(s);
    char *ans = (char *)malloc((N+1) * sizeof(char));
    for (int i = 0; s[i] != '\0'; i += direct) {
        if (s[i] == '(' || s[i] == ')') {
            i = pair[i];
            direct = -direct;
        }
        else {
            ans[++ write_index] = s[i];
        }
    }
    ans[++ write_index] = '\0';
    return ans;
}
int main() {
    char s[2000]; scanf("%s", s);
    char *ans = reverseParentheses(s);
    printf("%s", ans);
    return 0;
}