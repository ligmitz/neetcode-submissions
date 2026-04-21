class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1), rank(n + 1, 1);
        for (int i = 0; i <= n; i++) parent[i] = i;
        for (const auto &edge: edges) {
            if (!Union(parent, rank, edge[0], edge[1])) return vector<int>{edge[0],edge[1]};
        }
        return {};
    }

    int Find(vector<int>& parent, int node) {
        int node_parent = parent[node];
        while (node_parent != parent[node_parent]) {
            node_parent = parent[parent[node_parent]];
        }
        return node_parent;
    }

    bool Union(vector<int>& parent, vector<int>& rank, int node1, int node2) {
        int parent1 = Find(parent, node1);
        int parent2 = Find(parent, node2);

        if (parent1 == parent2) return false;

        if (rank[parent1] > rank[parent2]) {
            parent[parent2] = parent1;
            rank[parent1] += rank[parent2];
        } else {
            parent[parent1] = parent2;
            rank[parent2] += rank[parent1];
        }
        return true;
    }
};
