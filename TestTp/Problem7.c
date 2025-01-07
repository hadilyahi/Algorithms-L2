#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node {
    int val;
    struct node* left;
    struct node* right;
} node, *Tree;

Tree createNode(int val, Tree left, Tree right) {
    Tree newNode = (Tree)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Erreur d'allocation mémoire\n");
        exit(1);
    }
    newNode->val = val;
    newNode->left = left;
    newNode->right = right;
    return newNode;
}

int countNodes(Tree tree) {
    if (tree == NULL) return 0;
    return 1 + countNodes(tree->left) + countNodes(tree->right);
}

int findMinValue(Tree tree) {
    if (tree == NULL) return INT_MAX;
    int leftMin = findMinValue(tree->left);
    return (tree->val < leftMin) ? tree->val : leftMin;
}

int findMaxValue(Tree tree) {
    if (tree == NULL) return INT_MIN;
    int rightMax = findMaxValue(tree->right);
    return (tree->val > rightMax) ? tree->val : rightMax;
}

void calculateStatistics(Tree* tab, int N) {
    int minNodesIndex = -1, maxNodesIndex = -1;
    int minValueIndex = -1, maxValueIndex = -1;
    int minNodes = INT_MAX, maxNodes = INT_MIN;
    int globalMinValue = INT_MAX, globalMaxValue = INT_MIN;

    for (int i = 0; i < N; i++) {
        if (tab[i] == NULL) continue;

        int nodeCount = countNodes(tab[i]);
        int minValue = findMinValue(tab[i]);
        int maxValue = findMaxValue(tab[i]);

        if (nodeCount < minNodes) {
            minNodes = nodeCount;
            minNodesIndex = i;
        }
        if (nodeCount > maxNodes) {
            maxNodes = nodeCount;
            maxNodesIndex = i;
        }
        if (minValue < globalMinValue) {
            globalMinValue = minValue;
            minValueIndex = i;
        }
        if (maxValue > globalMaxValue) {
            globalMaxValue = maxValue;
            maxValueIndex = i;
        }
    }

    printf("Case contenant l'arbre avec le moins de nœuds : %d (%d nœuds)\n", minNodesIndex, minNodes);
    printf("Case contenant l'arbre avec le plus de nœuds : %d (%d nœuds)\n", maxNodesIndex, maxNodes);
    printf("Case contenant l'arbre avec la valeur minimale : %d (valeur = %d)\n", minValueIndex, globalMinValue);
    printf("Case contenant l'arbre avec la valeur maximale : %d (valeur = %d)\n", maxValueIndex, globalMaxValue);
}

int main() {
    int N;
    printf("Enter the number of TABLES: ");
    scanf("%d", &N);

    Tree tab[N];
    for (int i = 0; i < N; i++) {
        tab[i] = NULL;
    }

    tab[0] = createNode(10, createNode(5, NULL, NULL), createNode(15, NULL, NULL));
    tab[1] = createNode(20, createNode(18, NULL, NULL), createNode(25, NULL, NULL));
    tab[2] = createNode(7, createNode(3, NULL, NULL), NULL);

    calculateStatistics(tab, N);

    return 0;
}
