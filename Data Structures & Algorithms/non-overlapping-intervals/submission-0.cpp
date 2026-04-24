class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {return a[0] < b[0];});
        int prev_end = intervals[0][1], n = intervals.size(), result = 0;
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] >= prev_end) prev_end = intervals[i][1];
            else {prev_end = min(prev_end, intervals[i][1]); result += 1;}
        }
        return result;
    }
};
