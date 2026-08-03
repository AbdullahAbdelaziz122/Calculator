#include <stdio.h>
#include <stdbool.h>
#include "stack.h"

const Token INVALID_TOKEN = {TOKEN_INVALID, 0, 0};

void initialize(Stack *stack){
    stack->top=-1;
}

bool is_empty(Stack *stack){
    return (stack ->top == -1);
}

bool is_full(Stack *stack){
    return (stack ->top == MAX_SIZE);
}

void push(Stack *stack, Token t){
    if(is_full(stack)){
        printf("Stack overflow\n");
        return;
    }
    else{
        stack->data[++stack->top] = t ;
        printf("pushed token to stack\n");
        print_token(t);
    }
}

Token pop(Stack *stack){
    if(is_empty(stack)){
        printf("Stack Underflow\n");
        return INVALID_TOKEN;
    }

    Token popped = stack->data[stack->top];
    printf("Popped token from stack\n");
    print_token(popped);

    return popped;
}

Token peek(Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack is empty\n");
        return INVALID_TOKEN;
    }
    return stack->data[stack->top];
}
