#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 1000

typedef struct {
	char studentID[11];
	char submitDate[11];
	char submitTime[10];
	int result;
    int count;
} LOG;


int readLog(LOG *logArr) {
    char id[11];
    int i = 0;
    while (1) {
        scanf("%s", id);
        if (strcmp(id, "-1") == 0) break;
        strcpy(logArr[i].studentID, id);
        scanf("%s", logArr[i].submitDate);
        scanf("%s", logArr[i].submitTime);
        scanf("%d", &logArr[i ++].result);        
    }
    return i;
}


int numberofSubmits(LOG *logArr, int size) {
    for (int i = 0; i < size; i ++) logArr[i].count = 0;

    int students = 0;
    for (int i = 0; i < size; i ++) {
        if (logArr[i].count == 0) {
            students ++;
        }
        for (int j = 0; j < size; j ++) {
            if (strcmp(logArr[i].studentID, logArr[j].studentID) == 0) {
                logArr[j].count ++;
            }
        }
    }
	return students;
}


char* maximumNumberofSubmitPerStudent(LOG *logArr, int size) {
    for (int i = 0; i < size; i ++) logArr[i].count = 0;

    int max = 0;
    for (int i = 0; i < size; i ++) {
        for (int j = 0; j < size; j ++) {
            if (strcmp(logArr[i].studentID, logArr[j].studentID) == 0) {
                logArr[j].count ++;
            }
        }
        if (logArr[i].count > logArr[max].count) max = i;
    }
	return logArr[max].studentID;
}


void minMaxPoint(LOG *logArr, int size, int* minPoint, int* maxPoint) {
    *minPoint = logArr[0].result;
    *maxPoint = logArr[0].result;
    for (int i = 0; i < size; i ++) {
        if (logArr[i].result > *maxPoint) *maxPoint = logArr[i].result;
        if (logArr[i].result < *maxPoint) *minPoint = logArr[i].result;
    }
}


int getResultofStudentId(LOG *logArr, int size, const char* studentID) {
    int ans = 0;
    for (int i = 0; i < size; i ++) {
        if (strcmp(studentID, logArr[i].studentID) == 0 && ans < logArr[i].result) {
            ans = logArr[i].result;
        }
    }
	return ans;
}


void getStudentResult(LOG *logArr, int size)
{
	char nextStudentID[255];
	while (1)
	{
		fgets(nextStudentID, sizeof(nextStudentID), stdin);
		nextStudentID[strcspn(nextStudentID, "\r\n")] = 0;

		if (strcmp(nextStudentID, "$") == 0) break;

		int result = getResultofStudentId(logArr,size,nextStudentID);
		printf("StudentId %s result %d\n",nextStudentID,result);		
	}
}


int main() {
	LOG* logArr = NULL;
	int size;
	logArr = (LOG*) malloc(MAX_SIZE*sizeof(LOG));
    char nextCommand[100];
    while (1)
    {
        fgets(nextCommand, sizeof(nextCommand), stdin);
        nextCommand[strcspn(nextCommand, "\r\n")] = 0;
        if (strlen(nextCommand) == 0) continue;
        if (nextCommand[0] != '?') break;
        if (strcmp(&nextCommand[2], "readLog") == 0) {
            size = readLog(logArr);
        }
        else if (strcmp(&nextCommand[2], "numberofSubmits") == 0) {
            int numSubmits = numberofSubmits(logArr,size);
            printf("Number of Submits: %d\n",numSubmits);
        }
        else if (strcmp(&nextCommand[2], "maximumNumberofSubmitPerStudent") == 0) {
            char *studentID = maximumNumberofSubmitPerStudent(logArr,size);
            printf("The ID of student who submits the most times: %s\n",studentID);
        }
        else if (strcmp(&nextCommand[2], "minMaxPoint") == 0) {
            int min, max;
            minMaxPoint(logArr, size, &min, &max);
            printf("Point min: %d, max: %d\n", min, max);
        }
        else if (strcmp(&nextCommand[2], "getResultofStudentId") == 0) {
            getStudentResult(logArr, size);
        }
    }

    free(logArr);
    return 0;
}