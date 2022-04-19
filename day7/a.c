#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void make_list(int **ar, char *line) {
    int *arr = *ar;
    int i=0;
    do {
        arr[i++] = atoi(strsep(&line, ","));
    } while(line);
}

int calc_part2_fuel(int steps) {
    if (steps == 1 || steps == 0)
        return steps;
    return calc_part2_fuel(steps - 1) + steps;
}

int main() {
    FILE *fd = fopen("input", "r");
    char *line = NULL;
    size_t size = 4000;

    getline(&line, &size, fd);
    
    int *arr = malloc(sizeof(int) * 1000);
    make_list(&arr, line);

    for (int i=0; i<1000; ++i) {
        for (int j=0; j<1000 - i - 1; ++j) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    int median = arr[500] + arr[501];
    median /= 2;
    
    int fuel = 0;
    long fuel_2 = 0;
    for (int i=0; i<1000; ++i) {
        int res = median - arr[i];
        if (res < 0) res *= -1;
        fuel += res;
        fuel_2 += calc_part2_fuel(res);
    }

    printf("total fuel: %i", fuel);
    printf("total fuel part 2: %li", fuel_2);
    printf("\n%i", calc_part2_fuel(9));

}   
