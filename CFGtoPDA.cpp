#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum sizes
#define MAX_PRODUCTIONS 100
#define MAX_SYMBOLS 50
#define MAX_STACK_SIZE 100

// Structure to represent a production in the CFG
typedef struct {
    char lhs;  // Left-hand side of the production (non-terminal)
    char rhs[MAX_SYMBOLS];  // Right-hand side of the production (string of symbols)
} Production;

// Define PDA components
char stack[MAX_STACK_SIZE];
int top = -1;

// Function to push a symbol onto the stack
void push(char symbol) {
    if (top < MAX_STACK_SIZE - 1) {
        stack[++top] = symbol;
    } else {
        printf("Stack Overflow\n");
    }
}

// Function to pop a symbol from the stack
char pop() {
    if (top >= 0) {
        return stack[top--];
    } else {
        printf("Stack Underflow\n");
        return '\0';  // Return null if stack is empty
    }
}

// Function to print the stack (for debugging)
void printStack() {
    int i;  // Declare i outside the loop
    printf("Stack: ");
    for (i = top; i >= 0; i--) {
        printf("%c ", stack[i]);
    }
    printf("\n");
}

// Function to simulate the PDA (LL(1) parsing)
void simulatePDA(Production productions[], int numProductions, char startSymbol, char input[]) {
    int i = 0, j, k;  // Declare loop variables outside the loop

    // Push start symbol onto the stack
    push(startSymbol);

    while (i < strlen(input)) {
        printStack();
        char currentSymbol = stack[top];  // Peek the top of the stack
        char currentInput = input[i];  // Current input symbol

        if (currentSymbol == currentInput) {
            // If top of stack matches input symbol, pop the stack and move to next input symbol
            printf("Match: %c\n", currentSymbol);
            pop();
            i++;
        } else if (currentSymbol >= 'A' && currentSymbol <= 'Z') {
            // If top of stack is a non-terminal, apply production rule
            int productionFound = 0;
            for (j = 0; j < numProductions; j++) {
                if (productions[j].lhs == currentSymbol) {
                    // Apply the production (replace non-terminal with the right-hand side)
                    printf("Applying production: %c -> %s\n", productions[j].lhs, productions[j].rhs);
                    pop();
                    // Push the right-hand side onto the stack (in reverse order)
                    for (k = strlen(productions[j].rhs) - 1; k >= 0; k--) {
                        if (productions[j].rhs[k] != '\0') {
                            push(productions[j].rhs[k]);
                        }
                    }
                    productionFound = 1;
                    break;
                }
            }

            if (!productionFound) {
                printf("Error: No production rule found for %c\n", currentSymbol);
                return;
            }
        } else {
            // If top of stack is a terminal symbol, but it does not match the input symbol
            printf("Error: Unexpected symbol %c\n", currentSymbol);
            return;
        }
    }

    // After all input is processed, the stack should be empty
    if (top == -1) {
        printf("Input string accepted\n");
    } else {
        printf("Stack not empty, input rejected\n");
    }
}

int main() {
    int numProductions;  // Declare this outside the loop
    char startSymbol;

    // Read the number of productions
    printf("Enter the number of productions: ");
    scanf("%d", &numProductions);

    // Read the start symbol
    printf("Enter the start symbol: ");
    scanf(" %c", &startSymbol);

    // Read the productions
    Production productions[numProductions];  // Declare this outside the loop
    printf("Enter the productions in the format A -> abc:\n");
    int i;
    for (i = 0; i < numProductions; i++) {
        printf("Production %d: ", i + 1);
        scanf(" %c -> %s", &productions[i].lhs, productions[i].rhs);
    }

    // Read the input string to be parsed
    char input[MAX_SYMBOLS];
    printf("Enter the input string to be parsed: ");
    scanf("%s", input);

    // Simulate the PDA
    simulatePDA(productions, numProductions, startSymbol, input);

    return 0;
}



