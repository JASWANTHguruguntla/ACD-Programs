#include <stdio.h>
#include <string.h>

int dfa(char *input) {
    int state = 0; 
    int i;         

    for (i = 0; i < strlen(input); i++) {
        char symbol = input[i];

        switch (state) {
            case 0:
                if (symbol == '0')
                    state = 1;
                else if (symbol == '1')
                    state = 2;
                else
                    return 0; 
                break;
            case 1:
                if (symbol == '0')
                    state = 1;
                else if (symbol == '1')
                    state = 3;
                else
                    return 0;
                break;
            case 2:
                if (symbol == '0')
                    state = 0;
                else if (symbol == '1')
                    state = 1;
                else
                    return 0; 
                break;
            case 3:
                if (symbol == '0')
                    state = 3;
                else if (symbol == '1')
                    state = 3;
                else
                    return 0;
                break;0
        }
    }

    // Accept state is 3
    return state == 3;
}

int main() {
    char input[100];

    printf("Enter a binary string: ");
    scanf("%s", input);

    if (dfa(input)) {
        printf("The string is accepted by the DFA.\n");
    } else {
        printf("The string is rejected by the DFA.\n");
    }

    return 0;
}

