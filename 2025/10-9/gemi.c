#include <stdio.h>

/**
 * Lấy một số nguyên dương (> 0) hợp lệ từ người dùng.
 * Hàm này lặp cho đến khi đầu vào là số nguyên, > 0, và không có ký tự/số thập phân thừa.
 */
int get_positive_integer() {
    int N;
    
    while (1) {
        printf("Nhap so tu nhien N: ");
        
        char next_char;
        
        // Kiểm tra 3 điều kiện:
        // 1. scanf đọc được 2 mục (số %d và ký tự %c).
        // 2. Ký tự tiếp theo là '\n' hoặc ' ' (không phải '.', 'a',...).
        // 3. N > 0 (loại trừ số âm và 0).
        if (scanf("%d%c", &N, &next_char) == 2 && (next_char == '\n' || next_char == ' ') && N > 0) {
            return N; 
        }

        printf("Loi: N phai la so nguyen duong. Vui long nhap lai.\n");
        
        // Dọn dẹp bộ đệm sau khi lỗi xảy ra
        while (getchar() != '\n' && getchar() != EOF); 
    }
}

int main() {
    // Gọi hàm và lưu kết quả vào biến N
    int N = get_positive_integer();
    
    printf("So tu nhien N da nhap hop le la: %d\n", N);

    return 0;
}