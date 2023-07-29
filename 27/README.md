# Leetcode-July-Challenge 7/27
# 2141. Maximum Running Time of N Computers
> ## Solution: Binary search
> 題意：根據題目給定的電池容量陣列＆PC數量，決定能讓所有PC同時執行之maximum runtime。  
> 1. 此題可以利用binary search實作，先寫出BS架構。  
> 2. 設計一個check_battery的副程式，用來檢查當前選擇之runtime是否合乎電量規範
```
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
```
> ## Time complexity: O(NlogN)
