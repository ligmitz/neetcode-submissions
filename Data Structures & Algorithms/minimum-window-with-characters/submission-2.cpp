class Solution {
public:
    string minWindow(string s, string t) {
        int start, end = 1, size = s.size();
        map<char, int> count;
        if (s.find(t) != string::npos) return t;
        string output = "";
        for(auto ch: t) count[ch]++;
        while (end < size) {
            map<char, int> count_copy(count);
            start = end - 1;
            if (count_copy.find(s[end]) != count_copy.end()) count_copy[s[end]]--;
            if (count_copy[s[end]] == 0) count_copy.erase(s[end]);
            while (start >= 0) {
                if (count_copy.find(s[start]) != count_copy.end()) {
                    count_copy[s[start]]--;
                    if (count_copy[s[start]] == 0) count_copy.erase(s[start]);
                    if (count_copy.empty()) {
                        if (output.size() > (end - start + 1) || (output == "")) output = s.substr(start, end - start + 1);
                        break;
                    }
                }
                start--;
            }
            end++;
        }
        return output;
    }
};
