#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int* tree;
    int size;
    int left;
    int right;
} NumArray;

void build(int* tree ,int id, int l, int r, int* nums) {
    if (l == r) {
        tree[id] = nums[l];
        return;
    }

    int mid = (l+r)/2;
    build(tree, 2*id, l, mid, nums);
    build(tree, 2*id+1, mid+1, r, nums);

    tree[id] = tree[2*id] + tree[2*id+1];
}


NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray* obj = (NumArray*)malloc(sizeof(NumArray));
    obj->size = 4*(numsSize+1);
    obj->left = 0;
    obj->right = numsSize-1;

    obj->tree = (int*)malloc(obj->size * sizeof(int));

    build(obj->tree, 1, obj->left, obj->right, nums);

    return obj;
}

void update(int* tree, int id, int l, int r, int pos, int val) {
    if (l == r) {
        tree[id] = val;
        return;
    }

    int mid = (l+r)/2;
    if (pos <= mid) update(tree, 2*id, l, mid, pos, val);
    else update(tree, 2*id+1, r, mid+1, pos, val);

    tree[id] = tree[2*id] + tree[2*id+1];
}

void numArrayUpdate(NumArray* obj, int index, int val) {
    update(obj->tree, 1, obj->left, obj->right, index, val);
}

int query(int* tree, int id, int l, int r, int u, int v) {
    if (r < u || v < l) return 0;

    if (u <= l && r <= v) return tree[id];

    int mid = (l+r)/2;
    int max_left = query(tree, 2*id, l, mid, u, v);
    int max_right = query(tree, 2*id+1, mid+1, r, u, v);

    return max_left + max_right;
}
int numArraySumRange(NumArray* obj, int left, int right) {
    return query(obj->tree, 1, obj->left, obj->right, left, right);
}

void numArrayFree(NumArray* obj) {
    free(obj->tree);
    free(obj);
}
