class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.size() == 0) {
            return {newInterval};
        }
        
        vector<vector<int>> rs;
        bool is_add = false;
        int i = 0, begin, end;
        
        while (i < intervals.size()) {
            if (!is_add && newInterval[0]< intervals[i][0]) {
                i--;
                begin = newInterval[0];
                end = newInterval[1];
            } else {
                begin = intervals[i][0];
                end = intervals[i][1];
            }
                
            int j = i + 1;
            while (j < intervals.size() && intervals[j][0] <= end) {
                end = max(end, intervals[j++][1]);
            }
            if (newInterval[0] <= end) {
                end = max(end, newInterval[1]);
                while (j < intervals.size() && intervals[j][0] <= end) {
                    end = max(end, intervals[j++][1]);
                }
                is_add = true;
            }
            
            rs.push_back({begin, end});
            i = j;
        }
        
        if (!is_add) {
            rs.push_back(newInterval);
        }
        
        return rs;
    }
};