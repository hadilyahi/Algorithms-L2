#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "stack.h"

// Using Single Queue Stack:
typedef struct {
    Queue q;
} SingleQueueStack;

void initSingleQueueStack(SingleQueueStack* stack) {
    initializeQueue(&stack->q);
}


int isEmptySingleQueueStack(SingleQueueStack* stack) {
    return is_empty(&stack->q);
}

void pushSingleQueueStack(SingleQueueStack* stack, int value) {
    enqueue(&stack->q, value);
    int size = stack->q.rear;

  
    for (int i = 0; i < size - 1; i++) {
        enqueue(&stack->q, dequeue(&stack->q));
    }
}


int popSingleQueueStack(SingleQueueStack* stack) {
    if (isEmptySingleQueueStack(stack)) {
        printf("Stack is empty, cannot pop\n");
        return -1;
    }
    return dequeue(&stack->q);
}

int peekSingleQueueStack(SingleQueueStack* stack) {
    if (isEmptySingleQueueStack(stack)) {
        printf("Stack is empty, cannot peek\n");
        return -1;
    }
    return peek(&stack->q);
}

// Using Two Queue Stack:
typedef struct {
    Queue q1;
    Queue q2;
} TwoQueueStack;

void initTwoQueueStack(TwoQueueStack* stack) {
    initializeQueue(&stack->q1);
    initializeQueue(&stack->q2);
}


int isEmptyTwoQueueStack(TwoQueueStack* stack) {
    return is_empty(&stack->q1) && is_empty(&stack->q2);
}


void pushTwoQueueStack(TwoQueueStack* stack, int value) {
    enqueue(&stack->q2, value);

    while (!is_empty(&stack->q1)) {
        enqueue(&stack->q2, dequeue(&stack->q1));
    }

    
    Queue temp = stack->q1;
    stack->q1 = stack->q2;
    stack->q2 = temp;
}


int popTwoQueueStack(TwoQueueStack* stack) {
    if (isEmptyTwoQueueStack(stack)) {
        printf("Stack is empty, cannot pop\n");
        return -1;
    }
    return dequeue(&stack->q1);
}


int peekTwoQueueStack(TwoQueueStack* stack) {
    if (isEmptyTwoQueueStack(stack)) {
        printf("Stack is empty, cannot peek\n");
        return -1;
    }
    return peek(&stack->q1);
}


int main() {
    printf("Using Single Queue Stack:\n");
    SingleQueueStack singleStack;
    initSingleQueueStack(&singleStack);

    pushSingleQueueStack(&singleStack, 10);
    pushSingleQueueStack(&singleStack, 20);
    pushSingleQueueStack(&singleStack, 30);

    printf("Top element: %d\n", peekSingleQueueStack(&singleStack));
    printf("Popped: %d\n", popSingleQueueStack(&singleStack));
    printf("Popped: %d\n", popSingleQueueStack(&singleStack));

    printf("\nUsing Two Queue Stack:\n");
    TwoQueueStack twoStack;
    initTwoQueueStack(&twoStack);

    pushTwoQueueStack(&twoStack, 10);
    pushTwoQueueStack(&twoStack, 20);
    pushTwoQueueStack(&twoStack, 30);

    printf("Top element: %d\n", peekTwoQueueStack(&twoStack));
    printf("Popped: %d\n", popTwoQueueStack(&twoStack));

    return 0;
}
