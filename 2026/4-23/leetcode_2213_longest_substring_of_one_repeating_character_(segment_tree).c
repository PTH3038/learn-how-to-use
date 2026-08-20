#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct tree {
    char leftmost;
    char rightmost;
    int prefix;
    int suffix;
    int value;
} tree;

int max(int a, int b) {
    return (a > b) ? a : b;
}

tree complex_combine(tree two_id, tree two_id_plus, int l, int mid, int r) {
    tree ans;
    ans.leftmost = two_id.leftmost;
    ans.rightmost = two_id_plus.rightmost;

    if (two_id.rightmost == two_id_plus.leftmost) ans.value = max(two_id.suffix + two_id_plus.prefix, max(two_id.value, two_id_plus.value));
    else ans.value = max(two_id.value, two_id_plus.value);

    if (two_id.rightmost == two_id_plus.leftmost && two_id.prefix == mid-l+1) ans.prefix = two_id.prefix + two_id_plus.prefix;
    else ans.prefix = two_id.prefix;

    if (two_id.rightmost == two_id_plus.leftmost && two_id_plus.suffix == r-mid) ans.suffix = two_id.suffix + two_id_plus.suffix;
    else ans.suffix = two_id_plus.suffix;

    return ans;
}

void build (tree* st, int id, int l, int r, char* s) {
    if (l == r) {
        st[id].leftmost = s[l];
        st[id].rightmost = s[r];
        st[id].prefix = 1;
        st[id].suffix = 1;
        st[id].value = 1;
        return;
    }

    int mid = (l+r)/2;
    build(st, 2*id, l, mid, s);
    build(st, 2*id+1, mid+1, r, s);

    st[id] = complex_combine(st[2*id], st[2*id+1], l, mid, r);
}

void update(tree* st, int id, int l, int r, int pos, char val) {
    if (l == r) {
        st[id].leftmost = val;
        st[id].rightmost = val;
        return;
    }

    int mid = (l+r)/2;
    if (pos <= mid) update(st, 2*id, l, mid, pos, val);
    else update (st, 2*id+1, mid+1, r, pos, val);

    st[id] = complex_combine(st[2*id], st[2*id+1], l, mid, r);
}

int* longestRepeating(char* s, char* queryCharacters, int* queryIndices, int queryIndicesSize, int* returnSize) {
    *returnSize = queryIndicesSize;
    int* length = (int*)malloc(*returnSize * sizeof(int));

    int N = strlen(s);
    tree* st = (tree*)malloc((4*(N+1)) * sizeof(tree));

    build(st, 1, 0, N-1, s);

    for (int i = 0; i < queryIndicesSize; i ++) {
        update(st, 1, 0, N-1, queryIndices[i], queryCharacters[i]);
        length[i] = st[1].value;
    }

    free(st);
    return length;
}

int main() {
    char s[100]; scanf("%s", s);

    int queryIndicesSize; scanf("%d", &queryIndicesSize);
    char queryCharacters[queryIndicesSize]; scanf("%s", queryCharacters);
    int queryIndices[queryIndicesSize];
    for (int i = 0; i < queryIndicesSize; i ++) scanf("%d", &queryIndices[i]);

    printf("ANS: ");
    int dummy = 0;
    int* returnSize = &dummy;
    int* ans = longestRepeating(s, queryCharacters, queryIndices, queryIndicesSize, returnSize);
    for (int i = 0; i < *returnSize; i ++) printf("%d ", ans[i]);

    return 0;
}