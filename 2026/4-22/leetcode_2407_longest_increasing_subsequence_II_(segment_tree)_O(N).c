#include <stdio.h>
#include <stdlib.h>
int max(int a, int b) {
    return (a > b) ? a : b;
}

void update(int* tree, int id, int l, int r, int pos, int val) {
    if (l == r) {
        tree[id] = val;
        return;
    }

    int mid = (l+r)/2;
    if (pos <= mid) update(tree, 2*id, l, mid, pos, val);
    else update(tree, 2*id+1, mid+1, r, pos, val);

    tree[id] = max(tree[2*id], tree[2*id+1]);
}

int query(int* tree, int id, int l, int r, int u, int v) {
    if (u > r || v < l) return 0;

    if (u <= l && r <= v) return tree[id];

    int mid = (l+r)/2;
    int max_left = query(tree, 2*id, l, mid, u, v);
    int max_right = query(tree, 2*id+1, mid+1, r, u, v);

    return max(max_left, max_right);
}

int lengthOfLIS(int* nums, int numsSize, int k) {
    int tree[4*(100000+1)];
    for (int i = 0; i < 4*(100000+1); i ++) tree[i] = 0;
    
    for (int i = 0; i < numsSize; i ++) {
        int u = (nums[i]-k > 0) ? nums[i]-k : 0;
        int v = nums[i] - 1;
        
        int current_best_LIS = query(tree, 1, 1, 100000, u, v);
        update(tree, 1, 1, 100000, nums[i], current_best_LIS+1);
    }

    return tree[1];
}

int main() {
    int N, k; scanf("%d %d", &N, &k);

    int nums[N];
    for (int i = 0; i < N; i ++) scanf("%d", &nums[i]);

    printf("%d", lengthOfLIS(nums, N, k));

    return 0;
}