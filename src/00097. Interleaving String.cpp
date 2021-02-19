class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) return false;
        vector<vector<bool>> f(s3.length() + 1, vector<bool>(s1.length() + 1));
        
        f[0][0] = true;
        for (int i = 1; i <= s3.length(); i++) {
            for (int j = max(0, i - (int)s2.length()); j <= min(i, (int)s1.length()); j++) {
                bool tmp_1 = (i - j == 0 || s3[i - 1] != s2[i - j - 1]) ? false : f[i - 1][j];
                bool tmp_2 = (j == 0 || s3[i - 1] != s1[j - 1]) ? false : f[i - 1][j - 1];
                f[i][j] = tmp_1 || tmp_2;
            }
        }
                               
        return f[s3.length()][s1.length()];
    }
};