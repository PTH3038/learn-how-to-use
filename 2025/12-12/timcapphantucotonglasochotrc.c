#include <stdio.h>
int main() {
    int N; scanf("%d", &N);
    int a[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
    int S; scanf("%d", &S);
    //
    //
    //
    int max = 0;
    for (int i = 0; i < N; i ++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    //
    //
    //
    int inverted_a[max + 1];
    for (int i = 0; i <= max; i ++) {
        inverted_a[i] = 0;
    }
    for (int i = 0; i < N; i ++) {
        inverted_a[a[i]] = i;
    }
    for (int i = 0; i <= max; i ++) {
        printf("%d ", inverted_a[i]);
    }
    //
    //
    //
    for (int i = 0; i < N; i ++) {
        if (inverted_a[S - a[i]] != 0) {
            printf("%d %d\n", i, inverted_a[S - a[i]]);
            return 0;
        }
    }
}