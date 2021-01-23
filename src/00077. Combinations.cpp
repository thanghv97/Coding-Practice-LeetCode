class Solution {
public:
    void recursion(vector<vector<int>>& rs, const int &n, const int &k, 
                   vector<int> tmp, int begin) {
        if (tmp.size() == k) {
            rs.push_back(tmp);
            return;
        }
        
        for (int i = begin; i <= n - k + tmp.size() + 1; i++) {
            tmp.push_back(i);
            recursion(rs, n, k, tmp, i+1);
            tmp.pop_back();
        }
    } 
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> rs;
        vector<int> tmp;
        recursion(rs, n, k, tmp, 1);
        return rs;
    }
};