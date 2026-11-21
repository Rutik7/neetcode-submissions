class LRUCache {
    list<pair<int ,int>> cachelist;
    unordered_map<int,list<pair<int,int>>::iterator> cachemap;
    int maxSize;

    void moveToFront(list<pair<int,int>>::iterator it)
    {
        auto node = *it;
        cachelist.erase(it);
        cachelist.push_front(node);
        cachemap[node.first] = cachelist.begin();
    }

    void evict()
    {
        if(!cachelist.empty())
        {
            const auto& node = cachelist.back();
            cachemap.erase(node.first);
            cachelist.pop_back();
        }
    }
public:

    LRUCache(int capacity) {
        maxSize = capacity;
    }
    
    int get(int key) {
        auto it = cachemap.find(key);

        // if found
        if(it != cachemap.end())
        {
            moveToFront(it->second);
            return it->second->second;
        }

        else return -1;
    }
    
    void put(int key, int value) {
        // if key exists, update the value and move to front
        auto it = cachemap.find(key);
        if(it != cachemap.end())
        {
            it->second->second = value;
            moveToFront(it->second);
            return;
        }

        // if key does not exist, insert new node at front
        cachelist.push_front({key, value});
        cachemap[key] = cachelist.begin();

        // if the cache exceeds its maximum size, evict the least recently used item
        if(cachelist.size() > maxSize)
            evict();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */