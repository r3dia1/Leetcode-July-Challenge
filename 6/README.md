# Leetcode-July-Challenge 7/6
# 209. Minimum Size Subarray Sum
> Sliding Window:
>> 1. 宣告變數left, right分別代表min_subarray之最左和最右之index。  
>> 2. 宣告變數sum紀錄當前subarray所有元素之和。
>> 3. 宣告ans初始值為INT_MAX。(若是ans結束時仍為IN_MAX，則代表nums裡不存在符合之subarray。)  
>> 4. 方法如下圖:  
>> ![image]()
>> 5. Time Compplexity: O(N)

> BS + DFS: 
>> 1. 此想法根據day 1 challenge的方法所發想。
>> 2. 利用BS和subarray兩個條件來對DFS做剪枝 (eg. 1代表選0代表不選，因為所求為subarray，所以DFS時不存在11101這種組合)  
>> 3. Promblem: MLE (若是nums array數量龐大十，會造成DFS的memory使用量以指數形式上升)

