#include <stdio.h>
int C(int k, int N) {
    if (k == 0 || k == N) {
        return 1;
    }
    if (k == 1 || k == N-1) {
        return N;
    }
    int ans = C(k-1, N-1) + C(k, N-1);
    return ans;
}
int main() {
    int N, k; scanf("%d %d", &N, &k);
    printf("%d\n", C(k, N));
    return 0;
}