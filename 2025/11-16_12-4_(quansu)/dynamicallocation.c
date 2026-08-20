#include <stdio.h>
#include <stdlib.h>
void normalize (char *a)	{
	int i = 0;
	int j = 0;
	while (a[i] != '\0') {
		if (a[i] != ' ' && a[i] != '\t' && a[i] != '\n') {
			a[j++] = a[i];
		}
		i ++;
	}
	a[j] = '\0';
}
//
//
//
//
int main() {
	int N; scanf("%d", &N);
	if (N <= 0) {
		printf("ERROR");
		return 0;
	}
	char *a = (char *)malloc(N*sizeof(char) + 1);
	if (a == NULL) {
		printf("ERROR");
		return 1;
	}
	fgets(a, N+1, stdin);
	//
	//
	//
	//
	int index = N;
	char c;
	while ((c = getchar()) != '\n' && c != EOF) {
		if (index >= N) {
			N *= 2;
			char *temp = (char *)realloc(a, N*sizeof(char));
			if (temp == NULL) {
				printf("ERROR");
				free(a);
				a = NULL;
				return 1;
			}
			a = temp;
			temp = NULL;
		}
		a[index ++] = c;
	}
	a[index] = '\0';
	N = index;
	//
	//
	//
	//
	normalize(a);
	puts(a);
	//
	//
	//
	//
	free(a);
	a = NULL;
	return 0;
}