class Solution {
public:
    int numDecodings(string s) {
        if (s.length() == 0 || s[0] == '0') return 0;
        
        vector<int> f(s.length() + 1);
        f[0] = 1;
        f[1] = 1;
        
        for (int i = 1; i < s.length(); i++) {
            int num = (s[i-1] - 48) * 10 + (s[i] - 48);
            if (s[i] == '0') {
                if (num < 1 || num > 26) return 0;
                f[i+1] = f[i-1];
            } else {
                f[i+1] = (num >= 1 && num <= 26) ? ((num >= 1 && num <= 9) ? f[i] : f[i-1] + f[i]) : f[i];            
            }
        }
        return f[s.length()];
    }
};