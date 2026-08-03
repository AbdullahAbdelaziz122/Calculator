#include "eval.h"
#include "stack.h"
#include "tokenizer.h"
#include <stdio.h>




int precedence(char op) {
    switch (op) {
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

int shunting_yard(Token *infix, int infix_len, Token *postfix, int max_postfix) {
    Stack op_stack;
    init_stack(&op_stack);
    int postfix_count = 0;

    for (int i = 0; i < infix_len; i++) {
        Token t = infix[i];

        switch (t.type) {
            case TOKEN_NUMBER:
                if (postfix_count >= max_postfix) {
                    fprintf(stderr, "Error: Postfix output buffer overflow\n");
                    return -1;
                }
                postfix[postfix_count++] = t;
                break;

            case TOKEN_OPERATOR: {
                int curr_prec = precedence(t.op);
                while (!is_empty(&op_stack)) {
                    Token top = peek(&op_stack);
                    if (top.type != TOKEN_OPERATOR) break;
                    if (precedence(top.op) >= curr_prec) {
                        postfix[postfix_count++] = pop(&op_stack);
                        if (postfix_count >= max_postfix) {
                            fprintf(stderr, "Error: Postfix output buffer overflow\n");
                            return -1;
                        }
                    } else {
                        break;
                    }
                }
                push(&op_stack, t);
                break;
            }

            case TOKEN_LPAREN:
                push(&op_stack, t);
                break;

            case TOKEN_RPAREN: {
                int found_lparen = 0;
                while (!is_empty(&op_stack)) {
                    Token top = pop(&op_stack);
                    if (top.type == TOKEN_LPAREN) {
                        found_lparen = 1;
                        break;
                    }
                    if (postfix_count >= max_postfix) {
                        fprintf(stderr, "Error: Postfix output buffer overflow\n");
                        return -1;
                    }
                    postfix[postfix_count++] = top;
                }
                if (!found_lparen) {
                    fprintf(stderr, "Error: Mismatched parentheses (extra ')')\n");
                    return -1;
                }
                break;
            }

            default:
                fprintf(stderr, "Error: Unknown token type\n");
                return -1;
        }
    }

    // Pop remaining operators
    while (!is_empty(&op_stack)) {
        Token top = pop(&op_stack);
        if (top.type == TOKEN_LPAREN) {
            fprintf(stderr, "Error: Mismatched parentheses (extra '(')\n");
            return -1;
        }
        if (postfix_count >= max_postfix) {
            fprintf(stderr, "Error: Postfix output buffer overflow\n");
            return -1;
        }
        postfix[postfix_count++] = top;
    }

    return postfix_count;
}

void print_postfix(Token *postfix, int count) {
    printf("Postfix expression: ");
    print_tokens(postfix, count);
    printf("\n");
}
