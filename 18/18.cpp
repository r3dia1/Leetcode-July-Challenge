class LRUCache {
public:
    list<int> lru_list;
    int cache_size;
    int lru_key;

    // 這個資料型態宣告方式可以產生一對一的iterator指向每個key對應的value
    unordered_map<int, pair<list<int>::iterator, int>> cache;
    LRUCache(int capacity) {
        cache_size = capacity;
    }

    // 更新LRU list
    // 規則: 越靠近List front的元素代表距離上次使用時間越短，反之則為least used。
    void lru_replacement(int recent_key)
    {
        // 根據iterator位置刪除該元素
        lru_list.erase(cache[recent_key].first);
        // 將該元素放入lru list之front代表最新被使用過
        lru_list.push_front(recent_key);
        // 更新該元素之iterator
        cache[recent_key].first = lru_list.begin();
    }
    
    int get(int key) {
        // 檢查cache裡面是否有目標元素，沒有則回傳-1
        if(!cache.count(key))
            return -1;

        // 取得該元素回傳，並且更新LRU list
        lru_replacement(key);
        return cache[key].second;
    }
    
    void put(int key, int value) {
        if(cache.count(key))
        {
            // 欲put之元素已經在cache的話，則更新value & LRU list
            cache[key].second = value;
            lru_replacement(key);
        }
        else
        {
            // 若是cache仍有空位，則直接插入
            if(cache.size() < cache_size)
            {   
                lru_list.push_front(key);
                cache[key] = {lru_list.begin(), value};
            }
            else
            {
                //反之，把LRU element移出cache，並插入最新元素
                lru_key = lru_list.back(); // 取得lru key
                lru_list.pop_back();
                cache.erase(lru_key); // 刪除LRU element
                lru_list.push_front(key);
                cache[key] = {lru_list.begin(), value};
            }
        }
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */