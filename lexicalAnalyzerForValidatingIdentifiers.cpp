#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_IDENTIFIER_LENGTH 100

int isIdentifier(const char *str) {
    if (!isalpha(str[0]) && str[0] != '_')
        return 0;

    int i;
    for (i = 1; str[i] != '\0'; i++) {
        if (!isalnum(str[i]) && str[i] != '_')
            return 0;
    }
    return 1;
}

int main() {
    char input[MAX_IDENTIFIER_LENGTH];
    printf("Enter a token: ");
    scanf("%s", input);

    if (isIdentifier(input)) {
        printf("'%s' is a valid identifier.\n", input);
    } else {
        printf("'%s' is not a valid identifier.\n", input);
    }

    return 0;
}


