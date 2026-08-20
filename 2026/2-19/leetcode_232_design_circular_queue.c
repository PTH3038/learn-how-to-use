#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct {
	int* queue;
	int head;
	int tail;
	int size;
} MyCircularQueue;

MyCircularQueue *myCircularQueueCreate(int k) {
	MyCircularQueue *obj = (MyCircularQueue *)malloc(sizeof(MyCircularQueue));
	obj->queue = (int *)malloc(k * sizeof(int));
	obj->head = -1;
	obj->tail = -1;
	obj->size = k;
	return obj;
}

bool myCircularQueueIsEmpty(MyCircularQueue *obj) {
	if (obj->tail == -1) return true;
	else return false;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
	int k = obj->tail - obj->head;
	if ( (obj->tail == obj->size - 1 && obj->head == 0) || k == -1) return true;
	else return false;
}

bool myCircularQueueEnQueue(MyCircularQueue *obj, int value) {
	if (myCircularQueueIsFull(obj) == true) return false;
	if (myCircularQueueIsEmpty(obj) == true) obj->head ++;
	if (obj->tail < obj->size - 1) obj->queue[++ obj->tail] = value;
	else {
		obj->tail = 0;
		obj->queue[obj->tail] = value;
	}
	return true;
}

bool myCircularQueueDeQueue(MyCircularQueue *obj) {
	if (myCircularQueueIsEmpty(obj) == true) return false;
	else if (obj->head == obj->tail) {
		obj->head = -1;
		obj->tail = -1;
		return true;
	}
	if (obj->head < obj->size - 1) obj->head ++;
	else obj->head = 0;
	return true;
}

int myCircularQueueFront(MyCircularQueue *obj) {
	if (myCircularQueueIsEmpty(obj) == true) return -1;
	return obj->queue[obj->head];
}

int myCircularQueueRear(MyCircularQueue *obj) {
	if (myCircularQueueIsEmpty(obj) == true) return -1;
	return obj->queue[obj->tail];
}

void myCircularQueueFree(MyCircularQueue *obj) {
	free(obj->queue);
	free(obj);
}