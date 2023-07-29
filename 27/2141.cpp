class Solution {
public:
    bool check_battery(long long time, long long n, vector<int>& batteries)
    {
        long long sum = 0;
			// 計算當前電池是否能滿足PC's runtime，把電池電量總和相加做檢查
			// Why? 因為根據題目我們可以不考慮內部電池如何分配
			// 只要想成每個電池都切成單位來分配即可
        for(auto it: batteries)
        {
            // 對於每顆電池，總共也就跑time時間長度
				// 所以若是當前電池有更多電量，仍舊取到time即可
            sum += min((long long)it, time);
				// 一旦發現PC runtime滿足條件就回傳true
            if(sum >= time * n)
                return true;
        }
        
        return false;
    }

    long long maxRunTime(int n, vector<int>& batteries) {
			// Binary search基本配置寫法
        long long left = 0, right = LLONG_MAX/n;
        while(left < right)
        {
            long long mid = right - (right - left) / 2;
				// 檢查當前runtime是否合乎規範
            if(check_battery(mid, n, batteries))
            {
                left = mid;
            }
            else
            {
                right = mid - 1;
            }
        }

        return left;
    }
};