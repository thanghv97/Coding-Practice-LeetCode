class Solution {
public:
    void recursion(vector<string>& rs, string& tmp, const int& begin, const string& s, int num) {
        if (num == 4) {
            if (begin == s.length()) {
                rs.push_back(tmp);
            } 
            return;
        }
        
        string ss = "";
        int ss_int = 0;
        
        tmp = (num == 0) ? tmp : tmp + '.';
        for (int i = begin; i < s.length(); i++) {
            if (s[i] == '0' && (i == 0 || ss_int == 0)) {
                tmp += '0';
                recursion(rs, tmp, i + 1, s, num + 1);
                break;
            } else {
                ss += s[i];
                ss_int = ss_int * 10 + (s[i] - '0');
                if (ss_int > 255) {
                    break;
                }
                string input_str = tmp + ss;
                recursion(rs, input_str, i + 1, s, num + 1);
            }
        }        
    }
    
    vector<string> restoreIpAddresses(string s) {
        if (s.length() > 32) return {};
        
        vector<string> rs;
        string tmp = "";
        recursion(rs, tmp, 0, s, 0);
        return rs;
    }
};