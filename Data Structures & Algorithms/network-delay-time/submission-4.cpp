class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, unordered_map<int, int>> adj;
        vector<int> timings(n, INT_MAX);
        unordered_map<int, bool> visited;
        for (auto time: times) {
            adj[time[0]][time[1]] = time[2];
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        timings[k - 1] = 0;
        while (!pq.empty()) {
            auto [dist, parent] = pq.top();
            pq.pop();
            if (visited[parent]) continue;
            visited[parent] = true;
            for (auto node: adj[parent]) {
                if (!visited[node.first]) {
                    pq.push({dist + node.second, node.first});
                }
                timings[node.first - 1] = min(timings[node.first - 1], dist + node.second);
            }
        }
        int result = timings[0];
        for (int i = 0; i < n; i++) {
            result = max(result, timings[i]);
        }
        return result != INT_MAX ? result : -1;
    }
};
