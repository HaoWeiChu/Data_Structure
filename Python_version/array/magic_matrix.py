# -*- coding: utf-8 -*-
"""
Created on Wed Mar 22 15:15:27 2023

@author: howger
"""
import numpy as np
MAX = int(input("設定最大矩陣範圍   "))
# 初始化矩陣為 全 0 矩陣
square = np.zeros((MAX,MAX))


def magic(N):
    # 將 1 放置於矩陣中間
    i, j = 0, (N-1)//2
    square[i][j] = 1
    
    # 下一個要放置的數字 =2
    key = 2
    while key <= N*N:
        # p,q 是下一步的位置
        p, q = i-1, j-1
        if p == -1 and q == -1:
            i = (i+1)
            square[i][j] = key
            key += 1
        else:
            if p < 0:
                p = N-1
            if q < 0:
                q = N-1
            if square[p][q] != 0:
                i = (i+1) % N
            else:
                i = p
                j = q
            square[i][j] = key
            key += 1

def main():
    while True:
        N = int(input("Enter odd matrix size: "))
        if N % 2 == 0 or N <= 0 or N > 10:
            print("Input error")
        else:
            break
    
    magic(N)
    
    # 列印 魔術矩陣結果
    print(f"{N} * {N} matrix")
    print("-------------------")
    for i in range(N):
        for j in range(N):
            print('%5d' %(square[i][j]),end="")
        print()

if __name__ == "__main__":
    main()
