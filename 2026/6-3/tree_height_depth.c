#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int label;
    struct Node* rightSibling;
    struct Node* leftChild;
} Node;

Node* makeNode(int v) {
    Node* obj = (Node*)malloc(sizeof(Node));
    obj->label = v;
    obj->leftChild = NULL;
    obj->rightSibling = NULL;
    return obj;
}

int height(Node* r) {
    if (r == NULL) return 0;

    int ANS = 0;

    Node* p = r->leftChild;
    while(p) {
        int current_height = height(p);
        ANS = (ANS > current_height) ? ANS : current_height;

        p = p->rightSibling;
    }

    return ANS+1;
}

int depth(Node* r, int v, int d) {
    if (r == NULL) return -1;
    if (r->label == v) return d;

    Node* p = r->leftChild;
    while(p) {
        int current_depth = depth(p, v, d+1);       
        if (current_depth > 0) return current_depth;

        p = p->rightSibling;
    }

    return -1;
}

int main() {
    // Tạo các nút
    Node* root = makeNode(7);
    Node* n3 = makeNode(3);
    Node* n10 = makeNode(10);
    Node* n4 = makeNode(4);
    
    // Liên kết tầng 1
    root->leftChild = n3;
    n3->rightSibling = n10;
    n10->rightSibling = n4;
    
    // Con của 3
    Node* n8 = makeNode(8);
    Node* n12 = makeNode(12);
    n3->leftChild = n8;
    n8->rightSibling = n12;
    
    // Con của 8
    Node* n6 = makeNode(6);
    Node* n5 = makeNode(5);
    n8->leftChild = n6;
    n6->rightSibling = n5;
    
    // Con của 12
    Node* n1 = makeNode(1);
    n12->leftChild = n1;
    
    // Con của 6
    Node* n9 = makeNode(9);
    n6->leftChild = n9;
    
    // Con của 4
    Node* n11 = makeNode(11);
    Node* n2 = makeNode(2);
    n4->leftChild = n11;
    n11->rightSibling = n2;

    // Kiểm tra kết quả
    printf("Do cao cua nut 3: %d\n", height(n3));
    printf("Do cao cua nut 8: %d\n", height(n8));
    printf("Do cao cua nut 6: %d\n", height(n6));
    printf("Do cao cua toan bo cay: %d\n", height(root));

    printf("Do sau cua nut 3: %d\n", depth(root, 3, 1));
    printf("Do sau cua nut 8: %d\n", depth(root, 8, 1));
    printf("Do sau cua nut 6: %d\n", depth(root, 6, 1));
    return 0;
}
ABCXYZ