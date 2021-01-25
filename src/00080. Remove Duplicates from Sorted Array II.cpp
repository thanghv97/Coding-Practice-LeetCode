class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 1, j = 1;
        int num_appear = 1, prev_num = nums[0];
        while (j < nums.size()) {
            if (nums[j] != prev_num) {
                prev_num = nums[j];
                nums[i++] = nums[j++];
                num_appear = 1;
            } else {
                if (++num_appear > 2) {
                    j++;                     
                } else {
                    nums[i++] = nums[j++];
                }
            }
        }
        nums.erase(nums.begin() + i, nums.end());
        return nums.size();
    }
};