class LRUCache {
public:
  // key -> {value, latest timestamp}
    unordered_map<int, pair<int, int>> mp;

    // {key, timestamp}
    queue<pair<int, int>> q;

    int timer = 0;
    int cap;

    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        timer++;

        // Update latest timestamp
        mp[key].second = timer;

        // Record this latest access
        q.push({key, timer});

        return mp[key].first;
    }

    void put(int key, int value) {
        timer++;

        // Update/insert key
        mp[key] = {value, timer};

        // Record latest access
        q.push({key, timer});

        // Cache has exceeded capacity
        while (mp.size() > cap) {

            auto [oldKey, oldTime] = q.front();
            q.pop();

            // Check whether this is still the latest
            // access of oldKey
            if (mp.find(oldKey) != mp.end() &&
                mp[oldKey].second == oldTime) {

                mp.erase(oldKey);
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