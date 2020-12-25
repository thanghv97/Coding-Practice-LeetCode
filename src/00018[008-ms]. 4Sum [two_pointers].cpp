class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) return vector<vector<int>> {};
        vector<vector<int>> rs;
        
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; i++) {
            if (i == 0 || nums[i] != nums[i-1]) {
                if (nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) break;
                if (nums[i] + nums[nums.size()-1] + nums[nums.size()-2] + nums[nums.size()-3] < target) continue;
                for (int j = i + 1; j < nums.size() - 2; j++) {
                    if (j == i+1 || nums[j] != nums[j-1]) {
                        if (nums[i] + nums[j] + nums[j+1] + nums[j+2] > target) break;
                        if (nums[i] + nums[j] + nums[nums.size()-1] + nums[nums.size()-2] < target) continue;
                        int u = j + 1;
                        int v = nums.size() - 1;
                        while (u < v) {
                            int sum = nums[i] + nums[j] + nums[u] + nums[v];

                            if (sum == target) {
                                rs.push_back({nums[i], nums[j], nums[u++], nums[v--]});
                                while (u < v && nums[u] == nums[u-1]) u++;
                                while (u < v && nums[v] == nums[v+1]) v--;
                            } else if (sum < target) {
                                u++;
                            } else {
                                v--;
                            }
                        }
                    }
                }
            }
        }
        
        return rs;
    }
};