#include <stdio.h>
int main() {
    long long int a; scanf("%lld", &a);
    if (0 >= a || 10000000000 <= a) {printf("ERROR"); return 0;}
    int S = 0;
    do {
        if (a%2 != 0) {S += a%10;}
        a = a/10;
    } while (a != 0);
    printf("%d", S);


}