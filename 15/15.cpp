class Solution {
    static bool mycompare(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();

        //依據ending time sort array
        sort(events.begin(), events.end(), mycompare);

        //建立一個ending time陣列
        vector<int> ending_time({0});
        for(auto it: events)
        {
            ending_time.push_back(it[1]);
        }

        //處理events[i][2] iterate from i=0 的問題
        //starting from i=1 (fixed)
        events.insert(events.begin(), events[0]);

        vector<vector<int>> dp(n+1, vector<int>(k+1));

        // dp邊界設定，選取0個代表value = 0
        for(int i=0; i<n; i++)
            dp[i][0] = 0;


        for(int i=1; i<=n; i++)
        {
            //查詢時間不重疊且ending point距離第i個event之starting point最近的event是哪個
            int j = lower_bound(ending_time.begin(), ending_time.end(), events[i][0]) - 1 - ending_time.begin();
            for(int t=1; t<=k; t++)
            {
                //如果當前事件index < 選取總數，則有問題
                //反之，選取 max(dp[i-1][t], dp[j][t-1] + events[i][2])
                if(i >= t)
                    dp[i][t] = max(dp[i-1][t], dp[j][t-1] + events[i][2]);
            }
        }

        //從dp[n]陣列中選擇數值最大者回傳
        int ret = 0;
        for(auto it: dp[n])
        {
            ret = max(ret, it);
        }

        return ret;
    }
};