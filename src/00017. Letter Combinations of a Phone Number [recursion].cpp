class Solution {
public:
    vector<vector<char>> key = {{' '}, 
                                {' '},
                                {'a', 'b', 'c'},
                                {'d', 'e', 'f'},
                                {'g', 'h', 'i'},
                                {'j', 'k', 'l'},
                                {'m', 'n', 'o'},
                                {'p', 'q', 'r', 's'},
                                {'t', 'u', 'v'},
                                {'w', 'x', 'y', 'z'}};
    
    void recursive(vector<string> &rs, string digits, string str_curr, int k) {
        int cs = digits[k] - 48;
        for (int i = 0; i < key[cs].size(); i++) {
            string str_tmp = str_curr + key[cs][i];
            if (k + 1 == digits.length()) {
                rs.push_back(str_tmp);
            } else {
                recursive(rs, digits, str_tmp, k+1);
            }
        }        
    }
    
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) return vector<string>{};
        vector<string> rs; 
        recursive(rs, digits, "", 0);        
        return rs;
    }
};