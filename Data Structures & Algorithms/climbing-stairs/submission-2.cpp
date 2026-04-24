class Solution {
public:
    int climb(int i, int n, vector<int>& dp) {
        if (i == n) return 1;
        if (dp[i] != -1) return dp[i];
        dp[i] = 0;
        if (i + 1 == n) return dp[i] = climb(i + 1, n, dp);
        return dp[i] = climb(i + 1, n, dp) + climb(i + 2, n, dp);
    }

    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return climb(0, n, dp);
    }
};
