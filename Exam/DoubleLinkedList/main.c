#include <stdio.h>
#include "list.h"

void reverse(Node** head) {
    if (isListEmpty(*head)) {
        printf("The list is empty.\n");
        return;
    }

    Node* current = *head;
    Node* temp = NULL;

    while (current != NULL) {
        temp = getPrev(current);
        setPrev(current, getNext(current));
        setNext(current, temp);

        current = getPrev(current); 
    }

 
    if (temp != NULL) {
        *head = getPrev(temp);
    }
}

void printList(Node* head) {
    while (head != NULL) {
        printf("%d ", getValue(head));
        head = getNext(head);
    }
    printf("\n");
}
int main() {




    Node* head = createNode(1);
    Node* node2 = createNode(2);
    Node* node3 = createNode(3);
    Node* node4 = createNode(4);

 
    setNext(head, node2);
    setPrev(node2, head);

    setNext(node2, node3);
    setPrev(node3, node2);

    setNext(node3, node4);
    setPrev(node4, node3);

    printf("Original list: ");
    printList(head);

    reverse(&head);

    printf("Reversed list: ");
    printList(head);

 


    return 0;
}
