# Leetcode-July-Challenge 7/4
# 137. Single Number II
> 僅記錄分析學習思路
> Solution 1: Brute Force
>> 1. Use the library unordered_map which is base on hash table datastructure.  
>> 2. Each of its manipulation cost O(1) times  
>> 3. However, it will cost lots of memory usage O(N), so it's not a optimal method.  

> Solution 2: Bit Manipulating
>> 主要思路: 利用32-bits integer之特性，我們可以針對每個bit位置去做nums數列的總和%3，來做出所求single number之bitmask。  
>> 1. 將ans initialize為0，用來儲存所求之single number。  
>> 2. Iterate from i = 0 to i = 31. This loop considers each bit position from the least significant bit (LSB) to the most significant bit (MSB) of a 32-bit integer.  
>> 3. 初始化sum為0。此變數會記錄all numbers in nums在當前bit pposition為1的總數量。  
>> 4. Iterate through each number num in the input array:  
>>> * Right-shift num by i positions: num >> i. This operation moves the bit at position i to the least significant bit position.  
>>> * Perform a bitwise AND with 1: (num >> i) & 1. 這邊把LSB以integer的方式提出。若LSB=1則提出為1，反之亦然。
>>> * Add the result of (num >> i) & 1 to sum. This counts the number of 1s at bit position i for all the numbers in the array.
>> 5. 把sum % 3，若是結果為0則代表single number在此bit poisition i的數值為0，反之為1。  
>> 6. Left-shift the value of sum by i positions: sum << i.此處為建立single number之bitmask。  
>> 7. Use the bitwise OR operation with ans and pos: ans |= pos. 利用bitmask來還原single number之value。
>> 8. Time complexity: O(32*N) = O(N)
>> 9. Memeroy usage: O(1)
