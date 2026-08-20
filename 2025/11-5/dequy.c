#include <stdio.h>
int max(int a, int b, int c) {
    int max_val = a;
    if (b > max_val) {max_val = b;}
    if (c > max_val) {max_val = c;}
    return max_val;
}

int max_from_mid (int i, int j, int a[]) {
    int mid = i+(j-i)/2;
    int max_right = 0;
    int max_left = 0;
    while (mid < j) {
        if (a[mid] < a[mid+1]) {
            max_right = max_right + 1;
            mid = mid + 1;
        }
        else {break;}
    }
    mid = i+(j-i)/2;
    while (mid > i) {
        if (a[mid] > a[mid-1]) {
            max_left = max_left + 1;
            mid = mid - 1;
        }
        else {break;}
    }
    return (max_right + max_left + 1);
}

int func(int i, int j, int a[]) {
    int MAX_LENGTH = 0;
    int mid = i+(j-i)/2;
    if (i == j) {MAX_LENGTH = 1;}
    else if (i < j) {
        MAX_LENGTH = max(func(i, mid, a), max_from_mid(i, j, a), func(mid+1, j, a));
    }
    else {return 0;}
    return MAX_LENGTH;   
}

int main() {
    int N; printf("Nhap N: "); scanf("%d", &N);
    int a[N];
    for (int i = 0; i < N; i ++) {
        printf("Nhap a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    int kq = func(0, N-1 ,a);
    printf("Do dai day con dai nhat la %d\n", kq);
}