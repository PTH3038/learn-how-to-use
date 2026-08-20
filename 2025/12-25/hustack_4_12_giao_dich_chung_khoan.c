#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct trade {
    char key[20];
    char seri[10];
    int ammount;
    float price;
    char sell[5];
    int STT;
} trade;
int compare_trade(const void *a, const void *b) {
    const trade *t1 = (const trade *)a;
    const trade *t2 = (const trade *)b;

    float val1 = t1->ammount * t1->price;
    float val2 = t2->ammount * t2->price;

    if (val1 < val2) return -1;
    if (val1 > val2) return 1;
    if (t1->STT < t2->STT) return -1;
    if (t1->STT > t2->STT) return 1;

    return 0;
}
int main() {
    int N; scanf("%d", &N);
    trade a[N];
    for (int i = 0; i < N; i ++) {
        scanf("%s %s %d %f %s",  a[i].key
                              ,  a[i].seri
                              , &a[i].ammount
                              , &a[i].price
                              ,  a[i].sell);
        a[i].STT = i;
    }
    char command[20], serial[10];
    while (1) {
        scanf("%s", command);
        if (strcmp(command, "#") == 0) break;
        if (strcmp(command, "timKiemGiaoDichTheoMaCoPhieu") == 0) {
            scanf("%s", serial);
            for (int i = 0; i < N; i ++) {
                if (strcmp(serial, a[i].seri) == 0) {
                    printf("%s %s %d %.2f %s\n", a[i].key
                                               , a[i].seri
                                               , a[i].ammount
                                               , a[i].price
                                               , a[i].sell);
                }
            }
        }
        if (strcmp(command, "sapXepTheoTongGiaTri") == 0) {
            qsort(a, N, sizeof(trade), compare_trade);
            for (int i = N-1; i >= 0; i --) {
                printf("%s %s %d %.2f %s\n", a[i].key
                                           , a[i].seri
                                           , a[i].ammount
                                           , a[i].price
                                           , a[i].sell);
            }
        }
        float tong_mua = 0, tong_ban = 0;
        if (strcmp(command, "tinhTongSoCoPhieuMuaBanTheoMa") == 0) {
            scanf("%s", serial); 
            for (int i = 0; i < N; i ++) {
                if (strcmp(serial, a[i].seri) == 0) {
                    if (strcmp(a[i].sell, "Ban") == 0) {
                        tong_ban += a[i].ammount;
                    }
                    else {
                        tong_mua += a[i].ammount;
                    }
                }
            }
            printf("%.0f %.0f\n", tong_mua, tong_ban);
        }
        else if (strcmp(command, "timGiaoDichGiaTriCaoNhat") == 0) {
            if (N > 0) {
                int max_idx = 0;
                float max_val = a[0].ammount * a[0].price;
                for (int i = 1; i < N; i++) {
                    if (a[i].ammount * a[i].price > max_val) {
                        max_val = a[i].ammount * a[i].price;
                        max_idx = i;
                    }
                }
                printf("%s %s %d %.2f %s %.2f\n", a[max_idx].key
                                                , a[max_idx].seri
                                                , a[max_idx].ammount
                                                , a[max_idx].price
                                                , a[max_idx].sell
                                                , max_val);
            }
        }
    }
    return 0;
}
