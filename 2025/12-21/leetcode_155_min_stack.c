#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int *min;
    int *main;
    int index;
    int capa;
} MinStack;


MinStack* minStackCreate() {
    MinStack *obj = (MinStack *)malloc(sizeof(MinStack));
    obj->min = (int *)malloc(4*sizeof(int));
    obj->main = (int *)malloc(4*sizeof(int));
    obj->index = -1;
    obj->capa = 4;
    return obj;
}
void minStackPush(MinStack* obj, int val) {
    if (obj->index + 1 >= obj->capa) {
        obj->capa *= 2;
        obj->min = (int *)realloc(obj->min, obj->capa*sizeof(int));
        obj->main = (int *)realloc(obj->main, obj->capa*sizeof(int));
    }
    obj->index ++;
    if (obj->index == 0) {
        obj->min[obj->index] = val;
        obj->main[obj->index] = val;
        return;
    }
    obj->min[obj->index] = (val < obj->min[obj->index-1]) ? val : obj->min[obj->index-1];
    obj->main[obj->index] = val;
}


void minStackPop(MinStack* obj) {
    if (obj->index == -1) return;
    else obj->index --;
}

int minStackTop(MinStack* obj) {
    return obj->main[obj->index];
}
int minStackGetMin(MinStack* obj) {
    return obj->min[obj->index];
}
void minStackFree(MinStack* obj) {
    free(obj->min);
    free(obj->main);
    obj->min == NULL;
    obj->main == NULL;
    obj->index = 0;
    obj->capa = 0;   
}
int main() {
    MinStack *a = minStackCreate();
    minStackPush(a, 4);
    minStackPush(a, 6);
    minStackPush(a, 10);
    minStackPush(a, 3);
    minStackPush(a, 7);
    printf("%d", minStackGetMin(a));
    return 0;
}