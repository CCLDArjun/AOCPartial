#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void append_one(int *x);
int inv(int x);

int main() {
    FILE *fd = fopen("./input", "r");
    char *line;
    size_t max = 12;
    int nums = 12;
    int lines = 0;
    int *ones = calloc(nums, sizeof(int));


    while (getline(&line, &max, fd) != -1) {
        for (int i=0; *(line) != '\n'; ++i) {
            if (*line++ == '1') {
                ones[i]++;
            }
        }
        ++lines;
    }
    
    int gamma = 0, epsilon = 0;
    lines /= 2;
    for (int i=0; i<nums; i++) {
        if (ones[i] > lines) {
            printf("1");
            append_one(&gamma);
        }
        else {
            printf("0");
            gamma <<= 1;
        }
    }
    
    printf("\n");
    printf("gamma is: %i\n", gamma);
    printf("epsilon is: %i", inv(gamma));
}

void append_one(int *x) { // appends a one to the binary representation
    *x <<= 1;
    *x |= 1;
}

int inv(int x) {
    // find the number of "actual" bits
    // C integer has 32 bits. Only interested in the ones that represent the number 
    int bits = 0;
    int x_clone = x;
    int i = 0;
    int nums[32];

    while (x_clone != 0) {
        int t = x_clone & 1;
        if (t) {
            bits = i;
        }
        nums[i++] = t;
        x_clone >>= 1;
    }

    int ret = 0;
    while (bits > 0) {
        if (nums[bits--] & 1) {
            ret <<= 1;
        }
        else {
            append_one(&ret);
        }
    }

    return ret;
}

