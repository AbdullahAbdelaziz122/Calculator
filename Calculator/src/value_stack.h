#ifndef VALUE_STACK_H
#define VALUE_STACK_H

#include <stdbool.h>

#define VALUE_STACK_SIZE 100

typedef struct {
    int data[VALUE_STACK_SIZE];
    int top;
} ValueStack;

void init_value_stack(ValueStack *stack);
bool is_value_stack_empty(ValueStack *stack);
bool is_value_stack_full(ValueStack *stack);
bool push_value(ValueStack *stack, int value);
bool pop_value(ValueStack *stack, int *value);
bool peek_value(ValueStack *stack, int *value);

#endif
