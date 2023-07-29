class Solution {
public:
    vector<vector<double>> dp;
    double dfs(int a, int b)
    {
        if(a <= 0 && b > 0)
        {
            return 1;
        }
        else if(a <= 0 && b <= 0)
        {
            return 0.5;
        }
        
        if(b <= 0)
        {
            return 0;
        }

        if(dp[a][b] != -1)
            return dp[a][b];

        double ans = 0;
        ans += 0.25*dfs(max(0, a - 100), max(0, b));
        ans += 0.25*dfs(max(0, a - 75), max(0, b - 25));
        ans += 0.25*dfs(max(0, a - 50), max(0, b - 50));
        ans += 0.25*dfs(max(0, a - 25), max(0, b - 75));
        dp[a][b] = ans;

        return dp[a][b];
    }
    double soupServings(int n) {
        if(n >= 4800)
            return 1;
        dp.resize(n+1, vector<double> (n+1, -1));
        double ret = dfs(n, n);
        
        return ret;
    }
};