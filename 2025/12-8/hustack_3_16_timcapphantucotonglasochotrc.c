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
    int k; scanf("%d", &k);
    int used_index = 0;
    //
    //
    //
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) {
            if (a[j] == k - a[i] && i != j && ((used_index & (1 << i)) == 0) && ((used_index & (1 << j)) == 0)) {
                printf("%d %d\n", a[i], a[j]);
                used_index = used_index | (1 << i);
                used_index = used_index | (1 << j);
            }
        }
    }
    if (used_index == 0) {
        printf("No pair found");
    }
}