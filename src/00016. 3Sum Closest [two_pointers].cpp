class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int rs = nums[0] + nums[1] + nums[2];
        int closest = abs(rs - target);
        
        for (int k = 0; k < nums.size() - 2; k++) {
            if (k == 0 || nums[k] != nums[k-1]) {
                int i = k + 1;
                int j = nums.size() - 1;
                while (i < j) {
                    int sum = nums[k] + nums[i] + nums[j];
                    if (closest > abs(sum-target)) {
                        closest = abs(sum-target);
                        rs = sum;
                    }
                    if (sum == target) {
                        return sum;
                    } else if (sum < target) {
                        i++;
                    } else {
                        j--;
                    }
                }
            }
        }
        return rs;
    }
};