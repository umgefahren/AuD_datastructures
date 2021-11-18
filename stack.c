//
// Created by Hannes Furmans on 18.11.21.
//

#include "stack.h"
#include <stdlib.h>

struct Stack * push(struct Stack * current, int value) {
    struct Stack * new_stack = malloc(sizeof( struct Stack));
    new_stack->value = value;
    new_stack->next = current;
    return new_stack;
}

int pop(struct Stack * current) {
    int ret = current->value;
    struct Stack * next = current->next;
    if (next != NULL) {
        current->value = next->value;
        current->next = next->next;
    }
    free(next);
    return ret;
}

struct Stack * new(int value) {
    struct Stack * ret = malloc(sizeof(struct Stack));
    ret->value = value;
    return ret;
}