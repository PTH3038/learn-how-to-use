#include <stdio.h>
#include <string.h>
void func(char *s) {
    char *temp;
    char reject[] = "`~!@#$%^&*()_+-={}[]\\|:;\"'<>,./? ";
    temp = strtok(s, reject);
    while (temp) {
        printf("%s", temp);
        temp = strtok(NULL, reject);
    }
}
int main() {
    char s[51];
    fgets (s, 51, stdin);
    s[strcspn(s, "\n\r")] = '\0';
    func(s);
    return 0;
}