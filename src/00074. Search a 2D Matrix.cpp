class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int begin = 0;
        int end = n*m-1;
        while (begin <= end) {
            int mid = (begin + end) / 2;
            if (matrix[mid/m][mid%m] == target) {
                return true;
            } else if (matrix[mid/m][mid%m] > target) {
                end = mid - 1;
            } else {
                begin = mid + 1;
            }
        }
        return false;
    }
};