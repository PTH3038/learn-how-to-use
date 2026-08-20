#include <stdio.h>
int main() {
    int N; scanf("%d", &N);
    char bit[39] = "0000 0000 0000 0000 0000 0000 0000 0000";
    int index = 38;
    while (N) {
        if (bit[index] == ' ') {
            index --;
            continue;
        }
        if (N - 2*(N/2)) {
            bit[index] = '1';
        }
        index --;
        N /= 2;
    }
    printf("%s", bit);
    return 0;
}