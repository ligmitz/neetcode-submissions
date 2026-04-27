class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> zero_indices;
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) zero_indices.push_back({i, j});
            }
        }
        for (auto indice: zero_indices) {
            int row = indice[0];
            for (int j = 0; j < n; j++) matrix[row][j] = 0;
            int col = indice[1];
            for (int i = 0; i < m; i++) matrix[i][col] = 0;
        }
    }
};
