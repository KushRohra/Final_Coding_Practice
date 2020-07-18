//https://leetcode.com/problems/lru-cache/
class LRUCache {
public:
    int c=0;
    list<pair<int, int>> dq;
    unordered_map<int, list<pair<int, int>>::iterator> m;
    LRUCache(int capacity) {
        m.clear();
        c = capacity;
    }
   
    int get(int key)
    {
        auto it = m.find(key);
        if(it==m.end())
            return -1;
        int val = it->second->second;
        put(key, val);
        return val;
    }
   
    void put(int key, int value)
    {
        if(m.find(key)!=m.end())
            dq.erase(m[key]);
        dq.push_front(make_pair(key, value));
        m[key] = dq.begin();
        if(m.size()>c)
        {
            m.erase(dq.rbegin()->first);
            dq.pop_back();
        }
           
    }
};

