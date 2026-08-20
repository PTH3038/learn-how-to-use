#include <stdio.h>
#include <stdlib.h>
int V, E;
int u[1000], v[1000], c[1000];

void makeSet(int x, int p[], int r[]) {
    p[x] = x;
    r[x] = 0;
}

int findRoot(int x, int p[]) {
    if (x != p[x]) p[x] = findRoot(p[x], p);
    return p[x]; 
}

void unify(int x, int y, int p[], int r[]) {
    if (r[x] > r[y]) p[y] = x;
    else if (r[x] < r[y]) p[x] = y;
    else {
        p[y] = x;
        r[x] ++;
    }
}

int comparator(const void* a, const void* b) {
    int A = *(int*)a;
    int B = *(int*)b;
    if (c[A] < c[B]) return -1;
    else if (c[A] > c[B]) return 1;
    else {
        if (u[A] < u[B]) return -1;
        else if (u[A] > u[B]) return 1;
        else {
            if (v[A] < v[B]) return -1;
            else if (v[A] > v[B]) return 1;
            else return 0;
        }
    }
}

void swap(int a, int b) {
    int tmp;
    tmp = c[a]; c[a] = c[b]; c[b] = tmp;
    tmp = u[a]; u[a] = u[b]; u[b] = tmp;
    tmp = v[a]; v[a] = v[b]; v[b] = tmp;
}

int partition(int l, int r) {
    int pivot = l;
    int i = l;
    int j = r;
    while (i < j) {
        while (i <= r && comparator(&i, &pivot) < 0) i ++;
        while (l <= j && comparator(&pivot, &j) < 0) j --;

        if (i >= j) break;
        else swap(i ++, j --);
    }
    swap(pivot, j);
    return j;
}

void quickSort(int l, int r) {
    if (l < r) {
        int pivot = partition(l, r);
        quickSort(l, pivot-1);
        quickSort(pivot+1, r);
    }
}

void Kruskal() {
    int p[V+1];
    int r[V+1];
    for (int i = 1; i <= V; i ++) makeSet(i, p, r);

    quickSort(1, E);

    int number_of_edges_in_forest = 0;
    int sum_c = 0;

    for (int i = 1; i <= E; i ++) {
        int r_u = findRoot(u[i], p);
        int r_v = findRoot(v[i], p);
        if (r_u != r_v) {
            unify(r_u, r_v, p, r);

            number_of_edges_in_forest ++;
            sum_c += c[i];

            if (number_of_edges_in_forest == V-1) break;
        }
    }

    printf("%d", sum_c);
}

int main() {
    printf("Numbers of vertices and edges: ");
    scanf("%d %d", &V, &E);

    printf("Insert edges: ");
    for (int i = 1; i <= E; i ++) scanf("%d %d %d", &u[i], &v[i], &c[i]);

    Kruskal();
    return 0;
}