//
// Created by Hannes Furmans on 18.11.21.
//

#ifndef AUD_DATASTRUCTURES_STACK_H
#define AUD_DATASTRUCTURES_STACK_H

struct Stack {
    int value;
    struct Stack * next;
};

struct Stack * new(int value);

int pop(struct Stack * current);

struct Stack * push(struct Stack * current, int value);

#endif //AUD_DATASTRUCTURES_STACK_H
