#include<ranges>
class Solution {
public:
    int search(int left, int right, int target, const vector<int>& num) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (num[mid] == target) return mid;
            if (target < num[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }

    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        int size = numbers.size();
        for (auto const& [index, num]: views::enumerate(numbers)) {
            int other = target - num;
            int bin = search(index + 1, size - 1, other, numbers);
            if (bin != -1) {
                result.push_back(index + 1);
                result.push_back(bin + 1);
            }
        }
        return result;
    }
};
