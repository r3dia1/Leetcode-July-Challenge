# 2024. Maximize the Confusion of an Exam
> Solution: 
>> Same concept compare to #209. Minimum Size Subarray Sum (Sliding window).  
>> 1. Assume there is two subarray with (1's & 0's)  
>> 2. We use the sliding window approach to find the two longest subarray  
>> 3. Compare the two subarrays and choose the longer one as the answer.  

> Better Time Complexity:
>> 1. Find two longest subarray in the same time.  
>> 2. So that the time complexity will change from O(2N) to O(N).  
>> 3. Runtime improve: 30 ms -> 24 ms.