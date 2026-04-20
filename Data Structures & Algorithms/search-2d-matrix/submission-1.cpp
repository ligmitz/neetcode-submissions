class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int top = 0, bottom = matrix.size() - 1, left = 0, right = matrix[0].size() - 1, middle, center;

        while (top <= bottom) {
            middle = top + (bottom - top) / 2;
            if (matrix[middle][0] <= target && matrix[middle][right] >= target) {
                while (left <= right) {
                    center = left + (right - left) / 2;

                    if (matrix[middle][center] == target) return true;
                    if (matrix[middle][center] > target) right = center - 1;
                    else left = center + 1;
                }
            } else if (matrix[middle][0] > target) {
                bottom = middle - 1;
            } else {
                top = middle + 1;
            }
        }
        return false;
    }
};
