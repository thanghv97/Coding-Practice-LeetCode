class Solution {
public:
    bool bs(const vector<int> &nums, const int& target, int begin, int end) {
        while (begin <= end) {
            int mid = (begin + end) / 2;
            
            if (nums[mid] == target) {
                return true;
            }
            if (nums[begin] < nums[end]) {
                if (nums[mid] > target) {
                    return bs(nums, target, begin, mid - 1);
                } else {
                    return bs(nums, target, mid + 1, end);
                }
            } else {
                if ((nums[begin] == nums[mid] && bs(nums, target, begin, mid - 1)) || 
                    (nums[end] == nums[mid] && bs(nums, target, mid + 1, end))) {
                    return true;
                }
                if ((nums[begin] < nums[mid] && (target < nums[mid] && target >= nums[begin])) || 
                    (nums[begin] > nums[mid] && (target >= nums[begin] || target < nums[mid]))) {
                    return bs(nums, target, begin, mid - 1);
                } else {
                    return bs(nums, target, mid + 1, end);
                }
            }
        }
        return false;
    }
    
    bool search(vector<int>& nums, int target) {
        return bs(nums, target, 0, nums.size() - 1);
    }
};