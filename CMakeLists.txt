cmake_minimum_required(VERSION 3.20)
project(AuD_datastructures C)

set(CMAKE_C_STANDARD 11)

add_library(AuD_datastructures library.c stack.c stack.h queue.c queue.h)

add_executable(stack_test stack_test.c stack.c stack.h)

add_executable(queue_test queue_test.c queue.c queue.h)


enable_testing()
add_test(stack_push_pop_0 stack_test 0)
set_tests_properties(stack_push_pop_0 PROPERTIES PASS_REGULAR_EXPRESSION "SUCCESS")

add_test(stack_push_pop_1 stack_test 1)
set_tests_properties(stack_push_pop_1 PROPERTIES PASS_REGULAR_EXPRESSION "SUCCESS")

add_test(stack_push_pop_2 stack_test 2 1000000)
set_tests_properties(stack_push_pop_2 PROPERTIES PASS_REGULAR_EXPRESSION "SUCCESS")

add_test(queue_enque_deque_0 queue_test 0)
set_tests_properties(queue_enque_deque_0 PROPERTIES PASS_REGULAR_EXPRESSION "SUCCESS")

add_test(queue_enque_deque_1 queue_test 1)
set_tests_properties(queue_enque_deque_1 PROPERTIES PASS_REGULAR_EXPRESSION "SUCCESS")

add_test(queue_enque_deque_2 queue_test 2 1000000)
set_tests_properties(queue_enque_deque_2 PROPERTIES PASS_REGULAR_EXPRESSION "SUCCESS")