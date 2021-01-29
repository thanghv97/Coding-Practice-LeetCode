class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> rs;
        
        rs.push_back(0);
        rs.push_back(1);
        for (int i = 1; i < n; i++) {
            int sz = rs.size();
            int base = 1 << i;
            for (int j = sz - 1; j >= 0; j--) {
                rs.push_back(rs[j] + base);
            }
        }
        return rs;
    }
};