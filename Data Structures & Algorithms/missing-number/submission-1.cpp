class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        int result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i <= size; i++) {
            if (nums[i] != i) {
                result = i;
                break;
            }
        }
        return result;
    }
};
