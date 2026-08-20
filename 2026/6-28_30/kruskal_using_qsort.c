#include <stdio.h>
#include <stdlib.h>
//CTDL bieu dien cay:
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

void Kruskal() {
    //Disjoint set
    int p[V+1];
    int r[V+1];

    for (int i = 1; i <= V; i ++) makeSet(i, p, r);
    
    int edges[E+1];
    for (int i = 1; i <= E; i ++) edges[i] = i;

    qsort(edges+1, E, sizeof(int), comparator);

    int number_of_edges_in_forest = 0;
    int sum_c = 0;

    for (int i = 1; i <= E; i ++) {
        int r_u = findRoot(u[edges[i]], p);
        int r_v = findRoot(v[edges[i]], p);
        if (r_u != r_v) {
            unify(r_u, r_v, p, r);

            number_of_edges_in_forest ++;
            sum_c += c[edges[i]];

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