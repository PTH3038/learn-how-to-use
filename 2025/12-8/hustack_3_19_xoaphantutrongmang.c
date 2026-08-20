#include <stdio.h>
int main() {
    int N; scanf("%d", &N);
    if (N <= 0) {
        printf("Error");
        return 0;
    }
    int a[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
    int p; scanf("%d", &p);
    for (int i = 0; i < N; i ++) {
        if (i == p) {
            continue;
        }
        printf("%d ", a[i]);
    }
    return 0;
}