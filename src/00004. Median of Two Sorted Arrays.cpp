/* 
*	two_pointers: O(m+n)
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0;
        int j = 0;
        vector<int> merge_array;
        
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]){
                merge_array.push_back(nums1[i++]);
            }else{
                merge_array.push_back(nums2[j++]);
            }
        }
        
        while (i < nums1.size()) {
            merge_array.push_back(nums1[i++]);
        }
        
        while (j < nums2.size()) {
            merge_array.push_back(nums2[j++]);
        }
        if ((i+j) % 2 == 0) {
            return ((double)(merge_array[(i+j)/2]) + merge_array[(i+j)/2 - 1]) / 2;
        } else {
            return merge_array[(i+j)/2];
        }
    }
};

/*
*	binary_search: O(log(min(m,n)))
*/