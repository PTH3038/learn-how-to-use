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
    //
    //
    //
    int counter_bar[N];
    for (int i = 0; i < N; i++) {
        counter_bar[i] = 1;
    }
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (a[i] == a[j]) {
                counter_bar[i]++;
            }
        }
    }
    for (int i = 0; i < N; i ++) {
        printf("%d ", counter_bar[i]);
    }
    int max = counter_bar[0];
    int i_max = 0;
    for (int i = 0; i < N; i ++) {
        if (counter_bar[i] > max) {
            max = counter_bar[i];
            i_max = i;
        }
    }
    printf("%d", a[i_max]);
    return 0;
}