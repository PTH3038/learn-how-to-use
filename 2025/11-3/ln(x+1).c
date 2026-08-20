#include <stdio.h>
#include <math.h>
int main() {
    long double k, e; scanf("%Lf %Lf", &k, &e);
    if( !(0 < k && k <= 2 && 0 < e && e < 1) ) {printf("Error"); return 0;}
    unsigned int n = 1;
    while (e < (long double)fabs(pow(-1, n-1)*pow(k-1, n)/n)) {
        n += 1;
    }
    long double ln = 0;
    for (unsigned int i = 1; i <= n ; i ++) {
        ln += pow(-1, i-1)*pow(k-1, i)/i;
    }
    printf("%.7Lf, %d", ln, n);
    return 0;
        
} 
