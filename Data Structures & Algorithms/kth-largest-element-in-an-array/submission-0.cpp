class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int, greater<int>> mul(nums.begin(), nums.end());
        return *next(mul.begin(), k - 1);
    }
};
