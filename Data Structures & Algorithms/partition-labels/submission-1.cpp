class Solution {
public:
    vector<int> partitionLabels(string s) {
        int start = 0, end, size = s.size();
        vector<int> totals(26, 0);
        for (auto i:s) totals[i - 'a']++;
        unordered_set<char> current_set;
        vector<int> result;
        while (start < size) {
            cout<<"start:"<<start<<endl;
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
                cout<<"end:"<<end<<endl;
                cout<<"First"<<endl;
                for (auto it = current_set.begin(); it != current_set.end(); it++) cout<<"Item->"<<*it<<endl;
                if (current_set.find(s[end]) == current_set.end()) current_set.insert(s[end]);
                cout<<"Second"<<endl;
                for (auto it = current_set.begin(); it != current_set.end(); it++) cout<<"Item->"<<*it<<endl;
                totals[s[end] - 'a']--;
                cout<<"Total:"<<totals[s[end] - 'a']<<endl;
                if (!totals[s[end] - 'a']) current_set.erase(s[end]);
                cout<<"Third"<<endl;
                for (auto it = current_set.begin(); it != current_set.end(); it++) cout<<"Item->"<<*it<<endl;
                end++;
            }
            cout<<"end:"<<end<<endl;
            result.push_back(end - start);
            start = end;
        }
        return result;
    }
};
