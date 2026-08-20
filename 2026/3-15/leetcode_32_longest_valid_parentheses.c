#include <stdio.h>
#include <string.h>
#include <stdbool.h>
bool isMatch(char a, char b) {
    return (a == '(' && b == ')');
}
int longestValidParentheses(char* s) {
    int N = strlen(s);
    int stack[N+1];
    int top = -1;
    int MAX_ANS = 0;
    for (int i = 0; i <= N; i ++) {
        if (top >= 0 && isMatch(s[stack[top]], s[i]) == true) {
            top --;
            continue;
        }
        int length = (top == -1) ? i : (i - stack[top] - 1);
        MAX_ANS = (MAX_ANS > length) ? MAX_ANS : length;
        stack[++ top] = i;
    }
    return MAX_ANS;
}