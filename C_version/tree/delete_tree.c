
#include <stdio.h>
#include <stdlib.h>

// define the tree
typedef struct tree{
    int data;
    struct tree *left;
    struct tree *right;
}tree;

// define the tree function
tree* createtree(int data, tree* root){
    tree *newnode = (tree*)malloc(sizeof(tree));
    newnode -> data = data;
    newnode -> right = NULL;
    newnode -> left = NULL;
    if(root == NULL){
        root = newnode;
        return root;
    }
    else{
        tree *curr = root;
        tree *backup;
        while(curr != NULL){
            backup = curr;
            if(curr -> data > data)
                curr = curr->left;
            else
                curr = curr ->right;
        }
        if(backup -> data > data)
            backup -> left = newnode;
        else
            backup -> right = newnode;    
    }
    return root;
} 

// inorder tranversal
void inorder(tree *ptr){
    if(ptr != NULL){
        inorder(ptr -> left);
        printf("[%d] ", ptr -> data);
        inorder(ptr -> right);
    }
}

// 與 linked_list 相同，使用雙重指標進行刪除，可以確保列印時不會找不到樹根
void deletenode(tree **root, int data) {
    if (*root == NULL) return;

    // 判斷要刪除的節點在左子樹還是右子樹
    if ((*root)->data > data)
        deletenode(&((*root)->left), data);
    else if ((*root)->data < data)
        deletenode(&((*root)->right), data);
    else if ((*root)->data == data) {
        // 沒有子節點
        if ((*root)->left == NULL && (*root)->right == NULL) {
            free(*root);
            *root = NULL;  // 設定指標為 NULL
        }
        // 只有左節點
        else if ((*root)->left == NULL) {
            tree *temp = *root;
            *root = (*root)->right;
            free(temp);
        }
        // 只有右節點
        else if ((*root)->right == NULL) {
            tree *temp = *root;
            *root = (*root)->left;
            free(temp);
        }
        // 左右節點都有
        else {
            tree *temp = (*root)->right;
            // 取出右邊最小的數值，再將其刪除
            // 取出右邊分支的最小值作為新的樹根，再使用 deletenode 將其原本的位置刪除
            while (temp->left != NULL) {
                temp = temp->left;
            }
            (*root)->data = temp->data;
            deletenode(&((*root)->right), temp->data);
            // 處理左子樹的刪除情況
            deletenode(&((*root)->left), data);
        }
    }
}

int main(){
    tree *ptr = NULL;
    int data[7] = {5,3,7,1,4,6,9};
    int i;
    for(i=0;i<7;i++){
        ptr = createtree(data[i], ptr);
    }
    tree *temp1 = ptr;
    deletenode(&temp1, 3);
    inorder(ptr);
}