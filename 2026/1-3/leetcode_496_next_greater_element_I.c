#include <stdio.h>
#include <stdlib.h>
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    *returnSize = nums1Size;
    int next[10001];
    memset(next, -1, sizeof(next));
    int stack[1000] = {0};
    int top = -1;

    for (int i = 0; i < nums2Size; i ++) {
        while (top >= 0 && nums2[i] > stack[top]) next[stack[top --]] = nums2[i];
        stack[++ top] = nums2[i];
    }       
    
    int *ans = (int *)malloc(*returnSize*sizeof(int));
    for (int i = 0; i < *returnSize; i ++) {
        ans[i] = next[nums1[i]];
    }
    return ans;
}
int main() {
    int N1, N2; scanf("%d %d", &N1, &N2);
    int n1[N1], n2[N2];
    for (int i = 0; i < N1; i ++) {
        scanf("%d", &n1[i]);
    }
    for (int i = 0; i < N2; i ++) {
        scanf("%d", &n2[i]);
    }
    int rts = 0;
    int *returnSize = &rts;
    int *ans = nextGreaterElement(n1, N1, n2, N2, returnSize);
    for (int i = 0; i < *returnSize; i ++) {
        printf("%d ", ans[i]);
    }
    return 0;

}