# Leetcode-July-Challenge 7/18
# 146. LRU Cache
> ## Solution : hashmap & list
> 根據題目需求完成相對應之function。
> 變數宣告:
```
    list<int> lru_list; // 規則: 越靠近List front的元素代表距離上次使用時間越短，反之則為least used。

    int cache_size; // cache容量

    int lru_key; // 紀錄當前lru key

    // 這個資料型態宣告方式可以產生一對一的iterator指向每個key對應的value
    unordered_map<int, pair<list<int>::iterator, int>> cache;
```
> 1. LRUCache(int capacity): 建立可以更新cache容量的constructor。  
> 2. int get(int key): 檢查cache裡面是否有目標元素，取得該元素回傳並更新LRU list；沒有找到該元素則回傳-1。
> 3. void put(int key, int value):
>> condition 1: key element is already in cache. Then just upadate the value and update the LRU list.
>> condition 2: key element is not in cache and current cache size < maximum size. Then just insert the new cache element and update the LRU list.
>> condition 3: key element is not in cache and current cache size = maximum size. Remove the LRU element in cache, and insert the latest element & update the LRU list.