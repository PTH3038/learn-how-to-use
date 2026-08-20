#include <stdio.h>
int main () {
    double const a1 = 1678.0;
    double const a2 = 1734.0;
    double const a3 = 2014.0;
    double const a4 = 2536.0;
    double const a5 = 2834.0;
    double money = 0;
    double consumed; scanf("%lf", &consumed);
    if (consumed > 300) {
        money += (consumed - 300)*a5;
        consumed = 300;
    }
    if (consumed > 200) {
        money += (consumed - 200)*a4;
        consumed = 200;
    }
    if (consumed > 100) {
        money += (consumed - 100)*a3;
        consumed = 100;
    }
    if (consumed > 50) {
        money += (consumed - 50)*a2;
        consumed = 50;
    }
    if (consumed > 0) {
        money += (consumed - 0)*a1;
        consumed = 0;
    }
    printf("%.0lf", money);
    return 0;
}