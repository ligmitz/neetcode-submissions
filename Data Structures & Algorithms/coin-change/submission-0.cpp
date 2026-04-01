class Solution {
public:
    void bfs(int index, vector<int>& coins, int amount, int summ, int count, int& answer) {
        if (summ > amount) return;
        if (summ == amount) {
            answer = min(answer, count);
        };

        for (int i = index; i < coins.size(); i++) {
            bfs(i, coins, amount, summ + coins[i], count + 1, answer);
        }
    }

    int coinChange(vector<int>& coins, int amount) {
        int answer = INT_MAX;
        bfs(0, coins, amount, 0, 0, answer);
        return answer == INT_MAX ? -1:answer;
    }
};
