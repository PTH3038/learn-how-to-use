#include <stdio.h>
#include <string.h>

int main() {
    char can[10][10] = {"Giap", "At", "Binh", "Dinh", "Mau", "Ky", "Canh", "Tan", "Nham", "Quy"};
    char chi[12][10] = {"Ty", "Suu", "Dan", "Mao", "Thin", "Ty", "Ngo", "Mui", "Than", "Dau", "Tuat", "Hoi"};

    int year;
    
    scanf("%d", &year);
    if (year < 1 || year > 9999) {
        printf("Khong hop le!");
    }
    else {
        int i_can = (year + 6) % 10; 
        int i_chi = (year + 8) % 12;
        printf("%s %s\n", can[i_can], chi[i_chi]);
    }
    return 0;
}
