#include <stdio.h>
typedef struct node {
    int val ;
    struct node* left ;
    struct node* right ;
}
node , *Tree ;
void prefix (Tree a){
    if (a == NULL) return ;
    printf("%d \t", a->val);
    prefix(a->left);
    prefix(a->right);
}
Tree createNode(int val,Tree Left,Tree right ){

    Tree a =(Tree) malloc(sizeof(node));
    if(a == NULL ) return ;
    a->val = val ;
    a->left = Left;
    a->right = right;
    return a ;
}
void addNode(Tree* arbre , int val){
     Tree newNode = createNode(val,NULL,NULL);
     if(*arbre == NULL ){  // arber est vide
        *arbre = newNode;

     } else {
        if(val < (*arbre)->val){
            if((*arbre)->left == NULL){
                (*arbre)->left = newNode;
            } else {
                addNode(&((*arbre)->left),val);
            }
        }
        if(val > (*arbre)->val){
            if((*arbre)->right == NULL){
                (*arbre)->right = newNode;
            } else {
                addNode(&((*arbre)->right),val);
            }
        }
     }
}
Tree search(Tree arbre , int val){
     Tree i = arbre;
     int found = 0;
     while((i != NULL) && (!found)){
        if(i->val == val){
            found = 1;
            
    }
    else if (i->val > val){
        i = i->left;
     }
     else {
        i = i->right;
     }
     }
        return i;
}
// Initialisation du Tableau d'Arbres: Implémentez un tableau de taille N (valeur fixée par l'utilisateur)
// contenant des arbres binaires de recherche initialement vides.
 void initTab(Tree* tab, int N){
        for(int i = 0; i < N; i++){
            tab[i] = NULL;
        }

 }

int main(){
    // init tab 
    int N;
    printf("Enter the size of the table : ");
    scanf("%d",&N);
    Tree tab[N];
    initTab(tab,N);
    // create node in tab 
    tab[0] = createNode(10,NULL,NULL);
    // add node in tab
    addNode(&tab[0],5);
    addNode(&tab[0],15);
    addNode(&tab[0],3);
    // search node in tab
    Tree node = search(tab[0],3);
    if(node != NULL){
        printf("Node found : %d \n",node->val);
    } else {
        printf("Node not found \n");
    }
    // print the tree
    prefix(tab[0]);
    
    
    
    
     


}