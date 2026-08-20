#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct data {
    char firstName[100];
    char middleName[100];
    char lastName[100];
    char classNumber[10];
    char MSSV[10];
    double grade;
    double drl;
} data;

int comparator(const void* a, const void* b) {
    double a_grade = (*(data**)a)->grade;
    double b_grade = (*(data**)b)->grade;
    if (a_grade > b_grade) return -1;
    else if (a_grade < b_grade) return 1;
    else {
        double a_drl = (*(data**)a)->drl;
        double b_drl = (*(data**)b)->drl;
        if (a_drl > b_drl) return -1;
        else if (a_drl < b_drl) return 1;
        else {
            char* a_classNumber = (*(data**)a)->classNumber;
            char* b_classNumber = (*(data**)b)->classNumber;
            if (strcmp(a_classNumber, b_classNumber) < 0) return -1;
            else if (strcmp(a_classNumber, b_classNumber) > 0) return 1;
            else {
                char* a_MSSV = (*(data**)a)->MSSV;
                char* b_MSSV = (*(data**)b)->MSSV;
                if (strcmp(a_MSSV, b_MSSV) < 0) return -1;
                else if (strcmp(a_MSSV, b_MSSV) > 0) return 1;
                else {
                    char* a_firstName = (*(data**)a)->firstName;
                    char* b_firstName = (*(data**)b)->firstName;
                    if (strcmp(a_firstName, b_firstName) < 0) return -1;
                    else if (strcmp(a_firstName, b_firstName) > 0) return 1;
                    else {
                        char* a_middleName = (*(data**)a)->middleName;
                        char* b_middleName = (*(data**)b)->middleName;
                        if (strcmp(a_middleName, b_middleName) < 0) return -1;
                        else if (strcmp(a_middleName, b_middleName) > 0) return 1;
                        else {
                            char* a_lastName = (*(data**)a)->lastName;
                            char* b_lastName = (*(data**)b)->lastName;
                            if (strcmp(a_lastName, b_lastName) < 0) return -1;
                            else if (strcmp(a_lastName, b_lastName) > 0) return 1;
                            else return 0;
                        }
                    }
                }
            }
        }
    }
}

void swap(data** a, data** b) {
    data* temp = *a;
    *a = *b;
    *b = temp;
}

// INSERTION SORT

void insertionSort(int N, data* p[]) {
    int i, j;
    data* last;
    for (i = 0; i < N; i ++) {
        j = i;
        last = p[i];
        while (j > 0 && comparator(&p[j-1], &last) > 0) {
            p[j] = p[j-1];

            j --;
        }
        p[j] = last;
    }
}

//SELECTION SORT

void selectionSort(int N, data* p[]) {
    int i, j;
    int max_index;
    data* temp;
    for (i = 0; i < N; i ++) {
        max_index = i;
        for (j = i+1; j < N; j ++) {
            if (comparator(&p[j], &p[max_index]) < 0) max_index = j;
        }

        swap(&p[i], &p[max_index]);
    }
}

//BUBBLE SORT

void bubbleSort(int N, data* p[]) {
    for (int i = N-1; i >= 0; i --) {
        for (int j = 1; j <= i; j ++) {
            if (comparator(&p[j-1], &p[j]) > 0) swap(&p[j-1], &p[j]);
        }
    }
}

//MERGE SORT

void merge(data* p[], int l, int mid, int r) {
    int n1 = mid - l + 1;
    data* L[n1];
    for (int i = 0; i < n1; i ++) {
        L[i] = p[i+l];
    }

    int n2 = r - mid;
    data* R[n2];
    for (int i = 0; i < n2; i ++) {
        R[i] = p[i+mid+1];
    }

    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2) {
        if (comparator(&L[i], &R[j]) <= 0) p[k++] = L[i++];
        else p[k++] = R[j++];
    }

    while (i < n1) {
        p[k++] = L[i++];
    }
    while (j < n2) {
        p[k++] = R[j++];
    }
}

void merge_sort(data* p[], int l, int r) {
    if (l < r) {
       int mid = (l+r)/2;
        merge_sort(p, l , mid);
        merge_sort(p, mid+1, r);
        merge(p, l, mid, r);
    }
}

void mergeSort(int N, data* p[]) {
    merge_sort(p, 0, N-1);
}

//QUICK SORT

