
#ifndef STACK_H
#define STACK_H

#include "tokenizer.h"
#include <stdbool.h>
#define MAX_SIZE 100

extern const Token INVALID_TOKEN;

typedef struct {
    Token data[MAX_SIZE];
    int top;
} Stack;

void init_stack(Stack *stack);
void push(Stack *stack, Token t);
Token pop (Stack *stack);
Token peek(Stack *stack);
bool is_empty(Stack *stack);
bool is_full (Stack *stack);

#endif
