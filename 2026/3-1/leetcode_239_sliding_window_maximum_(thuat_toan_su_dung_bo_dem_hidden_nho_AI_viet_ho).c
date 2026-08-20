#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int* queue;
    int head;
    int tail;
    int count;
    int size;
} Queue;

Queue* Create(int k) {
    Queue *obj = (Queue *)malloc(sizeof(Queue));
    obj->queue = (int *)malloc(k * sizeof(int));
    obj->head = 0;
    obj->tail = -1;
    obj->count = 0;
    obj->size = k;
    return obj;
}

bool isEmpty(Queue *obj) { return obj->count == 0; }

void EnQueue(Queue *obj, int val) {
    obj->tail = (obj->tail + 1) % obj->size;
    obj->queue[obj->tail] = val;
    obj->count++;
}

void DeQueue(Queue *obj) {
    if (isEmpty(obj)) return;
    obj->head = (obj->head + 1) % obj->size;
    obj->count--;
}

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    if (numsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    Queue* q = Create(k);
    int* result = (int*)malloc((numsSize - k + 1) * sizeof(int));
    int resIdx = 0;
    int hidden = 0;

    for (int i = 0; i < numsSize; i++) {
        int x = nums[i];

        // 1. Làm sạch hàng đợi: Đảm bảo tính giảm dần từ đầu đến cuối
        // Nếu có thằng sau lớn hơn thằng trước, thằng trước biến thành hidden
        while (q->count >= 2) {
            int first = q->queue[q->head];
            int second = q->queue[(q->head + 1) % q->size];
            if (first < second) {
                DeQueue(q);
                hidden++;
            } else {
                break;
            }
        }

        // 2. So sánh X với head theo logic của ông
        if (!isEmpty(q) && x > q->queue[q->head]) {
            hidden += q->count; // Đẩy toàn bộ hiện tại vào hidden
            q->head = 0; q->tail = -1; q->count = 0; // Reset nhanh
            EnQueue(q, x);
        } else {
            EnQueue(q, x);
        }

        // 3. Đánh giá cửa sổ
        if (hidden + q->count == k) {
            result[resIdx++] = q->queue[q->head]; // Max luôn là head

            // Trượt cửa sổ
            if (hidden > 0) {
                hidden--;
            } else {
                // Khi hidden = 0, đẩy head ra vì nó chính là thằng già nhất ở đầu cửa sổ
                DeQueue(q);
            }
        }
    }

    *returnSize = resIdx;
    free(q->queue);
    free(q);
    return result;
}