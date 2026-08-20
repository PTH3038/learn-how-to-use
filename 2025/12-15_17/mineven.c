#include <stdio.h>
int main() {
    int N; scanf("%d", &N);
    if (N <= 0 || N >= 101) {
        printf("ERROR");
        return 0;
    }
    int a[N];
    for (int i = 0; i < N; i ++) {
        scanf("%d", &a[i]);
    }
    int min = 1;
    for (int i = 0; i < N; i ++) {
        if (a[i]%2 == 0) {
            min = a[i];
            break;
        }
    }
    if (min == 1) {
        printf("Day khong co so chan");
        return 0;
    }
    for (int i = 0; i < N; i ++) {
        if (a[i]%2 == 0 && a[i] < min) {
            min = a[i];
        }
    }
    printf("%d", min);
    return 0;
}