#include <stdio.h>
int main() {
    unsigned short int T; scanf("%hu", &T);
    unsigned short int ans[T];
    for (int i = 0; i < T; i ++) {
        // nhap day
        unsigned short int M, N; scanf("%hu %hu", &M, &N);
        long double a[M], b[N];
        for (int j = 0; j < M; j ++) {scanf("%Lf", &a[j]);}
        for (int j = 0; j < N; j ++) {scanf("%Lf", &b[j]);}
        //kiem tra dieu kien
        if (M != N) {ans[i] = 0;}
        else {
            ans[i] = 1;
            for (int j = 0; j < M; j++) {if (a[j] != b[j]) {ans[i] = 0; break;}}
        }
    }
    for (int i = 0; i < T; i ++) {printf("%hu\n", ans[i]);}
    return 0;
}