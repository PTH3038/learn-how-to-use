#include <stdio.h>
int main() {
    unsigned short int N, A, B; scanf("%hu %hu %hu", &N, &A, &B);
    if (A > B) {int temp = A; A = B; B = temp;}
    long long int S = 0;
    for (unsigned short int i = 1; i <= N; i++) {
        int current_value = i;
        int tongchuso = 0;
        while (current_value != 0) {
            tongchuso += current_value%10;
            current_value /= 10;
        }
        if (tongchuso >= A && tongchuso <= B) {S += i;}
    }
    printf("%lld", S);
    return 0;
}