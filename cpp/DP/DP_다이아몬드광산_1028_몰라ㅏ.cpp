// DP_다이아몬드광산_1028_몰라ㅏ

#include <cstdio>
enum { rb, lb };
int R, C, D[752][752][2];        // 4.5mb

int main() {
    int i, j, res = 0, t;
    // input data
    scanf("%d %d", &R, &C);
    for (i = 1; i <= R; i++) {
        for (j = 1; j <= C; j++){
          int pos; scanf("%d", &pos);
          D[i][j][rb] = D[i][j][lb] = pos;
        }
    }
    // calculate rb, lb : right-bottom, left-bottom
    for (i = R - 1; i >= 1; i--) {
        for (j = 1; j <= C; j++) {
            D[i][j][rb] *= 1 + D[i + 1][j + 1][rb];
            D[i][j][lb] *= 1 + D[i + 1][j - 1][lb];
        }
    }
    // search res
    for (i = 1; i <= R; i++) {
        for (j = 1; j <= C; j++) {
            for (t = D[i][j][lb] - 1; t >= res; t--)
                if (D[i][j][rb] >= t + 1 && D[i + t][j - t][rb] >= t + 1 && D[i + t][j + t][lb] >= t + 1)
                    res = t + 1;
        }
    }
    // n*m
    printf("%d\n", res);
    return 0;
}
