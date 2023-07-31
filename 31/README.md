# Leetcode-July-Challenge 7/31
# 712. Minimum ASCII Delete Sum for Two Strings
> ## Solution: dp
> 1. 題意分析: 給定兩個字符串 s1 和 s2，回傳刪除字符的最小 ASCII 總和，以使兩個字符串相等。  
> 2. dp method:
```
    // Construct dp array
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            if(s1[i-1] == s2[j-1])
            {
                // 因為兩字串當前字符比對成功，所以lcs增加，不刪除字符 & 不更新dp
                dp[i][j] = dp[i-1][j-1];
            }
            else
            {
                // 當兩個sequence的當前字符不同時，選擇有最小ASCII value者更新dp
                // e.g. "sea" & "eat" 兩個字串
                // 當s != e時，可以選擇去除s留下"ea" & "eat"繼續比較，或是去除e留下"sea" & "at"繼續比較
                // 無論時何種動作都要記得更新dp值
                dp[i][j] = min(dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1]);
            }
        }
```
> 3. Time complexity : O(s1_length * s2_length) = O(N^2)