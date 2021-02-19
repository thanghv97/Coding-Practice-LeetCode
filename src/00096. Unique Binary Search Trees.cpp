class Solution {
public:
    int recursion(const int& begin, const int& end, vector<vector<int>> &f) {
        if (f[begin][end] != -1) return f[begin][end];

        int rs = 0;
        for (int i = begin; i <= end; i++) {
            f[begin][i - 1] = (f[begin][i - 1] == -1) ? recursion(begin, i - 1, f) : f[begin][i - 1];
            f[i + 1][end] = (f[i + 1][end] == -1) ? recursion(i + 1, end, f) : f[i + 1][end];
            rs = rs + f[begin][i - 1] * f[i + 1][end];
        }
        return rs;
    }
    
    int numTrees(int n) {
        vector<vector<int>> f(n + 2, vector<int>(n + 2));
        for (int i = 0; i <= n + 1; i++) {
            for (int j = 0; j <= n + 1; j++) {
                f[i][j] = (i >= j) ? 1 : -1;
            }
        }
        return recursion(1, n, f);
    }
};