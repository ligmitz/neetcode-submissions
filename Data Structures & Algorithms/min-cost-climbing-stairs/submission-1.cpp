class Solution {
public:
    int recursion(int index, vector<int>& cost, int cost_size, vector<int>& dp) {
        if (index >= cost_size) return 0;
        if (dp[index] != -1) return dp[index];
        return dp[index] = cost[index] + min(recursion(index + 1, cost, cost_size, dp), recursion(index + 2, cost, cost_size, dp));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int cost_size = cost.size();
        vector<int> dp(cost_size, -1);
        return min(recursion(0, cost, cost_size, dp), recursion(1, cost, cost_size, dp));
    }
};
