#include <stdio.h>
#include <ctype.h>
#include <string.h>
void func(char *s) {
	char *temp;
	char reject[] = "1234567890~!@#$ \% ^&*()_-=+{}|[] \\<>,./?;:'\" ";
	temp = strtok(s, reject);
	while (temp) {
		if (strpbrk(temp, "ueoaiUEOAI") != NULL) printf("%s ", temp);
		temp = strtok(NULL, reject);
	}
}
int main() {
	char s[2001];
	fgets(s, 2001, stdin);
	s[strcspn(s, "\r\n")] = '\0';
	func(s);
	return 0;
}