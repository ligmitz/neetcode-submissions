class Solution {
public:
    int area(int left, int right, int bar1, int bar2) {
        return (right - left) * min(bar1, bar2);
    }
    int maxArea(vector<int>& heights) {
        int max_area = INT_MIN, size = heights.size();
        for (int i = 0; i < size - 1; i++) {
            for (int j = i + 1; j < size; j++) {
                max_area = max(max_area, area(i, j, heights[i], heights[j]));
            }
        }

        return max_area;
    }
};
