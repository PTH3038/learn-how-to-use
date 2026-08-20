#include <stdio.h>
int main() {
    double a[12];
    for (int i = 1; i <= 12; i ++) {
        printf("Nhap so: ");
        scanf("%lf", &a[i]);
    }
    for (int i = 0; i < 12; i += 4) {
        if (i != 4) {printf("|%6.0lf%6.0lf| |%6.0lf%6.0lf|\n", a[i], a[i+1], a[i+2], a[i+3]);}
        else {printf("|%6.0lf%6.0lf|*|%6.0lf%6.0lf|\n", a[i], a[i+1], a[i+2], a[i+3]);}
    }
}