class Solution {
public:
    vector<int> partitionLabels(string s) {
        int start = 0, end, size = s.size();
        vector<int> totals(26, 0);
        for (auto i:s) totals[i - 'a']++;
        unordered_set<char> current_set;
        vector<int> result;
        while (start < size) {
            end = start + 1;
            current_set.insert(s[start]);
            totals[s[start] - 'a']--;
            if (!totals[s[start] - 'a']) {
                current_set.erase(s[start]);
                result.push_back(1);
                start = end;
                continue;
            }
            while (!current_set.empty() && end < size) {
                if (current_set.find(s[end]) == current_set.end()) current_set.insert(s[end]);
                totals[s[end] - 'a']--;
                if (!totals[s[end] - 'a']) current_set.erase(s[end]);
                end++;
            }
            result.push_back(end - start);
            start = end;
        }
        return result;
    }
};
