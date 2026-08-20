#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int label;
    struct node* next;
} node;

node* makeNode(int v) {
    node* obj = (node*)malloc(sizeof(node));
    obj->label = v;
    obj->next = NULL;
    return obj;
}

node* insertFirst(node* head, int v) {
    node* new_node = makeNode(v);
    if (head == NULL) return new_node;
    else {
        new_node->next = head;
        head = new_node;
        return head;
    }
}

node* findLastNode(node* head) {
    node* pointer = head;
    while(pointer) {
        if (pointer->next == NULL) return pointer;
        pointer = pointer->next;
    }
    return NULL;
}

node* insertLast(node* head, int v) {
    node* new_node = makeNode(v);
    if (head == NULL) return new_node;
    else {
        node* last_node = findLastNode(head);
        last_node->next = new_node;
        return head;
    }
}

node* findBeforeNode(node* head, int v) {
    node* pointer = head;
    while (pointer && pointer->next) {
        if ((pointer->next)->label == v) return pointer;
        pointer = pointer->next;
    }
    return NULL;
    // => nếu hàm return NULL chỉ có 3 trường hợp: head == NULL,
    //hoặc không tồn tại node có label là v
    //hoặc node có label là v chính là node head,
}

node* insertBefore(node* head, int u, int v) {
    node* before_node = findBeforeNode(head, v);
    node* new_node = makeNode(u);
    if (before_node == NULL) {
        new_node->next = head;
        head = new_node;
        return head;
    }
    else {
        new_node->next = before_node->next;
        before_node->next = new_node;
        return head;
    }
}

node* findAfterNode(node* head, int v) {
    node* pointer = head;
    while (pointer) {
        if (pointer->label == v) return pointer;
        pointer = pointer->next;
    }
    return NULL;
    // => hàm chỉ return NULL trong 2 trường hợp: hoặc là head == NULL
    // hoặc là không tồn tại node có label là v
}

node* insertAfter(node* head, int u, int v) {
    node* after_node = findAfterNode(head, v);
    node* new_node = makeNode(u);

    new_node->next = after_node->next;
    after_node->next = new_node;
    return head;
}

node* removeNode(node* head, int u) {
    node* before_node = findBeforeNode(head, u);
    if (before_node == NULL) {
        return head->next;
    }
    else {
        node* temp = before_node->next;

        before_node->next = (before_node->next)->next;

        free(temp);
        return head;
    }
}

node* reverse(node* head) {
    node* curr = head;
    node* next = NULL;
    node* pre = NULL;

    while (curr) {
        next = curr->next; //lưu trữ current next
        curr->next = pre;
        pre = curr; //lưu trữ current
        curr = next;
    }

    return pre;
}

int main() {
    int N; scanf("%d", &N);

    int array[N];
    for (int i = 0; i < N; i ++) scanf("%d", &array[i]);

    int frequency[1001] = {0};

    node* head = NULL;
    for (int i = 0; i < N; i ++) {
        head = insertLast(head, array[i]);
        frequency[array[i]] ++;
    }

    char command[100];
    int u;
    int v;
    while (1) {
        scanf("%s", command);

        if (strcmp(command, "#") == 0) break;

        else if (strcmp(command, "addfirst") == 0) {
            scanf("%d", &u);

            if (frequency[u] == 0) {
                head = insertFirst(head, u);
                frequency[u] ++;
            }
        }

        else if (strcmp(command, "addlast") == 0) {
            scanf("%d", &u);

            if (frequency[u] == 0) {
                head = insertLast(head, u);
                frequency[u] ++;
            }
        }

        else if (strcmp(command, "addbefore") == 0) {
            scanf("%d", &u);
            scanf("%d", &v);
            if (frequency[u] == 0 && frequency[v] != 0) {   
                head = insertBefore(head, u, v);
                frequency[u] ++;
            }
        }

        else if (strcmp(command, "addafter") == 0) {
            scanf("%d", &u);
            scanf("%d", &v);
            if (frequency[u] == 0 && frequency[v] != 0) {   
                head = insertAfter(head, u, v);
                frequency[u] ++;
            }
        }

        else if (strcmp(command, "remove") == 0) {
            scanf("%d", &u);
            if (frequency[u] != 0) {
                head = removeNode(head, u);
                frequency[u] = 0;
            }
        }

        else if (strcmp(command, "reverse") == 0) {
            head = reverse(head);
        }
    }

    node* pointer = head;
    while (pointer) {
        printf("%d ", pointer->label);
        node* temp = pointer; 

        pointer = pointer->next;

        free(temp);
    }

    return 0;
}