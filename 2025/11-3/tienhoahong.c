#include <stdio.h>

int main()
{
    long double D; scanf("%Lf", &D);
    if (D <= 10000000) {printf("%.0Lf", D*0);}
    else if (10000000 < D && D <= 25000000) {printf("%.0Lf", D*0.02);}
    else if (25000000 < D && D <= 50000000) {printf("%.0Lf", D*0.05);}
    else {printf("%.0Lf", D*0.08);}
    return 0;

}