class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adjacency;
        unordered_map<int, int> indegree;
        for (int i = 0; i < numCourses; i++) indegree[i] = 0;
        for (auto &p: prerequisites) {
            adjacency[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        queue<int> q;
        int processed_courses = 0;
        for (auto [node, val]: indegree) {
            if (val == 0) q.push(node);
        }
        while (!q.empty()) {
            processed_courses++;
            int node = q.front();
            q.pop();
            for (int nb: adjacency[node]) {
                if (--indegree[nb] == 0) q.push(nb);
            }
        }
        return processed_courses == numCourses;
    }
};
