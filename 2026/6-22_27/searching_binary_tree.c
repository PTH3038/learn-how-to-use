#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node {
    int key;
    struct Node* leftChild;
    struct Node* rightChild;
} Node;

Node* makeNode(int v) {
    Node* obj = (Node*)malloc(sizeof(Node));
    obj->key = v;
    obj->leftChild = NULL;
    obj->rightChild = NULL;

    return obj;
}

void inOrder(Node* root) {
    if (root) {
        inOrder(root->leftChild);
        printf("%d ", root->key);
        inOrder(root->rightChild);
    }
}

Node* search(Node* root, int target) {
    if (root) {
        if (target < root->key) return search(root->leftChild, target);
        else if (target > root->key) return search(root->rightChild, target);
    }
    return root;
}

Node* findMin(Node* root) {
    if (root) {
        if (root->leftChild != NULL) return findMin(root->leftChild);
    }
    return root;
}

Node* findMax(Node* root) {
    if (root) {
        if (root->rightChild != NULL) return findMax(root->rightChild);
    }
    return root;
}

Node* insert(Node* root, int v) {
    if (root == NULL) root = makeNode(v);

    else if (v > root->key) root->rightChild = insert(root->rightChild, v);
    else root->leftChild = insert(root->leftChild, v);

    return root;
}

Node* delete(Node* root, int x) {
    if (root) {
        if (x < root->key) root->leftChild = delete(root->leftChild, x);
        else if (x > root->key) root->rightChild = delete(root->rightChild, x);
        else {
            if (root->leftChild && root->rightChild) {
                Node* successor = findMin(root->rightChild);

                root->key = successor->key;
                delete(root->rightChild, successor->key);
            }
            else {
                Node* temp = root;

                if (root->leftChild == NULL) root = root->rightChild;
                else if (root->rightChild == NULL) root = root->leftChild;

                free(temp);
            }
        }
    }
    return root;
}

int main() {
    char command[100];
    int x;
    Node* root = NULL;
    Node* p = NULL;
    while(1) {
        scanf("%s", command);
        if (strcmp("#", command) == 0) break;
        else if (strcmp("insert", command) == 0) {
            scanf("%d", &x);
            root = insert(root, x);
        }
        else if (strcmp("delete", command) == 0) {
            scanf("%d", &x);
            root = delete(root, x);
        }
        else if (strcmp("inOrder", command) == 0) {
            inOrder(root);
        }
        else if (strcmp("search", command) == 0) {
            scanf("%d", &x);
            p = search(root, x);
            if (p) printf("Found!\n");
            else printf("Not found!\n");
        }
        else if (strcmp("findMin", command) == 0) {
            p = findMin(root);
            if (p) printf("Found min: %d\n", p->key);
            else printf("Not found min!\n");
        }
        else if (strcmp("findMax", command) == 0) {
            p = findMax(root);
            if (p) printf("Found max: %d\n", p->key);
            else printf("Not found max!\n");
        }
    }
    return 0;
}
