class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = strlen(s1.c_str()), m = strlen(s2.c_str());
        // 在s1長度i和s2長度j時，所要移除LCS以外之最小ASCII和
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        //設定dp初值，另一sequence長度為0，dp必為該sequence之ASCII總和
        for(int i=1; i<=n; i++)
            dp[i][0] = dp[i-1][0] + (int)s1[i-1];
        for(int j=1; j<=m; j++)
            dp[0][j] = dp[0][j-1] + (int)s2[j-1];

        // Construct dp array
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
            {
                if(s1[i-1] == s2[j-1])
                {
                    // 因為lcs增加，所以不更新dp
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                {
                    // 當兩個sequence的當前字符不同時，選擇有最小ASCII value者更新dp
                    dp[i][j] = min(dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1]);
                }
            }
        
        // 建構dp完成後，回傳dp[n][m]
        return dp[n][m];
    }
};