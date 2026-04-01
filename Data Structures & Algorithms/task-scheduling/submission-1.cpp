using P = pair<char, vector<int>>;
class Solution {
public:
    struct PairComparator {
        bool operator() (const P& a, const P& b) {
            return a.second[0] < b.second[0];
        }
    };

    int leastInterval(vector<char>& tasks, int n) {
        int cycle = 0;
        priority_queue<P, vector<P>, PairComparator> pq;
        unordered_map<char, int> count;
        for (char task: tasks) count[task]++;

        for (auto item: count) {
            pq.push({item.first, {item.second, 0}});
        }

        while (!pq.empty()) {
            cycle++;
            vector<P> deferred;
            while (!pq.empty()) {
                auto item = pq.top();
                pq.pop();
                
                if (item.second[1] <= cycle) {
                    if (item.second[0] - 1 > 0)
                        pq.push({item.first, {item.second[0] - 1, cycle + n + 1}});
                    break;
                } else {
                    deferred.push_back(item);
                }
            }
            
            for (auto& d : deferred) pq.push(d);
        }
        return cycle;
    }
};
