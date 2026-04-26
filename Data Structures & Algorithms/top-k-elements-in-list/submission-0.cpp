class Solution {
    struct comparator {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
        }
    };

   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        vector<int> result;
        for (auto num : nums) count[num]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, comparator> pq;
        for (auto [num, i] : count) pq.push({num, i});
        while (!pq.empty() && k) {
            auto [num, i] = pq.top();
            pq.pop();
            result.push_back(num);
            k--;
        }
        return result;
    }
};
