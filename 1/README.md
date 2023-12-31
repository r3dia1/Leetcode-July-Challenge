# Leetcode-July-Challenge 7/1
# 2305. Fair Distribution of Cookies
>It's a NP problem.  
>We can use brutal method to solve the problem.

>Constraints:
>>```
>>2 <= cookies.length <= 8
>>1 <= cookies[i] <= 105
>>2 <= k <= cookies.length
>>```
>>The wort complexity is O(k^n).

# Solution: Binary Search & DFS
>Analysis:
>>If we only use DFS for brutal method, we want get a lower complexity.  
>>So we have to add a BS method to reduce the branch of DFS.

>Method:  
>>We can give a ceiling of each person's cookie to limit the distribution result.  
>>e.g. from 10000 -> 5000 -> 1000
>>  
>>When running DFS steps we can check less possibilities.  
>>By doing this we can get the minimum unfairness.  
