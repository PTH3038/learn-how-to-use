#include <stdio.h>
#include <string.h>
void backtracking(int OS_index, char *input_string, char *output_string, int size, int used, int k) {
    if (OS_index == k) {
        output_string[k] = '\0';
        printf("%s\n", output_string);
        return;
    }
    for (int i = 0; i < size; i ++) {
        if (!(used & (1<<i))) {
            output_string[OS_index] = input_string[i];
            used |= (1<<i);

            backtracking(OS_index+1, input_string, output_string, size, used, k);

            used &= (1<<i) ^ -1;
        }
    }
}

int main() {
    char input_string[100];
    scanf("%s", input_string);
    int size = strlen(input_string);

    char output_string[100];

    int k;
    scanf("%d", &k);

    backtracking(0, input_string, output_string, size, 0, k);
}