#include <stdio.h>
unsigned int f(int a) {
    unsigned int so_lan_chia_2 = 0;
    while (a != 0 && (a&1) != 0) {
        so_lan_chia_2 ++;
        a = a >> 1;
    }
    return so_lan_chia_2;
}
int main() {
    unsigned int N; scanf("%u", &N);
    unsigned int a[N];
    for (unsigned int i = 0; i < N; i++) {scanf("%u", &a[i]);}
    unsigned int MAXF = 0;
    for (unsigned int i = 0; i < N; i++) {
        unsigned temp = f(a[i]);
        if (temp > MAXF) {MAXF = temp;}
    }
    printf("%u", MAXF);
    return 0;


}