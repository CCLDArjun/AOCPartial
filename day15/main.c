#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#define LEN 100

int board[LEN][LEN] = {0};
int min_path_sum(int[LEN][LEN]);

int main() {
    FILE *fd = fopen("input", "r");
    char *line;
    size_t size = LEN;
    for (int r = 0;
            r < size && getline(&line, &size, fd) > 0; ++r) {
        for (int c = 0; c < size; ++c) {
            board[r][c] = line[c] - 48;
        }
    }


    int ret = min_path_sum(board);
    printf("%d\n", ret);
}


int min_path_sum(int grid[LEN][LEN]) {
    int dp[LEN][LEN] = {0};
    for (int i=0; i < LEN; ++i) {
        for (int j=0; j < LEN; ++j) {
            dp[i][j] += grid[i][j];
            if (i > 0 && j > 0) {
                dp[i][j] += fmin(dp[i - 1][j], dp[i][j - 1]);
            } else if (i > 0) {
                dp[i][j] += dp[i - 1][j];
            } else if (j > 0) {
                dp[i][j] += dp[i][j - 1];
            }
        }
    }

    return dp[LEN - 1][LEN - 1]; 
}



