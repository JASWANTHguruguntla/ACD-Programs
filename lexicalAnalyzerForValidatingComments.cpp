#include <stdio.h>
#include <string.h>

#define MAX_COMMENT_LENGTH 100

int isComment(const char *str) {
    int len = strlen(str);
    
    // Check for single-line comment (//)
    if (len >= 2 && str[0] == '/' && str[1] == '/') {
        return 1; // Single-line comment
    }
    
    // Check for multi-line comment (/* ... */)
    if (len >= 4 && str[0] == '/' && str[1] == '*' && str[len - 2] == '*' && str[len - 1] == '/') {
        return 1; // Multi-line comment
    }
    
    return 0;
}

int main() {
    char input[MAX_COMMENT_LENGTH];
    printf("Enter a token: ");
    
    // Adjusted to handle spaces after the input
    scanf(" %[^\n]", input);

    if (isComment(input)) {
        printf("is a valid comment.\n");
    } else {
        printf("is not a valid comment.\n");
    }

    return 0;
}

