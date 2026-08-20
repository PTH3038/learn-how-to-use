#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* simplifyPath(char* path) {
    int N = strlen(path);
    char *ans = (char *)malloc((N+1)*sizeof(char));
    char *token = strtok(path, "/");
    int top = -1;
    while (token != NULL) {
        if (strcmp(token, "..") == 0) {
            if (top > 0) {
                while (ans[top] != '/' && top > 0) top --;
                top --;
            }
        }
        else if (strcmp(token, ".") == 0) {
            token = strtok(NULL, "/");
            continue;
        }
        else {
            top ++;
            ans[top] = '/';
            for (int i = 0; token[i] != '\0'; i ++) {
                top ++;
                ans[top] = token[i];
            }
        }
        token = strtok(NULL, "/");
    }
    if (top == -1) ans[++ top] = '/';
    else if (top == 0) ans[top] = '/';
    ans[top+1] = '\0';
    return ans;
}
int main() {
    char path[3001]; scanf("%s", path);
    printf("%s", simplifyPath(path));
    return 0;
}