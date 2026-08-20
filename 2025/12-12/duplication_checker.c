#include <stdio.h>
int main() {
    int N; scanf("%d", &N);
    int a[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
    long long int used = 0;
    for (int i = 0; i < N; i ++) {
        if (used & (1LL << a[i])) {
            printf("Duplication found\n");
            return 0;
        }
        used |= (1LL << a[i]);
    }
    printf("No duplication\n");
    return 0;
}