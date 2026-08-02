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




bool isValidChar(char c){

// check is digit
if(isdigit(c)){
    return true;
}

// check operator

switch (c) {
    case '+':
        return true;
        break;

    case '-':
        return true;
        break;

    case '*':
        return true;
        break;

    case '/':
        return true;
        break;

    case '(':
        return true;
        break;

    case ')':
        return true;
        break;

    case ' ':
        return true;
        break;

    default:
        return false;
        break;
}



}


int main()
{

    char buffer[100];
    printf("Enter text: ");

    // read from stand, input (keyboard)
    if(fgets(buffer, sizeof(buffer), stdin) != NULL){


        size_t len = strlen(buffer);

        if (len > 0 && buffer[len - 1] != '\n')
        {
            // Input was truncated
            // TODO: clear the rest input buffer here
            fprintf(stderr, "Error: Input too long\n");
            return -1;
        }

        // remove the trailing newline character added by fgets
        buffer[strcspn(buffer, "\n")] = '\0';


        // TODO: Trim leading/trailing spaces


        // check empty error
        if(buffer[0] == '\0')
        {
            fprintf(stderr, "Error: Empty input\n");
            return -1;
        }

//       TODO: Remove thses debugers
//       printf("Size of buffer: %d\n", (int)strlen(buffer));
//       printf("last character: %c\n", buffer[(int)strlen(buffer)]);


        // check input
        for (int i = 0; i < (int)strlen(buffer); ++i)
        {
            if(!isValidChar(buffer[i])){
                fprintf(stderr, "Error: Invalid character '%c'\n", buffer[i]);
                printf("You can't use: %c\n", buffer[i]);
                return -1;
            }
        }


        printf("You entered: %s\n", buffer);


        // Tokenization
        Token tokens[100];
        int token_count = tokenize(buffer, tokens, 100);

        if (token_count == -1) {
            fprintf(stderr, "Tokenization failed\n");
            return -1;
        }

        printf("Tokens found: %d\n", token_count);
        for (int i = 0; i < token_count; i++) {
            switch (tokens[i].type) {
                case TOKEN_NUMBER:
                    printf("Token %d: NUMBER %d\n", i, tokens[i].value);
                    break;
                case TOKEN_OPERATOR:
                    printf("Token %d: OPERATOR '%c'\n", i, tokens[i].op);
                    break;
                case TOKEN_LPAREN:
                    printf("Token %d: LPAREN\n", i);
                    break;
                case TOKEN_RPAREN:
                    printf("Token %d: RPAREN\n", i);
                    break;
                default:
                    printf("Token %d: UNKNOWN\n", i);
                    break;
            }
        }

    }
    else{
        return -1;
    }
    return 0;
}
