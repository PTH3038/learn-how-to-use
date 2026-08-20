#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void reverse(char *sub_s) {
    int N = strlen(sub_s);
    for (int i = 0; i < N/2; i ++) {
        char temp = sub_s[N-i-1];
        sub_s[N-i-1] = sub_s[i];
        sub_s[i] = temp;
    }
}
char* reverseParentheses(char* s) {
    int N = strlen(s);

    int write_index = -1;
    char *ans = (char *)malloc((N+1) * sizeof(char));

    int top = -1;
    int brackets[2000];

    for (int i = 0; s[i] != '\0'; i ++) {
        if (s[i] == '(') {
            brackets[++ top] = write_index + 1;
        }
        else if (s[i] == ')') {
            ans[write_index+1] = '\0';
            reverse(ans + brackets[top --]);
        }
        else {
            ans[++ write_index] = s[i];
        }
    }
    ans[++ write_index] = '\0';
    return ans;
}
int main() {
    char s[2001]; scanf("%s", s);
    char *ans = reverseParentheses(s);
    printf("%s", ans);
    return 0;
}