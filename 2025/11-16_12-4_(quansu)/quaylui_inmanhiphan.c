#include <stdio.h>
void backtracking(int k, int N, char *a) {
	if (k == N) {
		a[N] = '\0';
		printf("%s\n", a);
		return;	
	}
	
	a[k] = '0';
	backtracking(k+1, N, a);
	
	a[k] = '1';
	backtracking(k+1, N, a);
}

int main() {
	int N; scanf("%d", &N);
	char a[N+1];
	backtracking(0, N, a);
	return 0;
}