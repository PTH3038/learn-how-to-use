#include <stdio.h>
int main() {
    unsigned long long int N; scanf("%llu", &N);
    if (N%2 == 0 && N != 2) {printf("Không phải là số nguyên tố."); return 0;}
    else if (N == 1) {printf("Không phải là số nguyên tố."); return 0;}
    else if (N == 2) {printf("Là số nguyên tố."); return 0;}
    else {
        for (unsigned long long int i = 3; i*i <= N; i ++) {
            if (N%i == 0) {printf("Không phải là số nguyên tố."); return 0;}
        }
        printf("Là số nguyên tố."); return 0;
    }
}