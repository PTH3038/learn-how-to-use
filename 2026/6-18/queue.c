#include <stdio.h>
typedef struct Node {
    char label;
    struct Node* next;
} Node;

Node* makeNode(char v) {
    Node* obj = (Node*)malloc(sizeof(Node));
    obj->label = v;
    obj->next = NULL;
    return obj;
}

Node* findLastNode(Node* head) {
    Node* pointer = head;
    while (pointer) {
        if (pointer->next == NULL) return pointer;
        pointer = pointer->next;
    }
    return NULL;
}

Node* enqueue(Node* head, char v) {
    Node* newNode = makeNode(v);
    if (head == NULL) return newNode;
    else {
        Node* lastNode = findLastNode(head);
        lastNode->next = newNode;
        return head;
    }
}

Node* dequeue(Node* head) {
    if (head == NULL) return NULL;
    else {
        Node* temp = head;;
        head = head->next;
        free(temp);
        return head;
    }
}

int main() {}
