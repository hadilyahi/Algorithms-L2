#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"


void preOrder(TreeNode* root) {
    if (!isTreeEmpty(root)) {
        printf("%d ", getValue(root));
        preOrder(getLeft(root));
        preOrder(getRight(root));
    }
}


void inOrder(TreeNode* root) {
    if (!isTreeEmpty(root)) {
        inOrder(getLeft(root));
        printf("%d ", getValue(root));
        inOrder(getRight(root));
    }
}


void postOrder(TreeNode* root) {
    if (!isTreeEmpty(root)) {
        postOrder(getLeft(root));
        postOrder(getRight(root));
        printf("%d ", getValue(root));
    }
}


void levelOrder(TreeNode* root) {
    if (isTreeEmpty(root)) return;

    TreeNode* queue[100];
    int front = 0, rear = 0;
    
    queue[rear++] = root; 

    while (front < rear) {
        TreeNode* current = queue[front++]; 
        printf("%d ", getValue(current));

        if (getLeft(current) != NULL)
            queue[rear++] = getLeft(current);
        if (getRight(current) != NULL)
            queue[rear++] = getRight(current);
    }
}

int main() {
   
    TreeNode* root = createNode(1);
    setLeft(root, createNode(2));
    setRight(root, createNode(3));
    setLeft(getLeft(root), createNode(4));
    setRight(getLeft(root), createNode(5));
    setLeft(getRight(root), createNode(6));
    setRight(getRight(root), createNode(7));

    printf("Pre-order Traversal: ");
    preOrder(root);
    printf("\n");

    printf("In-order Traversal: ");
    inOrder(root);
    printf("\n");

    printf("Post-order Traversal: ");
    postOrder(root);
    printf("\n");

    printf("Level-order Traversal: ");
    levelOrder(root);
    printf("\n");

    return 0;
}
