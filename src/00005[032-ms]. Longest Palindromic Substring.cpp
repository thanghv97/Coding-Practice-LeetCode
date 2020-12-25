class Solution {
public:
    string longestPalindrome(string s) {
        int rs = 0;
        int cs = 0;
        
        for (int i = 0; i < s.length(); i++) {
            int t1 = i - 1;
            int t2 = i + 1;
            int cout = 1;
            while (t1 >= 0 && t2 < s.length()) {
                if (s[t1] == s[t2]) {
                    t1--;
                    t2++;
                    cout+=2;
                } else {
                    break;
                }
            }
            
            if (cout > rs) {
                rs = cout;
                cs = i - rs/2;
            }
        }
        
        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] == s[i+1]) {
                int t1 = i - 1;
                int t2 = i + 2;
                int cout = 2;
                while (t1 >= 0 && t2 < s.length()) {
                    if (s[t1] == s[t2]) {
                        t1--;
                        t2++;
                        cout+=2;
                    } else {
                        break;
                    }
                }

                if (cout > rs) {
                    rs = cout;
                    cs = i - rs/2 + 1;
                }
            }
        }
        
        return s.substr(cs, rs);
    }
};