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

void generateDotFile(Tree tree, FILE* file) {
    if (tree == NULL) return;

    if (tree->left != NULL) {
        fprintf(file, "    %d -> %d;\n", tree->val, tree->left->val);
        generateDotFile(tree->left, file);
    }
    if (tree->right != NULL) {
        fprintf(file, "    %d -> %d;\n", tree->val, tree->right->val);
        generateDotFile(tree->right, file);
    }
}

void exportTreeToPNG(Tree* tab, int N) {
    int index;
    printf("Entrez l'indice de l'arbre à exporter (0 à %d) : ", N - 1);
    scanf("%d", &index);

    if (index < 0 || index >= N || tab[index] == NULL) {
        printf("Aucun arbre à cet indice.\n");
        return;
    }

    FILE* file = fopen("tree.dot", "w");
    if (file == NULL) {
        printf("Erreur lors de la création du fichier DOT.\n");
        return;
    }

    fprintf(file, "digraph Tree {\n");
    generateDotFile(tab[index], file);
    fprintf(file, "}\n");

    fclose(file);

    printf("Fichier DOT généré avec succès.\n");
    printf("Génération de l'image PNG...\n");

  
    system("dot -Tpng tree.dot -o tree.png");

    printf("Image PNG créée avec succès sous le nom 'tree.png'.\n");
}

void interactiveMenu(Tree* tab, int N) {
    int choice;

    while (1) {
        printf("\n=== MENU INTERACTIF ===\n");
        printf("1. Ajouter une valeur à un arbre\n");
        printf("2. Afficher un arbre dans différents ordres\n");
        printf("3. Exporter un arbre en image PNG\n");
        printf("4. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int index, val;
                printf("Entrez l'indice de l'arbre (0 à %d) : ", N - 1);
                scanf("%d", &index);
                if (index < 0 || index >= N) {
                    printf("Indice invalide.\n");
                    break;
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
                break;
            }
            case 2:
                printf("Affichage des arbres non inclus ici.\n");
                break;
            case 3:
                exportTreeToPNG(tab, N);
                break;
            case 4:
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
    tab[2] = createNode(20, createNode(6, NULL, NULL), createNode(2, NULL, NULL));
    interactiveMenu(tab, N);

    return 0;
}
