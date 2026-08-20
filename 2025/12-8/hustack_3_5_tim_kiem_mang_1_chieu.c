#include <stdio.h>
int main() {
    int N, x; scanf("%d %d", &N, &x);
    long int a[N];
    for (int i = 0; i < N; i++) {
        scanf("%ld", &a[i]);
    }
    int first_index = -1;
    int last_index = -1;
    for (int i = 0; i < N; i++) {
        if (a[i] == x) {
            first_index = i;
            last_index = first_index;
            break;
        }
    }
    for (int i = first_index + 1; i < N; i++) {
        if (a[i] == x) {
            last_index = i;
        }
    }
    if (first_index == -1) {
        printf("NO");
        return 0;
    }
    printf("%d %d\n", first_index, last_index);
    return 0;
}