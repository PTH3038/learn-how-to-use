#include <stdio.h>
int main() {
	int M, N; scanf("%d" "%d", &M, &N);
	double a[M][N];
	for (int i = 0; i < M; i ++) {
		for (int j = 0; j < N; j ++) {
			scanf("%lf", &a[i][j]);
		}
	}
	//
	//
	//
	for (int i = 0; i < M; i ++) {
		for (int j = 0; j < N; j ++) {
			printf("%4.1lf ", a[i][j]);
		}
		printf("\n");
	}
	printf("\n Dang bien doi...\n");
	//
	//
	//
	unsigned long long int state = 0;
	for (int cot = 0; cot < N; cot ++) {
		int hang = 0;
		while (hang < M) {
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
		for (int i = 0; i < M; i ++) {
			if (state & (1 << i)) {
				continue;
			}
			if (a[hang][cot] == 0) {
				continue;
			}
			double k = a[i][cot] / a[hang][cot];
			for (int j = cot; j < N; j ++) {
				a[i][j] -= a[hang][j] * k;	
			}
		}
	}
	//
	//
	//
	int usedrow = 0;
	for (int i = 0; i < M; i ++) {
		for (int j = 0; j < M; j ++) {
			if (usedrow & (1 << j)) {
				continue;
			}
			if (a[j][i] != 0) {
				for (int k = 0; k < N; k ++) {
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
	printf("\n Ma tran bac thang:\n");
	for (int i = 0; i < M; i ++) {
		for (int j = 0; j < N; j ++) {
			printf("%4.1lf ", a[i][j]);
		}
		printf("\n");
	}
	//
	//
	//
	int expandrank = 0;
	int rank = 0;
	for (int i = 0; i < M; i ++) {
		for (int j = 0; j < N-1; j ++) {
			if (a[i][j] != 0) {
				rank ++;
				break;
			}
		}
		for (int j = 0; j < N; j ++) {
			if (a[i][j] != 0) {
				expandrank ++;
				break;
			}
		}
	}
	printf("\n Rank: %d\n", rank);
	printf(" Expandrank: %d\n", expandrank);
	//
	//
	//
	int varies = 0;
	for (int i = 0; i < N-1; i ++) {
		for (int j = 0; j < M; j ++) {
			if (a[j][i] != 0) {
				varies ++;
				break;
			} 
		}
	}
	printf(" Varies: %d\n", varies);
	//
	//
	//
	if (rank < expandrank) {
		printf("\n Vo nghiem\n");
		return 0;
	}
	if (rank < varies) {
		printf("\n Vo so nghiem\n");
		return 0;
	}
	//
	//
	//
	double root(int N, double a[N-1][N], int x) {
		double nghiem = 0;
		if (x == N-2) {
			nghiem = a[N-2][N-1]/a[N-2][N-2];
		}
		else if (x > N-2) {
			printf("ERROR");
			return 1;
		}
		else {
			double S = 0;
			for (int i = x+1; i <= N-2; i ++) {
				S += a[x][i] * root(N, a, i);
			}
			nghiem = (a[x][N-1] - S) / a[x][x];
		}
		return nghiem;
	}
	printf("\n He co nghiem duy nhat:\n");
	for(int i = 0; i < M; i ++) {
			printf(" x[%d] = %lf\n", i+1, root(M+1, a, i));
	}
	//
	//
	//
	return 0;
}