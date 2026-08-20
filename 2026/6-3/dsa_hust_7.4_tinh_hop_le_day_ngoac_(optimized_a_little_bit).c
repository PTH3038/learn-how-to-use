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
    // Nếu gặp ngoặc đóng mà Stack rỗng hoặc không khớp -> Sai luôn, dừng sớm
    if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
        if (top == -1 || !isMatch(stack[top], s[i])) return 0;
        top--; // Khớp thì pop
    } 
    // Nếu là ngoặc mở -> Push vào
    else {
        stack[++top] = s[i];
    }
    i++;
}

    if (top == -1 && 1) return 1;
    else return 0;
}

int main() {
    char s[100000];
    scanf("%s", s);
    printf("%d", isValid(s));
    return 0;
}
