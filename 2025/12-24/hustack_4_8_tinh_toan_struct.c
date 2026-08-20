#include <stdio.h>
typedef struct grade {
    int toan;
    int li;
    int hoa;
} grade;
int main() {
    int N; scanf("%d", &N);
    grade a[N];
    for (int i = 0; i < N; i ++) {
        scanf("%d %d %d", &a[i].toan
                        , &a[i].li
                        , &a[i].hoa);
    }
    int avrg_count = 0;
    int zero_count = 0;
    for (int i = 0; i < N; i ++) {
        if ((a[i].toan + a[i].li + a[i].hoa) > 24) avrg_count ++; 
        if (a[i].toan == 0 || a[i].li == 0 || a[i].hoa == 0) zero_count ++;
    }
    printf("%d/%d\n", avrg_count, N);
    printf("%d/%d\n", zero_count, N);
    return 0;
}