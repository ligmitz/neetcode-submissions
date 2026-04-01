class Solution {
public:
    using vectp = pair<vector<int>, int>;
    struct comparator {
        bool operator() (const vectp& a, const vectp& b) {
            return a.second < b.second;
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vectp, vector<vectp>, comparator> vp;
        for (auto point: points) {
            int dist = point[0] * point[0] + point[1] * point[1];
            vp.push({point, dist});
            if (vp.size() > k) vp.pop();
        }

        vector<vector<int>> result;
        while (!vp.empty()) {
            result.push_back(vp.top().first);
            vp.pop();
        }
        return result;
    }
};
