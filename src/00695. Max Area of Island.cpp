class Solution {
public:
    int dfs(vector<vector<int>>& grid, const int& i, const int& j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0) {
            return 0;
        }
        
        int area = 0;
        if (grid[i][j] == 1) {
            grid[i][j] = 0;
            area ++;
            area += dfs(grid, i + 1, j);
            area += dfs(grid, i, j + 1);
            area += dfs(grid, i - 1, j);
            area += dfs(grid, i, j - 1);
        }
        
        return area; 
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int max_area = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    max_area = std::max(max_area, dfs(grid, i, j));
                }
            }
        }
        
        return max_area;
    }   
};