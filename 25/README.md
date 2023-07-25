# Leetcode-July-Challenge 7/25  
# 852. Peak Index in a Mountain Array  
> ## Solution: Binary search  
> 1. 在每一次尋訪時，取其中間點(left + right)/2  
> 2. 觀察中間點的左右元素是否高於中點，有的話則繼續尋訪左 or 右半邊，沒有的話則代表找到峰值並回傳。   
> 
> ## Analysis:  
> 1. 上述方法可以透過loop或是recursive來實現，只不過loop有相對更短的執行時間 & 更少的memory usage (no stack)  
> 2. Time complexity : 把遞迴關係列出來 T(n) = T(n/2) + O(1)，我們可以透過Master Thoerem得知時間複雜度為O(logN)