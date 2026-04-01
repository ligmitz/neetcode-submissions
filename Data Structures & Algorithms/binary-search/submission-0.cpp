class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto binarysearch = [](int left, int right, int target, vector<int>& nums){
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (nums[mid] == target) return mid;
                if (target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return -1;
        };
        return binarysearch(0, nums.size() - 1, target, nums);
    }
};
