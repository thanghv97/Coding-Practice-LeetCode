class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool a[256];
        int cs[256];
        memset(a, false, 256);
        memset(cs, 0, 256);
        int rs = 0, count = 0, j = 0;
        
        for (int i = 0; i < s.length(); i++) {
            int ch = (int)s[i];
            if (a[ch] == false) {
                count += 1;
            } else {   
                count = i - std::max(j, cs[ch]);
                j = std::max(j, cs[ch]);
            }
            
            a[ch] = true;
            cs[ch] = i;
            rs = std::max(rs, count);
        }

        return rs;
    }
};