#include <stdio.h>
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
int main() {
    int N;
    while (1) {
        printf("Nhap so tu nhien N: ");
        if (scanf("%d", &N) == 1) {
            if (N > 0) {           
                int c = getchar();
                if (c == '\n' || c == EOF) {
                    break;
                } else {
                    printf("N phai la so nguyen duong. Vui long khong nhap ky tu/so thap phan thua.\n");
                    clear_input_buffer();
                }
            } else {
                printf("N phai la so tu nhien (lon hon 0).\n");
                clear_input_buffer();
            }
        } else {
            printf("N phai la so nguyen duong. Vui long chi nhap so.\n");
            clear_input_buffer();
        }
    }
    printf("N = %d\n", N);
    return 0;
}