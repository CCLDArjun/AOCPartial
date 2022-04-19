/*
from collections import deque
fd = open("input", "r")

window = []
cnt = 0

for line in fd.readlines():
    curr = int(line.rstrip())
    window.append(curr)
    if (len(window) == 4):
        if (sum(window[0:3]) < sum(window[1:4])):
            cnt += 1
        del window[0]

print(cnt)
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define insert(X)   getline(&line, &max, fd); \
                    window[X] = atoi(line);

int main() {
    FILE *fd = fopen("./input", "r");
    char *line;
    size_t max = sizeof(char) * 4; 
    int *window = malloc(sizeof(int) * 4);
    int windex = 0;

    insert(0);
    insert(1);
    insert(2);
    insert(3);
    
    while (getline(&line, &max, fd) == -1) {
         
    }
}


