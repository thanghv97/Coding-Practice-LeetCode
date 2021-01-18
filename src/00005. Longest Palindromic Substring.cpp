/*
*	expand from center O(n^2)
*/
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

/*
*	dynamic_programing O(n^2)
*/
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> f(n, vector<bool>(n, false));
        
        int rs = 0, cs = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j >= 0; j--) {
                f[i][j] = (s[i] == s[j]) ? (j >= i-1 ? true : f[i-1][j+1]): false;
                if (f[i][j] && rs < i - j + 1) {
                    rs = i - j + 1;
                    cs = j;
                }
            }
        }
        
        return s.substr(cs, rs);
    }
};

/*
*	manacher's algorithm O(n)
*/
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<int> f(2 * n + 1);
        
        int right_most = 0, center = 0;
        int rs = 0, id;
        
        for (int i = 1; i < 2*n+1; i++) {
            f[i] = (i < right_most) ? std::min(right_most - i, f[2*center-i]) : 0;
            while (i-f[i]-1 >= 0 && i+f[i]+1 < 2*n+1 && 
                   ((i+f[i]+1)%2 == 0 || s[(i-f[i]-1)/2] == s[(i+f[i]+1)/2])) f[i]++;
            if (f[i] > rs) {
                rs = f[i];
                id = (i-1)/2;
            }
            if (i + f[i] > right_most) {
                right_most = i+f[i];
                center = i;
            }
        }
        
        return s.substr(id - (rs-1)/2, rs);
    }
};