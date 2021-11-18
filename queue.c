//
// Created by Hannes Furmans on 18.11.21.
//

#include "queue.h"
#include <stdlib.h>

struct Element {
    struct Element * next;
    struct Element * prev;
    int value;
};

struct Element * new_element(int value) {
    struct Element * ret = malloc(sizeof(struct Element));
    ret->value = value;
    return ret;
}

struct Queue * new_queue(int value) {
    struct Element * single_element = new_element(value);
    struct Queue * ret = malloc(sizeof(struct Queue));
    ret->first = single_element;
    ret->last = single_element;
    return ret;
}

void enque(struct Queue * current, int value) {
    struct Element * new_el = new_element(value);
    new_el->next = current->first;
    current->first->prev = new_el;
    current->first = new_el;
}

int deque(struct Queue * current) {
    struct Element * last_el = current->last;
    struct Element * new_last = last_el->prev;
    int ret = last_el->value;
    free(last_el);
    current->last = new_last;
    return ret;
}