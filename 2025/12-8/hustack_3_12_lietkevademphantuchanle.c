#include <stdio.h>
int main() {
    int N; scanf("%d", &N);
    if (N <= 0) {
        printf("Error");
        return 0;
    }
    int a[N];
    for (int i = 0; i < N; i ++) {
        scanf("%d", &a[i]);
    }
    int even[N], odd[N];
    int even_count = 0, odd_count = 0;
    for (int i = 0; i < N; i ++) {
        if (a[i] % 2 == 0) {
            even[even_count++] = a[i];
        } else {
            odd[odd_count++] = a[i];
        }
    }
    for (int i = 0; i < even_count; i ++) {
        printf("%d ", even[i]);
    }
    printf("\n");
    for (int i = 0; i < odd_count; i ++) {
        printf("%d ", odd[i]);
    }
    printf("\n");
}