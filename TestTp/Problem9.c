#include <stdio.h>
#include <stdlib.h>

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

void prefix(Tree tree) {
    if (tree == NULL) return;
    printf("%d ", tree->val);
    prefix(tree->left);
    prefix(tree->right);
}

void infix(Tree tree) {
    if (tree == NULL) return;
    infix(tree->left);
    printf("%d ", tree->val);
    infix(tree->right);
}

void postfix(Tree tree) {
    if (tree == NULL) return;
    postfix(tree->left);
    postfix(tree->right);
    printf("%d ", tree->val);
}

void displayTreeOrders(Tree* tab, int N) {
    int index;
    printf("Entrez l'indice de l'arbre à afficher (0 à %d) : ", N - 1);
    scanf("%d", &index);

    if (index < 0 || index >= N || tab[index] == NULL) {
        printf("Aucun arbre à cet indice.\n");
        return;
    }

    printf("Ordre Préfixe : ");
    prefix(tab[index]);
    printf("\n");

    printf("Ordre Infixe : ");
    infix(tab[index]);
    printf("\n");

    printf("Ordre Postfixe : ");
    postfix(tab[index]);
    printf("\n");
}

void addValue(Tree* tab, int N) {
    int index, val;
    printf("Entrez l'indice de l'arbre (0 à %d) : ", N - 1);
    scanf("%d", &index);
    if (index < 0 || index >= N) {
        printf("Indice invalide.\n");
        return;
    }
    printf("Entrez la valeur à ajouter : ");
    scanf("%d", &val);

    Tree newNode = createNode(val, NULL, NULL);
    if (tab[index] == NULL) {
        tab[index] = newNode;
    } else {
        Tree current = tab[index];
        while (1) {
            if (val < current->val) {
                if (current->left == NULL) {
                    current->left = newNode;
                    break;
                }
                current = current->left;
            } else {
                if (current->right == NULL) {
                    current->right = newNode;
                    break;
                }
                current = current->right;
            }
        }
    }
    printf("Valeur ajoutée avec succès.\n");
}

void interactiveMenu(Tree* tab, int N) {
    int choice;

    while (1) {
        printf("\n=== MENU INTERACTIF ===\n");
        printf("1. Ajouter une valeur à un arbre\n");
        printf("2. Afficher un arbre dans différents ordres\n");
        printf("3. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addValue(tab, N);
                break;
            case 2:
                displayTreeOrders(tab, N);
                break;
            case 3:
                printf("Au revoir !\n");
                return;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    }
}

int main() {
    int N;
    printf("Entrez le nombre de TABLES : ");
    scanf("%d", &N);

    Tree tab[N];
    for (int i = 0; i < N; i++) {
        tab[i] = NULL;
    }
    tab[0] = createNode(10, createNode(5, NULL, NULL), createNode(15, NULL, NULL));
    tab[1] = createNode(20, createNode(18, NULL, NULL), createNode(25, NULL, NULL));
    tab[1] = createNode(20, createNode(6, NULL, NULL), createNode(2, NULL, NULL));
    interactiveMenu(tab, N);

    return 0;
}
