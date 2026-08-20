#include <stdio.h>
#include <string.h>
int match_checker(char a, char b) {
    if ((a == '{' && b == '}') || (a == '[' && b == ']') || (a == '(' && b == ')')) {
        return 1;
    }
    return 0;
}
bool isValid(char* s) {
    if (s[0] == ')' || s[0] == ']' || s[0] == '}') {
        return false;
    }
    int N = strlen(s);
    if (N%2 != 0) {
        return false;
    }
    //
    //
    //
    char stack[N+1];
    for (int i = 0; i <= N; i ++) {
        stack[i] = '\0';
    }
    char *ptr = &stack[1];
    *ptr = s[0];
    for (int i = 1; i < N; i ++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            ptr ++;
            *ptr = s[i];
        }
        else {
            if (match_checker(*ptr, s[i]) == 1) {
                *ptr = '\0';
                ptr --;
            }
            else {
                return false;
            }
        }
    }
    if (*ptr) {
        return false;
    }
    else {
        return true;
    }
}
int main() {
    char s[100]; scanf("%s", s);
    int ans = isValid(s);
    if (ans) {
        printf("true\n");
        return 0;
    }
    else {
        printf("false\n");
        return 0;
    }
}