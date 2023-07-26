class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        if(hour < n-1)
            return -1;

        int valid = 0;
        double speed, test_hr;
        int left = 1, right = INT_MAX/100;
        while(right > left)
        {
            test_hr = 0;
            //取當前時速可選範圍的中間值
            speed = floor((left + right) / 2.0);

            //計算選取當前時速的話，總共會cost多少時間
            for(auto it: dist){
                test_hr = ceil(test_hr);
                test_hr += ((double)it)/(speed);
            } 
            
            // 若cost > hour則代表，需要從[speed+1 ~ right]選擇
            if(test_hr > hour)
            {
                left = speed + 1;
            }
            else // 若cost <= hour則代表，可以再檢查[1 ~ speed]是否有更好的選擇
            {
                valid = 1;
                right = speed;
            }
        }

        if(valid == 1)
            return right;
        else
            return -1;
    }
};