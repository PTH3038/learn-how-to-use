#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
char* decodeString(char* s) {
    char stack[10001];
    int opener_stack[11];
    int fre_stack[11];
    int write_index = 0;
    int top = 0;
    int k = 0;
    for (int i = 0; s[i] != '\0'; i ++) {
        if (isdigit(s[i])) {
            k = k*10 + s[i] - '0';
        }
        else if (s[i] == '[') {
            fre_stack[top] = k;
            opener_stack[top ++] = write_index;
            k = 0;
        }
        else if (s[i] == ']') {
            int count = fre_stack[top-1]-1;
            int gap = write_index - opener_stack[top-1];
            while (count) {
                memcpy(stack + write_index, stack + opener_stack[top-1], gap);
                write_index += gap;
                count --;
            }
            top --;
        }
        else {
            stack[write_index ++] = s[i];
        }
    }
    stack[write_index] = '\0';
    return stack;
}
int main() {
    char a[30]; scanf("%s", a);
    char *ans = decodeString(a);
    printf("%s", ans);
    return 0;
}