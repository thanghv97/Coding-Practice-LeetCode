class Solution {
public:
    vector<string> f1{"", "M", "MM", "MMM"};
    vector<string> f2{"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    vector<string> f3{"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    vector<string> f4{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        
    string intToRoman(int num) {
        string rs = f1[num/1000] + f2[(num/100)%10] + f3[(num/10)%10] + f4[num%10];
        
        return rs;
    }
};