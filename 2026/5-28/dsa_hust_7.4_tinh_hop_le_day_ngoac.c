#include <stdio.h>
#include <stdbool.h>
#include <string.h>
bool isMatch(char a, char b) {
    if (a == '(' && b == ')' ||
        a == '[' && b == ']' ||
        a == '{' && b == '}') return true;
    return false;
}

int isValid(char* s) {
    int N = strlen(s);
    if (N%2 != 0) return 0;

    char stack[N+1];
    int top = -1;

    int i = 0;
    while (s[i] != '\0') {
        if (top >= 0 && isMatch(stack[top], s[i]) == true) top --;
        else stack[++ top] = s[i];
        i ++;
    }

    if (top == -1) return 1;
    else return 0;
}

int main() {
    char s[100000];
    scanf("%s", s);
    printf("%d", isValid(s));
    return 0;
}