#include <stdio.h>
#include "list.h"


void insertNode(struct Node** head, int value, int k) {
    
    if (k == 0) {
        struct Node* newNode = createNode(value);
        setNext(newNode, *head); 
        *head = newNode;
        return;
    }

    struct Node* current = *head;
    int index = 0;
    while (current != NULL && index < k - 1) {
        current = getNext(current);
        index++;
    }

   
    if (current == NULL) {
        printf(" Index out of bounds\n");
        return;
    }

    struct Node* newNode = createNode(value);
    setNext(newNode, getNext(current));  
    setNext(current, newNode);  
}

void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", getValue(current));
        current = getNext(current);
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;  

    insertNode(&head, 10, 0); 
    insertNode(&head, 20, 1);  
    insertNode(&head, 15, 1);  

    printList(head); 

   
    insertNode(&head, 25, 5);  

    
    insertNode(&head, 5, 0);  
    printList(head);  

    return 0;
}