void insertion_sort_for_l_and_r(data* p[], int l, int r) {
    data* last;
    int j;
    for (int i = l; i <= r; i ++) {
        j = i;
        last = p[i];
        while (j >= l+1 && comparator(&p[j-1], &last) > 0) {
            p[j] = p[j-1];
            j --;
        }
        p[j] = last;
    }
}

int partition(data* p[], int l, int r) {
    data* pivot = p[r];

    int i = l;
    int j = r;
    while (i < j) {
        while (i <= r && comparator(&p[i], &pivot) <= 0) i ++;
        while (j >= l && comparator(&p[j], &pivot) > 0) j --;

        if (j <= i) break;
        else swap(&p[i++], &p[j--]);
    }

    swap(&p[j], &p[r]);
    return j;
}

void quick_sort(data* p[], int l, int r) {
    if (l < r) {
        if (r - l <= 15) {
            insertion_sort_for_l_and_r(p, l, r);
        }
        else {
            int pivot_index = partition(p, l, r);
            quick_sort(p, l, pivot_index-1);
            quick_sort(p, pivot_index+1, r);
        }
    } 
}

void quickSort(int N, data* p[]) {
    quick_sort(p, 0, N-1);
}

// HEAP SORT

void heapify(int N, data* p[], int i) {
    int left_child = 2*i+1;
    int right_child = 2*i+2;

    int priority = i;
    if (left_child < N && comparator(&p[left_child], &p[priority]) > 0) priority = left_child;
    if (right_child < N && comparator(&p[right_child], &p[priority]) > 0) priority = right_child;
    
    if (priority != i) {
        swap(&p[priority], &p[i]);
        heapify(N, p, priority);
    }
}

void build_heap(int N, data* p[]) {
    for (int i = N/2-2; i >= 0; i --) heapify(N, p, i);
}

void heapSort(int N, data* p[]) {
    build_heap(N, p);
    for (int i = N-1; i > 0; i --) {
        swap(&p[0], &p[i]);
        heapify(i, p, 0);
    }
}

// BINARY SEARCH

int binarySearch(data* p[], int l, int r, data* x) {
    if (l <= r) {
        int mid = (l+r)/2;
        if (comparator(&x, &p[mid]) < 0) return binarySearch(p, l, mid-1, x);
        else if (comparator(&x, &p[mid]) > 0) return binarySearch(p, mid+1, r, x);
        else return mid;
    }
    else return -1;
}

int main() {
    int N; 
    printf("Number of students: ");
    scanf("%d", &N);

    data a[N];
    data* p[N];

    printf("Data: ");
    for (int i = 0; i < N; i ++) {
        scanf("%s %s %s %s %s %lf %lf", a[i].firstName, a[i].middleName, a[i].lastName, a[i].classNumber, a[i].MSSV, &a[i].grade, &a[i].drl);
        p[i] = &a[i];
    }

    char command[20];

    printf("Sorting algorithm: ");
    scanf("%s", command);
    if (strcmp(command, "insertion") == 0) insertionSort(N, p);
    else if (strcmp(command, "selection") == 0) selectionSort(N, p);
    else if (strcmp(command, "bubble") == 0) bubbleSort(N, p);
    else if (strcmp(command, "merge") == 0) mergeSort(N, p);
    else if (strcmp(command, "quick") == 0) quickSort(N, p);
    else if (strcmp(command, "heap") == 0) heapSort(N, p);

    for (int i = 0; i < N; i ++) {
        printf("%s %s %-6s %-6s %-6s %.2lf %.0lf\n", p[i]->classNumber, p[i]->MSSV, p[i]->lastName, p[i]->middleName, p[i]->firstName, p[i]->grade, p[i]->drl);
    }

    printf("Searching algorithm: Binary search\nQuery data: ");
    data* x = (data*)malloc(sizeof(data));
    scanf("%s %s %s %s %s %lf %lf", x->firstName, x->middleName, x->lastName, x->classNumber, x->MSSV, &x->grade, &x->drl);

    int ANS = (data**)bsearch(&x, p, N, sizeof(data*), comparator) - p;
    // int ANS = binarySearch(p, 0, N-1, x);
    if (ANS == -1) printf("Not found!\n");
    else printf("Student's data is located at index %d after sorting\n", ANS);

    return 0;
}