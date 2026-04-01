class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
        for (auto routes: tickets) {
            graph[routes[0]].push(routes[1]);
        }
        vector<string> current_path, result;
        current_path.push_back("JFK");

        while (current_path.size() > 0) {
            string current_node = current_path[current_path.size() - 1];
            if (graph[current_node].size() > 0) {
                string next_node = graph[current_node].top();
                graph[current_node].pop();
                current_path.push_back(next_node);
            } else {
                string node = current_path.back();
                current_path.pop_back();
                result.push_back(node);
            }
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
