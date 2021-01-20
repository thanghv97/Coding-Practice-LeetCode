class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[n].size();
        
        vector<vector<int>> min_length(m, vector<int>(n));
        
        min_length[0][0] = grid[0][0];
        for (int i = 1; i < m; i++) min_length[i][0] = min_length[i-1][0] + grid[i][0];
        for (int i = 1; i < n; i++) min_length[0][i] = min_length[0][i-1] + grid[0][i];
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                min_length[i][j] = std::min(min_length[i-1][j], min_length[i][j-1]) + grid[i][j];
            }
        }
        return min_length[m-1][n-1];
    }
};