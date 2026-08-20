#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char **quick_sort(char **arr, int low, int high) {
    if (low >= high) {
        return arr;
    }
    char *pivot = arr[low];
    int last_min_index = low;
    for (int i = low+1; i <= high; i ++) {
        if (strcmp(arr[i], pivot) > 0) {
            continue;
        }
        last_min_index ++;
        char *temp = arr[i];
        arr[i] = arr[last_min_index];
        arr[last_min_index] = temp;
    }
    char *temp = arr[low];
    arr[low] = arr[last_min_index];
    arr[last_min_index] = temp;
    quick_sort(arr, last_min_index+1, high);
    quick_sort(arr, low, last_min_index-1);
    return arr;
}
int main() {
    int N; scanf("%d", &N);
    char **arr = (char **)malloc(N * sizeof(char *));
    for (int i = 0; i < N; i ++) {
        arr[i] = (char *)malloc(128 * sizeof(char));
        scanf("%s", arr[i]);
    }
    char **ans = quick_sort(arr, 0, N-1);
    for (int i = 0; i < N; i ++) {
        printf("%s\n", ans[i]);
    }
    return 0;
}