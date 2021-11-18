//
// Created by Hannes Furmans on 18.11.21.
//

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(int arg, char **argv) {

    int test_arg = atoi(argv[1]);
    // printf("test arg %i\n", test_arg);

    if (test_arg == 0) {
        struct Stack * stack = new(0);
        stack = push(stack, 1);
        int ret = pop(stack);
        if (ret == 1) {
            printf("SUCCESS\n");

        } else {
            printf("FAILURE\n");
        }
        free(stack);
        return 0;
    } else if (test_arg == 1) {
        struct Stack * stack = new(0);
        stack = push(stack, 1);
        int ret1 = pop(stack);
        int ret2 = pop(stack);
        if (ret1 == 1 && ret2 == 0) {
            printf("SUCCESS\n");
        } else {
            printf("FAILURE\n");
        }
        free(stack);
        return 0;
    } else if (test_arg == 2) {
        int test_size = atoi(argv[2]);
        int * test_data = malloc(test_size * sizeof(int));
        for (int i = 0; i < test_size; i++) {
            test_data[i] = i + 1;
        }

        struct Stack * test_stack = new(test_data[0]);

        for (int i = 1; i < test_size; i++) {
            test_stack = push(test_stack, test_data[i]);
        }

        int * test_result = malloc(test_size * sizeof(int));

        for (int i = 0; i < test_size; i++) {
            int val = pop(test_stack);
            int pos_in_test_data = test_size - 1 - i;
            int test_data_val = test_data[pos_in_test_data];
            if (val == test_data_val) {
                test_result[i] = 1;
            } else {
                test_result[i] = 0;
            }
        }

        for (int i = 0; i < test_size; i++) {
            int val = test_result[i];

            if (val == 0) {
                printf("FAILURE\n");
                printf("Failed at %i\n", i);
                return 0;
            }
        }
        free(test_stack);
        printf("SUCCESS\n");
    }
    return 0;
}