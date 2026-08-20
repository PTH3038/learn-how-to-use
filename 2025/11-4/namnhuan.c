#include <stdio.h>
int main() {
    int N; scanf("%d", &N);
    if ((N%4 == 0 && N%100 != 0) || N%400 == 0) {
        printf("%d là năm nhuận.", N);
        return 0;
    }
    printf("%d không phải là năm nhuận.", N);
    return 0;
}