#include <stdio.h>
#include <stdlib.h>
int max(int a, int b) {
    return (a > b) ? a : b;
}

int comparator(const void* a, const void* b) {
    int A = *(int*)a;
    int B = *(int*)b;

    if (A < B) return -1;
    if (A > B) return 1;
    return 0;
}

void update(int *st, int id, int l, int r, int pos, int val) {
    if (l == r) {
        st[id] = max(st[id], val);
        return;
    }

    int mid = (l+r)/2;
    if (pos <= mid) update(st, 2*id, l, mid, pos, val);
    else update(st, 2*id+1, mid+1, r, pos, val);

    st[id] = max(st[2*id], st[2*id+1]);
}

int query(int *st, int id, int l, int r, int q_l, int q_r) {
    if (q_r < l || r < q_l) return 0;

    if (q_l <= l && r <= q_r) return st[id];

    int mid = (l+r)/2;
    int max_left = query(st, 2*id, l, mid, q_l, q_r);
    int max_right = query(st, 2*id+1, mid+1, r, q_l, q_r);

    return max(max_left, max_right);
}

int getrank(int val, int* ranks, int m) {
    int* item = (int*)bsearch(&val, ranks, m, sizeof(int), comparator);
    if (item == NULL) return -1;
    return (int)(item - ranks);
}

int lengthOfLIS(int* nums, int numsSize) {
    int temp[numsSize];
    for (int i = 0; i < numsSize; i ++) temp[i] = nums[i];
    qsort(temp, numsSize, sizeof(int), comparator);

    int number_of_ranks = 0;
    for (int i = 0; i < numsSize; i ++) {
        if (i == 0 || temp[i] != temp[i-1]) temp[number_of_ranks ++] = temp[i];
    }

    int st[4*(numsSize+1)];
    for (int i = 0; i < 4*(numsSize+1); i ++) st[i] = 0;

    for (int i = 0; i < numsSize; i ++) {
        int current_rank = getrank(nums[i], temp, number_of_ranks);

        int current_lis = query(st, 1, 0, number_of_ranks-1, 0, current_rank-1);
        update(st, 1, 0, number_of_ranks-1, current_rank, current_lis+1);
    }

    return st[1];
}

int main() {
    int N; scanf("%d", &N);
    int a[N];
    for (int i = 0; i < N; i ++) scanf("%d", &a[i]);
    printf("%d", lengthOfLIS(a, N));
    return 0;
}