//
// Created by Hannes Furmans on 18.11.21.
//

#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

int main(int arg, char **argv) {
    int test_arg = atoi(argv[1]);

    if (test_arg == 0) {
        struct Queue * test_queue = new_queue(0);
        enque(test_queue, 1);

        int ret1 = deque(test_queue);
        int ret2 = deque(test_queue);

        if (ret1 == 0 && ret2 == 1) {
            printf("SUCCESS\n");
        } else {
            printf("FAILURE\n");
        }
        free(test_queue);
    } else if (test_arg == 1) {
        struct Queue * test_queue = new_queue(2);

        int ret1 = deque(test_queue);

        if (ret1 == 2) {
            printf("SUCCESS\n");
        } else {
            printf("FAILURE\n");
        }
        free(test_queue);
    } else if (test_arg == 2) {
        int test_size = atoi(argv[2]);
        int * test_data = malloc(test_size * sizeof(int));
        for (int i = 0; i < test_size; i++) {
            test_data[i] = i + 1;
        }
        struct Queue * test_queue = new_queue(test_data[0]);

        for (int i = 1; i < test_size; i++) {
            enque(test_queue, test_data[i]);
        }

        for (int i = 0; i < test_size; i++) {
            int required_value = test_data[i];
            int queue_value = deque(test_queue);
            if (required_value != queue_value) {
                printf("FAILURE\n");
                return 0;
            }
        }
        printf("SUCCESS\n");
        return 0;
    }

    return 0;
}
