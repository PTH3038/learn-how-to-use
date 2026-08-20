#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct logfile {
    char *day;
    char *time;
    char *designator;
    char *infor;
    char *infor2;
} logfile;
logfile *init() {
    logfile *obj = (logfile *)malloc(sizeof(logfile));
    obj->day = (char *)malloc(12*sizeof(char));
    obj->time = (char *)malloc(10*sizeof(char));
    obj->designator = (char *)malloc(9*sizeof(char));
    obj->infor = (char *)malloc(50*sizeof(char));
    obj->infor2 = (char *)malloc(210*sizeof(char));
    return obj;
}
int main() {
    int N; scanf("%d", &N);
    logfile *obj[N];
    for (int i = 0; i < N; i ++) {
        obj[i] = init();
        scanf("%s %s %s %s %s", obj[i]->day,
                                obj[i]->time,
                                obj[i]->designator,
                                obj[i]->infor,
                                obj[i]->infor2);
    }
    //
    //
    //
    int found = 0;
    for (int i = 0; i < N; i++) {
        char *ptr_longitude = strstr(obj[i]->infor2, "\"longitude\":");
        char *ptr_latitude = strstr(obj[i]->infor2, "\"latitude\":");
        if (ptr_longitude != NULL && ptr_latitude != NULL) {
            double lon, lat;
            sscanf(ptr_longitude + 12, "%lf", &lon);
            sscanf(ptr_latitude + 11, "%lf", &lat);
            if (lon != 0.0 && lat != 0.0) {
                printf("%s %s %s\n", obj[i]->day, obj[i]->time, obj[i]->designator);
                found = 1;
                break;
            }
        }
    }
    if (!found) {
        printf("01/01/1970 00:00:00 AM\n");
    }
}