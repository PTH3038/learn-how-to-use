#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct {
    int *deque;
    int front;
    int back;
    int count;
    int size;
} DeQue;

DeQue *Create(int k) {
    DeQue *obj = (DeQue *)malloc(sizeof(DeQue));
    obj->deque = (int *)malloc(k * sizeof(int));
    obj->front = k+1;
    obj->back = -1;
    obj->count = 0;
    obj->size = k;
    return obj;
}

bool isEmpty(DeQue *obj) {
    return obj->count == 0;
}

bool isFull(DeQue *obj) {
    return obj->count == obj->size;
}

bool push_front(DeQue *obj, int k) {
	if (isFull(obj) == true) return false;
	if (isEmpty(obj) == true) obj->back = 0;
	obj->front = (obj->front - 1 + obj->size) % obj->size;
	obj->deque[obj->front] = k;
	obj->count ++;
	return true;
}

bool push_back(DeQue *obj, int k) {
	if (isFull(obj) == true) return false;
	if (isEmpty(obj) == true) obj->front = 0;
	obj->back = (obj->back + 1) % obj->size;
	obj->deque[obj->back] = k;
	obj->count ++;
	return true;
}

bool pop_front(DeQue *obj) {
	if (isEmpty(obj) == true) return false;
    if (obj->count == 1) {
        obj->front = obj->size + 1;
        obj->back = -1;
        obj->count = 0;
        return true;
    }
	obj->front = (obj->front + 1) % obj->size;
	obj->count --;
	return true;
}

bool pop_back(DeQue *obj) {
	if (isEmpty(obj) == true) return false;
    if (obj->count == 1) {
        obj->front = obj->size + 1;
        obj->back = -1;
        obj->count = 0;
        return true;
    }
	obj->back = (obj->back - 1 + obj->size) % obj->size;
	obj->count --;
	return true;
}

void FREE(DeQue *obj) {
	free(obj->deque);
	free(obj);
}