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

int searchGlobally(Tree* tab, int N, int value) {
    for (int i = 0; i < N; i++) {
        if (tab[i] != NULL && searchInTree(tab[i], value)) {
            return i;
        }
    }
    return -1;
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
    tab[1] = createNode(20, createNode(18, NULL, NULL), createNode(25, NULL, NULL));

   

    int value;
    printf("Enter the value to search for globally: ");
    scanf("%d", &value);

    int index = searchGlobally(tab, N, value);
    if (index != -1) {
        printf("La valeur %d est trouvée dans l'arbre à l'index %d.\n", value, index);
    } else {
        printf("La valeur %d n'existe pas dans les arbres du tableau.\n", value);
    }

    return 0;
}
