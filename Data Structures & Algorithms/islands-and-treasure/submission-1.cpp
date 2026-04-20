class Solution {
   public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> treasures;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) treasures.push({i, j});
            }
        }
        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!treasures.empty()) {
            auto [i, j] = treasures.front();
            treasures.pop();
            for (auto dir: directions) {
                int ni = i + dir[0], nj = j + dir[1];
                if (ni >= 0 && nj >= 0 && ni < grid.size() && nj < grid[0].size() && grid[ni][nj] > grid[i][j] + 1) {
                    grid[ni][nj] = grid[i][j] + 1;
                    treasures.push({ni, nj});
                }
            }
        }
    }
};
