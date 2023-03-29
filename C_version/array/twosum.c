 #include <stdlib.h>
 #include <stdio.h>

int *twoSum(int* nums, int numsSize, int target)
{
    int i,j;
    int *result=(int*)malloc(sizeof(int)*2); 
    for(i=0;i<numsSize;i++)
    {
        for(j=i+1;j<numsSize;j++)
        {
            if(target==nums[i]+nums[j])
            {
                result[0]=i;
                result[1]=j;
                return result;
            }
            
        }    
    }
    
    return result;
}

int main(void){
    int nums[] = {2, 7, 11, 15};
    int numsSize = 4;
    int target = 9;
    int *result = twoSum(nums, numsSize, target);
    printf("answer: %d, %d", result[0], result[1]);
    free(result);
    return 0;
}