/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
   public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int pointera = 0, pointerb = 0, curr = 0, result = 0, n = intervals.size();
        vector<int> starts, ends;
        for (auto interval: intervals) {
            starts.push_back(interval.start);
            ends.push_back(interval.end);
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        while (pointera < n) {
            if (starts[pointera] < ends[pointerb]) {
                pointera++;
                curr++;
            } else {
                pointerb++;
                curr--;
            }
            result = max(result, curr);
        }
        return result;
    }
};
