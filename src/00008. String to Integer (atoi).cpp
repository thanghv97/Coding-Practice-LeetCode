class Solution {
public:
    int myAtoi(string s) {
        int cs = 0;
        
        // check first non-whitespace
        while (s[cs] == ' ') {
            cs++;
        }
        
        // check first word
        if ((s[cs] >= 'a' && s[cs] <= 'z') || 
            (s[cs] >= 'A' && s[cs] <= 'Z')) {
            return 0;
        }
        
        // check sign
        int sign = (s[cs] == '-') ? -1 : 1;
        if (s[cs] == '-' || s[cs] == '+') {
            cs++;
        }
        
        long tmp;
        int rs = 0;
        for (int i = cs; i < s.length(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                tmp = tmp * 10 + s[i] - 48;
                if (tmp > INT_MAX) {
                    rs = (sign == 1) ? INT_MAX : INT_MIN;
                    return rs;
                }
                rs = tmp;
            } else {
                break;
            }
        }
        rs *= sign;
        
        return rs;
    }
};