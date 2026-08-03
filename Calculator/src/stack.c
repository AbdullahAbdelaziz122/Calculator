#include <stdio.h>
#include <stdbool.h>
#include "stack.h"

const Token INVALID_TOKEN = {TOKEN_INVALID, 0, 0};

void init_stack(Stack *stack) {
    stack->top = -1;
}

bool is_empty(Stack *stack) {
    return stack->top == -1;
}

bool is_full(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(Stack *stack, Token t) {
    if (is_full(stack)) {
        fprintf(stderr, "Error: Stack overflow\n");
        return;
    }
    stack->data[++stack->top] = t;
}

Token pop(Stack *stack) {
    if (is_empty(stack)) {
        fprintf(stderr, "Error: Stack underflow\n");
        return INVALID_TOKEN;
    }
    return stack->data[stack->top--];
}

Token peek(Stack *stack) {
    if (is_empty(stack)) {
        fprintf(stderr, "Error: Stack is empty\n");
        return INVALID_TOKEN;
    }
    return stack->data[stack->top];
}
