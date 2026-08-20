#include <stdio.h>
int main() {
    int N; scanf("%d", &N);
    int even = 0, odd = 0;
    if (N == 0) {
        printf("1 0");
        return 0;
    }
    while (N) {
        if (N%2 == 0) {
            even ++;
        }
        else if (N%2 != 0) {
            odd ++;
        }
        N /= 10;
    }
    printf("%d %d", even, odd);
    return 0;
}