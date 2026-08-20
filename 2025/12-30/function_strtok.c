#include <stdio.h>
#include <string.h>
char *func(char *str, const char* delim) {
    static char *last = NULL;
    // 1) Khoi tao
    if (str != NULL) {
        last = str;
    }
    // 2) Neu mang rong ngay tu dau, loai
    if (last == NULL || *last == '\0') return NULL;
    // 3) Loai bo ki tu thua o dau
    while (*last != '\0' && strchr(delim, *last) != NULL) last ++;
    // 3.1) Neu sau cac ki tu loai bo la mang rong, loai
    if (*last == '\0') return NULL;
    // 4) Quet tu diem bat dau "chinh thuc" den khi gap ki tu phan cach
    char *start = last;
    while (*last != '\0') {
        if (strchr(delim, *last) != NULL) {
            *last = '\0';
            last ++;
            return start;
        }
        last ++;
    }
    return start;
}
int main() {
    char str[36] = "rauma/basau/dm/";
    char *ans = func(str, "/");
    while (ans != NULL) {
        printf("%s\n", ans);
        ans = func(NULL, "/");
    }
    return 0;
}
