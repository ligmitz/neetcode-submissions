class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            int other = target - nums[i];
            auto it = find(nums.begin() + i + 1, nums.end(), other);
            if (it != nums.end()) {
                result.push_back(i);
                result.push_back(it - nums.begin());
                break;
            }
        }
        return result;
    }
};
