#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Stack structure
typedef struct Stack {
    char *arr;
    int top;
    int capacity;
} Stack;

// Function to create a stack
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = (char*)malloc(capacity * sizeof(char));
    return stack;
}

// Function to check if stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Push element to stack
void push(Stack* stack, char ch) {
    stack->arr[++stack->top] = ch;
}

// Pop element from stack
char pop(Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->arr[stack->top--];
    }
    return '\0';
}

// Function to check matching pair
int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

// Function to check if brackets are balanced
char* isBalanced(char* s) {
    int n = strlen(s);
    Stack* stack = createStack(n);

    for (int i = 0; i < n; i++) {
        char ch = s[i];

        // If opening bracket, push to stack
        if (ch == '(' || ch == '{' || ch == '[') {
            push(stack, ch);
        }
        // If closing bracket, check stack
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty(stack)) {
                free(stack->arr);
                free(stack);
                return "NO";
            }
            char top = pop(stack);
            if (!isMatchingPair(top, ch)) {
                free(stack->arr);
                free(stack);
                return "NO";
            }
        }
    }

    // If stack empty => balanced
    char* result = isEmpty(stack) ? "YES" : "NO";

    free(stack->arr);
    free(stack);
    return result;
}

int main() {
    int n;
    scanf("%d", &n);
    char s[1000];

    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        printf("%s\n", isBalanced(s));
    }
    return 0;
}
