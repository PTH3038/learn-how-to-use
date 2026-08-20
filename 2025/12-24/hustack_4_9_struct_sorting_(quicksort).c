#include <stdio.h>
#include <string.h>
typedef struct sv {
    int STT;
    int MSSV;
    double GPA;
} sv;
sv *quick_sort(sv *list, int low, int high) {
    if (low >= high) {
        return list;
    }
    sv pivot = list[low];
    int index = low;
    for (int i = low + 1; i <= high; i ++) {
        if (list[i].GPA < pivot.GPA) continue;
        else if (list[i].GPA == pivot.GPA && list[i].STT > pivot.STT) continue;
        index ++;
        sv temp = list[index];
        list[index] = list[i];
        list[i] = temp;
    }
    sv temp = list[index];
    list[index] = list[low];
    list[low] = temp;
    quick_sort(list, index + 1, high);
    quick_sort(list, low, index - 1);
    return list;
}
int main() {
    sv list[1000];
    for (int i = 0; i < 1000; i ++) {
        list[i].MSSV = 0;
    }
    int i = 0;
    char curr[36];
    char curr2[36];
    while (1) {
        scanf("%s", curr);
        if (strcmp(curr, "#") == 0) break;
        scanf("%s", curr2);
        sscanf(curr,"%d", &list[i].MSSV);
        sscanf(curr2, "%lf", &list[i].GPA);
        list[i].STT = i;
        i ++;
    }
    sv *ans = quick_sort(list, 0, i-1);
    for (int j = 0; j < i; j ++) {
        printf("%d %.1lf\n", ans[j].MSSV, ans[j].GPA);
    }
    return 0;
}