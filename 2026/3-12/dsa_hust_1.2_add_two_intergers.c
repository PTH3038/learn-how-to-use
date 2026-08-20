#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *sum(char *a, char *b) {
    char *ans = (char *)malloc(21 * sizeof(char));
    int i = 0;
    int temp = 0;
    int len_a = strlen(a);
    int len_b = strlen(b);
    int digit_a, digit_b, digit_sum = 0;
    while (len_a-i-1 >=0 || len_b-i-1 >= 0 || temp) {
        if (len_a-i-1 >= 0) digit_a = a[len_a-i-1] - '0';
        if (len_b-i-1 >= 0) digit_b = b[len_b-i-1] - '0';
        digit_sum = digit_a + digit_b + temp;
        ans[i ++] = (digit_sum) % 10 + '0';
        temp = digit_sum / 10;
        digit_a = 0;
        digit_b = 0;
    }
    ans[i] = '\0';
    return ans;
}
int main() {
    char a[21]; char b[21];
    scanf("%s %s", &a, &b);
    char *ans = sum(a, b);
    for (int i = strlen(ans) - 1; i >= 0; i --) printf("%c", ans[i]);
    return 0;
}