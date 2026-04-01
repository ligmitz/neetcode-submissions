class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;
        unordered_map<int, vector<int>> mappings;
        for (auto edge: edges) {
            mappings[edge[0]].push_back(edge[1]);
            mappings[edge[1]].push_back(edge[0]);
        }
        set<int> visited;
        queue<int> q;
        q.push(0);
        visited.insert(0);
        while(!q.empty()) {
            int top = q.front();
            q.pop();
            for (int node: mappings[top]) {
                if (visited.find(node) == visited.end()) {
                    visited.insert(node);
                    q.push(node);
                }
            }
        }
        return visited.size() == n;
    }
};
