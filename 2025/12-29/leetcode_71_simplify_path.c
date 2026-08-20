#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* simplifyPath(char* path) {
    char *ans = (char *)malloc(3002 * sizeof(char));
    int N = strlen(path);
    int write_index = -1;
    int slash_count = 0;
    int period_count = 0;
    int stack_posi[3000] = {0};
    int top = -1;
    for (int i = 0; i <= N; i ++) {
        if (path[i] == '/' || path[i] == '\0') {
            if (period_count == 1) {
                period_count = 0;
                slash_count = 1;
            }
            else if (period_count == 2) {
                if (top != 0) top --;
                write_index = stack_posi[top];
                period_count = 0;
                slash_count = 1;
            }
            else if (period_count > 2) {
                write_index ++;
                ans[write_index] = '.';
                period_count --;
                while (period_count) {
                    write_index ++;
                    memcpy(ans + write_index, ans + stack_posi[top] + 1, 1);
                    period_count --;
                }
            }
            if (slash_count == 0) {
                write_index ++;
                ans[write_index] = path[i];
                slash_count ++;
                top ++;
                stack_posi[top] = write_index;
            }
        }
        else if (path[i] == '.') {
            if (write_index >= 0 && ans[write_index] != '/' && period_count == 0) {
                write_index ++;
                ans[write_index] = '.';
            }
            else {
                period_count ++;
            }
            slash_count = 0;
        }
        else {
            slash_count = 0;
            while (period_count) {
                write_index ++;
                ans[write_index] = '.';
                period_count --;
            }
            write_index ++;
            ans[write_index] = path[i];
        }
    }
    if (ans[write_index] == '/' && write_index != 0) ans[write_index] = '\0';
    if (ans[write_index+1] != '\0') ans[write_index+1] = '\0';
    return ans;
}
int main() {
    char path[3001]; scanf("%s", path);
    printf("%s", simplifyPath(path));
    return 0;
}