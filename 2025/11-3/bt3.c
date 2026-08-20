#include <stdio.h>
int main()
{
    int even = 0;
    int odd = 0;
    int positive = 0;
    int negative = 0;
    int N; scanf("%d", &N);
    int a[N];
    for (int i = 0; i <= N-1; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i <= N-1; i++) {
        if (a[i]%2 == 0) {even += 1;}
        else {odd += 1;}
        if (a[i] > 0) {positive += 1;}
        else if (a[i] < 0) {negative += 1;}
    }
    printf("Even: %d\n", even);
    printf("Odd: %d\n", odd);
    printf("Positive: %d\n", positive);
    printf("Negative: %d\n", negative);
    return 0;
    
    

}