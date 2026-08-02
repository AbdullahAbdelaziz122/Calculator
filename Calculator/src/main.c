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
            perror("Error: Empty input");
            return -1;
        }

//       TODO: Remove thses debugers
//       printf("Size of buffer: %d\n", (int)strlen(buffer));
//       printf("last character: %c\n", buffer[(int)strlen(buffer)]);


        // check input
        for (int i = 0; i < (int)strlen(buffer); ++i)
        {
            if(!isValidChar(buffer[i])){
                perror("Error: Invalid character");
                printf("You can't use: %c\n", buffer[i]);
                return -1;
            }
        }


        printf("You entered: %s\n", buffer);
    }
    else{
        return -1;
    }
    return 0;
}
