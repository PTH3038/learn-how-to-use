#include <stdio.h>
int main() {
    int N; scanf("%d", &N);
    if ( !(N >= 0 && N <= 65535) ) {
        printf("TOO BIG");
        return 0;
    }
    if (N == 0) {
        printf("0");
        return 0;
    }
    int vitri = 0;
    int ans = 0;
    while (N != 0) {
        if ( N&1 != 0) {
            ans = ans | (1 << vitri);
        }
        N = N >> 1;
        vitri++;
    }
    int a[vitri];
    for (int i = 0; i < vitri; i ++) {
        a[i] = (ans >> i) & 1;
    }
    for (int i = vitri - 1; i >= 0; i--) {
        printf("%d", a[i]);
    }
}