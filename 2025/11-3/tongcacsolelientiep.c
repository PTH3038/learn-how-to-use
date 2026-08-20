#include <stdio.h>
int main() {
    unsigned short int T; scanf("%hu", &T);
    int a[T];
    for (int i = 0; i < T; i++) {
        a[i] = 0;
        unsigned short int X, Y; scanf("%hu %hu", &X, &Y);
        unsigned short int x, y;
        if (Y < X) {x = Y; y = X;}
        else if (X < Y) {x = X; y = Y;}
        else {a[i] = 0; continue;}
        for (int j = x+1; j <= y-1; j++) {
            if (j%2 != 0) {a[i] += j;}
        }
    }
    for (int i = 0; i < T; i ++) {printf("%d\n", a[i]);}
    return 0;
}