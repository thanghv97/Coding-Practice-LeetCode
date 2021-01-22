class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        bool prev_row = false;
        for (int i = 0; i < n; i++) {
            bool check = false;
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    int k = i-1;
                    while (k >= 0) matrix[k--][j] = 0;
                    check = true;
                }
                matrix[i][j] = (i > 0 && matrix[i-1][j] == 0) ? 0 : matrix[i][j];
            }
            if (prev_row) {
                for (int j = 0; j < m; j++) {
                    matrix[i-1][j] = 0;
                }
                
            }
            prev_row = check;
        }
        if (prev_row) {
            for (int j = 0; j < m; j++) {
                matrix[n-1][j] = 0;
            }
        }
    }
};