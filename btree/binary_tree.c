// binary_tree.c
#include "binary_tree.h"

// Function to create a new tree node with a given value
TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to delete a node (free its memory)
void deleteNode(TreeNode* node) {
    if (node != NULL) {
        free(node);
    }
}

// Function to get the value stored in a node
int getValue(TreeNode* node) {
    return node ? node->value : -1;
}

// Function to set the value of a node
void setValue(TreeNode* node, int value) {
    if (node != NULL) {
        node->value = value;
    }
}

// Function to get the left child of a node
TreeNode* getLeft(TreeNode* node) {
    return node ? node->left : NULL;
}

// Function to set the left child for a given node
void setLeft(TreeNode* node, TreeNode* leftNode) {
    if (node != NULL) {
        node->left = leftNode;
    }
}

// Function to get the right child of a node
TreeNode* getRight(TreeNode* node) {
    return node ? node->right : NULL;
}

// Function to set the right child for a given node
void setRight(TreeNode* node, TreeNode* rightNode) {
    if (node != NULL) {
        node->right = rightNode;
    }
}

// Function to check if a tree is empty (i.e., root is NULL)
int isTreeEmpty(TreeNode* root) {
    return root == NULL;
}
