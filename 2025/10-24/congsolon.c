#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Hàm đảo ngược chuỗi (cần thiết cho phép cộng từ phải sang trái)
void reverse(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// Hàm thực hiện phép cộng
// Lưu ý: Đây là mã mẫu, cần được tối ưu và kiểm tra cẩn thận trong môi trường thi
void big_sum(char* a, char* b, char* result) {
    reverse(a);
    reverse(b);
    
    int n1 = strlen(a);
    int n2 = strlen(b);
    int max_len = (n1 > n2 ? n1 : n2);
    int carry = 0;
    int k = 0; // Index cho chuỗi kết quả

    for (int i = 0; i < max_len; i++) {
        // Lấy giá trị chữ số (hoặc 0 nếu chuỗi ngắn hơn)
        int d1 = (i < n1) ? (a[i] - '0') : 0;
        int d2 = (i < n2) ? (b[i] - '0') : 0;

        int sum = d1 + d2 + carry;
        
        result[k++] = (sum % 10) + '0'; // Lưu chữ số cuối cùng của tổng
        carry = sum / 10;                // Tính số nhớ
    }

    if (carry) {
        result[k++] = carry + '0'; // Lưu số nhớ cuối cùng
    }
    
    result[k] = '\0'; // Kết thúc chuỗi
    reverse(result); // Đảo ngược kết quả trở lại
}

int main() {
    // Độ dài tối đa của 10^19 là 20 ký tự (20 chữ số).
    // Tổng 2 * 10^19 tối đa là 21 ký tự (21 chữ số).
    // Ta chọn kích thước mảng đủ lớn, ví dụ 30
    char s_a[30], s_b[30], s_sum[30];

    // Đọc input dưới dạng chuỗi (cần đảm bảo không có khoảng trắng dư thừa)
    if (scanf("%s %s", s_a, s_b) != 2) return 1;

    big_sum(s_a, s_b, s_sum);

    printf("%s\n", s_sum);

    return 0;
}