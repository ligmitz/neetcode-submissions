class TimeMap {
    unordered_map<string, vector<pair<string, int>>> db;
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        db[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if (db.find(key) == db.end()) return "";
        auto& li = db[key];
        int left = 0, right = li.size() - 1;
        while (left < right) {
            int mid = left + (right - left + 1) / 2;
            if (li[mid].second <= timestamp) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return li[left].second > timestamp ? "" : li[left].first;
    }
};
