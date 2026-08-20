#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct vector {
    char **data;       //chứa các từ
    int size;         //số lượng các từ
    int capacity;    //dung lượng để so sánh với size
} vector;
//
vector *init_vector() {
    vector *v = (vector *)malloc(sizeof(vector));
    if (v == NULL) {
        exit(1);
    }
    v->size = 0;
    v->capacity = 4;
    v->data = (char **)malloc(v->capacity * sizeof(char *));
    if (v->data == NULL) {
        printf("ERROR");
        exit(1);
    }
    return v;
}
//
void push_back(vector *v, char *str) {
    if (v->size >= v->capacity) {
        v->capacity *= 2;
        char **temp_data = (char **)realloc(v->data, v->capacity * sizeof(char *));
        if (temp_data == NULL) {
            printf("ERROR");
            exit(1);
        }
        v->data = temp_data;
    }
    v->data[v->size] = strdup(str);
    if (v->data[v->size] == NULL) {
        printf("ERROR");
        exit(1);
    }
    v->size ++;
}
//
void free_vector(vector *v) {
    for (int i = 0; i < v->size; i ++) {
        free(v->data[i]);
    }
    if (v->data != NULL) {
        free(v->data);
    }
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
    free(v);
}
//
//
//
char *get_key(char *str) {
    int count[256] = {0};
    for (int i = 0; str[i] != '\0'; i ++) {
        count[(unsigned char)str[i]] ++;
    }
    //
    //
    //
    char *key = (char *)malloc(1300);
    if (key == NULL) {
        return NULL;
    }
    char *current_ptr = key;
    for (int i = 0; i < 256; i ++) {
        int add = snprintf(current_ptr, 1300 - (current_ptr - key), "%d ", count[i]);
        current_ptr += add;
    }
    *current_ptr = '\0';
    return key;
}
//
//
//
typedef struct node {
    char *key;
    vector *value;
    struct node *next;
} node;
//
void free_node(node *v) {
    free(v->key);
    v->key = NULL;
    free_vector(v->value);
    v->value = NULL;
    if (v->next != NULL) {
        free_node(v->next);
        v->next = NULL;
    }
    free(v);
}
//
//
//
typedef struct {
    node **bucket;
} map;
//
map *init_map() {
    map *m = (map *)malloc(sizeof(map));
    if (m == NULL) {
        exit(1);
    }
    m->bucket = (node **)calloc(10007, sizeof(node *));
    if (m->bucket == NULL) {
        exit(1);
    }
    return m; 
}
void free_map(map *m) {
    for (int i = 0; i < 10007; i ++) {
        if (m->bucket[i] != NULL) {
            free_node(m->bucket[i]);
        }
    }
    free(m->bucket);
    free(m);
}
//
//
//
unsigned int hash_function(char *str) {
    unsigned int hash = 5381;
    int c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; 
    }
    return hash % 10007; // 10007 là kích thước bucket bạn đã chọn
}
//
//
//
vector *get_or_create(char *key, map *hash_map) {
    unsigned int index = hash_function(key);
    node *current = hash_map->bucket[index];
    while (current != NULL) {
        if (strcmp(key, current->key) == 0) {
            return current->value; 
        }
        current = current->next;
    }
    node *new_node = (node *)malloc(sizeof(node));
    new_node->key = strdup(key);
    new_node->value = init_vector();
    //
    new_node->next = hash_map->bucket[index];
    hash_map->bucket[index] = new_node;
    //
    return new_node->value;
}
char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    map *hash_map = init_map();
    for (int i = 0; i < strsSize; i ++) {
        char *key = get_key(strs[i]);
        vector *v = get_or_create(key, hash_map); //hàm k chỉ return mà còn cập nhật hashmap
        push_back(v, strs[i]);
        free(key); //hàm get_key k có free tự động
    }
    //
    //
    //
    *returnSize = 0;
    for (int i = 0; i < 10007; i ++) {
        node *ptr = hash_map->bucket[i];
        while (ptr) {
            (*returnSize) ++;
            ptr = ptr->next;
        }
    }
    char ***result = (char ***)malloc((*returnSize)*sizeof(char **));
    *returnColumnSizes = (int *)malloc((*returnSize)*sizeof(int));
    int idx = 0; // Biến này để đếm xem mình đang đổ đến nhóm thứ mấy
    for (int i = 0; i < 10007; i++) {
        node *curr = hash_map->bucket[i];
        while (curr) { // Duyệt danh sách liên kết trong mỗi bucket
            // A. Ghi lại số lượng từ của nhóm này
            (*returnColumnSizes)[idx] = curr->value->size;

            // B. Cấp phát chỗ chứa cho các từ trong nhóm hiện tại
            result[idx] = (char **)malloc(curr->value->size * sizeof(char *));

            // C. Chép từng từ từ Vector vào khay kết quả
            for (int j = 0; j < curr->value->size; j++) {
                result[idx][j] = strdup(curr->value->data[j]);
            }

            idx++; // Xong một nhóm, tăng index để chuẩn bị cho nhóm tiếp theo
            curr = curr->next;
        }
    }

    
    return result;
}
