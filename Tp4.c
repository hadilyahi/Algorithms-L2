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

int main(){
    Tree n1= createNode(3,NULL,NULL);
   
    Tree n2= createNode(20,NULL,NULL); 
    Tree n3= createNode(5,n1,n2); 
    
   // add node to n3 
    addNode(&n3,10);
    addNode(&n3,15);
    addNode(&n3,4);
    addNode(&n3,2);
    
     prefix(n3);
     


}