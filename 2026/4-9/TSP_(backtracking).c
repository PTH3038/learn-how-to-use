#define INF 2147483647
#include <stdio.h>
int length = 0;
int current_best = INF;

int town_checker(int next_town, int N, int path[N+1]) {
    for (int j = 0; j < N; j ++) {
        if (path[j] == next_town) return 0;
    }
    return 1;
}

void BranchBound(int k, int N, int C[N][N], int min_C, int path[N+1]) {
    if (k == N - 1) {
        int way_back_home = C[path[k]][0];
        length += way_back_home;
        current_best = (length < current_best) ? length : current_best;

        for (int i = 0; i < N; i ++) printf("%d -> ", path[i]);
        printf("0  ANS: %d\n", current_best);

        length -= way_back_home;
        return;
    }

    int current_bound = length + (N-k)*min_C;
    if (current_bound >= current_best) return;

    for (int next_town = 1; next_town < N; next_town ++) {
        if (town_checker(next_town, k+1, path)) {
            length += C[path[k]][next_town];
            path[k+1] = next_town;

            BranchBound(k+1, N, C, min_C, path);

            length -= C[path[k]][next_town];
            path[k+1] = -1;
        }        
    }
}

int main() {
    int N; scanf("%d", &N);

    int min_C = INF;
    int C[N][N];
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) {
            scanf("%d", &C[i][j]);
            if (i != j) min_C = (min_C < C[i][j]) ? min_C : C[i][j];
        }
    }

    int path[N+1];
    for (int i = 0; i < N; i ++) path[i] = -1;
    path[0] = 0;

    BranchBound(0, N, C, min_C, path);
    printf("ANS: %d\n", current_best);
    return 0;
}