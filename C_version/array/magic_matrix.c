#include <stdio.h>
#include <string.h>
#include <stdlib.h>



// 

# define MAX 10
int square[MAX][MAX];
int N;

void magic(); //declaim the function
int main(){
    int i,j;
    do {  //使用 do-while迴圈 矩陣大小必須奇數、小於 MAX 
        printf("\n enter odd matrix size: ");
        scanf("%d", &N);
        if (N%2==0 || N<=0 || N>10)
            printf("input error");
        else
            break;
    } while(1); //無窮迴圈直到輸入正確數值
    
    magic();

    // 列印 魔術矩陣結果
    printf("%d * %d matrix \n",N,N);
    printf("-------------------\n");
    for (i=0;i<N;i++){
        for(j=0;j<N;j++)
            printf("%5d",square[i][j]);
        printf("\n");
        
    }


}

void magic(){ //define the function
    int i,j,key;
    int p,q;
    // 初始化矩陣 
    for (i=0;i<N;i++){
        for(j=0;j<N;j++){
            square[i][j] =0;
        }
    }
    // 將 1 放置於矩陣中間
    square[0][(N-1)/2] =1;
    // 下一個要放置的數字 =2
    key = 2;
    i =0;
    j = (N-1)/2;
    while( key <= N*N ){
        // p,q 是下一 步的位置
        p = i-1;
        q = j-1;
        if(p== -1 && q== -1){
            i = (i+1);
            square[i][j] = key;
            key++;
            }
        else{
            if(p<0) p= N-1;
            if (q<0) q = N-1;
            if (square[p][q]!=0)
                i = (i+1) %N;
            else{
                i = p;
                j= q;

            }
            square[i][j] = key;
            key++;
        }
        
    
}
}