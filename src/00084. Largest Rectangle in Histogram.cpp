class Solution {
public: 
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        std::stack<int> s;
        int rs = 0, i = 0;
        
        while (i < n) {
            if (s.empty() || heights[i] >= heights[s.top()]) {
                s.push(i++);
            } else {
                int tmp = s.top(); s.pop();
                rs = max(rs, (i - (s.empty() ? -1 : s.top()) - 1) * heights[tmp]);
            }
        }
        
        while (!s.empty()) {
            int tmp = s.top(); s.pop();
            rs = max(rs, (n - (s.empty() ? -1 : s.top()) - 1) * heights[tmp]);
        }
        return rs;
    }
};