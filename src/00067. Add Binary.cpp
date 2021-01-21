class Solution {
public:
    string addBinary(string a, string b) {
        if (a.length() > b.length()) return addBinary(b, a);
        
        int n = a.length();
        int m = b.length();
        string rs = "";
        
        int tmp = 0;
        for (int i = 0; i < n; i++) {
            int sum = (a[n-1-i] - '0') + (b[m-1-i] - '0') + tmp;
            rs = (char)(sum % 2 + '0') + rs;
            tmp = sum / 2;
        }
        
        for (int i = n; i < m; i++) {
            int sum = (b[m-1-i] - '0') + tmp;
            rs = (char)(sum % 2 + '0') + rs;
            tmp = sum / 2;
        }
        
        rs = (tmp > 0) ? "1" + rs : rs;
        
        return rs;
    }
};