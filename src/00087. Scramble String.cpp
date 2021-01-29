class Solution {
public:
    bool recursion(const string& s1, const string& s2, vector<vector<vector<int>>>& f,
                   const int& i, const int& j, const int& num) {
        if (f[i][j][num] != -1) return f[i][j][num] == 1;
        
        for (int k = 1; k < num; k++) {
            if ((recursion(s1, s2, f, i, j, k) && recursion(s1, s2, f, i + k, j + k, num - k)) || 
                (recursion(s1, s2, f, i, j + num - k, k) && recursion(s1, s2, f, i + k, j, num - k))) {
                f[i][j][num] = 1;
                return true;
            }
        }
        f[i][j][num] = 0;
        return false;
    }
    
    bool isScramble(string s1, string s2) {
        int n = s1.length();
        vector<vector<vector<int>>> f(n+1, vector<vector<int>>(n+1, vector<int>(n+1)));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                f[i][j][1] = (s1[i] == s2[j]) ? 1 : 0;
                for (int k = 2; k <= min(n - i, n - j); k++) {
                    f[i][j][k] = (s1.substr(i, k) == s2.substr(j, k)) ? 1 : -1; 
                }
            }
        }
        
        return recursion(s1, s2, f, 0, 0, n);
    }
};