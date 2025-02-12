#include <stdio.h>
#include <string.h>

#define MAX_STATEMENT_LENGTH 100

int isLoopingStatement(const char *str) {
    const char *loopingStatements[] = {"for", "while", "do"};
    int numStatements = sizeof(loopingStatements) / sizeof(loopingStatements[0]);
    int i; // Declare i outside the loop
    for (i = 0; i < numStatements; i++) {
        if (strcmp(str, loopingStatements[i]) == 0)
            return 1;
    }
    return 0;
}

int main() {
    char input[MAX_STATEMENT_LENGTH];
    printf("Enter a token: ");
    scanf("%s", input);

    if (isLoopingStatement(input)) {
        printf("'%s' is a valid looping statement.\n", input);
    } else {
        printf("'%s' is not a valid looping statement.\n", input);
    }

    return 0;
}

