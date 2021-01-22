class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int i0 = 0, i1 = n - 1;
        int j0 = 0, j1 = n - 1;
        vector<vector<int>> rs(n, vector<int>(n));
        
        int count = 1;
        while (i0 < i1 && j0 < j1) {
            for (int i = j0; i <= j1; i++) {
                rs[i0][i] = count++;
            }
            i0++;
            for (int i = i0; i <= i1; i++) {
                rs[i][j1] = count++;
            }
            j1--;
            for (int i = j1; i >= j0; i--) {
                rs[i1][i] = count++;
            }
            i1--;
            for (int i = i1; i >= i0; i--) {
                rs[i][j0] = count++;
            }
            j0++;
        }
        
        if (i0 == i1) {
            for (int i = j0; i <= j1; i++) {
                rs[i0][i] = count++;
            }        
        } 
        return rs;
    }
};