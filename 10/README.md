111. Minimum Depth of Binary Tree
> Solution: 
>> 1. 使用DFS演算法遍歷每一個leaf node，並且一邊計算minimum depth。
>> 2. DFS: 
>>> 先走左(root->left)，再走右(root->left)。  
>>> 遇到leaf node即回傳。  
>>> 又或是走完左 & 右之後也要回傳