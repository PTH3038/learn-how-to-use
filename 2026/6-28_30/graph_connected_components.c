#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Node {
    int key;
    struct Node* next;
} Node;

Node* makeNode(int v) {
    Node* obj = (Node*)malloc(sizeof(Node));
    obj->key = v;
    obj->next = NULL;

    return obj;
}

Node* findLastNode(Node* head) {
    Node* p = head;
    while (p) {
        if (p->next == NULL) return p;
        p = p->next;
    }
    return NULL;
}

Node* insertLast(Node* head, int v) {
    Node* newNode = makeNode(v);
    if (head == NULL) return newNode;
    else {
        Node* lastNode = findLastNode(head); 
        lastNode->next = newNode;
        return head;
    }
}

void DFS(int u, Node* A[], int C[], int nbCC) {
    C[u] = nbCC;

    Node* p = A[u];
    while (p) {
        if (C[p->key] == -1) {
            DFS(p->key, A, C, nbCC);
        }
        p = p->next;
    }
}

int func(Node* A[], int V, int C[]) {
    int nbCC = 0;
    for (int i = 1; i <= V; i ++) {
        if (C[i] == -1) {
            nbCC ++;
            DFS(i, A, C, nbCC);
        }
    }
    
    return nbCC;
}


typedef struct Queue {
    struct Node* front;
    struct Node* rear;
} Queue;

Queue* makeQueue() {
    Queue* obj = (Queue*)malloc(sizeof(Queue));
    obj->front = NULL;
    obj->rear = NULL;

    return obj;
}

Queue* enqueue(Queue* q, int v) {
    Node* newNode = makeNode(v);
    if (q->front == NULL && q->rear == NULL) {
        q->front = newNode;
        q->rear = newNode;
    }
    else {
        (q->rear)->next = newNode;
        q->rear = newNode;
    }
    return q;
}

int dequeue(Queue* q) {
    if(q->front && q->rear) {
        Node* temp = q->front;
        int return_value = temp->key;

        q->front = (q->front)->next;
        if (q->front == NULL) q->rear = NULL;

        free(temp);
        return return_value;
    }
    else return -1;
}

bool BFS(int u, Node* A[], int depth_bfs[]) {
    Queue* q = makeQueue();

    q = enqueue(q, u);
    depth_bfs[u] = 1;

    while (q->front && q->rear) {
        int stored_value = dequeue(q);

        Node* pointer = A[stored_value];
        while (pointer) {
            if (depth_bfs[pointer->key] == -1) {
                q = enqueue(q, pointer->key);
                depth_bfs[pointer->key] = depth_bfs[stored_value]+1;
            }
            else {
                if ((depth_bfs[stored_value]+depth_bfs[pointer->key]) % 2 == 0) return false;
            }

            pointer = pointer->next;
        }
    }
    return true;
}

void func2(Node* A[], int V) {
    int depth_bfs[V+1];
    for (int i = 1; i <= V; i ++) depth_bfs[i] = -1;  //depth_bfs[i] == -1 => chua dc duyet

    for (int i = 1; i <= V; i ++) {
        if (depth_bfs[i] == -1) {
            if (BFS(i, A, depth_bfs) == false) {
                printf("Bipartite graph: false\n");
                return;
            }
        }
    }
    printf("Bipartite graph: true\n");
}



int main() {
    printf("Numbers of vertices and edges: ");
    int V, E; scanf("%d %d", &V, &E);

    Node* A[V+1];
    for (int i = 1; i <= V; i ++) A[i] = NULL;

    printf("Insert edges: ");
    int u, v;
    for (int i = 0; i < E; i ++) {
        scanf("%d %d", &u, &v);
        A[u] = insertLast(A[u], v);
        A[v] = insertLast(A[v], u);
    }

    int* C = (int*)malloc((V+1)*sizeof(int));
    for (int i = 1; i <= V; i ++) C[i] = -1;    //C[i] == -1 tức là chưa được gán "nhãn liên thông"

    printf("Connected components:\n");
    int nbCC = func(A, V, C);
    for (int i = 1; i <= nbCC; i ++) {
        for (int j = 1; j <= V; j ++) {
            if (C[j] == i) printf("%d ", j);
        }
        printf("\n");
    }

    func2(A, V);
}

