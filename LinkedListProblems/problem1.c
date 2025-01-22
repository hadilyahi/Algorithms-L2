#include <stdio.h>
#define MAX_SIZE 100
typedef struct Node {
    int value;
    struct Node* next;
} Node;

// function prototypes
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

Node* createNode(int value)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void deleteNode(Node* node)
{
    free(node);
}

int getValue(Node* node)
{
    return node ? node->value : -1; // Return -1 if node is NULL
}

void setValue(Node* node, int value)
{
    if (node)
    {
        node->value = value;
    }
}

Node* getNext(Node* node)
{
    return node ? node->next : NULL;
}

void setNext(Node* node, Node* nextNode)
{
    if (node)
    {
        node->next = nextNode;
    }
}

int isListEmpty(Node* head)
{
    return head == NULL;  // Return 1 if the list is empty, 0 otherwise
}



// problem 1 : Write a program in C to create and display a Singly Linked List.
struct Node* initializeList() {
    int n;
    printf("Enter The number of nodes : ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Enter number of node large to 0 \n");
        return NULL; 
    }

    int value;
    printf("Enter the first node value: ");
    scanf("%d", &value);

    struct Node* head = createNode(value); 
    struct Node* current = head;

  
    for (int i = 2; i <= n; i++) {
        printf("Enter The Value of node %d : ", i);
        scanf("%d", &value);
         Node* newNode = createNode(value);
        setNext(current, newNode);
        current = newNode;
    }

    return head;
}
// problem 2 :  Write a program in C to create a singly linked list of n nodes and display it in reverse order.
Node* ReverseList(Node* head)
    {
        Node* prev = NULL;  
        Node* current = head;
        Node* next = NULL;

        while (current)
        {
            next = getNext(current);
            setNext(current, prev);
            prev = current;
            current = next;
        }
        return prev;
    }
// problem 3 :  Write a program in C to create a singly linked list of n nodes and count the number of nodes.
int countNodes(Node* head)
{
    int count = 0;
    Node* current = head;
    while (current)
    {
        count++;
        current = getNext(current);
    }
    return count;
}
    
// problem 4 : Write a program in C to insert a new node at the beginning of a Singly Linked List.
 Node* insertAtBeginning(Node* head, int value){
    Node* newNode = createNode(value);
    setNext(newNode, head);
    return newNode;
 }
// problem 5 :  Write a program in C to insert a new node at the end of a Singly Linked List.
Node* insertAtEnd(Node* head, int value)
{
    Node* newNode = createNode(value);
    if (isListEmpty(head))
    {
        return newNode;
    }

    Node* current = head;
    while (getNext(current))
    {
        current = getNext(current);
    }

    setNext(current, newNode);
    return head;
}
// problem 6 : Write a program in C to insert a new node at the middle of a Singly Linked List.
Node *insertAtMiddle(Node *head, int value, int position)
{
    Node *newNode = createNode(value);
    if (position <= 1)
    {
        setNext(newNode, head);
        return newNode;
    }

    Node *current = head; 
    for (int i = 1; i < position - 1; i++) 
    {
        if (current == NULL)
        {
            return head;
        }
        current = getNext(current);
    }

    if (current == NULL)
    {
        return head;
    }

    setNext(newNode, getNext(current));
    setNext(current, newNode);
    return head;
}
// problem 7 :  Write a program in C to delete the first node of a Singly Linked List.
Node* deleteFirstNode(Node* head)
{
    if (isListEmpty(head))
    {
        return NULL;
    }

    Node* newHead = getNext(head);
    deleteNode(head);
    return newHead;
}

// reverse the linked list by stack 
Node* reverseList(Node* head)
{
    Stack stack;
    initStack(&stack);

    Node* current = head;
    while (current)
    {
        push(&stack, getValue(current));
        current = getNext(current);
    }

    current = head;
    while (current)
    {
        setValue(current, peek(&stack));
        pop(&stack);
        current = getNext(current);
    }

    return head;
}

int main(){
    // // problem 1 : Write a program in C to create and display a Singly Linked List.
    // Node* head = initializeList();
    // Node* current = head;

    // while (current)
    // {
    //     printf("%d ", getValue(current));
    //     current = getNext(current);
    // }
    //  // problem 2 :  Write a program in C to create a singly linked list of n nodes and display it in reverse order.
    // Node* head = initializeList(); 
    // Node* reversedList = ReverseList(head); 
    // Node* current = reversedList; 

    // while (current) {
    //     printf("%d ", getValue(current)); 
    //     current = getNext(current); 
    // }
    // // problem 3 :  Write a program in C to create a singly linked list of n nodes and count the number of nodes.
    //  Node* head = initializeList();
    //     int count = countNodes(head);
    //     printf("Number of nodes: %d", count);
    // // problem 4 : Write a program in C to insert a new node at the beginning of a Singly Linked List.
    // Node* head = initializeList();
    // int value;
    // printf("Enter the value to insert at the beginning: ");
    // scanf("%d", &value);
    // head = insertAtBeginning(head, value);
    // Node* current = head;
    // while (current)
    // {
    //     printf("%d ", getValue(current));
    //     current = getNext(current);
    // }
    // problem 5 :  Write a program in C to insert a new node at the end of a Singly Linked List.
    // Node* head = initializeList();
    // int value;
    // printf("Enter the value to insert at the end: ");
    // scanf("%d", &value);
    // head = insertAtEnd(head, value);
    // Node* current = head;
    // while (current!=NULL)
    // {
    //     printf("%d ", getValue(current));
    //     current = getNext(current);
    // }
    // problem 6 : Write a program in C to insert a new node at the middle of a Singly Linked List.
    //  Node* head = initializeList();
    // int value, position;
    // printf("Enter the value to insert: ");
    // scanf("%d", &value);
    // printf("Enter the position to insert: ");
    // scanf("%d", &position);
    // head = insertAtMiddle(head, value, position);
    // Node* current = head;
    // while (current)
    // {
    //     printf("%d ", getValue(current));
    //     current = getNext(current);
    // }

 // reverse the linked list by stack
     Node* head = initializeList();
    head = reverseList(head);
    Node* current = head;
    while (current)
    {
        printf("%d ", getValue(current));
        current = getNext(current);
    }


   



    

    return 0;
}