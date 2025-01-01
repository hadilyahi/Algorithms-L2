#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// create a structure node
typedef struct node {
    int val;
    struct node* left;
    struct node* right;
} node, *Tree;

// create a function prefix
void prefix(Tree a) {
    if (a == NULL) return;
    printf("%d ", a->val);
    prefix(a->left);
    prefix(a->right);
}

// create a function createNode
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

    // init the array of trees
void initTab(Tree* tab, int N) {
    for (int i = 0; i < N; i++) {
        tab[i] = NULL;
    }
}

 // add node to the tree
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

// add value to the tree at index
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

void remplirCasesVides(Tree* tab, int N, int maxNodes) {
    for (int i = 0; i < N; i++) {
        if (tab[i] == NULL) {
            int numNodes = rand() % maxNodes + 1; 
            for (int j = 0; j < numNodes; j++) {
                int val = rand() % 1001; 
                ajouterValeur(tab, N, i, val);
            }
        }
    }
}

int main() {
    
    int N ,maxNodes;
    printf("Entrez le nombre d'arbres : ");
    scanf("%d", &N);
     printf("Entrez le nombre maximum de nœuds par arbre : ");
    scanf("%d", &maxNodes);
    
    Tree tab[N];

    
    initTab(tab, N);
    
    
    ajouterValeur(tab, N, 0, 10);
    ajouterValeur(tab, N, 0, 5);
    ajouterValeur(tab, N, 0, 15);
    ajouterValeur(tab, N, 1, 20);

      srand(time(NULL));

   
    remplirCasesVides(tab, N, maxNodes);
  
    for (int i = 0; i < N; i++) {
        printf("Arbre à l'index %d : ", i);
        if (tab[i] != NULL) {
            prefix(tab[i]);
        } else {
            printf("Vide");
        }
        printf("\n");
    }

    return 0;
}
