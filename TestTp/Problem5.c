#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct node {
    int val;
    struct node* left;
    struct node* right;
} node, *Tree;


void initTab(Tree* tab, int N) {
    for (int i = 0; i < N; i++) {
        tab[i] = NULL;
    }
}


Tree createNode(int val, Tree Left, Tree Right) {
    Tree a = (Tree)malloc(sizeof(node));
    if (a == NULL) return NULL;
    a->val = val;
    a->left = Left;
    a->right = Right;
    return a;
}


bool searchInTree(Tree tree, int value) {
    if (tree == NULL) {
        return false; 
    }
    if (tree->val == value) {
        return true; 
    }

    if (value < tree->val) {
        return searchInTree(tree->left, value);
    } else {
        return searchInTree(tree->right, value);
    }
}


void searchInSpecificTree(Tree* tab, int N, int index, int value) {
    if (index < 0 || index >= N) {
        printf("Erreur : index hors limites du tableau.\n");
        return;
    }
    if (tab[index] == NULL) {
        printf("L'arbre à l'index %d est vide.\n", index);
        return;
    }
    if (searchInTree(tab[index], value)) {
        printf("La valeur %d est trouvée dans l'arbre à l'index %d.\n", value, index);
    } else {
        printf("La valeur %d n'est pas trouvée dans l'arbre à l'index %d.\n", value, index);
    }
}


void prefix(Tree a) {
    if (a == NULL) return;
    printf("%d ", a->val);
    prefix(a->left);
    prefix(a->right);
}

int main() {
    int N;
    printf("Enter the number of TABLES: ");
    scanf("%d", &N);

    Tree tab[N];
    initTab(tab, N);


    tab[0] = createNode(10, createNode(5, NULL, NULL), createNode(15, NULL, NULL));

  
    printf("Contenu de l'arbre à l'index 0 (ordre préfixe) : ");
    prefix(tab[0]);
    printf("\n");

    int index, value;
    printf("Enter the index of the tree to search: ");
    scanf("%d", &index);
    printf("Enter the value to search for: ");
    scanf("%d", &value);

    searchInSpecificTree(tab, N, index, value);

    return 0;
}
