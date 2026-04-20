class Solution {
public:
    int navigate(int m, int n, int crow, int ccol, vector<vector<int>>& dp) {
        if (crow == m - 1 && ccol == n - 1) return 1;
        if (dp[crow][ccol] != -1) return dp[crow][ccol];
        dp[crow][ccol] = 0;
        if (crow < m - 1) 
            dp[crow][ccol] += navigate(m, n, crow + 1, ccol, dp);
        if (ccol < n - 1)
            dp[crow][ccol] += navigate(m, n, crow, ccol + 1, dp);
        return dp[crow][ccol];
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return navigate(m, n, 0, 0, dp);
    }
};
