class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int, int> nums_map;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums_map.count(target - nums[i]) > 0) {
                return vector<int>{nums_map.at(target - nums[i]), i};
            }
            nums_map.insert(std::pair<int, int>(nums[i], i));
        }
        return vector<int>{0, 0};
    }
};