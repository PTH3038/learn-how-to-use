#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node {
    char string[51];
    struct node *next;
} node;
unsigned int hash_function(char* str) {
    unsigned int hash = 0;
    while (*str) {
        hash = (hash * 31) + *str++;
    }
    return hash % 200003;
}   // <-- ham bam nay la gaymini viet
int find(node **bucket, char *str) {
    unsigned int key = hash_function(str);
    node *bucket_check = bucket[key];
    while (bucket_check != NULL) {
        if (strcmp(bucket_check->string, str) == 0) {
            return 1;
        }
        bucket_check = bucket_check->next;
    }
    return 0;
}
int insert(node **bucket, char *str) {
    if (find(bucket, str) == 1) {
        return 0;
    }
    unsigned int key = hash_function(str);
    node *temp = (node *)malloc(sizeof(node));
    strcpy(temp->string, str);
    temp->next = bucket[key];
    bucket[key] = temp;
    return 1;
}
int main () {
    node *bucket[200003] = {0};
    char current[51] = {0};
    while (scanf("%s", current) != EOF) {
        if (strcmp(current, "*") == 0) break;
        insert(bucket, current);
    }
    char command[51] = {0};
    while (scanf("%s", command) != EOF) {
        if (strcmp(command, "***") == 0) break;
        scanf("%s", current);
        if (strcmp(command, "find") == 0) {
            printf("%d\n", find(bucket, current));
        }
        else if (strcmp(command, "insert") == 0) {
            printf("%d\n", insert(bucket, current));
        }
    }
    return 0;

}
