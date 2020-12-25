class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) return vector<vector<int>>{};
        vector<vector<int>> rs;
        sort(nums.begin(),nums.end());

        for (int k = 0; k < nums.size() - 2; k++) {
            if (k == 0 || nums[k] != nums[k-1]) {
                if (nums[k] + nums[k+1] + nums[k+2] > 0) break;
                if (nums[k] + nums[nums.size()-1] + nums[nums.size()-2] < 0) continue;
                int i = k + 1;
                int j = nums.size() - 1;
                while (i < j) {
                    int sum = nums[i] + nums[j] + nums[k];
                    if (sum == 0) {
                        rs.push_back(vector<int>{nums[k], nums[i++], nums[j--]});
                        while (i < j && nums[i] == nums[i-1]) i++;
                        while (i < j && nums[j] == nums[j+1]) j--;
                    } else if (sum > 0) {
                        j--;
                    } else {
                        i++;
                    }
                }
            }
        }
        
        return rs;
    }
};