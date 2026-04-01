class Solution {
public:
    int recurse(int amount, int left, int currentAmount, vector<int>& coins, vector<vector<int>>& memo) {
        if (currentAmount > amount) return 0;
        if (currentAmount == amount) return 1;
        if (memo[left][currentAmount] != -1) return memo[left][currentAmount];
        int ways = 0;
        for (int i = left; i < coins.size(); i++) {
            ways += recurse(amount, i, currentAmount + coins[i], coins, memo);
        }
        return memo[left][currentAmount] = ways;
    }

    int change(int amount, vector<int>& coins) {
        if (amount == 0) return 1;
        vector<vector<int>> memo(coins.size(), vector<int>(amount + 1, -1));
        int ways = 0;
        for (int i = 0; i < coins.size(); i++) {
            ways += recurse(amount, i, coins[i], coins, memo);
        }
        return ways;
    }
};
