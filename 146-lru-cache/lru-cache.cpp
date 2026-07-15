class LRUCache {
public:
    int n;
    unordered_map<int, pair<list<int>::iterator,int>>mp;
    list<int>l1;
    LRUCache(int capacity) {
        n=capacity;
    }
    void makeRecentlyused(int key){
        l1.erase(mp[key].first);
        l1.push_front(key);
        mp[key].first = l1.begin();
    }

    int get(int key) {
        if(mp.find(key)==mp.end()){
            return -1;
        }
        makeRecentlyused(key);
        return mp[key].second;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            mp[key].second = value;
            makeRecentlyused(key);
        }else{
            l1.push_front(key);
            mp[key] = {l1.begin(),value};
        }
        if(mp.size()>n){
            int keytodel = l1.back();
            l1.pop_back();
            mp.erase(keytodel);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */