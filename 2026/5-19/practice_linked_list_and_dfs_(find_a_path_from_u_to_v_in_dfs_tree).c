#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    struct node* next;
    char label;
} node;

node* makeNode(char c) {
    node* obj = (node*)malloc(sizeof(node));
    obj->label = c;
    obj->next = NULL;
    return obj;
}

node* findlastNode(node* head) {
        node* p = head;
        
        while (p) {
            if (p->next == NULL) return p;
            p = p->next;
        }
        return NULL;
}

node* insertLast(node* head, char c) {
    node* newNode = makeNode(c);
    if (head == NULL) return newNode;
    else {
        node* lastNode = findlastNode(head);
        lastNode->next = newNode;
        return head;
    }
}

char pre[256] = {0};
int visited[256] = {0};
void DFS(char u, node** adj, int N) {
    visited[u] = 1;
    for (int i = 0; i < N; i ++) {
        if (adj[i]->label == u) {
            node* pointer = adj[i];
            while (pointer) {
                if (visited[pointer->label] == 0) {
                    pre[pointer->label] = u;
                    DFS(pointer->label, adj, N);
                }

                pointer = pointer->next;
            }
        }
    }   
}

int main() {
    int N; scanf("%d", &N);

    node** adj = (node**)malloc(N*sizeof(node*));
    for (int i = 0; i < N; i ++) adj[i] = NULL;

    for (int i = 0; i < N; i ++) {
        char temp;
        scanf(" %c", &temp);

        while (temp != '#') {
            adj[i] = insertLast(adj[i], temp);
            scanf(" %c", &temp);
        }
    }

    char u, v;
    scanf(" %c %c", &u, &v);

    DFS(u, adj, N);
    
    if (visited[v] = 1) {
        printf("Path found! Path is: %c <- ", v);
        while (pre[v] != u) {
            printf("%c <- ", pre[v]);
            v = pre[v];
        }
        printf("%c\n", u);
    }
    else printf("Path not found!\n");

    return 0;
}