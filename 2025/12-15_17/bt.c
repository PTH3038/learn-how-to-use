#include <stdio.h>
#include <math.h>
int main() {
    int N; scanf("%d", &N);
    if (N <= 0 || N > 100) {
        printf("ERROR");
        return 0;
    }
    double x[N+1], y[N+1];
    for (int i = 1; i <= N; i ++) {
        scanf("%lf", &x[i]);
    }
    for (int i = 1; i <= N; i ++) {
        scanf("%lf", &y[i]);
    }
    double a = 0, b2 = 0, c = 0;
    for (int i = 1; i <= N; i ++) {
        a += cos(x[i])*sin(y[i]);
        b2 += (x[i] - y[i])*(x[i] - y[i]);
        if (i < N) {
            c += pow(x[2], i+1) * y[i+1];
        }
    }
    printf("a = %lf\nb = %lf\nc = %lf\n", a, sqrt(b2), c);
    return 0;
}