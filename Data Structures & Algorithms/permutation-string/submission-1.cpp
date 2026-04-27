class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if (m < n) return false;
        vector<int> count(26, 0);
        for (char i: s1) count[i - 'a']++;
        for (int i = 0; i < n; i++) {
            if (s1.find(s2[i]) != string::npos) {
                count[s2[i] - 'a']--;
            }
        }
        if (all_of(count.begin(), count.end(), [](int i){return i == 0;})) return true;
        for (int i = n; i < m; i++) {
            if (s1.find(s2[i - n]) != string::npos) {
                count[s2[i - n] - 'a']++;
            }
            if (s1.find(s2[i]) != string::npos) {
                count[s2[i] - 'a']--;
            }
            if (all_of(count.begin(), count.end(), [](int i){return i == 0;})) return true;
        }

        return false;
    }
};
