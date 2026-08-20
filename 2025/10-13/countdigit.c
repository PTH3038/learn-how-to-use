#include <stdio.h>
int main () {
    unsigned long long int n; printf("Nhap N: "); scanf("%llu", &n);
    int count=0;
    if (n==0) {printf("So vua nhap co %d chu so\n", ++count); return 0;}
    while (n!=0) {
        count ++;
        n=n/10;
    }
    printf("So vua nhap co %d chu so\n", count);
    return 0;
}