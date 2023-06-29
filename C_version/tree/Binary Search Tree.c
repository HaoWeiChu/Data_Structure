#include <stdio.h>
#include <stdlib.h>

// declaim the sturct
typedef struct tree{
    struct tree* right;
    struct tree* left;
    int data;
}tree;



//  define function create the tree
tree* createtree(tree *root, int val){
    tree *newnode = (tree*)malloc(sizeof(tree));
    newnode -> data = val;
    newnode -> left= NULL;
    newnode -> right = NULL;
    if (root == NULL){
        root = newnode;
        return root; 
    }else{
        tree *current = root;
        tree *backup = NULL;
        while (current != NULL){
           backup =  current;
           if(current -> data > val){
            current = current->left;
           }
           else{
            current = current->right;
           }
        }
    if (backup -> data > val)
            backup -> left = newnode; 
    else{
        backup -> right = newnode;
    }
    }
    return root;

}

// inorder tranversal
void inorder(tree *ptr){
    if (ptr != NULL){
        inorder(ptr-> left);
        printf("[%d]  ",ptr->data);
        inorder(ptr -> right);
    }

}


// 使用 遞迴(recursive) 方法
// 但是此方法要搭配 for loop

void bfs1(tree *ptr, int level){
    if(ptr == NULL) return;
    if(level == 1) printf("[%d] ",ptr-> data);
    if(level > 1){
        bfs1(ptr -> left , level- 1);
        bfs1(ptr -> right, level- 1);
    }
}


// main
int main(){
    tree *root = NULL;
    int data[7] = {3,2,5,1,4,7};
    tree *ptr =NULL;
   
    for(int i=0;i<7;i++){
        ptr = createtree(ptr , data[i]);
    }
    printf("\n======bst ======\n");
    int i;
    tree *temp = ptr;
    for(i=1;i<=3;i++){
        bfs1(temp,i);
        printf("\n");
    }
 
    
}