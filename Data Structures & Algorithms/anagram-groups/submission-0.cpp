class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mappings;
        for (string str: strs) {
            string sorted_string = str;
            sort(sorted_string.begin(), sorted_string.end());
            mappings[sorted_string].push_back(str);
        }
        vector<vector<string>> result;
        for (auto [_, value]: mappings) {
            result.push_back(value);
        }
        return result;
    }
};
