class Solution {
   public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int, vector<int>> mappings, reverse_mappings;
        for (auto item : trust) {
            mappings[item[1]].push_back(item[0]);
            reverse_mappings[item[0]].push_back(item[1]);
        }
        for (auto [person, judges] : mappings) {
            if (judges.size() == (n - 1) && reverse_mappings[person].size() == 0) return person;
        }
        return -1;
    }
};