def twosum( nums, target):
    for i in range(len(nums)):
      
        for j in range(i+1, len(nums)):
            
            if nums[i] + nums[j] == target:               
                return [i,j]
            
            


A =[3,2,4]
B = 7
print(twosum(A, B))