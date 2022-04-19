#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))

int board[1000][1000] = {0};
void part_1(), part_2();

int main() {
    part_2();
}

void part_2() {
    FILE *fd = fopen("input", "r");
    int count = 0;
    for (int i=0; i<500; ++i) {
        char *line = NULL;
        size_t size = 18;
        getline(&line, &size, fd);
        
        int x1, y1, x2, y2;
        x1 = atoi(strsep(&line, ","));
        y1 = atoi(strsep(&line, " "));

        line += 3;
        x2 = atoi(strsep(&line, ","));
        y2 = atoi(strsep(&line, "\n"));
        if (x1 != x2 && y1 != y2) { // diagonal
            int c = MIN(x1, x2), ex = MAX(x1, x2),
                r = MIN(y1, y2), ey = MAX(y1, y2);
            while (c != ex || r != ey) {
                ++board[r][c];
                if (board[r++][c++] == 2) ++count;
            }
        } else {
            for (int r = MIN(y1, y2); r <= MAX(y1, y2); ++r) {
                for (int c = MIN(x1, x2); c <= MAX(x1, x2); ++c) {
                    ++board[r][c];
                    if (board[r][c] == 2) ++count;
                }
            }
        }
    }
    printf("%i", count);
}

void part_1() {
    FILE *fd = fopen("input", "r");
    int count = 0;
    for (int i=0; i<500; ++i) {
        char *line = NULL;
        size_t size = 18;
        getline(&line, &size, fd);
        
        int x1, y1, x2, y2;
        x1 = atoi(strsep(&line, ","));
        y1 = atoi(strsep(&line, " "));

        line += 3;
        x2 = atoi(strsep(&line, ","));
        y2 = atoi(strsep(&line, "\n"));

        if (x1 != x2 && y1 != y2) 
            continue;

        for (int r = MIN(y1, y2); r <= MAX(y1, y2); ++r) {
            for (int c = MIN(x1, x2); c <= MAX(x1, x2); ++c) {
                ++board[r][c];
                if (board[r][c] == 2) ++count;
            }
        }
    }

    printf("%i", count);

}
