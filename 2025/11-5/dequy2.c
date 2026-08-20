#include <stdio.h>
int max (int a, int b) {
    int max;
    if (a > b) {max = a;}
    else if (a < b) {max = b;}
    else {max = a;}
    return max;
}
int max_leftside_length(int i, int j, int a[]) {
    int vari = i;
    int left_length = 0;
    while (vari < j) {
        if (a[vari] < a[vari+1]) {
            left_length ++;
            vari ++;
        }
        else {break;}
    }
    return left_length + 1;
}
int LENGTH(int i, int j, int a[]) {
    int length = 0;
    if (i == j) {length = 1;}
    else if (i < j) {
        length = max(max_leftside_length(i, j, a), LENGTH(i + max_leftside_length(i, j, a), j, a));
    }
    else {return 1;}
    return length;
}
int main() {
    int N; printf("Nhap N: "); scanf("%d", &N);
    if (N<=0) {printf("Khong ton tai day co do dai <= 0\n"); return 0;}
    int a[N];
    for (int i = 0; i < N; i ++) {
        printf("Nhap a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    int result = LENGTH(0, N-1, a);
    printf("Do dai day con dai nhat la %d\n", result);
    return 0;
}