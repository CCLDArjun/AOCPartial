#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    FILE *fd = fopen("./input", "r");
    char *line;
    size_t max = 10;
    int horiz = 0;
    int depth = 0;
    while (getline(&line, &max, fd) != -1) {
        char *direction = strsep(&line, " ");
        int mag = atoi(line);
        if (strcmp("forward", direction) == 0) {
            horiz += mag; 
        }
        if (strcmp("up", direction) == 0) {
            depth -= mag;
        }
        if (strcmp("down", direction) == 0) {
            depth += mag;
        }
    }
    printf("%d\n", depth * horiz);
}
