#include <stdio.h>
#include <ctype.h>

#define MAX_SIZE 100


typedef struct {
    char arr[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack* stack) {
    stack->top = -1;
}

int is_empty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, char value) {
    if (stack->top < MAX_SIZE - 1) {
        stack->arr[++(stack->top)] = value;
    }
}

char pop(Stack* stack) {
    if (!is_empty(stack)) {
        return stack->arr[(stack->top)--];
    }
    return '\0'; // Return null char if stack is empty
}

char peek(Stack* stack) {
    if (!is_empty(stack)) {
        return stack->arr[stack->top];
    }
    return '\0'; // Return null char if stack is empty
}


int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void infix_to_postfix(const char* infix) {
    Stack stack;
    initStack(&stack);
    char postfix[MAX_SIZE] = "";
    int k = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if (isalnum(ch)) {
            postfix[k++] = ch;
        } else if (ch == '(') {
       
            push(&stack, ch);
        } else if (ch == ')') {
        
            while (!is_empty(&stack) && peek(&stack) != '(')
                postfix[k++] = pop(&stack);
            pop(&stack); 
        } else {
            
            while (!is_empty(&stack) && precedence(peek(&stack)) >= precedence(ch))
                postfix[k++] = pop(&stack);
            push(&stack, ch);
        }
    }

 
    while (!is_empty(&stack))
        postfix[k++] = pop(&stack);
    postfix[k] = '\0';

    printf("Postfix: %s\n", postfix);

}
int evaluate_postfix(const char* postfix) {
Stack stack;
initStack(&stack);

for (int i = 0; postfix[i] != '\0'; i++) {
char ch = postfix[i];
if (isdigit(ch)) {
push(&stack, ch - '0');
} else {
int b = pop(&stack);
int a = pop(&stack);
switch (ch) {
case '+': push(&stack, a + b); break;
case '-': push(&stack, a - b); break;
case '*': push(&stack, a * b); break;
case '/': push(&stack, a / b); break;
}
}
}
return pop(&stack);
}
void reverseString(char *c , int n){
    Stack stack ;
    initStack(&stack);
    for(int i = 0 ; i < n ; i++){
        push(&stack , c[i]);
    }
    for(int i = 0 ; i < n ; i++){
        c[i] = peek(&stack);
        pop(&stack);
    }
    

}
int main() {
    // char infix[MAX_SIZE];
    // printf("Enter an infix expression: ");
    // gets(infix);

    // infix_to_postfix(infix);
    // evaluate_postfix("23*54*+");
    // printf("Result: %d\n", evaluate_postfix("236*54*+"));
     char c[] = "Hello";
    reverseString(c , 5);
    printf("Reversed string: %s\n", c);
    return 0;
}
