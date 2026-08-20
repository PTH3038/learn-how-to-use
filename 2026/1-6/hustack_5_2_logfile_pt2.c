#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 1000
#define MAX_QUESTION_SIZE 10
typedef struct
{
	char studentID[11];
	char questionID[50];
	char submitDate[11];
	char submitTime[10];
	int result;
    int count;
    int STT;
} LOG;

/*Hàm đọc vào danh sách các câu hỏi trong bài thi*/
void readExamDetail(char lstExamQuestions[][50], int* numQuestions)
{
	int index = 0;
	char nextLine[255];
	while (1)
	{
		fgets(nextLine, sizeof(nextLine), stdin);
		nextLine[strcspn(nextLine, "\r\n")] = 0;

		if (strcmp(nextLine, "-1") == 0) break;

		strcpy(lstExamQuestions[index], nextLine);

		index++;
	}
	*numQuestions = index;
}

// Hàm đọc log và lưu vào mảng log logArr
// Hàm trả về số lượng dòng log đọc được qua tên hàm
int readLog(LOG* logArr)
{
	int lineCount = 0;
	char nextLine[255];
	while (1)
	{
		fgets(nextLine, sizeof(nextLine), stdin);
		nextLine[strcspn(nextLine, "\r\n")] = 0;

		if (strcmp(nextLine, "-1") == 0) break;

		// đọc các tham số
		sscanf(nextLine, "%s %s %s %s %d", logArr[lineCount].studentID,
			logArr[lineCount].questionID, logArr[lineCount].submitDate,
			logArr[lineCount].submitTime, &logArr[lineCount].result);

		logArr[lineCount].STT = lineCount ++;
	}
	return lineCount;
}
//============================================================================
// hàm thống kê số lượng sinh viên đã gửi bài dựa trên dữ liệu log từ mảng Log
// số lượng log trong mảng là size 
// logArr là mảng log đã đọc với số lượng log là size
int numberofSubmits(LOG* logArr, int size)
{
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

// hàm tìm và in ra điểm của 1 mã sinh viên dựa trên dữ liệu log từ mảng Log 
// Nếu sinh viên chưa gửi bài thì điểm mặc định là 0
// lstExamQuestions là danh sách ID các bài trong đề thi
// numQuestions là số lượng câu trogn đề thi
// logArr là mảng log đã đọc với số lượng log là size
int getResultofStudentId(char lstExamQuestions[][50], int numQuestions, LOG* logArr, int size, const char* studentID)
{
    int total = 0;
    for (int i = 0; i < numQuestions; i ++) {
        int max = 0;
        for (int j = 0; j < size; j ++) {
            if (strcmp(studentID, logArr[j].studentID) == 0 && 
                strcmp(lstExamQuestions[i], logArr[j].questionID) == 0 &&
                max < logArr[j].result) max = logArr[j].result;
        }
        total += max;
    }
	return total;	
}

/*Hàm in ra chi tiết điểm bài thi của sinh viên gồm
<Mã bài> <Ngày> <Giờ> <Điểm>
Trên mỗi dòng độc lập
Bài nào sinh viên không submit thì bỏ qua
Các bài theo đúng thứ tự ban đầu trong log
Thời gian submit lấy là thời điểm lần đầu gửi bài điểm cao nhất*/
// lstExamQuestions là danh sách ID các bài trong đề thi
// numQuestions là số lượng câu trogn đề thi
// logArr là mảng log đã đọc với số lượng log là size
void printStudentExamDetail(char lstExamQuestions[][50], int numQuestions, LOG* logArr, int size, const char* studentID)
{
    for (int i = 0; i < size; i ++) {
        if (strcmp(logArr[i].studentID, studentID) == 0) {
            int max = -1;
            int firstIndexMax = -1;

            for (int j = 0; j < size; j ++) {
                if (strcmp(logArr[j].studentID, studentID) == 0 && 
                    strcmp(logArr[j].questionID, logArr[i].questionID) == 0 &&
                    logArr[j].result > max) {
                        max = logArr[j].result;
                        firstIndexMax = j;
                }
            }
            if (i == firstIndexMax) {
                printf("%s %s %s %d\n", logArr[i].questionID, 
                                        logArr[i].submitDate, 
                                        logArr[i].submitTime, 
                                        logArr[i].result);
            }
        }
    }
}

/* hàm thống kê và trả về chi tiết số lượng submit cho mỗi bài thi
 in ra dạng
 <mã bài> <số lần submit> <điểm trung bình>
 điểm trung bình lấy đến 2 chữ số thập phân
 nếu bài đó không có submit thì điểm sẽ là 0.00
 thông tin mỗi bài trên 1 dòng theo đúng thứ tự
 // lstExamQuestions là danh sách ID các bài trong đề thi
// numQuestions là số lượng câu trogn đề thi
// logArr là mảng log đã đọc với số lượng log là size
*/
void printSubmitStatistic(char lstExamQuestions[][50], int numQuestions, LOG* logArr, int size)
{
	for (int i = 0; i < numQuestions; i++) {
		int count = 0;
		double sum = 0;
		for (int j = 0; j < size; j++) {
			if (strcmp(logArr[j].questionID, lstExamQuestions[i]) == 0) {
				count++;
				sum += logArr[j].result;
			}
		}
		double avg = (count > 0) ? (sum / count) : 0.00;
		printf("%s %d %.2f\n", lstExamQuestions[i], count, avg);
	}
}



//===========================================
void getStudentResult(char lstExamQuestions[][50], int numQuestions, LOG* logArr, int size)
{
	char nextStudentID[255];
	while (1)
	{
		fgets(nextStudentID, sizeof(nextStudentID), stdin);
		nextStudentID[strcspn(nextStudentID, "\r\n")] = 0;

		if (strcmp(nextStudentID, "$") == 0) break;

		int result = getResultofStudentId(lstExamQuestions, numQuestions, logArr, size, nextStudentID);
		printf("StudentId %s result %d\n", nextStudentID, result);
	}
}
void getStudentSubmitDetail(char lstExamQuestions[][50], int numQuestions, LOG* logArr, int size)
{
	char nextStudentID[255];
	while (1)
	{
		fgets(nextStudentID, sizeof(nextStudentID), stdin);
		nextStudentID[strcspn(nextStudentID, "\r\n")] = 0;

		if (strcmp(nextStudentID, "$") == 0) break;

		printStudentExamDetail(lstExamQuestions, numQuestions, logArr, size, nextStudentID);
	}
}
int main()
{
	char lstExamQuestions[10][50];
	int lstQuestionSize = 0;
	LOG* logArr = NULL;
	int size;
	logArr = (LOG*)malloc(MAX_SIZE * sizeof(LOG));
	char nextCommand[100];
	while (1)
	{
		fgets(nextCommand, sizeof(nextCommand), stdin);
		nextCommand[strcspn(nextCommand, "\r\n")] = 0;
		if (strlen(nextCommand) == 0) continue;
		if (nextCommand[0] != '?') break;
		if (strcmp(&nextCommand[2], "loadLogSubmit") == 0) {
			size = readLog(logArr);
		}
		else if (strcmp(&nextCommand[2], "loadExamQuestions") == 0) {
			readExamDetail(lstExamQuestions, &lstQuestionSize);
			printf("Number of Questions: %d\n", lstQuestionSize);
		}
		else if (strcmp(&nextCommand[2], "numberofSubmits") == 0) {
			printf("Number of submit: %d\n", numberofSubmits(logArr, size));
		}
		else if (strcmp(&nextCommand[2], "getSubmitStatistic") == 0) {
			printSubmitStatistic(lstExamQuestions, lstQuestionSize, logArr, size);
		}
		else if (strcmp(&nextCommand[2], "getStudentResults") == 0) {
			getStudentResult(lstExamQuestions, lstQuestionSize, logArr, size);
		}
		else if (strcmp(&nextCommand[2], "getStudentSubmitDetail") == 0) {
			getStudentSubmitDetail(lstExamQuestions, lstQuestionSize, logArr, size);
		}

	}

	free(logArr);
	return 0;
}