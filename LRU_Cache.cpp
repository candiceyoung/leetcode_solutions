class LRUCache{
private:
    list<int> keys;
    pair<int, list<int>::iterator> values;
    unordered_map<int, pair<int, list<int>::iterator>> kvs;
    int max_capacity;
    
    void visit(unordered_map<int, pair<int, list<int>::iterator>>::iterator it) {
        int key = it->first;
        keys.erase(it->second.second);
        keys.push_front(key);
        it->second.second = keys.begin();
    }
    
public:
    LRUCache(int capacity) {
        max_capacity = capacity;
    }
    
    int get(int key) {
        auto it = kvs.find(key);
        if (it != kvs.end()) {
            // found
            visit(it);
            return it->second.first;
        }
        else return -1;
    }
    
    void set(int key, int value) {
        auto it = kvs.find(key);
        if (it != kvs.end()) {
            // found
            visit(it);
        }
        else {
            if (kvs.size() == max_capacity) {
                kvs.erase(keys.back());
                keys.pop_back();
            }
            keys.push_front(key);
        }
        kvs[key] = make_pair(value, keys.begin());
    }
};