#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Point {
    int row;
    int col;
    int step;
} Point;

typedef struct Node {
    struct Node* next;
    Point coor;
} Node;

Node* makeNode(int r, int c, int s) {
    Node* obj = (Node*)malloc(sizeof(Node));
    obj->coor.row = r;
    obj->coor.col = c;
    obj->coor.step = s;
    obj->next = NULL;
    return obj;
}

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

Queue makeQueue() {
    Queue obj;
    obj.front = NULL;
    obj.rear = NULL;
    return obj;
}

Queue enqueue(Queue q, int r, int c, int s) {
    Node* newNode = makeNode(r, c, s);
    if (q.front == NULL) {
        q.front = newNode;
        q.rear = newNode;
        return q;
    }
    else {
        q.rear->next = newNode;
        q.rear = newNode;

        return q;
    }
}

Queue dequeue(Queue q) {
    if (q.front != NULL) {
        q.front = q.front->next;

        if (q.front == NULL) q.rear = NULL;
        return q;
    }
}

int findPath(int r, int c, int M, int N, int a[M+1][N+1]) {
    int frequency[M+1][N+1];
    for (int i = 1; i <= M ; i ++) {
        for (int j = 1; j <= N; j ++) frequency[i][j] = 0;
    }

    Queue q = makeQueue();
    q = enqueue(q, r, c, 0);
    frequency[r][c] = 1;

    while (q.front && q.rear) {
        Point coor = q.front->coor;
        q = dequeue(q);

            if (coor.row+1 > M || coor.row+1 < 1 || coor.col > N || coor.col < 1) {
                return coor.step+1;
            }
            else if (frequency[coor.row+1][coor.col] == 0 && a[coor.row+1][coor.col] == 0) {
                q = enqueue(q, coor.row+1, coor.col, coor.step+1);
                frequency[coor.row+1][coor.col] = 1;
            }

            if (coor.row-1 > M || coor.row-1 < 1 || coor.col > N || coor.col < 1) {
                return coor.step+1;
            }
            else if (frequency[coor.row-1][coor.col] == 0 && a[coor.row-1][coor.col] == 0) {
                q = enqueue(q, coor.row-1, coor.col, coor.step+1);
                frequency[coor.row-1][coor.col] = 1;
            }

            if (coor.row > M || coor.row < 1 || coor.col+1 > N || coor.col+1 < 1) {
                return coor.step+1;
            }
            else if (frequency[coor.row][coor.col+1] == 0 && a[coor.row][coor.col+1] == 0) {
                q = enqueue(q, coor.row, coor.col+1, coor.step+1);
                frequency[coor.row][coor.col+1] = 1;
            }

            if (coor.row > M || coor.row < 1 || coor.col-1 > N || coor.col-1 < 1) {
                return coor.step+1;
            }
            else if (frequency[coor.row][coor.col-1] == 0 && a[coor.row][coor.col-1] == 0) {
                q = enqueue(q, coor.row, coor.col-1, coor.step+1);
                frequency[coor.row][coor.col-1] = 1;
            }
    }
    return -1;
}

int main() {
    int M, N, r, c; scanf("%d %d %d %d", &M, &N, &r, &c);

    int a[M+1][N+1];
    for (int i = 1; i <= M; i ++) {
        for (int j = 1; j <= N; j ++) scanf("%d", &a[i][j]);
    }

    printf("%d", findPath(r, c, M, N, a));
    return 0;
}