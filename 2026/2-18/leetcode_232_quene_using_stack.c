#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct {
    int* stackin;
    int* stackout;
    int topin;
    int topout;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* obj = (MyQueue *)malloc(sizeof(MyQueue));
    obj->stackin = (int *)malloc(100 * sizeof(int));
    obj->stackout = (int *)malloc(100 * sizeof(int));
    obj->topin = -1;
    obj->topout = -1;
    return obj;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->topin ++;
    obj->stackin[obj->topin] = x;
}

int myQueuePop(MyQueue* obj) {
    if (obj->topout == -1) {
        while (obj->topin != -1) {
            obj->stackout[++ obj->topout] = obj->stackin[obj->topin --];
        }
    }
    return obj->stackout[obj->topout --];
}

int myQueuePeek(MyQueue* obj) {
    if (obj->topout == -1) {
        while (obj->topin != -1) {
            obj->stackout[++ obj->topout] = obj->stackin[obj->topin --];
        }
    }
    return obj->stackout[obj->topout];
}

bool myQueueEmpty(MyQueue* obj) {
    if (obj->topin == -1 && obj->topout == -1) return true;
    else return false;
}

void myQueueFree(MyQueue* obj) {
    free(obj->stackin);
    free(obj->stackout);
    free(obj);
}
int main() {

}