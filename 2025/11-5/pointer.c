#include <stdio.h>
int main() {
    int num1, num2; scanf("%d %d", &num1, &num2);
    printf("%d %d\n%p\n%p\n", num1, num2, &num1, &num2);
    int* n1 = &num1;
    int* n2 = &num2;
    int temp = *n1; *n1 = *n2; *n2 = temp;
    printf("%d %d\n%p\n%p\n", num1, num2, &num1, &num2);
    return 0;
}