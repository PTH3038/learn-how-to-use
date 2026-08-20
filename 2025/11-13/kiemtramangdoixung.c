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
    for (int i = 0; i < N/2; i ++) {
        if (a[i] != a[N-i-1]) {
            printf("No");
            return 0;
        }
    }
    printf("Yes");
    return 0;
}