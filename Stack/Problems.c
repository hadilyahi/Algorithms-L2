#include <stdio.h>

#define MAX_SIZE 100
struct Stack {
    int items[MAX_SIZE];
    int top;
};

// Implementation of stack.c:
// Initialize the stack
void initStack(struct Stack* stack) {
stack->top = -1;
}
// Check if the stack is empty
int is_empty(const struct Stack* stack) {
return stack->top == -1;
}
// Check if the stack is full
int is_full(const struct Stack* stack) {
return stack->top == MAX_SIZE - 1;
}
// Push an item onto the stack

void push(struct Stack* stack, int item) {
if (is_full(stack)) {
printf("Stack Overflow! Cannot push %d\n", item);
return;
}
stack->items[++stack->top] = item;
}
// Pop an item from the stack
int pop(struct Stack* stack) {
if (is_empty(stack)) {
printf("Stack Underflow! Cannot pop.\n");
return -1; // Error value
}
return stack->items[stack->top--];
}
// Peek the top item of the stack
int peek(const struct Stack* stack) {
if (is_empty(stack)) {
printf("Stack is empty! Cannot peek.\n");
return -1; // Error value
}
return stack->items[stack->top];
}
// Clear the stack
void clear(struct Stack* stack) {
stack->top = -1;
}

int is_matching_pair(char opening, char closing) {
return (opening == '(' && closing == ')') ||
(opening == '{' && closing == '}') ||

(opening == '[' && closing == ']');
}
// Check for balanced parentheses
void check_parentheses(const char* expression) {
struct  Stack stack;
initStack(&stack);
for (int i = 0; i < strlen(expression); i++) {
char ch = expression[i];
if (ch == '(' || ch == '{' || ch == '[') {
push(&stack, ch);
} else if (ch == ')' || ch == '}' || ch == ']') {
if (is_empty(&stack) || !is_matching_pair(pop(&stack), ch)) {
printf("Unbalanced\n");
return;
}
}
}
printf(is_empty(&stack) ? "Balanced\n" : "Unbalanced\n");
}
int main() {
char expression[MAX_SIZE];
printf("Enter an expression: ");
scanf("%s", expression);
check_parentheses(expression);
return 0;
}