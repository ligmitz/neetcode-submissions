class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0, j = 0, profit = 0, size = prices.size();
        while (i < size) {
            j = i + 1;
            while (j < size) {
                profit = max(profit, prices[j] - prices[i]);
                j++;
            }
            i++;
        }
        return profit;
    }
};
