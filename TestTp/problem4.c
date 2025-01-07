#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
    int val;
    struct node* left;
    struct node* right;
} node, *Tree;


void prefix(Tree a) {
    if (a == NULL) return;
    printf("%d ", a->val);
    prefix(a->left);
    prefix(a->right);
}


Tree createNode(int val, Tree left, Tree right) {
    Tree a = (Tree)malloc(sizeof(node));
    if (a == NULL) {
        printf("Erreur d'allocation mémoire.\n");
        exit(1);
    }
    a->val = val;
    a->left = left;
    a->right = right;
    return a;
}


int getRootValue(Tree a) {
    if (a == NULL) return -1;
    return a->val;
}


void initTab(Tree* tab, int N) {
    for (int i = 0; i < N; i++) {
        tab[i] = NULL;
    }
}


void addNode(Tree* arbre, int val) {
    Tree newNode = createNode(val, NULL, NULL);
    if (*arbre == NULL) {
        *arbre = newNode;
    } else {
        if (val < (*arbre)->val) {
            if ((*arbre)->left == NULL) {
                (*arbre)->left = newNode;
            } else {
                addNode(&((*arbre)->left), val);
            }
        } else if (val > (*arbre)->val) {
            if ((*arbre)->right == NULL) {
                (*arbre)->right = newNode;
            } else {
                addNode(&((*arbre)->right), val);
            }
        }
    }
}


void ajouterValeur(Tree* tab, int N, int index, int val) {
    if (index < 0 || index >= N) {
        printf("Erreur : index hors limites du tableau.\n");
        return;
    }
    if (tab[index] == NULL) {
        tab[index] = createNode(val, NULL, NULL);
    } else {
        addNode(&(tab[index]), val);
    }
}


void bubbleSort(Tree* tab, int N) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (getRootValue(tab[j]) > getRootValue(tab[j + 1])) {
                Tree temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
        }
    }
}


void selectionSort(Tree* tab, int N) {
    for (int i = 0; i < N - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < N; j++) {
            if (getRootValue(tab[j]) < getRootValue(tab[minIndex])) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            Tree temp = tab[i];
            tab[i] = tab[minIndex];
            tab[minIndex] = temp;
        }
    }
}


void merge(Tree* tab, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Tree* L = (Tree*)malloc(n1 * sizeof(Tree));
    Tree* R = (Tree*)malloc(n2 * sizeof(Tree));

    for (int i = 0; i < n1; i++) L[i] = tab[left + i];
    for (int j = 0; j < n2; j++) R[j] = tab[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (getRootValue(L[i]) <= getRootValue(R[j])) {
            tab[k++] = L[i++];
        } else {
            tab[k++] = R[j++];
        }
    }

    while (i < n1) tab[k++] = L[i++];
    while (j < n2) tab[k++] = R[j++];

    free(L);
    free(R);
}


void mergeSort(Tree* tab, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(tab, left, mid);
        mergeSort(tab, mid + 1, right);
        merge(tab, left, mid, right);
    }
}


void printTab(Tree* tab, int N) {
    for (int i = 0; i < N; i++) {
        printf("Arbre à l'index %d (racine = %d): ", i, getRootValue(tab[i]));
        if (tab[i] != NULL) {
            prefix(tab[i]);
        } else {
            printf("Vide");
        }
        printf("\n");
    }
}

int main() {
    int N = 5;
    Tree tab[N];

    initTab(tab, N);

   
    ajouterValeur(tab, N, 0, 30);
    ajouterValeur(tab, N, 0, 10);
    ajouterValeur(tab, N, 0, 50);

    ajouterValeur(tab, N, 1, 20);
    ajouterValeur(tab, N, 2, 40);
    ajouterValeur(tab, N, 3, 60);
    ajouterValeur(tab, N, 4, 15);

    printf("Avant le tri:\n");
    printTab(tab, N);


    printf("\nChoisissez une méthode de tri :\n");
    printf("1. Tri par bulles (Bubble Sort)\n");
    printf("2. Tri par sélection (Selection Sort)\n");
    printf("3. Tri par fusion (Merge Sort)\n");
    printf("Entrez votre choix (1-3) : ");

    int choix;
    scanf("%d", &choix);


    switch (choix) {
        case 1:
            bubbleSort(tab, N);
            printf("\nAprès le tri (Bubble Sort):\n");
            break;
        case 2:
            selectionSort(tab, N);
            printf("\nAprès le tri (Selection Sort):\n");
            break;
        case 3:
            mergeSort(tab, 0, N - 1);
            printf("\nAprès le tri (Merge Sort):\n");
            break;
        default:
            printf("Choix invalide. Aucun tri effectué.\n");
            return 1;
    }

    printTab(tab, N);

    return 0;
}
