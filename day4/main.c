#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int get_num(FILE *fd);
int get_board(FILE *fd, int board[5][5]);
int* moves_and_score(int board[5][5], int nums[100]);

int main() {
    FILE *fd = fopen("input", "r");
    int nums[100];
    for (int i=0; i<100; ++i) {
        nums[i] = get_num(fd);
    }
    fclose(fd);
    
    int board[5][5];
    fd = fopen("board_input", "r");

    get_board(fd, board);
    int *best_score = moves_and_score(board, nums);
    int *worst_score = moves_and_score(board, nums);

    while (get_board(fd, board)) {
        int *scores = moves_and_score(board, nums);
        // printf("%i, %i, %i\n", scores[0], scores[1], scores[2]);

        if (scores[0] < best_score[0]) {
            free(best_score);
            best_score = scores;
        } else if (scores[0] > worst_score[0]) {
            free(worst_score);
            worst_score = scores;
        } else {
            free(scores);
        }
    }
    
    printf("%i, %i, %i\n", best_score[0], best_score[1], best_score[2]);
    printf("best score is: %i\n", best_score[1] * best_score[2]);

    printf("%i, %i, %i\n", worst_score[0], worst_score[1], worst_score[2]);
    printf("worst score is: %i\n", worst_score[1] * worst_score[2]);
}

bool bingo(int board[5][5]) {
    bool cols[] = {1, 1, 1, 1, 1};
    
    for (int r=0; r<5; ++r) {
        int row = true;
        for (int c=0; c < 5; ++c) {
            if (board[r][c] != -1) {
                row = false;
                cols[c] = false;
            }
        }
        if (row)
            return row;
    }

    for (int i=0; i<5; ++i)
        if (cols[i])
            return cols[i];

    return false;
}

int sum(int board[5][5]) {
    int s = 0;
    for (int r=0; r<5; ++r) {
        for (int c=0; c<5; ++c) {
            if (board[r][c] != -1)
                s += board[r][c]; 
        }
    }
    return s;
}

int* moves_and_score(int board[5][5], int nums[100]) {
    // returned as [number of moves, score]
    int *ret = malloc(sizeof(int) * 3);
    ret[0] = 0;

    for (int i=0; i<100; ++i) {
        int num = nums[i];
        ++ret[0];
        for (int r=0; r < 5; ++r) {
            for (int c=0; c < 5; ++c) {
                if (board[r][c] == num) {
                    board[r][c] = -1;
                    if (bingo(board)) {
                        ret[1] = sum(board);
                        ret[2] = num;
                        return ret;
                    }
                }
            }
        }
    }
    return ret;
}

int get_board(FILE *fd, int board[5][5]) {
    for (int r=0; r < 5; ++r) {
         char *line = NULL;
         int c = 0;
         size_t length = sizeof(char) * 14;
         if (getline(&line, &length, fd) == -1) {
            return 0;
         }

         while (c < 5) {
             *(line + 2) = '\0';
             board[r][c++] = atoi(line);
             line = line + 3;
         }
    }
     
    char *line = NULL;
    int c = 0;
    size_t length = sizeof(char);
    getline(&line, &length, fd);

    return 1;
}

int get_num(FILE *fd) {
    static long next_num_pos = 0;
    char *num = strdup("00");
    long prev_position = ftell(fd);

    fseek(fd, next_num_pos++, SEEK_SET);

    int numi = 0;
    char c; 
    while (numi < 2 && (fread(&c, sizeof(char), 1, fd))) {
        num[numi++] = c;
        ++next_num_pos;
    }

    fseek(fd, prev_position, SEEK_SET);
    if (num[1] == ',') { 
        next_num_pos--;
        return atoi(&num[0]);
    }

    return atoi(num);
}

