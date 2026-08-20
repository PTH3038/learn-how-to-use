#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int* queue;
    int head;
    int tail;
    int count;
} RecentCounter;

RecentCounter* recentCounterCreate() {
    RecentCounter *obj = (RecentCounter *)malloc(sizeof(RecentCounter));
    obj->queue = (int *)malloc(3006 * sizeof(int));
    obj->head = 0;
    obj->tail = -1;
    obj->count = 0;
    return obj;
}

bool isEmpty(RecentCounter *obj) {
    return obj->count == 0;
}

bool isFull(RecentCounter *obj) {
    return obj->count == 3006;
}

bool EnQueue(RecentCounter *obj, int k) {
    if (isFull(obj) == true) return false;
    obj->tail = (obj->tail + 1) % 3006;
    obj->queue[obj->tail] = k;
    obj->count ++;
    return true;
}

bool DeQueue(RecentCounter *obj) {
    if (isEmpty(obj) == true) return false;
    obj->head = (obj->head + 1) % 3006;
    obj->count --;
    return true;
}

int recentCounterPing(RecentCounter* obj, int t) {
    EnQueue(obj, t);
    while (obj->queue[obj->head] < t - 3000) DeQueue(obj);
    return obj->count;
}

void recentCounterFree(RecentCounter* obj) {
    free(obj->queue);
    free(obj);
}
