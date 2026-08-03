/*
 ============================================================================
 Name        : Calculator.c
 Author      : Abdullah Abdelaziz
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

# include <stdio.h>
# include <string.h>
# include <stdbool.h>
# include <ctype.h>
# include "tokenizer.h"
# include "eval.h"



bool isValidChar(char c) {
    if (isdigit((unsigned char)c)) return true;
    switch (c) {
        case '+': case '-': case '*': case '/':
        case '(': case ')': case ' ':
            return true;
        default:
            return false;
    }
}

int main() {
    char buffer[100];
    printf("Enter expression: ");

    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        fprintf(stderr, "Error: Failed to read input\n");
        return -1;
    }

    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] != '\n') {
        fprintf(stderr, "Error: Input too long\n");
        return -1;
    }
    buffer[strcspn(buffer, "\n")] = '\0';

    // Trim spaces (simple: remove trailing spaces)
    while (len > 0 && buffer[len - 1] == ' ') {
        buffer[--len] = '\0';
    }
    // Remove leading spaces (shift left)
    char *start = buffer;
    while (*start == ' ') start++;
    if (start != buffer) {
        memmove(buffer, start, strlen(start) + 1);
    }

    if (buffer[0] == '\0') {
        fprintf(stderr, "Error: Empty input\n");
        return -1;
    }

    // Validate characters
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (!isValidChar(buffer[i])) {
            fprintf(stderr, "Error: Invalid character '%c'\n", buffer[i]);
            return -1;
        }
    }

    printf("You entered: %s\n", buffer);

    // Tokenize
    Token tokens[100];
    int token_count = tokenize(buffer, tokens, 100);
    if (token_count == -1) {
        fprintf(stderr, "Tokenization failed\n");
        return -1;
    }

    printf("Tokens found: %d\n", token_count);
    print_tokens(tokens, token_count);
    printf("\n");

    // Shunting-Yard
    Token postfix[100];
    int postfix_count = shunting_yard(tokens, token_count, postfix, 100);
    if (postfix_count == -1) {
        fprintf(stderr, "Shunting-Yard conversion failed\n");
        return -1;
    }

    print_postfix(postfix, postfix_count);

    return 0;
}
