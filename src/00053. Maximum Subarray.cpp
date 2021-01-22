class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int min_sum = 0, rs = INT_MIN, sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            rs = max(rs, sum - min_sum);
            min_sum = min(min_sum, sum);
        }
        
        return rs;
    }
};