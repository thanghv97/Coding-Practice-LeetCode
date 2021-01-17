class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return {-1,-1};
        int l,r;
        int begin = 0;
        int end = nums.size()-1;
        
        while (begin <= end) {
            int mid = (begin + end) / 2;
            
            if (nums[mid] >= target) {
                end = mid - 1;
            } else {
                begin = mid + 1;
            }
        }
        l = end + 1;
        
        begin = l;
        end = nums.size() - 1;
        while (begin <= end) {
            int mid = (begin + end) / 2;
            
            if (nums[mid] <= target) {
                begin = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        r = begin - 1;
        
        if (l == nums.size() || nums[l] != target) {
            return {-1,-1};
        } else {
            return {l,r};
        }
    }
};