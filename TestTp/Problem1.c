#include <stdio.h>

// create a structure node
typedef struct node {
    int val ;
    struct node* left ;
    struct node* right ;
}
node , *Tree ;
// create a function prefix
void prefix (Tree a){
    if (a == NULL) return ;
    printf("%d", a->val);
    prefix(a->left);
    prefix(a->right);
}
// create a function createNode
Tree createNode(int val,Tree Left,Tree right ){
    Tree a =(Tree) malloc(sizeof(node));
    if(a == NULL ) return -1;
    a->val = val ;
    a->left = Left;
    a->right = right;
    return a ;
}
 
 // Initialisation du Tableau d'Arbres: Implémentez un tableau de taille N (valeur fixée par l'utilisateur)
// contenant des arbres binaires de recherche initialement vides.
 void initTab(Tree* tab, int N){
        for(int i = 0; i < N; i++){
            tab[i] = NULL;
        }

 }
    
// create a main function

int main (){
        // create a variable N
        int N;
        printf("Enter the number of trees: ");
        scanf("%d", &N);
        // create a variable tab
        Tree tab[N];
        // call the function initTab
        initTab(tab, N);


        return 0;
}