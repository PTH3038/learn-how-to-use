    #include <stdio.h>
    int main() {
        long long int N; scanf("%lld", &N);
        if (N <= 0) {printf("Error"); return 0;}
        long long int count = 0;
        long long int S = 0;
        for (long long int i = 1; i*i <= N; i ++) {
            if ( N%i == 0) {
                count += 1;
                if (i%5 != 0 && i%3 == 0) {S += i;}
                long long int j = N/i;
                if (j != i) {
                    count += 1;
                    if (j%5 != 0 && j%3 ==0) {S += j;}
                }
            }
        }
        printf("%lld\n", count);
        printf("%lld", S);
        return 0;
        


    }