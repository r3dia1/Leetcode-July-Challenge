# Leetcode-July-Challenge 7/15
# 1751. Maximum Number of Events That Can Be Attended II
> ## 如何區分何時該sort starting / ending point?
>> 1. 遇到the maximum number of non-overlaping intervals => sort by ending point.
>> 2. 遇到the minimum number of intervals that cover the whole range => sort by starting point.

> ## Solution: Dynamic programming  
>> dp[i][t] : the maximum value you can gain by participating t events from the first to i-th events.  
>> 1. if not pick the events[ i ]  
>> ```dp[i][t] = dp[i-1][t] ``` 
>> 3. if pick the events[i]  
>> ```dp[i][t] = dp[j][t-1] + events[i][2]  ```  
>> // 查詢時間不重疊且ending point距離第i個event之starting point最近的event是哪個  
>> ```j = lower_bound(ending_time.begin(), ending_time.end(), events[i][0]) - 1 - ending_time.begin();```

> ## Time complexity = O(events.length * k)

> ## 注意事項: dp邊界問題
>> e.g. dp[j][0] 時，因為選擇0個events，所以其value要優先初始化為0
