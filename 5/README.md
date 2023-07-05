# Leetcode-July-Challenge 7/5
# 1493. Longest Subarray of 1's After Deleting One Element
> Brute force (mine)
>> 1. 利用for迴圈去假設nums每個位置刪除後的所有情況，並計算最大的1's subarray值回傳。  
>> 2. 使用到了recirsive的技巧  
>> 3. Analysis: Time Complexity  = O(N^2) 會產生TLE(pass 53/67 test cases)  

> Solution:
>> 目的: 在O(N)時間內完成
>> 障礙: 如何一邊假設該位置可以移除，又能同時計算該情況之subarray的max長度呢?  
>> 1. 使用left、right變數紀錄當前subarray之最左與最右的index。    
>> 2. 使用zero變數紀錄left和right之間，有多少個0。  
>> 3. zero必須控制在1個以內 = 求最大的subarray that can only contain 1 zero (eg. 1111101111)  
>> 4. 移除那個唯一的0後，即為所求。  
>> 5. Analysis: Time Complexity  = O(N)、 Space complexity = O(N)