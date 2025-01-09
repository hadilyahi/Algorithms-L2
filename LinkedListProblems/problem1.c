#include <stdio.h>
typedef struct Node {
    int value;
    struct Node* next;
} Node;

// function prototypes
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
        struct Node* newNode = createNode(value);
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
int main(){
    // problem 1 : Write a program in C to create and display a Singly Linked List.
    Node* head = initializeList();
    Node* current = head;

    while (current)
    {
        printf("%d ", getValue(current));
        current = getNext(current);
    }
     // problem 2 :  Write a program in C to create a singly linked list of n nodes and display it in reverse order.
    Node* head = initializeList(); 
    Node* reversedList = ReverseList(head); 
    Node* current = reversedList; 

    while (current) {
        printf("%d ", getValue(current)); 
        current = getNext(current); 
    }
    // problem 3 :  Write a program in C to create a singly linked list of n nodes and count the number of nodes.
     Node* head = initializeList();
        int count = countNodes(head);
        printf("Number of nodes: %d", count);
    // problem 4 : Write a program in C to insert a new node at the beginning of a Singly Linked List.
    Node* head = initializeList();
    int value;
    printf("Enter the value to insert at the beginning: ");
    scanf("%d", &value);
    head = insertAtBeginning(head, value);
    Node* current = head;
    while (current)
    {
        printf("%d ", getValue(current));
        current = getNext(current);
    }
    

    return 0;
}