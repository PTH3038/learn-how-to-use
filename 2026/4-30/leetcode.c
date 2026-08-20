#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
max(int a, int b) {
    return (a > b) ? a : b;
}

typedef struct BCS {
    int sum;
    int max;
} BCS;

build(BCS* obj, int id, int l, int r, int m) {
    if (l == r) {
        obj[id].sum = m;
        obj[id].max = m;

        return;
    }

    int mid = (l+r)/2;
    build(obj, 2*id, l, mid, m);
    build(obj, 2*id+1, mid+1, r, m);

    obj[id].sum = obj[2*id].sum + obj[2*id+1].sum;
    obj[id].max = max(obj[2*id].max, obj[2*id+1].max);
}

int ROW, COL;
BCS* BCSCreate(int n, int m) {
    BCS* obj = (BCS*)malloc((n+1) * sizeof(BCS));

    ROW = n;
    COL = m;

    build(obj, 1, 0, n-1, m);
    return obj;
}


int* BCSGather(BCS* obj, int k, int maxRow, int* retSize) {
    *retSize = 2;
    int* ans = (int*)malloc(*retSize * sizeof(int));
  
}

int query(BCS* obj, int id, int l, int r, int u, int v) {
    if (v < l || r < u) return 0;

    if (u <= l && r <= v) return obj[id].sum;

    int mid = (l+r)/2;
    int max_left = query(obj, 2*id, l, mid, u, v);
    int max_right = query(obj, 2*id+1, mid+1, r, u, v);

    return max_left + max_right;
}

void fill(BCS* obj, int id, int l, int r, int* val) {
    if (obj[id].sum <= *val) {
        *val -= obj[id].sum;
        obj[id].sum = 0;
        obj[id].max = 0;
        
        return;
    }

    int mid = (l+r)/2;
    fill(obj, 2*id, l, mid, val);
    if (*val > 0) fill(obj, 2*id+1, mid+1, r, val);

    obj[id].sum = obj[2*id].sum + obj[2*id+1].sum;
    obj[id].max = max(obj[2*id].max, obj[2*id+1].max);
}

bool BCSScatter(BCS* obj, int k, int maxRow) {
    int gap_left = query(obj, 1, 0, ROW-1, 0, maxRow);
    if (k > gap_left) return false;

    fill(obj, 1, 0, ROW-1, &k);
    return true;
}

void BCSFree(BCS* obj) {
    
}