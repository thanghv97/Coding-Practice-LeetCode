class Solution {
public:
    void recursive(vector<string> &rs, string str_tmp, int n, int count, int i) {
        /*** add '(' ***/
        if (count < n) {
            recursive(rs, str_tmp + '(', n, count+1, i+1);
        }
        
        /*** add ')' ***/
        if (i > 0) {
            recursive(rs, str_tmp + ')', n, count, i-1);
        }
        
        if (i == 0 && count == n) {
            rs.push_back(str_tmp);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> rs;
        recursive(rs, "(", n, 1, 1);
        return rs;
    }
};