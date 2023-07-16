# Leetcode-July-Challenge 7/16
# 1125. Smallest Sufficient Team
> ## Solution: bitmask + dp  
> ## Analysis: 
> 1. 我們可以把所有request skills & people's skills，以一組bit mask (eg. 10001)來看待  
>> // 0代表該skill不存在於skill set內，反之1代表存在  
>> // 所以我們在處理dp之前，需要把所有的ppl skill轉換成skill set bit masks。  
> 2. 對於dp部分 
>> 若是用一般背包問題解法，沒有辦法漸進更新dp table:  
``` 
    for people[i] ...
        for skillset ...
            old_skillset = skillset | skills[i]
            dp[skillset] = min(dp[skillset], dp[old_skillset] + 1)
```
>> 改成以下則可行:  
``` 
    for people[i] ...
        for skillset ...
            new_skillset = skillset | skills[i]
            dp[new_skillset] = min(dp[newskillset], dp[skillset] + 1)
```
>> // 記得注意邊界問題 dp[0] = 0  
> ## Time complexty = O(ppl.size * (2^req_size))
