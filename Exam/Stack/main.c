#include "stack.h"
#include <stdio.h>
#include <ctype.h>









int precedence(char op) {
    switch (op) {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        default: return 0;
    }
}

void infix_to_postfix(const char* infix, char* postfix) {
    Stack stack;
    initStack(&stack);
    int k = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if (isalnum(ch)) {
            postfix[k++] = ch;
        } else if (ch == '(') {
            push(&stack, ch);
        } else if (ch == ')') {
            while (!is_empty(&stack) && peek(&stack) != '(') {
                postfix[k++] = pop(&stack);
            }
            pop(&stack); 
        } else {
            while (!is_empty(&stack) && precedence(peek(&stack)) >= precedence(ch)) {
                postfix[k++] = pop(&stack);
            }
            push(&stack, ch);
        }
    }

    while (!is_empty(&stack)) {
        postfix[k++] = pop(&stack);
    }

    postfix[k] = '\0';
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


int main() {
   
    Stack stack;
    initStack(&stack);
    // const char* infix = "A+B*(C-D)+E/F";
    // char postfix[100];
    // infix_to_postfix(infix, postfix);
    // printf("Postfix: %s\n", postfix);


    const char* postfix = "236*54*+";
    printf("Result: %d\n", evaluate_postfix(postfix));
  

   
    return 0;
}
