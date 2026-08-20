#include <stdio.h>
#include <math.h>
int main() {
    int N; scanf("%d", &N);
    int binary[N];
    for (int i = 0; i < N; i ++) {
        scanf("%d", &binary[i]);
    }
    int decimal = 0;
    for (int i = N-1; i >= 0; i --) {
        decimal += binary[i] * pow(2, N-1-i);
    }
    printf("%d\n", decimal);
}