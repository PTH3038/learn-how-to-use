#include <stdio.h>
int main() {
    int N; scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        if (i == (N+1)/2) {
            for (int j = 1; j <= N; j++) {
                if (j == i) {printf("X");}
                else {printf("*");}
            }
        }
        else {
            for (int j = 1; j <= N; j++) {
                if (j == i) {printf("\\");}
                else if (j == N-i+1) {printf("/");}
                else {printf("*");}
            }
        }
        printf("\n");
    }
    return 0;
}