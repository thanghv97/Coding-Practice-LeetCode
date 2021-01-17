class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> nums_map;
        
        for (int i = 0; i < nums.size(); i++) {
            const auto it = nums_map.find(target - nums[i]);
            if (it != nums_map.end()) {
                return vector<int>{it->second, i};
            }
            nums_map.insert(std::pair<int, int>(nums[i], i));
        }
        return vector<int>{0, 0};
    }
};