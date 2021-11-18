//
// Created by Hannes Furmans on 18.11.21.
//

#ifndef AUD_DATASTRUCTURES_QUEUE_H
#define AUD_DATASTRUCTURES_QUEUE_H



struct Queue {
    struct Element * first;
    struct Element * last;
};

struct Queue * new_queue(int value);

void enque(struct Queue * current, int value);

int deque(struct Queue * current);


#endif //AUD_DATASTRUCTURES_QUEUE_H
