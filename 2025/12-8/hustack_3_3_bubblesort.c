#include <stdio.h>
int bubblesort(int *a, int N) {
    for (int i = 0; i < N-1; i ++) {
        if (a[i] > a[i+1]) {
            int temp = a[i];
            a[i] = a[i+1];
            a[i+1] = temp;
        }
    }
    //
    //
    //
    for (int i = 0; i < N-1; i ++) {
            if (a[i] > a[i+1]) {
                return 0;
            }
    }
    return 1;
}
//
//
//
int main() {
    int N; scanf("%d", &N);
    int a[N];
    for (int i = 0; i < N; i++) { 
        scanf("%d", &a[i]);
    }
    //
    //
    //
    int state = bubblesort(a, N);
    while (state == 0) {
        state = bubblesort(a, N);
    }
    //
    //
    //
    for (int i = 0; i < N; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}