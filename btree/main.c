#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"
#include <stdbool.h> 

// Problem 1 : 
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

// Problem 2:
int getHeight(TreeNode* root) {
    if (isTreeEmpty(root)) {
        return -1;
    }
    
    int leftHeight = getHeight(getLeft(root));
    int rightHeight = getHeight(getRight(root));

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// problem 3 :
int countNodes(TreeNode* root) {
    if (isTreeEmpty(root)) {
        return 0;
    }
    
    return 1 + countNodes(getLeft(root)) + countNodes(getRight(root));
}

// problem 4 :
int countLeafNodes(TreeNode* root) {
    if (isTreeEmpty(root)) {
        return 0; 
    }   
    if (getLeft(root) == NULL && getRight(root) == NULL) {
        return 1; 
    }
    return countLeafNodes(getLeft(root)) + countLeafNodes(getRight(root));
}

// problem 5 :
bool isFullBinaryTree(TreeNode* root) {
    if (isTreeEmpty(root)) {
        return true;
    }
    if (getLeft(root) == NULL && getRight(root) == NULL) {
        return true;
    }
    if (getLeft(root) != NULL && getRight(root) != NULL) {
        return isFullBinaryTree(getLeft(root)) && isFullBinaryTree(getRight(root));
    }
    return false;
}
int main() {
    
    // problem 1 :

    // TreeNode* root = createNode(1);
    // setLeft(root, createNode(2));
    // setRight(root, createNode(3));
    // setLeft(getLeft(root), createNode(4));
    // setRight(getLeft(root), createNode(5));
    // setLeft(getRight(root), createNode(6));
    // setRight(getRight(root), createNode(7));

    // printf("Pre-order Traversal: ");
    // preOrder(root);
    // printf("\n");

    // printf("In-order Traversal: ");
    // inOrder(root);
    // printf("\n");

    // printf("Post-order Traversal: ");
    // postOrder(root);
    // printf("\n");

    // printf("Level-order Traversal: ");
    // levelOrder(root);
    // printf("\n");

    // problem 2: 

    // TreeNode* root = createNode(10);
    // setLeft(root, createNode(20));
    // setRight(root, createNode(30));
    // setLeft(getLeft(root), createNode(40));
    // setRight(getLeft(root), createNode(50));
    // setLeft(getRight(root), createNode(60));
    // setRight(getRight(root), createNode(70));
    // setLeft(getLeft(getLeft(root)), createNode(80));


    // printf("Height of the tree: %d\n", getHeight(root));

    // problem 3 : 
    // TreeNode* root = createNode(10);
    // setLeft(root, createNode(20));
    // setRight(root, createNode(30));
    // setLeft(getLeft(root), createNode(40));
    // setRight(getLeft(root), createNode(50));
    // setLeft(getRight(root), createNode(60));
    // setRight(getRight(root), createNode(70));
    // setLeft(getLeft(getLeft(root)), createNode(80));
    // printf("Total number of nodes: %d\n", countNodes(root));

    // problem 4 :
        // TreeNode* root = createNode(10);
        // setLeft(root, createNode(20));
        // setRight(root, createNode(30));
        // setLeft(getLeft(root), createNode(40));
        // setRight(getLeft(root), createNode(50));
        // setLeft(getRight(root), createNode(60));
        // setRight(getRight(root), createNode(70));
        // setLeft(getLeft(getLeft(root)), createNode(80));
        // printf("Total number of leaf nodes: %d\n", countLeafNodes(root));

    // problem 5 :
    TreeNode* root = createNode(1);
    setLeft(root, createNode(2));
    setRight(root, createNode(3));
    setLeft(getLeft(root), createNode(4));
    setRight(getLeft(root), createNode(5));
    setLeft(getRight(root), createNode(6)); 
    if (isFullBinaryTree(root)) {
        printf("The tree is a Full Binary Tree.\n");
    } else {
        printf("The tree is NOT a Full Binary Tree.\n");
    }

    
    
    


    return 0;
}
