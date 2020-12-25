class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) return 0;
        int n = haystack.length();
        int m = needle.length();
        
        for (int i = 0; i < n - m + 1; i++) {
            if (haystack[i] == needle[0]) {
                bool check = true;
                for (int j = 1; j < m; j++) {
                    if (haystack[i+j] != needle[j]){
                        check = false;
                        break;
                    }
                }
                if (check) {
                    return i;
                }
            }                
        }
        return -1;
    }
};