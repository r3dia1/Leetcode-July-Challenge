# Leetcode-July-Challenge 7/24
# 50. Pow(x, n)
> ## Solution: recursive  
> 分析: 此題不可能使用for迴圈解(TLE)，所以我們必須使用遞迴犧牲記憶體空間換取執行時間。  
> 遞迴情況討論:  
>> 1. n = 0 : return 1  

>> 2. n = 1: return x  

>> 3. n = -1 : return 1/x  

>> 4. 我們思考一下會發現pow(x, n)，其實就是pow(x, n/2)的平方。我們要利用這個思路來減少我們遞迴的次數!
>>> (1) n為偶數時 : return pow(x, n/2) * pow(x, n/2)  
>>> (2) n為正奇數時 : return pow(x, n/2) * pow(x, n/2) * x  //e.g. 2^5 = 2^2 * 2^2 * 2  
>>> (3) n為負奇數時 : return pow(x, n/2) * pow(x, n/2) * 1/x