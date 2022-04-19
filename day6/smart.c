#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void make_list(long *arr, char *line) {
    do {
        *(line + 1) = '\0';
        ++arr[atoi(line)];
    } while(*(line += 2));
}

int main() {
    FILE *fd = fopen("input", "r");
    long arr[9] = {0};
   
    char *line = NULL;
    size_t size = 1000;
    getline(&line, &size, fd);
    
    make_list(arr, line);
    for (long r=0; r<256; ++r) {
        long babies = arr[0];
        
        for (long i=0; i<8; ++i) {
            arr[i] = arr[i+1];
        }
        arr[8] = 0;
        for (long i=0; i<babies; ++i) {
            ++arr[6];
            ++arr[8];
        }
        
    }

    long sum = 0;
    for (long i=0; i<9; ++i) {
        sum += arr[i]; 
    }
    printf("%li", sum);

}


