#include <stdio.h>
void backtracking(int index, int N, int k, char *input_string, char *output_string, int used_i) {
	if (index == k) {
		output_string[k] = '\0';
		printf("%s\n", output_string);
		return;
	}
	for (int i = 0; i < N; i ++) {
		if (used_i & (1<<i)) {
			continue;
		}
		used_i = used_i | (1<<i);
		output_string[index] = input_string[i];
		backtracking(index+1, N, k, input_string, output_string, used_i);
		/*used_i = used_i & ((1<<i) ^ -1);*/     /*tat bit*/
	}
}
//
//
//
int main () {
	int N, k;
	scanf("%d %d", &N, &k);
	char input_string[N+1];
	scanf("%s", input_string);
	char output_string[k+1];
	//
	//
	//
	int used_i = 0;
	backtracking(0, N, k, input_string, output_string, used_i);
}