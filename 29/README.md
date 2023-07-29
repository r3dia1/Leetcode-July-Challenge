# Leetcode-July-Challenge 7/29
# 808. Soup Servings
> ## Solution: Recursive + cache
> 1. 題意分析: 給定A、B兩種湯各 n (ml)，總共有四種方法來供應這兩種湯品。回傳 A 湯首先變空的機率，加上 A 和 B 同時變空之機率的一半。  
> 2. 供應方法:
```
    1. Serve 100 ml of soup A and 0 ml of soup B,
    2. Serve 75 ml of soup A and 25 ml of soup B,
    3. Serve 50 ml of soup A and 50 ml of soup B, and
    4. Serve 25 ml of soup A and 75 ml of soup B.
```
> 3. 核心遞迴:
```
    // 針對四種serve情況去做機率的運算
    // 由於不能讓湯的剩餘量被扣成負數，所以用max(0, a or b)來做防範
    ans += 0.25*dfs(max(0, a - 100), max(0, b));
    ans += 0.25*dfs(max(0, a - 75), max(0, b - 25));
    ans += 0.25*dfs(max(0, a - 50), max(0, b - 50));
    ans += 0.25*dfs(max(0, a - 25), max(0, b - 75));
```

> 4. 回傳條件:
```
    // 若是A和B同時被耗盡，則回傳機率1/2
    if (a <= 0 && b <= 0)
        return 0.5;
    // 若是A先背號進而以，則回傳機率1
    if (a <= 0)
        return 1.0;
    // B先輩耗盡則不再所求範圍內，所以回傳機率0
    if (b <= 0)
        return 0.0;
```

> 5. No need to calculate after 480048004800. Because, when n=4801n=4801n=4801, the probability is 0.999995382315≈1.00.999995382315 ≈ 1.00.999995382315≈1.0
Thus, we can output 1.01.01.0 for any n>4800n > 4800n>4800.