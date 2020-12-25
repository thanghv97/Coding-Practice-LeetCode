class Solution {
public:
    vector<string> f1{"", "M", "MM", "MMM"};
    vector<string> f2{"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    vector<string> f3{"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    vector<string> f4{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    
    int romanToInt(string s) {
        int i = 0;
        int j = i;
        string tmp;
        int rs = 0;

        /*** get f1 ***/
        while (s[j] == 'M') {
            j++;
        }
        if (j != i) {
            tmp = s.substr(i, j - i);
            for (int k = 0; k < f1.size(); k++) {
                if (f1[k] == tmp) {
                    rs = rs + k * 1000;
                    break;
                }
            }
        }
        
        /*** get f2 ***/
        i = j;
        while (s[j] == 'C' || s[j] == 'D' || s[j] == 'M') {
            j++;
        }
        if (j != i) {
            tmp = s.substr(i, j - i);
            for (int k = 0; k < f2.size(); k++) {
                if (f2[k] == tmp) {
                    rs = rs + k * 100;
                    break;
                }
            }
        }
        
        /*** get f3 ***/
        i = j;
        while (s[j] == 'X' || s[j] == 'L' || s[j] == 'C') {
            j++;
        }
        if (j != i) {
            tmp = s.substr(i, j - i);
            for (int k = 0; k < f3.size(); k++) {
                if (f3[k] == tmp) {
                    rs = rs + k * 10;
                    break;
                }
            }
        }
        
        /*** get f4 ***/
        i = j;
        while (s[j] == 'I' || s[j] == 'V' || s[j] == 'X') {
            j++;
        }
        if (j != i) {
            tmp = s.substr(i, j - i);
            for (int k = 0; k < f4.size(); k++) {
                if (f4[k] == tmp) {
                    rs = rs + k ;
                    break;
                }
            }
        }
        
        return rs;
    }
};