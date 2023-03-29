#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/* stack project */

#define NUM 100
int stack[NUM];
int top = -1;
// 使用三個函式(放入push、彈出pop、列印print)
void push(int);
int pop(void);
void printstack(void);

// 主函式
int main(void){
    int choice =0,n;
    while (choice != -1){  // 設立判斷式 只要不為 -1 就不跳出迴圈
        printf("1) push 2) pop 3) printstack  -1) quit\n");
        printf("enter your chioce: ");
        scanf("%d",&choice);
        switch(choice){  //使用 switch 進行功能選擇
            case 1:
                printf("what do you want to input:\n");
                scanf("%d",&n);
                push(n);
                break;
            case 2:
                printf("%d was popped from stack \n",pop());
                break;
            case 3:
                printstack();
                break;
            
        }
    }
}

void push(int n){
    if (top == NUM-1){
        printf("stack is fulled");
        exit(1); //堆疊滿了，exit(0) 表示程式正常結束，而 exit(1) 則表示程式異常結束
    }
    top++;
    stack[top] = n;
}

int pop(void){
    if(top ==-1){
        printf("stack is empty\n");
        exit(1); //堆疊資料空了 跳出程式，exit(0) 表示程式正常結束，而 exit(1) 則表示程式異常結束
        
    }
    top--;
    return stack[top];
}

void printstack(void){
    int i;
    if(top ==-1){
        printf("stack is empty:\n");
    }else{
        printf("stack\n");
        printf("-------------\n");
        for (i=top;i>=0;i--){
            printf("%d",stack[i]);
        printf("\n");
        }
    }
}

