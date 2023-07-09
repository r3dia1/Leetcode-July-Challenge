class Solution {
public:
    int largestVariance(string s) {
        int n = s.size();
        unordered_map<char, vector<int>> c_map;
        for(int i=0; i<n; i++)
            c_map[s[i]].push_back(i);

        int ret = 0;
        for(auto& [a, pos0]: c_map)
            for(auto& [b, pos1]: c_map)
            {
                if(a == b)
                    continue;
                
                //空集合時的初始定義
                int dp0 = 0, dp1 = INT_MIN;
                int i = 0, j = 0;

                while(i<pos0.size() || j<pos1.size())
                {
                    if(j == pos1.size() || (i<pos0.size() && pos0[i]<pos1[j]))
                    {
                        dp1 = dp1 + 1;
                        dp0 = dp0 + 1;
                        i++;
                    }
                    else if(i == pos0.size() || (j<pos1.size() && pos1[j]<pos0[i]))
                    {
                        dp1 = max(dp0, dp1) - 1;
                        dp0 = 0;
                        j++;
                    }

                    ret = max(ret, dp1);
                }
            }

        return ret;
    }
};