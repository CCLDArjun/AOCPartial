#include <stdio.h>
#include <stdlib.h>

int main() {
    int cnt = 0;
    FILE *fd = fopen("./input", "r");

    size_t buff_size = sizeof(char) * 4;
    char *curr = (char *) malloc(buff_size);

    getline(&curr, &buff_size, fd);
    int prev = atoi(curr);
    getline(&curr, &buff_size, fd);
    int currn = atoi(curr);

    while(getline(&curr, &buff_size, fd) != -1) {
        if (currn > prev) {
            ++cnt;
        }
        prev = currn;
        currn = atoi(curr);
    }

    printf("%d\n", cnt);
}
