#include "value_stack.h"
#include <stdio.h>
#include <stdbool.h>

void init_value_stack(ValueStack *stack) {
    stack->top = -1;
}

bool is_value_stack_empty(ValueStack *stack) {
    return stack->top == -1;
}

bool is_value_stack_full(ValueStack *stack) {
    return stack->top == VALUE_STACK_SIZE - 1;
}

bool push_value(ValueStack *stack, int value) {
    if (is_value_stack_full(stack)) {
        fprintf(stderr, "Value stack overflow\n");
        return false;
    }
    stack->data[++stack->top] = value;
    return true;
}

bool pop_value(ValueStack *stack, int *value) {
    if (is_value_stack_empty(stack)) {
        fprintf(stderr, "Value stack underflow\n");
        return false;
    }
    *value = stack->data[stack->top--];
    return true;
}

bool peek_value(ValueStack *stack, int *value) {
    if (is_value_stack_empty(stack)) {
        fprintf(stderr, "Value stack is empty\n");
        return false;
    }
    *value = stack->data[stack->top];
    return true;
}
