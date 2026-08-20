#include <stdio.h>
typedef struct {
    float x;
    float y;
} Diem;

typedef struct {
    Diem tam;
    float banKinh;
} HinhTron;

int main() {
    HinhTron ht;

    printf("Nhap toa do tam hinh tron (x, y): ");
    scanf("%f %f", &ht.tam.x, &ht.tam.y);
    printf("Nhap ban kinh R: ");
    scanf("%f", &ht.banKinh);

    Diem p;
    printf("Nhap toa do diem P (x, y): ");
    scanf("%f %f", &p.x, &p.y);

    float dx = p.x - ht.tam.x;
    float dy = p.y - ht.tam.y;
    float d2 = dx*dx + dy*dy;
    float r2 = ht.banKinh * ht.banKinh;

    printf("Ket qua:\n");
    if (d2 <= r2) {
        printf("Diem (%.2f, %.2f) nam trong hinh tron\n", p.x, p.y);
    }
    else {
        printf("Diem (%.2f, %.2f) nam ngoai hinh tron\n", p.x, p.y);
    }

    return 0;
}