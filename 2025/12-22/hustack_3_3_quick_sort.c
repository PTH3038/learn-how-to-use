#include <stdio.h>
int *func(int *a, int low, int high) {
    if (low >= high) {
        return a;
    }
    int index = low;
    int pivot = a[low];
    for (int i = low + 1; i <= high; i ++) {
        if (a[i] > pivot) {
            continue;
        }
        index ++;
        int temp = a[index];
        a[index] = a[i];
        a[i] = temp;
    }
    int temp = a[index];
    a[index] = a[low];
    a[low] = temp;
    func(a, low, index - 1);
    func(a, index + 1, high);
    return a;
}
int main() {
    int N; scanf("%d", &N);
    int a[N];
    for (int i = 0; i < N; i ++) {
        scanf("%d", &a[i]);
    }
    int *ans = func(a, 0, N-1);
    for (int i = 0; i < N; i ++) {
        printf("%d ", ans[i]);
    }
}