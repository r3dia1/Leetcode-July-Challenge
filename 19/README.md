# Leetcode-July_challenge 7/19
# 435. Non-overlapping Intervals
> ## Solution: Greedy
> 1. 先把intervals依照end.time由小到大進行排序。  
> 2. 採取greedy策略，從end.time越早的開始選擇（這樣後面能選擇的interval就更多）。  
> 3. 在選擇過程中要注意intervals彼此間不能有overlap的情形，所以會需要比較前一個選擇和當前的interval是否重疊。(previous_choice & current)  

> ## Time complexity: O(N);
