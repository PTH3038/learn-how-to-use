#include <stdio.h>
#include <string.h>
int main() {
    char s[101], t[101]; scanf("%s %s", s, t);
    if (strlen(s) != strlen(t)) {
        printf("No");
        return 0;
    }
    int counter[256] = {0};
    for (int i = 0; s[i] != '\0'; i ++) {
        counter[(unsigned char)s[i]]++;
        counter[(unsigned char)t[i]]--;
    }
    for (int i = 0; s[i] != '\0'; i ++) {
        if (counter[i] != 0) {
            printf("No");
            return 0;
        }
    }
    printf("Yes");
    return 0;
}