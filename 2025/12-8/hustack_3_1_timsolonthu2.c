#include <stdio.h>
int main() {
    unsigned short int N; scanf("%hu", &N);
    long long int a[N];
    for (unsigned short int i = 0; i < N; i ++) {
        scanf("%lld", &a[i]);
    }
    int max_i = 0;
    long long int max = a[0];
    for (unsigned short int i = 0; i < N; i ++) {
        if (a[i] >= max) {
            max = a[i];
        }
    }
    for (unsigned short int i = 0; i < N; i ++) {
        if (a[i] == max) {
            max_i = max_i | (1 << i);
        }
    }
    long long int ans = max;
    for (unsigned short int i = 0; i < N; i ++) {
        if (max_i & (1 << i)) {
            continue;
        }
        else {
            ans = a[i];
            break;
        }
    }
    for (unsigned short int i = 0; i < N; i ++) {
        if (a[i] >= ans && !(max_i & (1 << i))) {
            ans = a[i];
        }
    }
    if (ans == max) {
        printf("NOT FOUND");
        return 0;
    }
    printf("%lld", ans);
    return 0;
}