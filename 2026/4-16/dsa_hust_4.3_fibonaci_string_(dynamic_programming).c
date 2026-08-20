#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int strcheck(char* temp, int M, char** forbid) {
    for (int i = 0; i < M; i ++) {
        if (strstr(temp, forbid[i]) != NULL) return 0;
    }
    return 1;
}

char func(char** previous_string, char** current_string, int M, char** forbid, int k) {

    while (strlen(*current_string) <= k) {
        int N1 = strlen(*previous_string);
        int N2 = strlen(*current_string);

        char* temp = (char*)malloc((N1+N2+1) * sizeof(char));
        temp[0] = '\0';
        strcat(temp, *current_string);
        strcat(temp, *previous_string);

        char* another_temp = (char*)realloc(*previous_string, N2+1);
        if (another_temp != NULL) {
            *previous_string = another_temp;
            strcpy(*previous_string, *current_string);
        }

        if (strcheck(temp, M, forbid)) {
            another_temp = (char*)realloc(*current_string, N1+N2+1);
            if (another_temp != NULL) {
                *current_string = another_temp;
                strcpy(*current_string, temp);
            }
        }

        free(temp); 
    }
    return (*current_string)[k];
}

int main() {
    char* s1 = (char*)malloc(101 * sizeof(char));
    char* s2 = (char*)malloc(101 * sizeof(char));
    scanf("%s %s", s1, s2);

    int M; scanf("%d", &M);
    char** forbid = (char**)malloc(M * sizeof(char*));
    for (int i = 0; i < M; i ++) {
        forbid[i] = (char*)malloc(21 * sizeof(char));
        scanf("%s", forbid[i]);
    }

    int k; scanf("%d", &k);

    printf("%c", func(&s1, &s2, M, forbid, k));

    return 0;
}