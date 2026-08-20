#include <stdio.h>
#include <stdlib.h>
int main() {
    int N; scanf("%d", &N);
    int *a = (int*) calloc(N, sizeof(int));
    if (a == NULL) {
        return 1;
    }
    for (int i = 0; i < N; i ++) {
        *(a+i) = i+1;
        printf("%d ", *(a+i));
    }
    printf("\n");
    for (int i = 0; i < N; i ++) {
        printf("%p\n", &*(a+i));
    }

    int *temp = a;
    a = (int*) realloc(a, 2*N*sizeof(int));
    if (a == NULL) {                         //VẤN
        free(temp);                          //ĐỀ
        temp = NULL;                         //AN
        return 1;                            //TOÀN
    }
    for (int i = 5; i < 2*N; i ++) {
        *(a+i) = 36;
    }
    for (int i = 0; i < 2*N; i ++) {
        printf("%d ", *(a+i));
    }
    printf("\n");
    for (int i = 0; i < 2*N; i ++) {
        printf("%p\n", &*(a+i));
    }
    free(a);
    a = NULL; temp = NULL;
    return 0;

}