class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length() + 1;
        int m = p.length() + 1;
        vector<vector<bool>> f(n, vector<bool>(m, false));
        
        f[0][0] = true;
        for (int i = 1; i < n; i++) {
            f[i][0] = false;
        }
        
        for (int j = 1; j < m; j++) {
            f[0][j] = (p[j-1] == '*' && f[0][j-2]);
        }
                
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (p[j-1] != '*') {
                    f[i][j] = f[i-1][j-1] && ((p[j-1] == s[i-1]) || p[j-1] == '.');
                } else {
                    f[i][j] = f[i][j-2] || ((p[j-2] == s[i-1] || p[j-2] == '.') && f[i-1][j]); 
                }
            }
        }
        
        return f[n-1][m-1];
    }
};