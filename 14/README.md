# Leetcode-July-Challenge 7/14
# 1218. Longest Arithmetic Subsequence of Given Difference
> Solution: 
>> 以 [1, 2, 3, 4] 為例，dofference = 1。  
>> 我們要檢查4是否出現在longest arithmetic subsequence裡面，我們要檢查3是否存在(4 - 1 = 3)。
>> 以此檢查方式為基礎，我們可以利用dynamic programming來建立含有每個元素之不同subarray長度。

> Approach: 
>> 1. Use unordered_map to record each subarray length.  
>> 2. iterate full number array and check if the (current number - difference) number exists or not.  
>> 3. If exists then map[current number] = map[curn - diff] + 1, else map[current number] = 1.  
>> 4. after iteration select the longest subarray length and return.  