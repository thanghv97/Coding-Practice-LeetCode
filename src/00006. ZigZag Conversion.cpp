class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        vector<vector<int>> mod;
        int n = numRows * 2 - 2;
        
        mod.resize(n/2+1);
        
        for (int i = 0; i < s.length(); i++) {
            int tmp = i % n;
            tmp = (tmp > n/2) ? n - tmp : tmp;
            
            mod[tmp].push_back((int)s[i]);
        }
        
        string rs;
        for (int i = 0; i < n/2 + 1; i++) {
            for (int j = 0; j < mod[i].size(); j++) {
                rs += (char) mod[i][j];
            }
        }
        return rs;
    }
};