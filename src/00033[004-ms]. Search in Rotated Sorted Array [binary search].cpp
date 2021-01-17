class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int id = -1;
        for (int i = nums.size() - 1; i > 0; i--) {
            if (nums[i-1] < nums[i]) {
                id = i - 1;
                break;
            }
        }
        
        if (id == -1) {
            reverse(nums.begin(),nums.end());
        } else {
            int i = id + 1;
            while (i < nums.size() && nums[i] > nums[id]) i++;
            
            int tmp = nums[id];
            nums[id] = nums[i-1];
            nums[i-1] = tmp;
            
            sort(nums.begin() + id + 1, nums.end());
        }
    }
};