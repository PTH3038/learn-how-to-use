#include <stdio.h>
#include <string.h>

typedef struct pill {
    char name[20];
    int year;
    int ammount;
    int price;
} pill;

int main() {
    pill a[100] = {0};
    char temp_name[20];
    int index = 0;
    while (1) {
        scanf("%s", temp_name);
        if (strcmp(temp_name, "***") == 0) break;
        
        strcpy(a[index].name, temp_name);
        scanf("%d", &a[index].year);
        scanf("%d", &a[index].ammount);
        scanf("%d", &a[index].price);
        index ++;
    }

    // Yeu cau 1: In danh sach thuoc ra man hinh
    printf("Danh sach thuoc ban dau:\n");
    for (int i = 0; i < index; i++) {
        printf("%s %d %d %d\n", a[i].name, a[i].year, a[i].ammount, a[i].price);
    }
    // Yeu cau 2: In danh sach thuoc het han
    printf("Danh sach thuoc het han:\n");
    for (int i = 0; i < index; i++) {
        if (a[i].year < 2026) {
            printf("%s %d %d %d\n", a[i].name, a[i].year, a[i].ammount, a[i].price);
        }
    }

    // Yeu cau 4: Tinh tong gia tri cac thuoc da het han
    long int tong_gia_tri = 0;
    for (int i = 0; i < index; i++) {
        if (a[i].year < 2026) {
            tong_gia_tri += (long int)a[i].ammount * a[i].price;
        }
    }
    printf("Tong gia tri thuoc da het han: %ld\n", tong_gia_tri);

    // Yeu cau 5: Sap xep danh sach theo nam het han tang dan
    for (int i = 0; i < index - 1; i++) {
        for (int j = i + 1; j < index; j++) {
            if (a[i].year > a[j].year) {
                pill temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    printf("Danh sach thuoc sau khi sap xep theo nam het han:\n");
    for (int i = 0; i < index; i++) {
        printf("%s %d %d %d\n", a[i].name, a[i].year, a[i].ammount, a[i].price);
    }

    // Yeu cau 3: Xoa thuoc het han khoi danh sach
    for (int i = 0; i < index; i++) {
        if (a[i].year < 2026) {
            for (int j = i; j < index - 1; j++) {
                a[j] = a[j + 1];
            }
            index--;
            i--; 
        }
    }
    printf("Danh sach thuoc con dung duoc sau khi xoa:\n");
    for (int i = 0; i < index; i++) {
        printf("%s %d %d %d\n", a[i].name, a[i].year, a[i].ammount, a[i].price);
    }

    return 0;
}