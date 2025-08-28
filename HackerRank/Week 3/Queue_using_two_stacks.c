#include <stdio.h>
#include <stdlib.h>

// Stack structure
typedef struct {
    int* arr;
    int top;
    int capacity;
} Stack;

// Create a stack
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = (int*)malloc(capacity * sizeof(int));
    return stack;
}

// Push element
void push(Stack* stack, int value) {
    stack->arr[++stack->top] = value;
}

// Pop element
int pop(Stack* stack) {
    return stack->arr[stack->top--];
}

// Peek element
int peek(Stack* stack) {
    return stack->arr[stack->top];
}

// Check if empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

int main() {
    int q;
    scanf("%d", &q);

    Stack* stack_in = createStack(100000);
    Stack* stack_out = createStack(100000);

    for (int i = 0; i < q; i++) {
        int type;
        scanf("%d", &type);

        if (type == 1) {
            int x;
            scanf("%d", &x);
            push(stack_in, x);
        } else if (type == 2) {
            if (isEmpty(stack_out)) {
                while (!isEmpty(stack_in)) {
                    push(stack_out, pop(stack_in));
                }
            }
            pop(stack_out);
        } else if (type == 3) {
            if (isEmpty(stack_out)) {
                while (!isEmpty(stack_in)) {
                    push(stack_out, pop(stack_in));
                }
            }
            printf("%d\n", peek(stack_out));
        }
    }

    return 0;
}
