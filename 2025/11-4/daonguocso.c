#include <stdio.h>
int main() {
    unsigned long long int N; scanf("%llu", &N);
    if (N == 0) {printf("0"); return 0;}
    short int a[21];
    short int i = 0;
    while (N != 0) {
        if (N%10 == 0) {
            N /= 10;
            continue;
        }
        a[i] = N%10;
        N /= 10;
        i ++;
    }
    for (short int j = 0; j < i; j ++) {
        printf("%d", a[j]);
    }
    return 0;
    

}