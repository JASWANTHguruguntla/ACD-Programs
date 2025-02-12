#include <stdio.h>
#include <string.h>

#define MAX_KEYWORD_LENGTH 32
#define MAX_KEYWORDS 32

const char *keywords[MAX_KEYWORDS] = {
    "auto", "break", "case", "char", "const", "continue", "default", "do",
    "double", "else", "enum", "extern", "float", "for", "goto", "if",
    "int", "long", "register", "return", "short", "signed", "sizeof", "static",
    "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"
};

int isKeyword(const char *str) {
    int i; // Declare i outside the loop
    for (i = 0; i < MAX_KEYWORDS; i++) {
        if (strcmp(str, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int main() {
    char input[MAX_KEYWORD_LENGTH];
    printf("Enter a token: ");
    scanf("%s", input);

    if (isKeyword(input)) {
        printf("'%s' is a valid keyword.\n", input);
    } else {
        printf("'%s' is not a valid keyword.\n", input);
    }

    return 0;
}

