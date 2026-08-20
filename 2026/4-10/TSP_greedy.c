#include <stdio.h>
int select(int current_town, int N, int C[N][N], int frequency[N]) {
    int best = -1;
    for (int i = 0; i < N; i ++) {
        if (frequency[i] != 0 || i == current_town) continue;
        if (best == -1 || C[current_town][i] < C[current_town][best]) best = i;
    }
    return best;
}

int feasible( ) {
    return 1;               // just return 1 =)))
}

void greed(int N, int C[N][N], int start_town) {
    int length = 0;

    int path[N];
    path[0] = start_town;     //mang tham so

    int k = 0;

    int frequency[N];
    for (int i = 0; i < N; i ++) frequency[i] = 0;
    frequency[start_town] ++;

    while (k < N-1) {
        int current_town = path[k];
        int next_town = select(current_town, N, C, frequency);
        
        frequency[next_town] ++;

        if (feasible( )) {
            path[++ k] = next_town;
            length += C[current_town][next_town];
        }
    }

    for (int i = 0; i < N; i ++) {
        printf("%d - > ", path[i]);
    }
    int waybackhome = C[path[N-1]][0];
    printf("0\nANS: %d\n", length + waybackhome);
}

int main() {
    int N; scanf("%d", &N);

    int C[N][N];
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) scanf("%d", &C[i][j]);
    }

    greed(N, C, 0);
}