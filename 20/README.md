# Leetcode-July-Challenge 7/20
# 735. Asteroid Collision
> ## Solution 1: use Slide Window to update the collision result  
> 1. 宣告兩個變數p1 & p2，分別指向asteroids陣列中的連續兩個元素。  
> 2. 接著從頭開始做collision的合併，合併前提為p1 > 0 && p2 < 0，然而其中情況又分成三種:
>> (1) abs(asteroids[p1]) > abs(asteroids[p2]) : 根據題目規則移除p2  
>> (2) abs(asteroids[p1]) < abs(asteroids[p2]) : 根據題目規則移除p1  
>> (3) abs(asteroids[p1]) == abs(asteroids[p2]) : 兩者抵銷，移除both  
> 3. 利用迴圈式的持續更新p1 & p2的合併情況，直到p2 iterate到底為止
> 4. 回傳合併完成後的陣列。  

> ## Solution 2: use Stack -->Better
> 1. 利用stack來實作上述方法，從頭檢查到尾  
> 2. 合併規則相同，只不過合併元素的方式，透過push & pop來進行  
> 3. 利用此資料結構可以大幅減少time complexity to O(N)