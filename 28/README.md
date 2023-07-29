# Leetcode-July-Challenge 7/28
# 486. Predict the Winner
> ## Solution: Recursive + 剪枝  
> 1. 題目分析： 兩個人分別輪流取出頭尾的數字，組合成各自的max score，並比較大小。  
> 2. 核心算法：  
```
	// 假設當前player選擇最前端的數字，則當前player和另一個player的數字總和差為：
	int pick_leftScore = nums[left] - getScore(left + 1, right, nums);
	
   // 假設當前player選擇最尾端的數字，則當前player和另一個player的數字總和差為：
	int pick_rightScore = nums[right] - getScore(left, right - 1, nums);
	
	// 把當前left ＆ right情況下，對於頭或尾兩者數字總和差結果，選擇差值大者紀錄起來：
   cache[left][right] = max(pick_leftScore, pick_rightScore);

	// 回傳結果
   return cache[left][right];
```
> 3. 剪枝：因為進行recursive的過程中，可能會產生大量重複計算。所以，我們可以把每次結果記錄起來給下次使用，來避免重複計算。  
> ## Time complexity: O(N^2) 因為Ｔ(n) = T(n-1) + O(1) = T(1) + O(N^2)
