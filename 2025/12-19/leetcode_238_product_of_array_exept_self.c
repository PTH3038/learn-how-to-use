#include <stdio.h>
#include <stdlib.h>
int *productExceptSelf(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int *ans = (int *)malloc(*returnSize * sizeof(int));
    for (int i = 0; i < numsSize; i ++) {
        ans[i] = 1;
    }
    for (int i = 1; i < numsSize; i ++) {
        ans[i] *= nums[i-1] * ans[i-1];
    }
    for (int i = numsSize-2; i >= 0; i --) {
        ans[i] *= nums[i+1];
        nums[i] *= nums[i+1];
    }
    return ans;
}
int main() {
    int N; scanf("%d", &N);
    int a[N];
    for (int i = 0; i < N; i ++) {
        scanf("%d", &a[i]);
    }
    int rts = 0;
    int *returnSize = &rts;
    int *ans_arr = productExceptSelf(a, N, returnSize);
    for (int i = 0; i < *returnSize; i ++) {
        printf("%d ", ans_arr[i]);
    }
    free(ans_arr);
    return 0;
}