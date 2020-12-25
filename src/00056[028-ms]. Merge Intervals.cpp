class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int min = intervals[0][0];
        int max = intervals[0][1];
        int last_val[10001];
        vector<vector<int>> rs;
        
        memset(last_val, -1, 10001 * sizeof(int));
        for (int i = 0; i < intervals.size(); i++) {
            last_val[intervals[i][0]] = std::max(last_val[intervals[i][0]], intervals[i][1]);
        }
        
        int ii = intervals[0][1];
        int last = -1;
        int begin = 0, end;
        
        for (int i = 0; i < 10001; i++) {
            if (last_val[i] != -1) {
                begin = (last == -1) ? i : begin;
                last = std::max(last_val[i], last); 
            }
            if (last == i) {
                end = last;
                rs.push_back({begin, end});
                last = -1;
            }
        }
        
        return rs;
    }
};