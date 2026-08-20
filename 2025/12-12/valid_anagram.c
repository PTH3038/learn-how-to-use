#include <stdio.h>
#include <string.h>
int main() {
    char s[100], t[100];
    scanf("%s %s", s, t);
    if (strlen(s) != strlen(t)) {
        printf("No");
        return 0;
    }
    for (int i = 0; s[i] != '\0'; i ++) {
        for (int j = 0; t[j] != '\0'; j ++) {
            if (s[i] == t[j]) {
                t[j] = '#';
                break;
            }
        }
    }
    for (int i = 0; t[i] != '\0'; i ++) {
        if (t[i] != '#') {
            printf("No");
            return 0;
        }
    }
    printf("Yes");
    return 0;
}