#include <stdio.h>
#include <stdlib.h>
int *topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    *returnSize = k;
    int fre[20001] = {0};
    for (int i = 0; i < numsSize; i ++) {
        fre[nums[i] + 10000] ++;
    }
    int max_fre = 0;
    for (int i = 0; i < numsSize; i ++) {
        if (max_fre < fre[nums[i] + 10000]) {
            max_fre = fre[nums[i] + 10000];
        }
    }
    int head_bucket[max_fre+1];
    for (int i = 0; i <= max_fre; i ++) {
        head_bucket[i] = -10001;
    }
    int under[20001];
    for (int i = 0; i < 20001; i ++) {
        under[i] = -10001;
    }
    for (int i = -10000; i <= 10000; i ++) {
        if (fre[i + 10000] != 0) {
            under[i + 10000] = head_bucket[fre[i + 10000]];
            head_bucket[fre[i + 10000]] = i;
        }
    }
    int *ans_arr = (int *)malloc(*returnSize * sizeof(int));
    //
    //
    //
    while (k) {
        if (head_bucket[max_fre] != -10001) {
            ans_arr[*returnSize - k] = head_bucket[max_fre];
            head_bucket[max_fre] = under[head_bucket[max_fre] + 10000];
            k --;
        }
        else {
            max_fre --;
        }
    }
    return ans_arr;
}
int main() {
    int N; scanf("%d", &N);
    int a[N];
    for (int i = 0; i < N; i ++) {
        scanf("%d", &a[i]);
    }
    int k; scanf("%d", &k);
    int returnsize = 0;
    int *returnSize = &returnsize;
    int *ans = topKFrequent(a, N, k, returnSize);
    for (int i = 0; i < *returnSize; i ++) {
        printf("%d ", ans[i]);
    }
}