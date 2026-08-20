#include <stdio.h>
int main() {
	int N; scanf("%d", &N);
	double a[N][N*2];
	for (int i = 0; i < N; i ++) {
		for (int j = 0; j < N*2 ; j ++) {
			if (j < N) {
				scanf("%lf", &a[i][j]);
			}
			else {
				if (j == N+i) {
					a[i][j] = 1;
				}
				else {
					a[i][j] = 0;
				}
			}
		}
	}
	//
	//
	//
	for (int i = 0; i < N; i ++) {
		for (int j = 0; j < 2*N; j ++) {
			if (j == N) {
				printf(" |%5.1lf", a[i][j]);
			}
			else {
				printf("%5.1lf", a[i][j]);
			}
		}
		printf("\n");
	}
	//
	//
	//
	int state = 0;
	for (int cot = 0; cot < N; cot ++) {
		int hang = 0;
		while (hang < N) {
			if (state & (1 << hang)) {
				hang ++;
				continue;
			}
			if (a[hang][cot] == 0) {
				hang ++;
				continue;
			}
			state = state | (1 << hang);
			break;
		}
		//
		//
		//
		for (int i = 0; i < N; i ++) {
			if (i == hang) {
				continue;
			}
			if (a[hang][cot] == 0) {
				continue;
			}
			double k = a[i][cot] / a[hang][cot];
			for (int j = 0; j < N*2; j ++) {
				a[i][j] -= a[hang][j] * k;
			}
		}
	}
	//
	//
	//
	int usedrow = 0;
	for (int i = 0; i < N; i ++) {
		for (int j = 0; j < N; j ++) {
			if (usedrow & (1 << j)) {
				continue;
			}
			if (a[j][i] != 0) {
				for (int k = 0; k < N*2; k ++) {
					double temp = a[i][k];
					a[i][k] = a[j][k];
					a[j][k] = temp;
				}
				usedrow = usedrow | (1 << i);
				break;
			}
		}
	}
	//
	//
	//
	for (int i = N-1; i >= 0; i --) {
		double moc = a[i][i];
		for (int j = i; j < 2*N; j ++) {
			a[i][j] /= moc;
		}
	}
	//
	//
	//
	for (int i = 0; i < N; i ++) {
		if (a[i][i] != 1) {
			printf("  Ma tran khong kha nghich");
			return 0;
		}
	}
	//
	//
	//
	printf("  Ma tran kha nghich:\n");
	for (int i = 0; i < N; i ++) {
		for (int j = 0; j < 2*N; j ++) {
			if (j == N) {
				printf(" |%5.1lf", a[i][j]);
			}
			else {
				printf("%5.1lf", a[i][j]);
			}
		}
		printf("\n");
	}
	//
	//
	//
	return 0;
}