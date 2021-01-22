class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int i0 = 0, i1 = m - 1;
        int j0 = 0, j1 = n - 1;
        
        vector<int> rs;
        
        while (i0 < i1 && j0 < j1) {
            for (int i = j0; i <= j1; i++) {
                rs.push_back(matrix[i0][i]);
            }
            i0++;
            for (int i = i0; i <= i1; i++) {
                rs.push_back(matrix[i][j1]);
            }
            j1--;
            for (int i = j1; i >= j0; i--) {
                rs.push_back(matrix[i1][i]);
            }
            i1--;
            for (int i = i1; i >= i0; i--) {
                rs.push_back(matrix[i][j0]);
            }
            j0++;
        }
        
        if (i0 == i1) {
            for (int i = j0; i <= j1; i++) {
                rs.push_back(matrix[i0][i]);
            }   
        } else if (j0 == j1) {
            for (int i = i0; i <= i1; i++) {
                rs.push_back(matrix[i][j0]);
            }
        }
        return rs;
    }
};