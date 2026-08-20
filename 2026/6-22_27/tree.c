#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node {
    char key;
    struct Node* leftChild;
    struct Node* rightSibling;
} Node;

Node* makeNode(char v) {
    Node* obj = (Node*)malloc(sizeof(Node));
    obj->key = v;
    obj->leftChild = NULL;
    obj->rightSibling = NULL;
}

void preOrder(Node* root) {
    if (root != NULL) {
        printf("%c ", root->key);
        preOrder(root->leftChild);
        preOrder(root->rightSibling);
    }
}

void postOrder(Node* root) {
    if (root != NULL) {
        postOrder(root->leftChild);
        printf("%c ", root->key);
        postOrder(root->rightSibling);
    }
}

void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->leftChild);
        printf("%c ", root->key);

        if (root->leftChild) {
            Node* p = (root->leftChild)->rightSibling;
            while(p) {
                inOrder(p);
                p = p->rightSibling;
            }
        }
    }
}

int depth(Node* root, char x, int root_depth) {
    if (root == NULL) return -1;
    if (root->key == x) return root_depth;

    Node* p = root->leftChild;
    while (p) {
        int x_depth = depth(p, x, root_depth+1);
        if (x_depth > 0) return x_depth;

        p = p->rightSibling;
    }
    return -1;
}

int height(Node* root) {
    if (!root) return 0;

    int root_height = 1;

    Node* p = root->leftChild;
    while(p) {
        int this_child_height = height(p);
        if (root_height < this_child_height + 1) root_height = this_child_height + 1;

        p = p->rightSibling;
    }
    return root_height;
}


int main() {
    Node* root = makeNode('a');
    Node* nb = makeNode('b');
    Node* nc = makeNode('c');
    Node* nd = makeNode('d');
    Node* ne = makeNode('e');
    Node* nf = makeNode('f');
    Node* ng = makeNode('g');
    Node* nh = makeNode('h');
    Node* ni = makeNode('i');
    Node* nj = makeNode('j');

    root->leftChild = nb;
    nb->rightSibling = nc;
    nc->rightSibling = nd;

    nc->leftChild = ne;
    ne->rightSibling = nf;

    nd->leftChild = ng;

    ne->leftChild = nh;
    nh->rightSibling = ni;

    nf->leftChild = nj;

    char command[20];
    printf("Order type: ");
    scanf("%s", &command);
    if (strcmp(command, "preOrder") == 0) preOrder(root);
    else if (strcmp(command, "postOrder") == 0) postOrder(root);
    else if (strcmp(command, "inOrder") == 0) inOrder(root);

    printf("\nNeed to find: ");
    char need_to_find_label;
    scanf(" %c", &need_to_find_label);
    printf("Node's depth: %d\n", depth(root, need_to_find_label, 1));

    printf("Tree' s height: %d\n", height(root));
    return 0;
}
