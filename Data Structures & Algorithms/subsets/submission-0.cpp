class Solution {
public:
    void backtrack(vector<int> nums, vector<vector<int>>& result, int index, vector<int> temp) {
        result.push_back(temp);
        if (index == nums.size()) return;
        for (int i = index; i < nums.size(); i++) {
            temp.push_back(nums[i]);
            backtrack(nums, result, i + 1, temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int size = nums.size();

        vector<vector<int>> result;
        backtrack(nums, result, 0, {});
        return result;
    }
};
