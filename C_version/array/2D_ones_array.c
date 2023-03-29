#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(){
    int i,j;
    int a[5][5];
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            a[i][j] =0;
            printf("\ta[%d][%d]=%d\t",i,j,a[i][j]);
            if(j==4)
                printf("\n");
            
        }
    }
}