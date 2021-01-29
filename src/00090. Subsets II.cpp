class Solution {
public:
    void recursion(const vector<int>& nums, vector<vector<int>>& rs, vector<int>& tmp, const int& begin) {
        int n = nums.size();
        int prev_val = -11;
        for (int i = begin; i < n; i++) {
            if (nums[i] != prev_val) {
                tmp.push_back(nums[i]);
                rs.push_back(tmp);
                recursion(nums, rs, tmp, i + 1);
                tmp.pop_back();
                prev_val = nums[i];
            }
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> rs;
        vector<int> tmp;
        
        rs.push_back({});
        sort(nums.begin(), nums.end());
        recursion(nums, rs, tmp, 0);
        return rs;
    }
};