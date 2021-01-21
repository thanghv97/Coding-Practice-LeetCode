class Solution {
public:
    void checkSign(const string& s, int& i) {
        i += (s[i] == '-' || s[i] == '+') ? 1 : 0;
    }
    
    bool checke(const string& s, int& i, bool prev_num1, bool prev_num2) {
        if (i == s.length()) return false;
        checkSign(s, i);
        if (i == s.length()) return false;
        
        // get number
        while (i < s.length() && s[i] >= '0' && s[i] <= '9') i++;

        return (i == s.length() && (prev_num1 || prev_num2));
    }
    
    bool checkDot(const string& s, int& i, bool prev_num) {
        // get number
        if (i == s.length()) return (prev_num == true);
        
        bool prev_num1 = false;
        if ((s[i] < '0' || s[i] > '9') && s[i] != 'e') return false;
        while (i < s.length() && s[i] >= '0' && s[i] <= '9') {
            i++;
            prev_num1 = true;
        }
        if (i == s.length()) return true;
        
        if (s[i] != 'e' && s[i] != 'E') return false;
        i++;
        return checke(s, i, prev_num, prev_num1);
    }
    
    bool isNumber(string s) {
        int i = 0;
        
        // check sign
        checkSign(s, i);
        if (i == s.length()) return false;
        
        // get number 
        bool prev_num = false;
        if ((s[i] < '0' || s[i] > '9') && s[i] != '.') return false;
        while (i < s.length() && s[i] >= '0' && s[i] <= '9') {
            i++;
            prev_num = true;
        }
        if (i == s.length()) return true;

        // check dot or e 
        if (s[i] != 'e' && s[i] != '.' && s[i] != 'E') return false;
        if (s[i++] == '.') {
            return checkDot(s, i, prev_num);
        } else {
            return checke(s, i, prev_num, true);
        }
    }
};