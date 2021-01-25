class Solution {
public:
    int search(vector<int>& nums, int target) {
        int begin = 0;
        int end = nums.size() - 1;
        
        while (begin <= end) {
            int mid = (begin + end) / 2;
            
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[begin] <= nums[end]) {
                if (nums[mid] > target) {
                    end = mid - 1;
                } else {
                    begin = mid + 1;
                }
            } else {
                if ((nums[begin] < nums[mid] && (target < nums[mid] && target >= nums[begin])) || 
                    (nums[begin] > nums[mid] && (target >= nums[begin] || target < nums[mid]))) {
                    end = mid - 1;
                } else {
                    begin = mid + 1;
                }
            }
        }
        
        return -1;
    }
};