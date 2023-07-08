# 2551. Put Marbles in Bags
> Solution: 
>> 1. 先分析題目目的: 
>>>> 假設題目給定v={x1,x2,x3,x4,x5,x6,x7,x8,x9,x10} & k，則依照條件我們要把marbles放到各個bag中。  
>>>> 我們可以用這種分配法表示: [x1 x2 x3] [x4 x5 x6 x7 x8] [x9 x10]  
>>>> 接著題目要求"The score after distributing the marbles is the sum of the costs of all the k bags."  
>>>> 相當於求(x1 + x3) + (x4 + x8) + (x9 + x10)  
>>>> 最後"Return the difference between the maximum and minimum scores among marble distributions."

>> 2. Greedy method: 
>>>> 那我麼可以把題目的意思理解成對v插入k-1個隔板: [x x x | x x x x x | x x]  
>>>> 並且要求隔板兩左右兩個元素相加要越大越好，則我們可以求得maximum score; 反之，相加越小越好，則可以求得minimum score。  

>> 3. Priority queue:
>>>> 原始的priority queue會根據各元素的以大到小來排序 (用在minimum score)。  
>>>> priority_queue<int, vector<int>, greater<int>> 則會以小到大來排序 (用在maxmum score)。  
>>>> Time complexity = O(NlogN)  
>>>> //基本上是heap結構，所以n個元素建立需要O(NlogN)，pop N個元素也要O(NlogN)的時間。
>>>> //或許用array + sort()處裡會更快
