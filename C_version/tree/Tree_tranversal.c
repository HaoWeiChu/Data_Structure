#include <stdio.h>
#include <stdlib.h>

// Binary Tree Tranversal
// 透過使用 前序、中序、後序 進行二元樹列印
// 這邊透過搭配 createtree 函式 進行列印實作
/*======= example ======== */
/* [5]----root
  [3]  [7]----level 1
[1][4]  [6][9] -----level 2

preorder: 5>3>1>4>7>6>9
inorder: 1>3>4>5>6>7>9
postorder: 1>4>3>6>9>7>5
*/

// create tree function
typedef struct tree{
    struct tree *right;
    struct tree *left;
    int data;
}tree;


// inorder tranversal
void inorder(tree *ptr){
    if (ptr != NULL){
        inorder(ptr-> left);
        printf("[%d] ",ptr->data);
        inorder(ptr -> right);
    }

}

// preorder tranversal
void preorder(tree *ptr){
    if(ptr!= NULL){
        printf("[%d] ",ptr -> data);
        preorder(ptr -> left);
        preorder(ptr -> right); 
    }
}

void postorder(tree *ptr){
    if(ptr != NULL){
        postorder(ptr -> left);
        postorder(ptr -> right);
        printf("[%d] ", ptr -> data);
    }
}




tree* createtree(tree *root, int val){
    tree *newnode = (tree*)malloc(sizeof(tree));
    newnode -> data = val;
    newnode -> left= NULL;
    newnode -> right = NULL;
    if (root == NULL){
        root = newnode;
        return root; //這邊的 return 會直接跳出 函式不會執行下面的第二個 return roo
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

// main
int main(){
    tree *root = NULL;
    int data[7] = {5,3,7,1,4,6,9};
    tree *ptr =NULL;
    for(int i=0;i<7;i++){
        ptr = createtree(ptr , data[i]);
    }
    tree *temp1 = ptr;
    tree *temp2 = ptr;
    tree *temp3 = ptr;
    printf("=== inorder trans ===\n");
    inorder(temp1);
    printf("\n===== preorder =====\n");
    preorder(temp2);
    printf("\n=== postorder ====\n");
    postorder(temp3);

      
}