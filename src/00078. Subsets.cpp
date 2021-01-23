class Solution {
public:
    void recursion(vector<vector<int>> &rs, const vector<int> &nums, 
                   vector<int> tmp, int begin) {
        for (int i = begin; i < nums.size(); i++) {
            tmp.push_back(nums[i]);
            rs.push_back(tmp);
            recursion(rs, nums, tmp, i+1);
            tmp.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> rs;
        vector<int> tmp;
        rs.push_back({});
        recursion(rs, nums, tmp, 0);
        return rs;
    }
};