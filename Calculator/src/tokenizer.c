#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "tokenizer.h"

/*
 * Tokenize the input string into an array of tokens.
 *
 * Parameters:
 *   input      - null-terminated string to tokenize
 *   tokens     - array to store the tokens
 *   max_tokens - maximum number of tokens to store
 *
 * Returns:
 *   Number of tokens on success
 *   -1 on error (invalid character, max tokens exceeded)
 */

int tokenize(const char *input, Token *tokens, int max_tokens) {
    int token_count = 0;
    int i = 0;

    while (input[i] != '\0') {
        // Check token count limit
        if (token_count >= max_tokens) {
            fprintf(stderr, "Error: Maximum token limit (%d) exceeded\n", max_tokens);
            return -1;
        }

        // Skip spaces
        if (input[i] == ' ') {
            i++;
            continue;
        }


        if (isdigit((unsigned char)input[i])) {
            int value = 0;

            while (isdigit((unsigned char)input[i])) {
                value = value * 10 + (input[i] - '0');
                i++;
            }

            // Store the number token
            tokens[token_count].type = TOKEN_NUMBER;
            tokens[token_count].value = value;
            token_count++;

            continue;
        }

        // Check for unary minus
        // A '-' is unary if:
        // - It's the first character of the expression (i == 0)
        // - The previous character (after skipping spaces) is a '(' or operator
        if (input[i] == '-') {
            // Check if it's a unary minus
            int is_unary = 0;

            if (i == 0) {
                is_unary = 1;
            } else {
                // Look backwards, skipping spaces to find the previous non-space character
                int j = i - 1;
                while (j >= 0 && input[j] == ' ') {
                    j--;
                }
                if (j >= 0) {
                    char prev = input[j];
                    if (prev == '(' || prev == '+' || prev == '-' || prev == '*' || prev == '/') {
                        is_unary = 1;
                    }
                }
            }

            if (is_unary) {
                // Unary minus: expect a number after it
                i++;  // Skip the '-'

                // Skip any spaces after the '-'
                while (input[i] == ' ') {
                    i++;
                }

                // Parse the number
                if (!isdigit((unsigned char)input[i])) {
                    fprintf(stderr, "Error: Expected number after unary minus\n");
                    return -1;
                }

                int value = 0;
                while (isdigit((unsigned char)input[i])) {
                    value = value * 10 + (input[i] - '0');
                    i++;
                }

                // Store the negative number token
                tokens[token_count].type = TOKEN_NUMBER;
                tokens[token_count].value = -value;
                token_count++;
                continue;
            }
        }

        // Check for operators
        if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {
            tokens[token_count].type = TOKEN_OPERATOR;
            tokens[token_count].op = input[i];
            token_count++;
            i++;
            continue;
        }

        // Check for parentheses
        if (input[i] == '(') {
            tokens[token_count].type = TOKEN_LPAREN;
            token_count++;
            i++;
            continue;
        }

        if (input[i] == ')') {
            tokens[token_count].type = TOKEN_RPAREN;
            token_count++;
            i++;
            continue;
        }

        // If we get here, the character is invalid
        fprintf(stderr, "Error: Invalid character '%c' at position %d\n", input[i], i);
        return -1;
    }

    return token_count;
}

void print_token(Token t){
    switch (t.type) {
                case TOKEN_NUMBER:
                    printf("Token: NUMBER %d\n", t.value);
                    break;
                case TOKEN_OPERATOR:
                    printf("Token: OPERATOR '%c'\n", t.op);
                    break;
                case TOKEN_LPAREN:
                    printf("Token: LPAREN\n");
                    break;
                case TOKEN_RPAREN:
                    printf("Token: RPAREN\n");
                    break;
                default:
                    printf("Token: UNKNOWN\n");
                    break;
            }
}

void print_tokens(Token *tokens, int tokens_count){
    for(int i =0; i<tokens_count; i++){
        switch (tokens[i].type) {
                case TOKEN_NUMBER:
                    printf("%d ", tokens[i].value);
                    break;
                case TOKEN_OPERATOR:
                    printf("%c ", tokens[i].op);
                    break;
                case TOKEN_LPAREN:
                case TOKEN_RPAREN:
                    break;
                default:
                    printf("Token %d: UNKNOWN\n", i);
                    break;
            }
    }
}
