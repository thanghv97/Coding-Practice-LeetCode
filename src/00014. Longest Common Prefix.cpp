class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) { return ""; } 
        if (strs.size() == 1) { return strs[0]; }
        string str_tmp;
        int rs = 0;
        int ii = 0;
        
        while (ii < strs[0].length()) {
            bool check = true;
            
            for (int i = 1; i < strs.size(); i++) {
                if (strs[i][ii] != strs[0][ii]) {
                    check = false;
                    break;
                }
            }
            
            if (!check) {
                break;
            }
            rs++;
            ii++;
        }
        
        if (rs == 0) {
            return "";
        }
        return strs[0].substr(0, ii);
    }
};