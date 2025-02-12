#include <stdio.h>
#include <string.h>

#define MAX_OPERATOR_LENGTH 3

int isOperator(const char *str) {
    const char *operators[] = {"+", "-", "*", "/", "%", "++", "--", "=", "+=", "-=", "*=", "/=", "%=", "==", "!=", "<", ">", "<=", ">=", "&&", "||", "!", "&", "|", "^", "~", "<<", ">>"};
    int numOperators = sizeof(operators) / sizeof(operators[0]);
    int i; // Declare i outside the loop
    for (i = 0; i < numOperators; i++) {
        if (strcmp(str, operators[i]) == 0)
            return 1;
    }
    return 0;
}

int main() {
    char input[MAX_OPERATOR_LENGTH];
    printf("Enter a token: ");
    scanf("%s", input);

    if (isOperator(input)) {
        printf("'%s' is a valid operator.\n", input);
    } else {
        printf("'%s' is not a valid operator.\n", input);
    }

    return 0;
}

