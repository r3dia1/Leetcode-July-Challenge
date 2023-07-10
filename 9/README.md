# 2272. Substring With Largest Variance
> Solution 1: O(26*26*N)
>> 1. 根據題目給定的數據量 = 1e4，我們可以大致推斷解法時間複雜度可能落在O(K*N)，k is constant。  
>> 2. 這邊要提到Kadane Algo: the maximum sum array，算法如下:
>>> // x x x x x i  
>>> // dp[i]: the maimum array sum ending at i.  
>>> // dp[i] = max(nums[i], dp[i-1] + nums[i])

>> 3. 接著，根據題目的敘述我們可以把所求視為以下:
>>> s = x x [a x x  b a a a] x  b x  
>>> s = 0 0  1 0 0 -1 1 1 1  0 -1 0  //把a當作1、b當作-1。  
>>> 求含有-1之並擁有最大sum value的subarray，並回傳其sum value。

>> 4. 方法如下:
```
dp0[i]: the maximum subarray sum ending at i, and this subarray does not contain -1.
dp1[i]: the maximum subarray sum ending at i, and this subarray contains -1.
  
for(int i=0; i<n; i++)
{
    if(nums[i] == 1)
    {
        dp0[i] = dp0[i-1] + 1;
        dp1[i] = dp1[i-1] + 1;        
    }
    else if(nums[i] == -1)
    {
        dp0[i] = 0; //矛盾
        dp1[i] = max(dp0[i-1], dp1[i-1]) - 1; //因為i=-1，所以選含-1或不含的都無所謂
    }

    ret = max(ret, dp1[i]);
}
```

> Solution 2: O(26*N)
>> 1. 縮減時間複雜度方法:
>>> s = x x [a x x  b a a a] x  b x  
>>> s = 0 0  1 0 0 -1 1 1 1  0 -1 0  
>>> 在這邊我們略過element = 0的各元素不檢查

>> 2. 利用unordered_map<char, vector<int>>來記錄每個元素出現的位置即可不檢查0。  
>> 3. 只是對於遇到1 & 遇到0的條件會需要仔細的定義:
>>> 遇到0: b元素遍歷完畢 or (a元素尚未遍歷完畢 & a元素的當前位置 < b元素的當前位置) //相當於1要比-1更早被處裡  
>>> 遇到1: a元素遍歷完畢 or (b元素尚未遍歷完畢 & b元素的當前位置 < a元素的當前位置) //相當於-1要比1更早被處裡
