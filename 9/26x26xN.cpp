class Solution {
public:
    int largestVariance(string s) {
        int n = s.size();
        unordered_set<char> c_set(s.begin(), s.end());

        int ret = 0;

        for(char a: c_set)
            for(char b: c_set)
            {
                if(a == b)
                    continue;
                
                //空集合時的初始定義
                int dp0 = 0, dp1 = INT_MIN;
                for(int i=0; i<n; i++)
                {
                    if(s[i] == a)
                    {
                        dp1 = dp1 + 1;
                        dp0 = dp0 + 1;
                    }
                    else if(s[i] == b)
                    {
                        dp1 = max(dp0, dp1) - 1;
                        dp0 = 0;
                    }

                    ret = max(ret, dp1);
                }
            }

        return ret;
    }
};