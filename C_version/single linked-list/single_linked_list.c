#include <stdio.h>
#include <stdlib.h>


// 定義單向鏈結的節點結構
struct Node {
    int data;          // 節點存儲的數據
    struct Node* next; // 指向下一個節點的指針
};

// 創建一個新節點，並返回指向新節點的指針
struct Node* create_node(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL; 
    return new_node;
}

// 向鏈結的尾部添加一個新節點
void add_node(struct Node** head_ref, int data) {
    struct Node* new_node = create_node(data);
    if (*head_ref == NULL) {
        // 如果鏈結為空，則將新節點作為頭節點
        *head_ref = new_node;
    } else {
        // 如果鏈結不為空，則將新節點添加到尾部
        struct Node* curr_node = *head_ref;
        while (curr_node->next != NULL) {
            curr_node = curr_node->next;
        }
        curr_node->next = new_node;
    }
}

// 從鏈結中刪除第一個值等於給定數據的節點
void delete_node(struct Node** head_ref, int data) {
    if (*head_ref == NULL) {
        // 如果鏈結為空，則不進行任何操作
        return;
    }
    if ((*head_ref)->data == data) {
        // 如果頭節點的數據等於給定數據，則刪除頭節點
        struct Node* temp_node = *head_ref;
        *head_ref = (*head_ref)->next;
        free(temp_node);
    } else {
        // 否則在鏈結中查找要刪除的節點
        struct Node* prev_node = *head_ref;
        struct Node* curr_node = (*head_ref)->next;
        while (curr_node != NULL && curr_node->data != data) {
            prev_node = curr_node;
            curr_node = curr_node->next;
        }
        if (curr_node != NULL) {
            // 如果找到要刪除的節點，則刪除該節點
            prev_node->next = curr_node->next;
            free(curr_node);
        }
    }
}

void print_list(struct Node* head) {
    // 宣告一個指向節點的指針，初始值為 head
    struct Node* current = head;

    // 循環整個鏈結，打印每個節點的數據
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
// 打印整個鏈結的數據
int main(){
    struct Node* head =NULL;
    add_node(&head,10);
    add_node(&head,30);
    add_node(&head,40);
    // 列印 linked list 結果
    printf("linked list output:\n");
    print_list(head);
    // 使用 delete node 
    printf("after delete assigned node\n");
    delete_node(&head,30);
    print_list(head);


}


