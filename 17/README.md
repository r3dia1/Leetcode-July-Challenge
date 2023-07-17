# Leetcode-July-Challenge 7/17
# 445. Add Two Numbers II
> ## Solution: Add from highest digit to lowest digit  
> 1. 先分別計算l1, l2的長度l1_len, l2_len  
> 2. 宣告一個vector<int> ret來記錄數字和  
> 3. 開始從最高位數做加法，分以下三種情況:  
>> (1) l1_len > l2_len : 該位數只取l1放入ret  
>> (2) l1_len < l2_len : 該位數只取l2放入ret  
>> (3) l1_len = l2_len : 若 l1[i] + l2[i] >= 10 代表有進位問題，則必須要更新ret裡面受影響的高位數value。反之，則直接push_back即可。  
> 4. 把vector ret建立成一個List structure並回傳即完成。  
> 5. Time complexity: O(N)
