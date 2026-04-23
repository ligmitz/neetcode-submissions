class Solution {
   public:
    void backtrack(vector<int>& candidates, int target, int start, int curr_sum,
                   vector<vector<int>>& result, vector<int>& temp) {
        if (curr_sum == target) {
            result.push_back(temp);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1]) continue;
            if (curr_sum + candidates[i] > target) break;
            temp.push_back(candidates[i]);
            backtrack(candidates, target, i + 1, curr_sum + candidates[i], result, temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> temp;
        backtrack(candidates, target, 0, 0, result, temp);
        return result;
    }
};
