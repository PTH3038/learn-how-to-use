#include <stdio.h>
#include <stdlib.h>
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    *returnSize = temperaturesSize;
    int *ans = (int *)malloc(*returnSize * sizeof(int));
    memset(ans, 0, *returnSize * sizeof(int));

    int top = -1;
    int stack[100001];
    
    for (int i = 0; i < temperaturesSize; i ++) {
        while (top >= 0 && temperatures[stack[top]] < temperatures[i]) {
            int prevIdx = stack[top --];
            ans[prevIdx] = i - prevIdx;
        }
        stack[++ top] = i; 
    }
    return ans;
}
int main() {
    int N; scanf("%d", &N);
    int a[N];
    for (int i = 0; i < N; i ++) scanf("%d", &a[i]);

    int rts = 0;
    int *returnSize = &rts;
    int *ans = dailyTemperatures(a, N, returnSize);
    for (int i = 0; i < *returnSize; i ++) printf("%d ", ans[i]);
    return 0;
}