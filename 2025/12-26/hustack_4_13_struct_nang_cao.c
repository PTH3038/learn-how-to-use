#include <stdio.h>
#include <string.h>
typedef struct worker {
    char name[36];
    float factor;
} worker;
//
//
//
void one(int N, worker list[N]) {
    for (int i = 0; i < N; i++) {
        printf("%s %.2f\n", list[i].name, list[i].factor * 130);
    }
}
//
//
//
void quick_sort(int N, worker list[N], int low, int high) {
    if (low >= high) return;
    worker pivot = list[low];
    int index = low;
    for (int i = low+1; i <= high; i ++) {
        if (strcmp(list[i].name, pivot.name) > 0) continue;
        index ++;
        worker temp = list[i];
        list[i] = list[index];
        list[index] = temp;
    }
    worker temp = list[index];
    list[index] = list[low];
    list[low] = temp;
    quick_sort(N, list, index+1, high);
    quick_sort(N, list, low, index-1);
}
void two(int N, worker list[N]) {
    quick_sort(N, list, 0, N-1);
    for (int i = 0; i < N; i++) {
        printf("%s %.2f\n", list[i].name, list[i].factor * 130);
    }
}
//
//
//
void three(int N, worker list[N]) {
    int index_max = 0;
    for (int i = 0; i < N; i ++) {
        if (list[i].factor > list[index_max].factor) index_max = i;
    }
    printf("%s %.2f\n", list[index_max].name, list[index_max].factor * 130);
}
//
//
//
int main() {
    int N; scanf("%d", &N);
    worker list[N];
    for (int i = 0; i < N; i ++) {
        scanf("%s %f", list[i].name, &list[i].factor);
    }
    int T; scanf("%d", &T);
    //
    int index = 0;
    int curr = 0;
    while (1) {
        if (index == T) break;
        scanf("%d", &curr);
        if (curr == 1) one(N, list);
        else if (curr == 2) two(N, list);
        else if (curr == 3) three(N, list);
        index ++;
    }
    return 0;
}