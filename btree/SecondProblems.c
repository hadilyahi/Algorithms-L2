#include "binary_tree.h"
#include <stdbool.h>
#include <math.h>

// problem 6:
int getHeight(TreeNode* root) {
    if (isTreeEmpty(root)) {
        return -1;
    }
    int leftHeight = getHeight(getLeft(root));
    int rightHeight = getHeight(getRight(root));
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}
int countNodes(TreeNode* root) {
    if (isTreeEmpty(root)) {
        return 0;
    }
    return 1 + countNodes(getLeft(root)) + countNodes(getRight(root));
}
bool isPerfectBinaryTree(TreeNode* root) {
    int height = getHeight(root);
    int totalNodes = countNodes(root);

  
    int expectedNodes = pow(2, height + 1) - 1;

    return totalNodes == expectedNodes;
}
// problem 7:
TreeNode* insertBST(TreeNode* root, int value) { 
    if (isTreeEmpty(root)) {
        return createNode(value);
    }
    if (value < getValue(root)) {
        setLeft(root, insertBST(getLeft(root), value));
    }
    else {
        setRight(root, insertBST(getRight(root), value));
    }

    return root; 
}
void inorderTraversal(TreeNode* root) {
    if (!isTreeEmpty(root)) {
        inorderTraversal(getLeft(root));
        printf("%d ", getValue(root));  
        inorderTraversal(getRight(root)); 
    }
}
// problem 8:
TreeNode* findMin(TreeNode* root) {
    while (!isTreeEmpty(getLeft(root))) {
        root = getLeft(root);
    }
    return root;
}
TreeNode* deleteBST(TreeNode* root, int value) {
    if (isTreeEmpty(root)) {
        return NULL;
    }
    if (value < getValue(root)) {
        setLeft(root, deleteBST(getLeft(root), value));
    } else if (value > getValue(root)) {
        setRight(root, deleteBST(getRight(root), value));
    } else {
        if (isTreeEmpty(getLeft(root)) && isTreeEmpty(getRight(root))) {
            deleteNode(root);
            return NULL;
        }
        else if (isTreeEmpty(getLeft(root))) {
            TreeNode* temp = getRight(root);
            deleteNode(root);
            return temp;
        } else if (isTreeEmpty(getRight(root))) {
            TreeNode* temp = getLeft(root);
            deleteNode(root);
            return temp;
        }
        else {
            TreeNode* temp = findMin(getRight(root)); 
            setValue(root, getValue(temp));
            setRight(root, deleteBST(getRight(root), getValue(temp)));
        }
    }
    return root;
}
// problem 9:
bool isMirror(TreeNode* leftSubtree, TreeNode* rightSubtree) {
    if (isTreeEmpty(leftSubtree) && isTreeEmpty(rightSubtree)) {
        return true;
    }
    if (isTreeEmpty(leftSubtree) || isTreeEmpty(rightSubtree)) {
        return false;
    }
    return (getValue(leftSubtree) == getValue(rightSubtree)) &&
           isMirror(getLeft(leftSubtree), getRight(rightSubtree)) &&
           isMirror(getRight(leftSubtree), getLeft(rightSubtree));
}
bool isSymmetric(TreeNode* root) {
    if (isTreeEmpty(root)) {
        return true;
    }
    return isMirror(getLeft(root), getRight(root));
}
// problem 10 :
int getNodeDepth(TreeNode* root, int value, int depth) {
    if (isTreeEmpty(root)) {
        return -1; 
    }

    if (getValue(root) == value) {
        return depth;
    }
    int leftDepth = getNodeDepth(getLeft(root), value, depth + 1);
    if (leftDepth != -1) {
        return leftDepth;
    }
    return getNodeDepth(getRight(root), value, depth + 1);
}
int findDepth(TreeNode* root, int value) {
    return getNodeDepth(root, value, 0);
}

int main() {
    // problem 6:
    // TreeNode* root = createNode(1);
    // setLeft(root, createNode(2));
    // setRight(root, createNode(3));
    // setLeft(getLeft(root), createNode(4));
    // setRight(getLeft(root), createNode(5));
    // setLeft(getRight(root), createNode(6));
    // setRight(getRight(root), createNode(7));
    // if (isPerfectBinaryTree(root)) {
    //     printf("The Tree in Perfecte\n");
    // } else {
    //     printf("The Tree not Perfect\n");
    // }
    // problem 7:
    // TreeNode* root = NULL; 
    // root = insertBST(root, 50);
    // root = insertBST(root, 30);
    // root = insertBST(root, 70);
    // root = insertBST(root, 20);
    // printf(" binary tree : ");
    // inorderTraversal(root);
    // printf("\n");
    // problem 8:
    // TreeNode* root = NULL;
    // root = insertBST(root, 50);
    // root = insertBST(root, 30);
    // root = insertBST(root, 70);
    // root = insertBST(root, 20);
    // root = insertBST(root, 40);
    // root = insertBST(root, 60);
    // root = insertBST(root, 80);
    // printf("Before deletion");
    // inorderTraversal(root);
    // printf("\n");
    // root = deleteBST(root, 50);
    // printf("After Deletion ");
    // inorderTraversal(root);
    // printf("\n");
    // problem 9:
    // TreeNode* root = createNode(1);
    // setLeft(root, createNode(2));
    // setRight(root, createNode(2));
    // setLeft(getLeft(root), createNode(3));
    // setRight(getLeft(root), createNode(4));
    // setLeft(getRight(root), createNode(4));
    // setRight(getRight(root), createNode(3));
    // if (isSymmetric(root)) {
    //     printf("Tree Symmetry\n");
    // } else {
    //     printf("Tree Not Symmetry\n");
    // }
    // problem 10 :
    TreeNode* root = createNode(1);
    setLeft(root, createNode(2));
    setRight(root, createNode(3));
    setLeft(getLeft(root), createNode(4));
    setRight(getLeft(root), createNode(5));
    int value = 5;
    int depth = findDepth(root, value);
    if (depth != -1) {
        printf("The depth of node %d is: %d\n", value, depth);
    } else {
        printf("Node %d is not found in the tree.\n", value);
    }
    


    return 0;
}