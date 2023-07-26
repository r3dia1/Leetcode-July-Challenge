# Leetcode-July-Challenge 7/26
# 1870. Minimum Speed to Arrive on Time
> ## Solution: Binary Search
> 1. 先找出一個必定不會遲到的火車時速speed(in integer)  
> 2. 接著在1 ~ speed之間做binary search:  
```
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
```
>> 3. 找到目標 minimum positive integer speed 回傳  
> ## Time complexity: O(N*logN)