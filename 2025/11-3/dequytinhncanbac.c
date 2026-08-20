#include <stdio.h>
#include <math.h>
long double ncanbac(int n, int x) {
    long double ans = 0;
    int xmu3 = x*x*x;
    if (n==1) {ans = sqrt(xmu3);}
    else if (n > 1) {
    ans = sqrt(xmu3 + ncanbac(n-1, x));
    }
    return ans;
}


int main() {
    int n, x; scanf("%d %d", &n, &x);
    printf("%.4Lf", ncanbac(n, x));
    return 0;
}