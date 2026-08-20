#include <stdio.h>
#include <stdlib.h>
int *delete(int *a, int N, int *counter) {
    int count = 0;
    for (int i = 0; i < N; i ++) {
        if (a[i]%5 != 0) {
            count ++;
        }
    }
    *counter = count;
    int *array = (int *)malloc(count*sizeof(int));
    int index = 0;
    for (int i = 0; i < N; i ++) {
        if (a[i]%5 != 0) {
            array[index] = a[i];
            index ++;
        }
    }
    return array;
}
void free_array(int *array) {
    if (array == NULL) {
        free(array);
    }
}
int main() {
    int N; printf("Nhap N: "); scanf("%d", &N);
    int a[N]; printf("Nhap cac phan tu cua mang: ");
    for (int i = 0; i < N; i ++) {
        scanf("%d", &a[i]);
    }
    //
    //
    // Ham in:
    int counter = 0;
    int *counter_ptr = &counter;
    int *array = delete(a, N, counter_ptr);
    for (int i = 0; i < *counter_ptr; i ++) {
        printf("%d ", array[i]);
    }
    free(array);
    return 0;
}