#include <stdio.h>
#include <string.h>
int main() {
    int N; printf("Nhap so dong: "); scanf("%d", &N);
    getchar();
    char text[N][81];
    for (int i = 0; i < N; i ++) {
        fgets(text[i], 81, stdin);
        text[i][strcspn(text[i], "\n")] = '\0';
    }
    //Yeu cau 1:
    char s[81]; printf("Nhap xau s: "); scanf("%s", s);
    getchar();
    for (int i = 0; i < N; i ++) {
        char *p = strstr(text[i], s);
        while (p) {
            printf("Dong %d cot %d\n", i, p - text[i]);
            p = strstr(++ p, s);
        }
    }
    //Yeu cau 2:
    for (int i = 0; i < N; i ++) {
        char *p = strstr(text[i], "hanoi");
        while (p) {
            strncpy(p, "HANOI", 5);
            p = strstr(++ p, "hanoi");
        }
    }
    //Yeu cau 3 & 4:
    char words[2400][81];
    int frequency[2400] = {0};
    int word_count = 0;
    int total = 0;
    for (int i = 0; i < N; i ++) {
        char temp[81];
        strcpy(temp, text[i]);
        char *token = strtok(temp, " ");
        while (token) {
            total ++;
            int found = 0;
            for (int j = 0; j < word_count; j ++) {
                if (strcmp(token, words[j]) == 0) {
                    frequency[j] ++;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                strcpy(words[word_count], token);
                frequency[word_count ++] ++;
            }
            token = strtok(NULL, " ");
        }
    }
    printf("Tong so tu: %d\nTan suat:\n", total);
    for (int i = 0; i < word_count; i ++) {
        printf("%s: %d\n", words[i], frequency[i]);
    }

    return 0;
}