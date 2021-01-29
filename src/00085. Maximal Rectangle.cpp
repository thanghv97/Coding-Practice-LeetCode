class Solution {
public:
    int findMaxRectangle(const vector<int>& heights) {
        std::stack<int> s;
        int rs = 0, tmp;
        
        s.push(0);
        for (int i = 1; i < heights.size(); i++) {
            while (!s.empty() && heights[i] < heights[tmp = s.top()]) {
                s.pop();
                rs = max(rs, (i - (s.empty() ? -1 : s.top()) - 1) * heights[tmp]);
            }
            s.push(i);
        }

        return rs;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        int rs = 0;
        
        vector<int> heights(m + 1, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                heights[j] = (matrix[i][j] == '1') ? heights[j] + 1 : 0;
            }
            rs = max(rs, findMaxRectangle(heights));
        }
        
        return rs;
    }
};