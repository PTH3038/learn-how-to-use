#include <stdio.h>
#include <string.h>

typedef struct Team {
    char name[50];
    int goals_win;
    int goals_loss;
    int yellow_cards;
    int red_cards;
} Team;

int main() {
    Team a[32];
    int n = 32;
    // Yeu cau 1: Nhap du lieu cho 32 doi tu ban phim
    printf("Nhap thong tin cho 32 doi bong:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", a[i].name);
        scanf("%d", &a[i].goals_win);
        scanf("%d", &a[i].goals_loss);
        scanf("%d", &a[i].yellow_cards);
        scanf("%d", &a[i].red_cards);
    }
    // Yeu cau 2: Nhap vao ten doi bong va tim kiem
    char search_name[50];
    int found = 0;
    printf("\nNhap ten doi bong can tim thanh tich: ");
    scanf("%s", search_name);
    for (int i = 0; i < n; i++) {
        if (strcmp(a[i].name, search_name) == 0) {
            printf("Thanh tich cua doi %s: Thang %d - Thua %d, The vang %d, The do %d\n",
                   a[i].name, a[i].goals_win, a[i].goals_loss, a[i].yellow_cards, a[i].red_cards);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Khong tim thay doi bong ten %s\n", search_name);
    }
    // Yeu cau 3: Tinh va dua ra man hinh so diem cua cac doi
    printf("\nBang diem cua cac doi bong:\n");
    printf("%-20s %-10s\n", "Ten doi", "Tong diem");
    for (int i = 0; i < n; i++) {
        int total_points = (a[i].goals_win * 10) 
                         - (a[i].goals_loss * 5) 
                         - (a[i].yellow_cards * 2) 
                         - (a[i].red_cards * 5);
        
        printf("%-20s %-10d\n", a[i].name, total_points);
    }

    return 0;
}