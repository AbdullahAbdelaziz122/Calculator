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





// bool isValidChar(char c){
// switch (c) {
//     case 1:
//     }
// }


int main()
{

    char buffer[100];
    printf("Enter text: ");

    // read from stand, input (keyboard)
    if(fgets(buffer, sizeof(buffer), stdin) != NULL){


        //printf("%d", (int)strlen(buffer));

        // check buffer overflow
        if(buffer[(int)strlen(buffer) - 1] != '\n')
        {
             perror("Error: Input too long");
             return -1;
        }

        // check empty error
        if(strlen(buffer) - 1 == 0)
        {
            perror("Error: Empty input");
            return -1;
        }

        // // check input
        // for (int i = 0; i < (int)strlen(buffer); ++i)
        // {
        //     if(!isValid(buffer[i])){
        //         perror("Error: Invalid character");
        //         printf("You can't use: %c\n", buffer[i]);
        //         return -1;
        //     }
        // }


        // remove the trailing newline character added by fgets
        buffer[strcspn(buffer, "\n")] = '\0';

        printf("You entered: %s\n", buffer);
    }
    else{
        return -1;
    }
    return 0;
}
