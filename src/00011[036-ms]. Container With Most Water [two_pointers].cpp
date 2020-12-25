class Solution {
public:
    int maxArea(vector<int>& height) {
        int rs = 0;
        for (int i = 0, j = height.size() - 1; i < j; ) {
            rs = max(rs, (j-i) * min(height[i], height[j]));
            height[i] > height[j] ? j-- : i++ ;
        }
        return rs;
    }
};