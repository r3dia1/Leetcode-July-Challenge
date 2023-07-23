# Leetcode-July-Challenge 7/23
# 894. All Possible Full Binary Trees

> ## 題目分析:
>> 1. Number of nodes in each FBT is always odd (因為FBT之定義左右子樹不為NULL)  
>> 2. SubFBTs are the solutions of the smaller problems (這有助於我們使用dp來加速execution)

> ## Solution: Bruter force
>> 1. 當node總數為n時的情況為: 左子樹的node總數可能有: 1 ~ n-1個，同時右子樹可能有: n-1 ~ 0個。
>> 2. 所以利用recursive的方式去暴力建樹
```
    trees(n):
        for i in range(0, n)
            root -> left = tree(i)
            root -> right = tree(n - i - 1)
```
> ## dp for avoiding repeated execution
>> 1. 分析: 首先我們根據題目提供的圖片會發現，很多的subFBT其實是重複出現的。這也代表著出現了多次的重複計算。
>> 2. 解法: 把計算過的subFBTs存起來，當我們執行tree(i)時發現已經有已知結果，則直接回傳結果，便可以省下大量的計算時間。
