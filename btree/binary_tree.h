// binary_tree.h
#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>

// Definition of a TreeNode structure
typedef struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Function prototypes
TreeNode* createNode(int value);
void deleteNode(TreeNode* node);
int getValue(TreeNode* node);
void setValue(TreeNode* node, int value);
TreeNode* getLeft(TreeNode* node);
void setLeft(TreeNode* node, TreeNode* leftNode);
TreeNode* getRight(TreeNode* node);
void setRight(TreeNode* node, TreeNode* rightNode);
int isTreeEmpty(TreeNode* root);

#endif // BINARY_TREE_H
