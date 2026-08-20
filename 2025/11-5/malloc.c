#include <stdio.h>
#include <stdlib.h>
int main() {
    int *prt;
    int N; scanf("%d", &N);
    prt = (int*) malloc(N * sizeof(int));
    if (prt == NULL) {
        return 1;
    }
    for (int i = 0; i < N; i ++) {
        prt[i] = i*36;
    }
    for (int i = 0; i < N; i ++) {
        printf("%d\n", prt[i]);
    }
    free(prt);
    prt = NULL;
    return 0;

}