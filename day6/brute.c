#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Fish {
    int int_timer;
    struct Fish *next;
};

void make_list(char *line, struct Fish *head, struct Fish **tail);
void reproduce(struct Fish *list, struct Fish **tail);
int calculate_length(struct Fish *head);

void print_list(struct Fish *head) {
    while (head) {
        printf("%i,", head->int_timer);
        head = head->next;
    }
    printf("\n");
}

int main() {
    FILE *fd = fopen("input", "r");
    char *line = NULL;
    size_t size = 1000;
    getline(&line, &size, fd);
    struct Fish *head = malloc(sizeof(struct Fish)), *tail;
    make_list(line, head, &tail);
    for (int i=0; i<80; ++i) {
        reproduce(head, &tail);
    }
    printf("length is: %i", calculate_length(head));
}

void reproduce(struct Fish *list, struct Fish **tail) {
    while (list) {
        if (--list->int_timer == -1) {
            list->int_timer = 6;
            struct Fish *baby = malloc(sizeof(struct Fish));
            baby->int_timer = 9;
            (*tail)->next = baby;
            *tail = baby;
        }
        list = list->next;
    }
}

int calculate_length(struct Fish *head) {
    int ret = 0;
    while (head) {
        ++ret;
        head = head->next;
    }
    return ret;
}

void make_list(char *line, struct Fish *head, struct Fish **tail) {
    *(line + 1) = '\0';
    head->int_timer = atoi(line);
    *tail = head;
    line += 2;

    do {
        *(line + 1) = '\0';
        struct Fish *new = malloc(sizeof(struct Fish));
        new->int_timer = atoi(line);
        new->next = NULL;
        (*tail)->next = new;
        *tail = new;
    } while(*(line += 2));
}

