#include <stdio.h>
#include <math.h>

int main() {
    double k, e;
    if (scanf("%lf %lf", &k, &e) != 2) return 0;

    if (k <= 0 || k > 2 || e <= 0 || e >= 1) {
        printf("Error\n");
        return 0;
    }

    double x = k - 1.0;
    double ln_k = 0.0;
    double term;
    int n = 1;
    double x_pow_n = x;

    while (1) {
        term = x_pow_n / n;
        
        // 1. Thực hiện cộng số hạng thứ n vào tổng trước
        if (n % 2 != 0) {
            ln_k += term;
        } else {
            ln_k -= fabs(term);
        }

        // 2. Kiểm tra điều kiện dừng sau khi đã cộng
        // Nếu số hạng vừa cộng thỏa mãn <= e thì dừng lại
        if (fabs(term) <= e) {
            break;
        }

        // 3. Chuẩn bị cho số hạng tiếp theo
        n++;
        x_pow_n *= x;
    }

    printf("%.7f\n", ln_k);
    printf("%d\n", n);

    return 0;
}