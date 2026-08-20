#include <stdlib.h>
#include <stdio.h>

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    if (numsSize == 0 || k == 0) {
        *returnSize = 0;
        return NULL;
    }

    int* ans = (int*)malloc((numsSize - k + 1) * sizeof(int));
    *returnSize = numsSize - k + 1;

    int* deque = (int*)malloc(numsSize * sizeof(int));
    int head = 0;
    int tail = 0;
    //head < tail => queue khong trong
    for (int i = 0; i < numsSize; i++) {
        if (head < tail && deque[head] <= i - k) head++;
        while (head < tail && nums[deque[tail - 1]] <= nums[i]) tail--;
        deque[tail++] = i;
        if (i >= k - 1) ans[i - k + 1] = nums[deque[head]];
    }

    free(deque);
    return ans;
}