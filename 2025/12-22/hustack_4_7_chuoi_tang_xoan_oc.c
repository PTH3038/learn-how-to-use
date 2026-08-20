#include <stdio.h>
#include <string.h>
#include <stdbool.h>
bool func(char *str) {
    int N = strlen(str);
    char *ptr = &str[0];
    int i = 1;
    while (i <= N/2) {
        if (*(ptr + i - 1) > *(ptr + N - i)) {
            return false;
        }
        if (*(ptr + N - i) > *(ptr + i)) {
            return false;
        }
        i ++;
    }
    return true;
}
int main() {
    char s[257]; scanf("%s", s);
    int ans = func(s);
    if (ans) {
        printf("true");
    }
    else {
        printf("fasle");
    }
    return 0;
}