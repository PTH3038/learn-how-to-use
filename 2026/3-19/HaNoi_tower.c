#include <stdio.h>
int HaNoiTower(int N, int start, int middle, int end) {
    if (N == 1) {
        printf("%d -> %d\n", start, end);
        return 1;
    }
    else {
        int di_chuyen_n_tru_mot_thg_dau_tien = HaNoiTower(N-1, start, end, middle);
        int di_chuyen_thg_to_nhat_bi_bo_lai_o_day = HaNoiTower(1, start, middle, end);
        int di_chuyen_n_tru_mot_thg_kia_ve_dich = HaNoiTower(N-1, middle, start, end);
        return di_chuyen_n_tru_mot_thg_dau_tien + di_chuyen_thg_to_nhat_bi_bo_lai_o_day + di_chuyen_n_tru_mot_thg_kia_ve_dich;
    }
} 
int main() {
    int N; scanf("%d", &N);
    printf("%d", HaNoiTower(N, 1, 2, 3));
    return 0;
}