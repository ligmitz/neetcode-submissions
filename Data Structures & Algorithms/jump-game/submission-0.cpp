class Solution {
    bool jump(vector<int>& nums, int i) {
        if (i >= (nums.size() - 1)) return true;
        bool allowed = false;
        for (int j = 1; j <= nums[i]; j++) {
            if ((i + j) == (nums.size() - 1)) {
                allowed = true;
                break;
            }
            allowed = allowed || jump(nums, i + j);
        }
        return allowed;
    }
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 0) return false;
        return jump(nums, 0);
    }
};
