#include <stdio.h>
int main() {
    short int T; scanf("%hu", &T);
    int a[T];
    for (int i = 0; i < T; i++) {scanf("%d", &a[i]);}
    for (int i = 0; i < T; i++) {
        int B[10];
        int j = 0;
        if (a[i] == 0) {
            printf("0\n");
            continue;
        }    
        while (a[i] != 0) {
            B[j] = a[i]%10;
            a[i] = a[i]/10;
            j++;
        }
        for (int k = j - 1; k >= 0; k -= 1) {
            printf("%d ", B[k]);
        }
        printf("\n");
    }
    return 0;
}