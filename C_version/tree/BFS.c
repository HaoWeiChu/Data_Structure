// 將二元樹進行廣度

// Breadth first search (廣度優先順序)
/*  用於建立 二元樹 從樹根開始依序往下 printf */
/*  example 
 ============
[root]
[element][element] ---level 1
[element][element][element][element] ----level 2 
================
*/


// 使用 遞迴(recursive) 方法
void bfs(tree *ptr, int level){
    if(ptr == NULL) return;
    if(level == 1) printf("[%d] ",ptr-> data);
    if(level > 1){
        bfs(ptr -> left , level- 1);
        bfs(ptr -> right, level- 1);
    }
}

// 使用佇列(Queue) 方法
// 就可以將 樹根 依序 往下一層一層列印
// 使用 佇列 方法
void bfs(tree *root) {
tree *queue[100]; // 儲存每一層的節點
int head = 0; // 佇列頭
int tail = 0; // 佇列尾
// tail++ 用於下一次，這次儲存的位址還是 queue[0]
queue[tail++] = root; // 將根節點加入佇列
while (head != tail){ // 當佇列不為空
    tree *current = queue[head++]; // 取出佇列頭
    //printf("[%d] ", current->data); // 輸出節點值
    if (current->left != NULL){ // 如果有左節點，加入佇列
        queue[tail++] = current->left;
        }
    if (current->right != NULL){ // 如果有右節點，加入佇列
    queue[tail++] = current->right;
        }
    }

int i;
for(i=0;i<tail;i++){
    printf("[%d] ",queue[i]->data);
    
}
}