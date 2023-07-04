# Leetcode-July-Challenge 7/3
# 859. Buddy Strings
> Solution: 鴿籠原理 & <set> library  
>> // Part 1: s == goal  
>> Q: 要如何檢查兩個string (s & goal)中存在兩個不同位置但相同的元素呢?
>>   
>> ANS:  
>> 利用鴿籠原理，檢查s中所有unique的元素，再看s的總長度。  
>>若是unique.length < s.length，則代表存在兩個不同位置但相同的元素。

>> // Part2: s != goal  
>> 1. 此處已知s != goal  
>> 2. 所以我們分別從頭和尾檢查s與goal counter之第一個不一樣的element。  
>> 3. 接著再對兩個不同處做交換，看看能否讓s == goal。  
>> 4. 若是不行，則回傳false。
